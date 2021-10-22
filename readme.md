# OCMA
Jogo de simulação em uma área de pesca gerenciada pelo OCMA - Órgão de Controle do Meio Ambiente.

## Introdução

O litoral nordestino é cheio de recursos naturais que estão desaparecendo devido à exploração indiscriminada. Estes recursos são necessários para milhares de pessoas, inclusive para por na mesa seu alimento diário. Nossa fauna marinha é um exemplo disso. Temos uma grande variedade peixes: pargo, cioba, ariacó, dentão, guaíba, sirigado, robalo, badejo, serra, cavala... Enfim, são muitos. Porém, o que deveria ser uma atividade sustentável, a pesca dos animais que ainda não chegaram à fase de reprodução, sem importar o tamanho ou idade, passa a ser insustentável (literalmente). Com o tempo, a população diminui e torna-se um risco à espécie... e à mesa das pessoas.

Com o avanço da tecnologia, dos robôs, carros autônomos e outras inovações, não é difícil imaginar que a autonomia chegue à indústria pesqueira. Barcos inteligentes poderão, no futuro, ser capazes de pescar sem intervenção humana, seguindo normas rígidas do controle ambiental(*). Caso algum pescador inescrupuloso alteresse a programação do barco, sua "caixa preta" (necessária para ter autorização de pesca) denunciaria suas irregularidades.

A dificuldade para os pescadores do futuro será, portanto, de programar seus barcos inteligents de forma a maximizar a pesca, em um ambiente onde outros barcos-pescadores também competem pelos mesmos recursos naturais, mas sem infringir a regulamentação do controle ambiental.

O presente projeto consiste em criar um bot que controla um barco-pesqueiro inteligente. Esse bot irá competir com outros bots como se estivessem em um jogo. Ganha quem programou o bot que obtém, no final do jogo, o maior lucro. Quanto mais peixe, mais dinheiro. Mas se alguma norma for infringida... a multa será dolorosa!

(*) - com esperança que, nessa época, o controle ambiental ainda não tenha sido completamente destruído.

## Visão geral

Seu objetivo é conduzir seu barco-pesqueiro em uma área de pesca e, ao final de um dado número de rodadas, obter um lucro com a venda dos peixes maior que o dos seus colegas. Os barcos partem de um porto (pode haver mais de um) para pescar. Eles possuem um reservatório com uma capacidade máxima de peixes e, portanto, em algum momento, devem retornar a um porto (qualquer um) para realizar a venda do que pescaram, esvaziando seus estoque antes de retornar ao mar.

Porém, cuidado! Caso o barco saia da área de pesca, será multado. Caso o barco navegue por mais tempo que o permitido, será multado. Caso o barco pesque mais que a capacidade máxima de peixes que suporta, será multado. Caso o barco pesque mais do que o permitido em um ponto de pesca, também será multado. E, neste último caso, perderá a licença de pesca... ou seja, fim de jogo.

Há 3 espécies de peixe presentes na área: Robalo, Cioba e Tainha, cada um com seu valor no mercado (como pode ver, no futuro, ainda não resolvemos o problema da inflação...):

* Robalo: R$ 200/kg
* Cioba: R$ 150/kg
* Tainha: R$ 100/kg

Então, é importante priorizar os peixes que irão pescar porque o barco possui uma autonomia de navegação e uma capacidade máxima de peixe que pode levar, independente do tipo. O barco que navegar mais que o permitido, antes de retornar a um porto, ou que levar mais peixe que sua capacidade, será multado. Se quiser aumentar as permissões, terá que comprar um barco maior (uma lancha). Barcos maiores possuem mais autonomia (navegam por mais tempo) e levam mais peixes, mas são caros. Então, é necessário avaliar se o custo vale o benefício. No final das contas, ganha quem tiver mais lucro, e não quem tem um barco maior.

Há apenas dois tipos de barcos, a canoa e a lancha, que possuem as seguintes características:

* Canoa: transporta até 10kg de peixe e faz até 30 deslocamentos.
* Lancha: transporta até 20kg de peixe e faz até 50 deslocamentos.

