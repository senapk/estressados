### ufc
# Grande fila colorida

- Na entrada de um evento, os participantes ganhavam uma camisa de brinde para usar.
- A camisa era sempre de uma cor só e eles podiam escolher a cor que quisessem.
- Cada camisa tinha um número que ia de -10 até 10 que representava aquela cor.
- Após vestirem suas camisas, os participantes formaram uma grande fila.
- A cor -10 representa a cor azul e a 10 a cor vermelha.
- Dois números iguais significam duas cores iguais. 
- As cores vão gradativamente da mais fria até a mais quente.
- Uma camera sobre o saguao do evento coletou as cores da fila e enviou para um computador que vai processar e responder as seguintes perguntas.

---

**Busca**
- 00. Dada a cor X, a cor X apareceu na fila?
- 01. Quantas vezes a cor X apareceu na fila?
- 02.Em que posições da fila apareceu a cor X?

**Contagem**
- 10. Quantas cores diferentes apareceram na fila?
- 11. Quais cores apareceram na fila?
- 12. Quantas pessoas estavam sozinhas com aquela cor na fila?
- 13. Qual cor apareceu mais vezes na fila e quantas vezes ela apareceu? Se houver empate, mostre todas as vencedoras.
- 14. Quantas cores apareceram mais de 3 vezes no total?

**Frio ou Quente**
- 20. Cores menores que 0 são cores frias e as maiores que 0 são cores quentes. Quem apareceu mais, frias ou quentes?

**Times**
Duas ou mais pessas seguidas com a mesma cor formam um time.]os ]os]
- 31. Quantos times existem na fila?
- 32. Qual o maior time que apareceu na fila?
- 33. Quantos times tinham 5 ou mais pessoas?
- 34. Quantas pessoas não estavam em um time?

**Proximidade**
- 40. Quantas pessoas estavam com cor 0 ou ao lado de alguém com a cor 0?
- 41. Quantas pessoas estavam de cor 0 ou até n pessoas de distancia de alguém de cor 0?

**Sequencias**
- 51. Dada uma sequencia de cores, diga quantas vezes ela apareceu na fila.
- 52. Uma grupo ascendente é quando temos pessoas seguidas com cores que vão esquentando. 
    - O grupo [-4 -1 2 2 5] e um grupo ascendente de 6 pessoas. 
    - Mostre o maior grupo ascendente da fila. 
    - Se houver empate, mostre os grupos vencedores.
- 53. O calor total de um grupo se dá pela soma dos números dos participantes. 
    - O grupo [-2 1 3 -4 5 -1] tem calor total 2. 
    - Analise os elementos da fila de 4 em 4 e mostre qual grupo mais quente da fila. 
    - Se houver empate, mostre todos os grupos vencedores.
- 54. Homogêneo é um grupo onde de um participante pro outro muda no máximo 2 tons. 
    - Qual o maior grupo homogêneo? 
    - Se houver empate, todos os grupos vencedores.
- 55. Casais são formados quando quando uma pessoa de uma cor encontra o seu oposto. 
    - O 3 e o -3 formam um casal.
    - O 0 forma casa com outro 0.
    - Os participantes fossem orientados a sair da fila e procurar seu par.
    - Quantos casais poderiam ser formados?
- 56. Pedimos pros participantes se organizassem em trios. 
    - Todos os 3 deveriam estar com a mesma cor. 
    - Quantos trios foram formados?

**Mata mata**
- 70. Dado um cor X, como fica a fila após remover X?
- 71. O coordenador disse: se você está do lado de alguém da mesma
    cor que você, saia da fila com ele.
    - Quando os pares saiam, as vezes se formavam novos pares que também saíam.
    - Quem ficou na fila?

**Ordenacao**
- 80. Ordene a fila por cores da mais fria para a mais quente.

**Circular mata times**
- 90. Os participantes foram convidados a fazer uma fila circular.
    - Todos deram as maos.
    - O ultimo da fila deu as maos ao primeiro. 
    - Time é quando temos 2 ou mais pessoas com a mesma cor, lembra?
    - O coordenador comecou a retirar da fila todos os times.
    - Depois de reorganizada, removia os novos times que se formavam.
    - Qual configuração sobrou na fila?

**Circular com token**
- 91. Os participantes foram convidados a fazer uma fila circular.
    - Os elementos com cor 0 não puderam participar dessa brincadeira.
    - O coodenador jogou uma bolinha para um dos participantes.
    - Se o participante for frio, o companheiro da esquerda dele sai da fila.
    - Se o participante for quente, o companheiro da direita dele sai da fila.
    - A bolinha vai para o companheiro que veio para o lugar de quem saiu.
    - Dado o primeiro jogador que recebeu a bolinha, quem ganhará o jogo?

**Circular dupla**
- 92. Os participantes foram convidados a fazer duas filas com o mesmo tamanho.
    - Após isso ele
    - Quantos elementos eles deram as mãos formando filas circulares.
    - Qual a maior sequencia encontrada na primeira fila que também existe na outra fila?
