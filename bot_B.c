/********************************************************************
  Bot-exemplo
  
  Bot_B: anda pra cima
  
  Após receber as informações iniciais do jogo, a cada rodada esse
  bot irá se movimentar para cima.
  Cabe a você agora aprimorar sua estratégia!!!
 ********************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_LINE 50

int main() {
  char line[MAX_LINE];   // dados temporários
  char myId[MAX_LINE];   // identificador do bot em questão

  setbuf(stdin, NULL);   // stdin, stdout e stderr não terão buffers
  setbuf(stdout, NULL);  // assim, nada é "guardado temporariamente"
  setbuf(stderr, NULL);

  // DADOS DO INÍCIO DA PARTIDA
  int h, w, v, t, n, x, y;
  scanf("AREA %i %i", &h, &w);       // dimensão da área de pesca: altura (h) x largura (w)
  for (int i = 0; i < h; i++) {   
    for (int j = 0; j < w; j++) {
      scanf("%i", &v);               // lê os valores de cada posição da área
    }
  }
  scanf(" TIME %i", &t);             // número de rodadas
  scanf(" BOTS %i", &n);             // quantidade de bots
  for (int i = 0; i < n; i++) {      // para cada bot
    scanf("%s %i %i", line, &x, &y); // lê seu id e sua posição
  }
  scanf(" YOU %s\n", myId);          // por fim, sabe qual seu próprio id

  // DADOS DURANTE A PARTIDA
  char id[MAX_LINE];
  char item[MAX_LINE];
  
  // fica num laço infinito, pois quem vai terminar seu programa é o jogo.
  while (1) {
    // antes de enviar algum comando, deve esperar "sua vez"
    // entra, então, num laço esperando chegar a mensagem "BOT <seu_id>"
    do {
      fgets(line, MAX_LINE, stdin);
      sscanf(line, " %s %s", item, id);
    } while (strcmp(item, "BOT") || strcmp(id, myId));

    // como saiu do laço anterior, é "sua vez"
    printf("UP\n"); // envia uma das ações possíveis (nesse caso, ir para cima)
    fgets(line, MAX_LINE, stdin);   // vê qual foi o resultado da ação.
  }

  return 0;
}