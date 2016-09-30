# ufc

# Laço

As atividades devem usar apenas laço. Não use vetores para nenhuma delas. Nosso objetivo é aprimorar nosso domínio de laço.

Clique no nome da linguagem para ver a resposta ou a dica[C, Python, Dica]. 
[bita](bita.md#ufc)
Sugestão: use o google-chrome.

---
### Faça um laço que mostre os números ímpares entre 0 e 20. 
>`1 3 5 ... 19`

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

---
### Faça um laço para imprimir de 1 a 31, de 3 em 3 
>`1 4 7 10 ... 31`

<details><summary>C</summary>
```c++
for(int i = 1; i < 31; i += 2)
    cout << i << " ";
```
</details>

<details><summary>Python</summary>
```python
for i in range(1, 31, 3):
    print i + " ",
```
</details>

---
### Um laço para imprimir de 10 até 0 de 2 em 2
>`10 8 6 4 2 0` 


<details><summary>C</summary>
```c++
for(int i = 10; i >= 0; i -= 2)
    cout << i << " ";
```
</details>

<details><summary>Python</summary>
```python
for i in range(10, 0, -2):
    print i + " ",
```
</details>

---
### Com dois contadores, imprima 'i' indo de 0 até 10 enquanto 'j' vai de 10 até 0. Em um mesmo laço, a cada interação incremente 'i' e decremente 'j'. Imprima ambos.

> `[0 10] [1 9] [2 8] ... [8 2] [9 1] [10 0]`

<details><summary>C</summary>
```c++
//opcao 1
for(int i = 0, j = 10; i <= 10; i++, j--)
    cout << i << " " << j << " ";
//opcao 2
int j = 10;
for(int i = 0; i <= 10; i++){
    cout << i << " " << j << " ";
    j--;
}
    
```
</details>

<details><summary>Python</summary>
```python
for i in range(10, 0, -2):
    print i + " ",
```
</details>

---
### Faça o exercício anterior usando apenas um contador.
>`dica: imprima << i << " " << (10 - i)` 


---
### Usando um laço, sorteie 5 números entre 0 e 100, imprima-os, e no final, mostre o menor.
    20 43 15 18 91 12
    12

<details><summary>C</summary>
```c++
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
    srand(time(NULL));//inicializando a aleatoriedade
    int min = 101;//precisa ser maior que o máximo
    for(int i = 0; i < 5; i++){
        int num = rand() % 101;
        printf("%d ", num);
        if(num < min)
            min = num;
    }
    printf("\n%d", min); 
    return 0;
}
```
</details>

---
### Usando um laço apenas, sorteie 5 números e mostre ao final o menor e o maior.
    20 43 15 18 91 12
    12 43


<details><summary>C</summary>
```c++
    int min = 101;
    int max = 0;
    for(int i = 0; i < 5; i++){
        int num = rand() % 101;
        printf("%d ", num);
        if(num < min)
            min = num;
        if(num > max)
            max = num;
    }
    printf("\n%d %d", min, max); 
    return 0;
}
```
</details>

---
### Usando um laço apenas, sorteie 5 números. Retire o maior e o menor e mostre a média dos que sobraram.

<details><summary>Clique para DICA</summary>
```
    inicialize maior e menor
    inicialize total com 0
    faca 5 vezes:
        sorteie um numero
        se numero maior que maior
            ele sera o novo maior
        se numero menor que menor
            ele sera o novo menor
        aumente total do valor de numero
    retire do total o maior e o menor
    divida o total por 3
    imprima a media
}
```
</details>


<details><summary>C</summary>
```c
    int min = 101;
    int max = 0;
    int total = 0;
    for(int i = 0; i < 5; i++){
        int num = rand() % 101;
        printf("%d ", num);
        if(num < min)
            min = num;
        if(num > max)
            max = num;
        total += num;
    }
    total = total - max - min;
    float media = total / 3;
    printf("\n%f", media); 
    return 0;

```
</details>

---
### Pegar números do usuários até ele digitar -1, depois imprima a média.

<details><summary>C</summary>
```c
    int qtd = 0;
    int soma = 0;
    int num;//o numero do usuario
    while(num != -1){
        puts("Digite um numero, -1 para sair");
        scanf("%d", &num);
        if(num == -1)
            break;
        total += num;
        qtd++;
    }
    printf("%f", (total/(float)qtd));
    return 0;
```
</details>

---

<details><summary>C</summary>
```c
    int qtd = 0;
    int soma = 0;
    int num;//o numero do usuario
    while(num != -1){
        puts("Digite um numero, -1 para sair");
        scanf("%d", &num);
        if(num == -1)
            break;
        total += num;
        qtd++;
    }
    printf("%f", (total/(float)qtd));
    return 0;
```
</details>

---
### Dado um número qualquer, imprima ao contrario.
    >> 574839
    << 938475

<details><summary>DICA</summary>
```DICA
    leia numero
    enquanto numero for diferente de zero
        unidade eh numero modulo 10
        imprima unidade
        divida o numero por 10
```
</details>

<details><summary>C</summary>
```c
    int num = 0;
    scanf("%d", num);
    while(num != 0){
        printf("%d", (num % 10));
        num = num / 10;
    }
```
</details>

---
### Dado um número e uma posição, retorne o dígito correspondente. 0 para unidade, 1 para dezena, 2 para centena, etc.
    >> 3652 2
    << 6
    
<details><summary>C</summary>
```c
    int num = 0;
    int digito;
    scanf("%d %d", num, digito);
    for(int i = 0; i < digito; i++)
        num = num / 10;
    printf("%d", (num % 10));
```
</details>
    
