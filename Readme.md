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

Para todas as funções de busca por posição, caso não encontre elemento que satisfaça a busca, retorne -1.

## BLOCO I

### find
- **in**: existe determinado valor na fila?
- **index_of**: qual posição aparece X na fila pela primeira vez?
- **find_if**: qual a posição do primeiro homem da fila?
- **min_element**: qual a posição do menor valor da lista?
- **find_min_if**: qual a posição do homem mais calmo?

### count
- **count**: quantas vezes o valor X apareceu na fila?
- **average**: qual a média de stress?
- **half_compares**: qual metade da lista é mais estressada? [draw, first, second]
- **more_men_or_women**: existem mais homens ou mulheres? [draw, men, women]
- **sex_battle**: quem é mais estressado em média? [draw, men, women]

## BLOCO II

### filter
- **get_men**: retorne uma lista com os homens.
- **get_calm_women**: retorne uma lista com as mulheres stress menor que 10.

### sort
- **sort**: ordene a lista por valor absoluto 
- **sort_stress**: ordene a lista por nível de stress

### reverse
- **reverse**: retorne uma nova lista invertida
- **reverse_inplace**: inverta a lista

### set
- **unicos**: retorne uma lista sem repetição de valores
- **repetidos**: retorne uma lista apenas com os valores repetidos

## Bloco III

### map
- **ocorrencias**: Faça um mapeamento de quantas vezes cada nível de stress aparece.

### proximidade
- **acompanhados**: quais posições existem homens ao lado de pelo menos uma mulher?
- **sozinhos**: quais posições existem homens que não estão do lado de nenhuma mulher?

### sequências
- **times** Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Em quais posições começa o time e quantos indivíduos ele possui?
- **casais**: Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress são se encontram. Caso os participantes sejam orientados a sair da fila e procurar um par, quantos casais poderiam ser formados?

### alteração
- **remover_todos**: dado a lista com os índices de todas as pessoas que saíram da fila, qual a fila resultante?
- **dance**: O coordenador disse: se você está do lado de alguém da com o mesmo nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes, novos pares se formavam, e estes também saíam. Quem ficou na fila?




## Extra
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