No início do jogo, todos os bots controlam uma canoa. Não precisa ser comprada. A lancha, por outro lado, pode ser comprada por R$ 10.000. Então, a compra da lancha pode valer a pena (ou não) em função do tamanho da área de pesca, do número de rodadas que o jogo terá, da posição dos pontos de pesca... Enfim, cabe a você programar seu bot para saber se e quando comprar uma lancha.

A limitação de quantos quilos o barco consegue transportar (10kg para as canoas e 20kg para as lanchas) deve ser seguida à risca, sob pena de levar uma multa de R$ 500 por quilo excedente. Esteja, portanto, atento para não ultrapassar o limite.

Os deslocamentos que o tipo de barco permite (30 para as canoas e 50 para as lanchas) indicam que o barco deve voltar a um porto antes desse número de deslocamento. As canoas possuem uma bateria menor e, portanto, uma menor autonomia, enquanto as lanchas podem navegar mais. Caso o barco não retorne a um porto nesse intervalo, será necessário contratar um reboque para levar o barco ao porto. Esse reboque custa R$ 2.000. Portanto, ao se afastar de um porto, verifique se a distância ainda dá para retornar antes do limite de deslocamento, para não precisar pagar reboques.

Os peixes se encontram espalhados na área, em pontos de pesca previamente conhecidos no início do jogo. Porém, não se sabe a quantidade de peixes nesses pontos. Para ter essa informação, é necessário pagar o serviço de radar, exceto no início do jogo, quando todos recebem essa informação gratuitamente. O serviço de radar custa R$ 200 e pode ser solicitado a qualquer momento do jogo.

Independentemente do radar, o bot também sabe a quantidade de peixes em um ponto de pesca quando seu barco se encontra sobre o ponto. Porém, não vale a pena se deslocar até um ponto e descobrir, apenas quando chegar lá, que não se pode pescar. É melhor saber antes. É importante saber a quantidade de peixes em um ponto de pesca porque não é permitido pescar todos os peixes que estão lá. Ao longo do jogo, o número de peixes nos pontos de pesca pode aumentar pouco a pouco. Porém, os pontos com 0 peixes não possuem essa característica. O barco que fizer isso será multado em R$ 50.000 e terá sua licença cancelada. Em outras palavras, o jogo termina para o bot em questão (os demais continuam).

O jogo dura um certo número de rodadas, informado no início da partida. Terminado esse tempo, o período de pesca se encerra. Quando isso ocorre, espera-se que todos os barcos já estejam de volta a um porto para vender seus peixes. Os que não tiverem retornados, não poderão vender suas cargas (peixes que transportam). Portanto, esteja atento também ao número de turnos de uma partida e procure voltar a um porto antes disso.

## Executando o jogo

O jogo é executado a partir de um programa "regulador" (chamaremos aqui de `ocma` - *órgão de controle do meio ambiente* 😁). Este é um programa (executável) que irá chamar e gerenciar os programas (executáveis) dos bots que controlam os barcos. Ou seja, não será você quem irá executar seu programa. Será outro programa, o `ocma`.

O programa `ocma` é um script em Javascript e deve ser chamado usando o nodeJs. Para dar início a um jogo com dois bots competidores, por exemplo `bot_A` e `bot_B`, basta executar:

```sh
$ node ocma bot_A bot_B
```

Caso você não tenha o nodeJs instalado, pode fazê-lo a partir do endereço https://nodejs.org/pt-br/. O programa funciona com a versão 10 do Node ou mais recentes. Se não desejar ou não puder instalar o nodeJs, é possível acessar estes mesmos arquivos no repl.it no endereço: [SITE]. No repl.it, o botão "Play" irá executará o script.

Lembre-se também que `bot1` e `bot2` são executáveis. Ou seja, é você quem deve compilar seu código C e gerar estes programas antes de iniciar o jogo. Bots de exemplo são fornecidos para você dar o pontapé inicial.

