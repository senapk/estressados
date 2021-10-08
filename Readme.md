## Algorítmos mais importantes de FUP

![](fila.png)

## Fila dos estressados


- Na entrada de um evento de um experimento social, os participantes ganhavam uma pulseira especial que precisavam ficar utilizando.
- A pulseira informava, num pequeno visor, um número inteiro que representava o nível de stress daquele participante.
- Nenhum participante sabia o que aquele número significava.
- O número 1 significava totalmente tranquilo e ia aumentando conforme o stress do participante aumentava a´té o valor máximo de 99.
- Para fazer uma representação lógica, os números positivos representam homens e os números negativos representam mulheres em um vetor de inteiros.
- Precisamos escrever os algorítmos que identifiquem informações importantes sobre os participantes da fila.

**Exemplos:** 
- `{]` equivale a uma fila vazia.
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
bool existe(vector<int> fila, int x);

existe({-1, -50, -99}, -1); // true
existe({-1, -50, -99}, 10); // false
```

- **contar**: Quantas vezes o valor X apareceu na fila?

```cpp
int contar(vector<int> fila, int x);

contar({-1, -50, -1 -99}, -1); // 2
contar({-1, -50, -1, -99}, 10); // 0
```

- **procurar_valor**: Em que posição da fila aparece X pela primeira vez?
```cpp
//retorna -1 se não encontrar
int procurar_valor(vector<int> fila, int x);

procurar_valor({-1, -50, -1 -99}, -50); // 1
procurar_valor({-1, -50, -1, -99}, 10); // -1
```
- **procurar_valor_apartir**: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
```cpp
//retorna -1 se não encontrar
int procurar_valor(vector<int> fila, int x, int inicio);

procurar_valor({5, 3, -1, -50, -1, -99}, -1, 0); // 2
procurar_valor({5, 3, -1, -50, -1, -99}, -1, 3); // 4
procurar_valor({5, 3, -1, -50, -1, -99}, -1, 4); // 4
```

### **Melhor caso**: 4 funções
- **procurar_menor**: qual o menor valor da lista?
```cpp
int procurar_menor(vector<int> fila);

procurar_menor({5, 3, -1, -50, -1, -99}); // -99
```
- **procurar_menor_pos**: qual a posição do menor valor da lista?
```cpp
int procurar_menor_pos(vector<int> fila);

procurar_menor_pos({5, 3, -1, -50, -1, -99}); // 5
```
- **procurar_menor_pos_apartir**: Dada a posição para iniciar a busca, qual a posição do menor valor da lista?
```cpp
int procurar_menor_pos_apartir(vector<int> fila, int inicio);

procurar_menor_pos_apartir({5, 3, -1, -50, -1, 10}, 3); // 3
```
- **procurar_melhor_se**: qual a posição do HOMEM mais calmo? (menor valor maior que 0)
```cpp
//retorna -1 se não encontrar
int procurar_melhor_pos_se(vector<int> fila);

procurar_melhor_pos_se({5, 3, -1, -50, -1, -99}); // 1
procurar_melhor_pos_se({-1, -50, -1, -99}); // -1
```


### **Contagem**: 4 funções
- **calcular_stress_medio**: qual a média de stress da fila? (abs)
```cpp
float calcular_stress_medio(vector<int> fila);
```
- **mais_homens_ou_mulheres**: Na fila existem mais homens ou mulheres?
```cpp
//retorna "homens", "mulheres" ou "empate"
string mais_homens_ou_mulheres(vector<int> fila);

mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}); // "mulheres"
mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99}); // "empate"
mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99}); // "homens"
```
- **qual_metade_eh_mais_estressada**: O nível de stress somado de todas as pessoas da primeira metade é maior que o nível de stress somado das pessoas da segunda metade da fila? (abs)
```cpp
//retorna "primeira", "segunda" ou "empate"
string mais_homens_ou_mulheres(vector<int> fila);

mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}); // "segunda"
mais_homens_ou_mulheres({50, 98, 2, -50, -1, -99}); // "empate"
mais_homens_ou_mulheres({-51, 99, 1, -50, -1, -99}); // "primeira"
```

- **homens_sao_mais_estressados_que_mulheres**: a média do stress dos homens é maior que a das mulheres? 

## BLOCO II

### **Filter - Operações de Filtragem**: 4 funções
- **clonar**: retorna um novo vetor copiando os valores do vetor de entrada
```cpp
vector<int> clone(const vector<int>& v);
```

- **pegar_homens**: retorne uma lista com os homens (valores positivos)

```cpp
vector<int> pegar_homens(const vector<int>& v);
```

- **pegar_calmos**: retorne uma lista com as pessoas com stress menor que 10 (positivos menor que 10) (abs)

```cpp
vector<int> pegar_calmos(const vector<int>& v);
```

- **pegar_mulheres_calmas**: retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)

```cpp
vector<int> pegar_mulheres_calmas(const vector<int>& v);
```

### **Acesso**: 5 funções
- **inverter_com_copia**
```cpp
//retorna um novo vetor com os dados invertidos
vector<int> inverter_com_copia(const vector<int>& v);
```

- **reverter_inplace**
```cpp
//inverte os valores do vetor de entrada sem uso de vetor auxiliar
void inverter_inplace(vector<int>& v);
```

- **sortear**
```cpp
//retorna aleatoriamente um elemento do vetor
int sortear(const vector<int>& v);
```

- **embaralhar**
```cpp
//embaralha o vetor original
void embaralhar(vector<int>& v);
```

- **ordenar** - selection sort utilizando 
```cpp
//ordena o vetor original
void ordenar(vector<int>& v);
```

### **Conjuntos**: 3 funções
- **exclusivos**: O fiscal permitiu a entrada de um único representante de cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?
```cpp
//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, -1, -3}
vector<int> exclusivos(const vector<int>& v);
```

- **diferentes**: Qual a lista dos diferentes níveis de stress que aparecem?
```cpp
//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, 2}
vector<int> diferentes(const vector<int>& v);
```

- **abandonados**: quais pessoas ficaram na fila após remover um exemplar de cada valor?
```cpp
//{1, 3, 4, 3, -1, -2, -2} -> {3, -2}
vector<int> abandonados(const vector<int>& v);
```

## BLOCO III

### **Map - Manipulação**: 3 funções
- **sozinhos**: Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)
```cpp
//{1, 3, 4, 3, -1, -3, -3} -> {4}
vector<int> sozinhos(const vector<int>& v);
```

{1, 3, 4, 3, -1, -2, -2} -> {3, -2}
- **mais_ocorrencias**: Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)
    - ```{1, 3, 4, 5, -1, -5, -5} -> 3```
- **mais_recorrentes**: Quais os níveis de stress mais recorrentes. (abs)
    - ```{1, 3, 4, 5, -1, -5, -5, 3, -3} -> {5, 3}```

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

