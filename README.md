# Laço

1. Faça um laço que mostre os números ímpares entre 0 e 20. 
```
1 3 5 ... 19
```
<details><summary>C</summary>
```c++
for(int i = 1; i < 20; i += 2)
    cout << i << " ";
```
</details>

<details><summary>Python</summary>
```python
for i in range(1, 20, 2):
    print i + " ",
```
</details>

- Imprimir de 1 a 31, de 3 em 3 
    1, 4, 7, ..., 31
- Imprimir de 10 até 0 
    10, 9, 8, 7, ..., 0
- Com dois contadores, imprima 'i' indo de 0 até 10 enquanto
'j' vai de 10 até 0.
    [0 10] [1 9] [2 8] ... [8 2] [9 1] [10 0]
- Faça o exercício anterior usando apenas 'i'.
    dica: imprima << i << " " << (10 - 1) << " "
- Usando um laço, sorteie 5 números entre 0 e 100, imprima-os, e no final, mostre o menor.
    20 43 15 18 91 12
    12
- Usando um laço apenas, sorteie 5 números e mostre ao final o menor e o maior.
- Usando um laço apenas, sorteie 5 números e mostre a soma de todos menos o menor e o maior. 
- Pegar números do usuários até ele digitar -1, depois mostre quantos ele digitou, a soma e a média.
- Dado um número qualquer, imprima ao contrario.
    >> 574839
    << 938475
- Dado um número e uma posição, retorne o dígito correspondente.
    0 para unidade, 1 para dezena, 2 para centena, etc.
    >> 3652 2
    << 6
    