A imagem abaixo ilustra um exemplo de execução do jogo. A saída é feito no terminal (linux).

![Exemplo de saída do jogo](./screen.png)


## Comunicação

O jogo é baseado em turnos e, em cada turno, os bots terão oportunidade, na sua vez, de realizar uma única ação... e colher as informações fruto da ação realizada.

O script `ocma` irá intermediar essas ações a partir de mensagens via entrada e saída padrão. Assim, quando seu bot quiser informar uma ação (ex: deslocar para a esquerda), ele precisará enviar para a saída padrão uma string detalhando a ação (ex: `printf("LEFT\n");`). Da mesma forma, as informações obtidas pelo bot devem ser lidas a partir da entrada padrão. Assim, quando seu bot precisar receber uma informação (ex: quantos barcos estão competindo), ele precisará ler da entrada padrão essa informação (ex: `scanf("BOATS %i", &numBoats);`).

A saída e entrada de dados seguem uma sequência e formatação específicas. Por exemplo, só se deve fazer `scanf("NUM_BOATS %i", &numBoats);` quando souber que o `ocma` irá enviar para a entrada padrão do seu bot uma mensagem com essa informação. Seu bot deve se ater estritamente a sequência e formatação para que o processo do OCMA entenda as mensagens.

## Início do jogo

No início do jogo, o script `ocma` irá enviar a todos os bots as seguintes informações (devem ser lidas da entrada padrão):

* A string `AREA` seguida de dois inteiros A e L com as dimensões da área de pesca (altura e largura, respectivamente);
* Uma matriz A x L de inteiros contendo informações de cada célula da área de pesca (ver *Área de pesca*);
* A string `TIME` seguida de um inteiro com a quantidade de rodadas que o jogo terá (o barco deve retornar a um porto antes de terminar as rodadas, sob pena de não poder vender sua carga);
* A string `BOTS` seguida de um inteiro N com o número de bots no jogo;
* As N linhas seguintes conterão uma string e dois valores inteiros. A string é o identificador do bot e os valores inteiros, LIN e COL respectivamente, são sua posição na área de pesca. Assim, eles seguirão sempre a seguinte restrição: 0 <= LIN < A e 0 <= COL < L. Os identificadores estarão na ordem em que os bots serão executados, turno a turno. Essa ordem é definida aleatoriamente no início do jogo e mantida nos turnos seguintes.
* Por fim, a string `YOU` seguida de uma string com o identificador do seu bot (cada um receberá o seu).

### Área de pesca
Cada célula da matriz A x L contém um dos seguintes valores inteiros:
* 0: indica que não há nada, apenas mar.
* 1: indica um porto. Pode haver mais de um porto.
* entre 10 e 39: indicam um ponto de pesca, tal que as dezenas representam o tipo de peixe e as unidades a quantidade de peixes em quilo (haverá no máximo 9kg de peixe em um ponto de pesca). A dezena de 10 (valores de 10 a 19) indica a presença de Tainha, 20 (valores de 20 a 29) de Cioba e 30 (valores de 30 a 39) Robalo. Assim, o valor 32 informa que há 2kg de Robalo em uma determinada posição.

Um exemplo de entrada de dados a ser lida por um bot no início do programa é:
```
AREA 17 14
[TODO gerar uma matriz exemplo]
TIME 10
BOATS 2
bot_A 10 7
bot_B 5 12
YOU bot1
```

### Considerações sobre os dados iniciais

Os identificadores dos bots serão os nomes dos executáveis na competição. Assim, se seu executável for `mybot`, o identificador a ser passado para os demais bots será este. Para evitar conflito de nomes, gere seu executável com seu nome. Assim, quando for competir, saberá por quem torcer 😉. Evite nomes grandes também. O script `ocma` irá considerá apenas os 10 primeiros caracteres. Assim, `aaaaaaaaaa` e `aaaaaaaaaab`, para efeito de identificação, são iguais.

Considere que a competição pode ser feita com qualquer número de bots. Assim, não se restrinja a apenas 2 barcos no mar, como nos exemplos deste documento. A competição pode ser feita por grupos (por exemplo, de 4 em 4) ou com todos da turma, e mesmo com alunos de outras turmas.

