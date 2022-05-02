## Algorítmos mais importantes de FUP

![](fila.png)

## Fila dos estressados


- Na entrada de um evento de um experimento social, os participantes ganhavam uma pulseira especial que precisavam ficar utilizando.
- A pulseira informava, num pequeno visor, um número inteiro que representava o nível de stress daquele participante.
- O número 1 significava totalmente tranquilo e vai aumentando conforme o stress do participante aumentava até o valor máximo de infinito.
- Para fazer uma representação lógica de homens e mulheres em um vetor de inteiros, os números positivos representam os homens e os números negativos representam mulheres.
- Precisamos escrever os algorítmos que identifiquem informações importantes sobre os participantes da fila.

**Exemplos:** 
- `[]]` equivale a uma fila vazia.
- `[-1, -50, -99]` equivale a uma mulher totalmente tranquila, uma mulher médio estressada e uma mulher extremamente estressada.
- `[80, 70, 90, -4]` equivale a três homens estressados e uma mulher tranquila. 
---

<!--TOC_BEGIN-->
- [Algorítmos mais importantes de FUP](#algorítmos-mais-importantes-de-fup)
- [Fila dos estressados](#fila-dos-estressados)
- [Exercícios](#exercícios)
- [BLOCO I](#bloco-i)
    - [find](#find)
    - [condicional](#condicional)
    - [contagem](#contagem)
    - [parcial](#parcial)
- [BLOCO II](#bloco-ii)
    - [filter](#filter)
    - [sort](#sort)
    - [reverse](#reverse)
    - [set](#set)
    - [map](#map)
- [BLOCO III](#bloco-iii)
    - [proximidade](#proximidade)
    - [sequências](#sequências)
    - [alteração](#alteração)
    - [rand](#rand)
<!--TOC_END-->


## Exercícios

Para todas as funções de busca por posição, caso não encontre elemento que satisfaça a busca, retorne -1.

## BLOCO I

### find
- **in**: existe determinado valor na fila?
- **index_of**: qual posição aparece X na fila pela primeira vez?

### condicional
- **find_if**: qual a posição do primeiro homem da fila?
- **min_element**: qual a posição do menor valor da lista?
- **find_min_if**: qual a posição do homem mais calmo?

### contagem
- **count**: quantas vezes o valor X apareceu na fila?
- **average**: qual a média de stress?

### parcial
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

### map
- **ocorrencias**: Faça um mapeamento de quantas vezes cada nível de stress aparece.

## BLOCO III

### proximidade
- **acompanhados**: quais posições existem homens ao lado de pelo menos uma mulher?
- **sozinhos**: quais posições existem homens que não estão do lado de nenhuma mulher?

### sequências
- **times** Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Em quais posições começa o time e quantos indivíduos ele possui?
- **casais**: Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress são se encontram. Caso os participantes sejam orientados a sair da fila e procurar um par, quantos casais poderiam ser formados?

### alteração
- **remover_todos**: dado a lista com os índices de todas as pessoas que saíram da fila, qual a fila resultante?
- **dance**: O coordenador disse: se você está do lado de alguém da com o mesmo nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes, novos pares se formavam, e estes também saíam. Quem ficou na fila?

### rand
- **sortear**: retorna aleatoriamente um elemento do vetor 
- **embaralhar**: retorna um vetor embaralhado

