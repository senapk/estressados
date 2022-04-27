## Algorítmos mais importantes de FUP

![](fila.png)

## Fila dos estressados


- Na entrada de um evento de um experimento social, os participantes ganhavam uma pulseira especial que precisavam ficar utilizando.
- A pulseira informava, num pequeno visor, um número inteiro que representava o nível de stress daquele participante.
- O número 1 significava totalmente tranquilo e vai aumentando conforme o stress do participante aumentava até o valor máximo de infinito.
- Para fazer uma representação lógica de homens e mulheres em um vetor de inteiros, os números positivos representam os homens e os números negativos representam mulheres.
- Precisamos escrever os algorítmos que identifiquem informações importantes sobre os participantes da fila.

**Exemplos:** 
- `{}` equivale a uma fila vazia.
- `{-1, -50, -99}` equivale a uma mulher totalmente tranquila, uma mulher médio estressada e uma mulher extremamente estressada.
- `{80, 70, 90, -4}` equivale a três homens estressados e uma mulher tranquila. 
---

<!--TOC_BEGIN-->
- [Algorítmos mais importantes de FUP](#algorítmos-mais-importantes-de-fup)
- [Fila dos estressados](#fila-dos-estressados)
- [Exercícios](#exercícios)
- [BLOCO I](#bloco-i)
    - [**Busca**: 4 funções](#busca-4-funções)
    - [**Melhor caso**: 4 funções](#melhor-caso-4-funções)
    - [**Contagem**: 4 funções](#contagem-4-funções)
- [BLOCO II](#bloco-ii)
    - [**Filter - Operações de Filtragem**: 4 funções](#filter---operações-de-filtragem-4-funções)
    - [**Acesso**: 5 funções](#acesso-5-funções)
    - [**Conjuntos**: 3 funções](#conjuntos-3-funções)
- [BLOCO III](#bloco-iii)
    - [**Map - Manipulação**: 3 funções](#map---manipulação-3-funções)
    - [**Proximidade**: 2 funções](#proximidade-2-funções)
    - [**Sequências**: 3 funções](#sequências-3-funções)
    - [**Grupos**: 2 funções](#grupos-2-funções)
    - [**Alteração**: 3 funções](#alteração-3-funções)
<!--TOC_END-->


## Exercícios

## BLOCO I

### **Busca**: 4 funções
- **existe**: Alguém com o valor X está na fila?
```cpp
bool in(std::vector<int> fila, int x);
bool in(std::list<int> fila, int x);

assert(in({-1, -50, -99}, -1) == true);
assert(in({-1, -50, -99}, -50) == true);
assert(in({-1, -50, -99}, -99) == true);
assert(in({-1, -50, -99}, 12) == false); 
```

- **count**: Quantas vezes o valor X apareceu na fila?

```cpp
int count(std::vector<int> fila, int x);
int count(std::list<int> fila, int x);

assert(count({-1, -50, -1, -99}, -1) == 2);
assert(count({-1, -50, -1, -99}, 10) == 0);
```

- **find**: "Onde" aparece X na fila pela primeira vez?
```cpp
//retorna -1
int find_index(std::vector<int> fila, int x);

assert(find_index({-1, -50, -1, -99}, -50) == 1);
assert(find_index({-1, -50, -1, -99}, -99) == 3);
assert(find_index({-1, -50, -1, -99}, 10) == -1);
```

- Variantes de find:
```cpp
//retorna nulltpr se não encontrar
int * find(std::vector<int>& vet, int x);

//return 
std::list<int>::iterator find(std::list<int>& fila, int x);
```

- **find_begin**: Dada a posição para iniciar a busca, qual a primeira posição em que aparece X?
```cpp
//retorna -1 se não encontrar
int find_begin(std::vector<int> fila, int x, int inicio = 0);

assert(find_begin({5, 3, -1, -50, -1, -99}, -1, 0) == 2);
assert(find_begin({5, 3, -1, -50, -1, -99}, -1, 3) == 4); 
assert(find_begin({5, 3, -1, -50, -1, -99}, -1, 4) == 4);
assert(find_begin({5, 3, -1, -50, -1, -99}, -1, 5) == -1);
```

### **Melhor caso**:
- **min_element**: qual a posição do menor valor da lista?

```cpp
int min_element(const std::vector<int>& fila);

assert(min_element({5, 3, -1, -50, -1, -99}) == 5);
```

- **find_if**: qual a posição do primeiro homem da fila (Primeiro valor maior que 0)?
```cpp
//retorna -1 se não encontrar
int find_if(const std::vector<int>& fila);

assert(find_if({5, 3, -1, -50, -1, -99}) == 0);
assert(find_if({-1, -50, -1, -99, -444}) == -1);
```

- **find_min_if**: qual a posição do HOMEM mais calmo (Menor valor maior que 0)?
```cpp
//retorna -1 se não encontrar
int find_min_if(const std::vector<int>& fila);

assert(find_min_if({5, 3, -1, -50, -1, -99}) == 1);
assert(find_min_if({-1, -50, -1, -99, -444}) == -1);
```


### **Contagem**: 4 funções
- **calcular_stress_medio**: qual a média de stress da fila? (abs)
```cpp
float calcular_stress_medio(const std::vector<int>& fila);
```
- **mais_homens_ou_mulheres**: Na fila existem mais homens ou mulheres?
```cpp
//retorna "homens", "mulheres" ou "empate"
enum class Result { homens, mulheres, empate };

Result mais_homens_ou_mulheres(const std::vector<int>& fila);

assert(mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}) == Sexo::empate);
assert(mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99}) == Sexo::mulheres);
assert(mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99}) == Sexo::homens);
```
- **qual_metade_eh_mais_estressada**: O nível de stress somado de todas as pessoas da primeira metade é maior que o nível de stress somado das pessoas da segunda metade da fila? (abs)
```cpp
//retorna "primeira", "segunda" ou "empate"
std::string metade_mais_estressada(const std::vector<int>& fila);

assert(metade_mais_estressada({5, 3, -1, -50, -10, -999}) == "segunda");
assert(metade_mais_estressada({50, 98, 2, -50, -1, -991}) == "empate");
assert(metade_mais_estressada({-51, 99, 1, -50, -1, -99}) == "primeira");
```

- **homens_sao_mais_estressados_que_mulheres**: a média do stress dos homens é maior que a das mulheres? 

```cpp
//retorna "primeira", "segunda" ou "empate"
std::string quem_eh_mais_estressado(const std::vector<int>& fila);

assert(quem_eh_mais_estressado({5, 3, -1, -50, -10, -999}) == "mulheres");
assert(quem_eh_mais_estressado({50, 98, 2, -50, -1, 9991}) == "homens");
assert(quem_eh_mais_estressado({-50, 99, 1, 50, -1, -99}) == "empate");
```

## BLOCO II

### **Filter - Operações de Filtragem**: 4 funções
- **clonar**: retorna um novo vetor copiando os valores do vetor de entrada
```cpp
std::vector<int> clone(const std::vector<int>& v);
```

- **pegar_homens**: retorne uma lista com os homens (valores positivos)

```cpp
std::vector<int> pegar_homens(const std::vector<int>& v);
```

- **pegar_calmos**: retorne uma lista com as pessoas com stress menor que 10 (abs)

```cpp
std::vector<int> pegar_calmos(const std::vector<int>& v);
```

- **pegar_mulheres_calmas**: retorne uma lista com as mulheres com nível de stress menor que 10. (negativos menor que 10)

```cpp
std::vector<int> pegar_mulheres_calmas(const std::vector<int>& v);
```

### **Acesso**: 5 funções
- **inverter_com_copia**
```cpp
//retorna um novo vetor com os dados invertidos
std::vector<int> inverter_com_copia(const std::vector<int>& v);
```

- **reverter_inplace**
```cpp
//inverte os valores do vetor de entrada sem uso de vetor auxiliar
void inverter_inplace(std::vector<int>& v);
```

- **sortear**
```cpp
//retorna aleatoriamente um elemento do vetor
int sortear(const std::vector<int>& v);
```

- **embaralhar**
```cpp
//embaralha o vetor original
void embaralhar(std::vector<int>& v);
```

- **ordenar** - selection sort utilizando 
```cpp
//ordena o vetor original
void ordenar(std::vector<int>& v);
```

### **Conjuntos**: 3 funções
- **separar**: Separe os únicos dos repetidos para cada valor da lista.



- **exclusivos**: O fiscal permitiu a entrada de um único representante de cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?
```cpp
//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, -1, -2}
std::vector<int> unicos(const std::vector<int>& v);
```

- **diferentes**: Qual a lista dos diferentes níveis de stress que aparecem?
```cpp
//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, 2}
std::vector<int> diferentes(const std::vector<int>& v);
```

- **duplicados**: Quais os valores duplicados que não foram incluídos na lista de únicos?
```cpp
//{1, 3, 4, 3, -1, -2, -2} -> {3, -2}
std::vector<int> abandonados(const std::vector<int>& v);
```

## BLOCO III

### **Map - Manipulação**: 3 funções
- **ocorrencias**: Faça um mapeamento de quantas vezes cada nível de stress aparece.

- **sozinhos**: Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)
```cpp
//{1, 3, 4, 3, -1, -3, -3} -> {4}
std::vector<int> sozinhos(const std::vector<int>& v);
```

{1, 3, 4, 3, -1, -2, -2} -> {3, -2}
- **mais_ocorrencias**: Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)
```cpp
{1, 3, 4, 5, -1, -5, -5} -> 3
```

- **mais_recorrentes**: Quais os níveis de stress mais recorrentes. (abs)
```cpp
{1, 3, 4, 5, -1, -5, -5, 3, -3} -> {5, 3}
```

### **Proximidade**: 2 funções
- **briga** Quando alguém super estressado(>50) está ao lado de duas pessoas muito estressadas(>30) pode dar briga. Quantas vezes essa situação acontece?
- **apaziguado** Se alguém hiper estressado(>80) estiver ao lado de pelo menos uma pessoa bem tranquila (<10) ela vai ser apaziguada. Em que posições estão esses que serão apaziguados?


### **Sequências**: 3 funções
- **quantos_times** Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Quantos times existem na fila?
- **maior_time** Qual o maior time que apareceu na fila?
- **sozinhos** Quantas pessoas não estavam em um time?

### **Grupos**: 2 funções
- **casais**: Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress são formados. O 3 e o -3 formam um casal. Os participantes fossem orientados a sair da fila e procurar seu par. Quantos casais poderiam ser formados?
- **trios**: Pedimos pros participantes se organizassem em trios. Todos os 3 deveriam estar com o mesmo nível de stress.Quantos trios podem ser formados?

### **Alteração**: 3 funções
- **remove**: Dado a pessoa X, como fica a fila após remover X?
- **insert**: Como fica a fila se eu inserir a pessoa X na posição Y.
- **dance**: O coordenador disse: se você está do lado de alguém da com o mesmo nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes se formavam novos pares que também saíam. Quem ficou na fila?