O tamanho da área de pesca é aleatório, pois o tamanho pode influenciar consideravelmente na estratégia utilizada. Porém, suas dimensões (altura e largura) irão sempre variar entre 10 e 20.

O tempo para terminar o jogo (e os barcos retornarem aos portos) também é aleatório, mas gira em torno do dobro da área de pesca (2 * altura * largura).

## Rodadas do jogo

No início de cada turno, o script `ocma` irá informar a todos os bots quem está "na vez". Ele enviará a string `BOT` seguida de outra string contendo o identificador do bot que irá executar uma ação. Por exemplo: `BOT b1`. Nesse caso, o bot da vez (`b1`) deve enviar para a saída padrão uma ação a ser realizada no jogo. As ações foram organizadas nas seguintes categorias:

1. Deslocamento
2. Pesca
3. Compra e venda
4. Solicitação de informação

Como o bot pode enviar qualquer dado para a saída padrão, se este não for reconhecido como uma das ações acima, ele será desconsiderado e o bot perde a oportunidade de executar algo no seu turno. Nesse caso, o script `ocma` envia como resultado da ação a string `INVALID`, indicando que foi uma ação inválida.

**Obs**: Todo comando de ação deve ser concluído com um salto de linha (`\n`) para que o término do comando seja reconhecido.

### Ações de deslocamento

Para o barco do bot se mover na área de pesca, ele deve realizar uma das seguintes ações de deslocamento (enviar para a saída padrão):

* `LEFT`: o bot informa que quer se deslocar para esquerda.
* `RIGHT`: o bot informa que quer se deslocar para direita.
* `UP`: o bot informa que quer se deslocar para cima.
* `DOWN`: o bot informa que quer se deslocar para baixo.
* `WAIT`: o bot informa que não fará nada. Essa ação é útil principalmente quando o barco encontra-se no porto aguardando o término do jogo. 

O resultado da solicitação de deslocamento é recebido logo em seguida (deve ser lido da entrada padrão). Com exceção da ação `WAIT`, que tem como resultado a string `NONE`, as demais ações podem ter um dos seguintes resultados:

* `PORT`: indica que o barco se deslocou e atracou no porto (sua nova posição se encontra sobre um porto).
* `SEA`: indica que o barco se deslocou e sua nova posição não se encontra em nenhum ponto de interesse. Está no mar.
* `SEABASS` (Robalo) ou `SNAPPER` (Cioba) ou `MULLET` (Tainha), seguido de um inteiro entre 0 e 9: indica que o barco se deslocou e sua nova posição é um ponto de pesca. Ele informa o tipo de peixe do ponto de pesca e a quantidade (em kg) que há nele.
* `BUSY`: indica que o deslocamento não foi realizado devido à célula para a qual o bot quer se delocar já estar ocupada por outro bot. O único local onde pode haver vários barcos concomitantemente são os portos. Nos demais, apenas um barco pode ocupar o lugar.
* `OUT`: indica que o deslocamento não foi realizado devido à célula para a qual o bot quer se delocar se encontrar fora da área de pesca (limites da matriz). Nesse caso, além de não ter a ação realizada, o bot paga uma multa de R$ 500. Esse valor é automaticamente deduzido do seu saldo.
* `TUGBOAT`, seguida de dois valores inteiros: indica que o deslocamento não foi realizado devido ao barco ter ultrapassado o limite de deslocamentos do barco (autonomia). Um serviço de reboque é contratado no valor de R$ 2.000 (debitado de seu saldo) e o barco irá para um porto. Os dois valores inteiros indicam a nova posição do barco, linha e coluna respectivamente.

### Ação de pesca

Há apenas uma ação de pesca:
* `FISh`: pesca 1kg de peixe que se encontra sob o barco do bot. Lembre-se que o ponto de pesca não pode ficar sem peixe, sob pena de receber uma multa (além de ser eliminado do jogo!).

O resultado da ação pode ser:
* O nome do peixe pescado, `SEABASS` (Robalo) ou `SNAPPER` (Cioba) ou `MULLET` (Tainha): caso a pesca tenha ocorrido. O barco transportará o peixe mesmo que ultrapasse a carga máxima do barco. A multa, neste caso, será calculada apenas quando o bot for vender o peixe.
* `NONE`: caso a ação de pesca tenha sido solicitada em uma posição que não é um ponto de pesca.
* `IMPACT`: indica que houve um impacto ambiental devido ao bot ter "zerado" um ponto de pesca. Uma multa de R$ 50.000 será aplicada e o jogo termina para o bot.

### Ações de compra e venda

As ações de compra e venda só são possíveis se o barco do bot se encontrar atracado no porto.

* `UPGRADE`: compra uma lancha. Isso significa que a capacidade de transporte e a de deslocamento aumentam, mas que R$ 10.000 será debitado do saldo do bot. Esta ação só pode ser executada se o bot tiver pelo menos R$ 10.000 de saldo.
* `SELL`: vende todos os peixes que transporta.

O resultado dessas ações será um inteiro representando o novo saldo do bot. Por exemplo, se o bot tinha R$ 20.000 e comprou uma lancha (`UPGRADE`), o resultado será `10000`. Se o bot tinha apenas R$ 5.000 no saldo e tentar comprar uma lancha, o resultado será `5000`, indicando que não houve a compra.

Se o bot vender seus peixes (`SELL`), o resultado também será o seu saldo adicionado à soma dos valores dos peixes que transporta. Porém, caso haja mais peixe que a capacidade máxima do barco, do novo saldo será subtraído o valor da multa por kg excedente (de R$ 500).

Se o bot não tiver nenhum peixe para vender ou se ele não se encontrar no porto, o valor de retorno será o mesmo do seu saldo atual.

Obs: Caso o bot tente comprar uma lancha (`UPGRADE`) já tendo comprado uma antes, o valor será debitado de qualquer forma, mas não haverá incremento algum nas capacidades já presentes.

### Ação de solicitação de informação

* `RADAR`: requer o serviço de radar para informar a situação dos peixes nos pontos de pesca. É importante usar esse serviço de tempo em tempo porque a quantidade de peixes pode aumentar (reprodução). O serviço de radar custa R$ 200 e pode ser solicitado a qualquer momento do jogo.

O resultado da ação é uma matriz de inteiros, a mesma apresentada na [Área de pesca](), mas com as quantidades de peixes atualizadas.

## Término do jogo

O jogo terminará se:
* O número rodadas informado no início do jogo (`TIME`) chegar ao fim;
* Todos os barcos estiverem em algum porto e realizarem a ação `WAIT` na mesma rodada, ou;
* Não houver mais bot ativo.

Há alguns casos em que o bot é considerado inativo e é eliminado do jogo. São eles:
* O programa do bot para de executar por alguma razão, seja por causa de um bug, erro de execução ou simplesmente terminou o que estava programado.
* O programa não responde por mais de 3 segundos. Isso pode ocorrer devido a um loop (infinito talvez?!) ou a um [deadlock](https://pt.wikipedia.org/wiki/Deadlock). O deadlock pode ocorrer se o bot não seguir a sequência esperada de entrada e saída. Por exemplo, o script `ocma` está esperando uma ação do bot e o bot esperando uma informação do script. Passados 3 segundos sem resposta, o script encerra o processo do bot e o elimina do jogo.

Com o jogo terminado, será apresentado a lista dos bots e seus saldos na ordem de colocação, do maior saldo para o menor. O vencedor é quem tiver o maior saldo.

Obs: É possível que haja saldo negativos.

## Debugar

Como o programa de seu bot será lançando por outro programa (`ocma`), você não vai ter acesso direto a algumas ferramentas de debugagem presentes nas IDEs. Caso você queira/precise encontrar um erro no seu bot ou entender o que está acontecendo, algumas possibilidades foram adicionadas ao jogo.

