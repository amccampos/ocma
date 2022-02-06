/********************************************************************
  Bot-exemplo
  
  Bot_A: anda pra esquerda
  
  Após receber as informações iniciais do jogo, a cada rodada esse
  bot irá se movimentar para esquerda.
  Cabe a você agora aprimorar sua estratégia!!!
 ********************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_LINE 50

/* ADAPTAR EM FUNÇÃO DE COMO OS DADOS SERÃO ARMAZENADOS NO SEU BOT */
void readData(int h, int w) {
  char id[MAX_LINE];
  int v, n, x, y;

  for (int i = 0; i < h; i++) {   
    for (int j = 0; j < w; j++) {
      scanf("%i", &v);
    }
  }
  scanf(" BOTS %i", &n);           // lê a quantidade de bots
  for (int i = 0; i < n; i++) {
    scanf("%s %i %i", id, &x, &y); // lê o id dos bots e suas posições
  }
}

int main() {
  char line[MAX_LINE];   // dados temporários
  char myId[MAX_LINE];   // identificador do bot em questão

  setbuf(stdin, NULL);   // stdin, stdout e stderr não terão buffers
  setbuf(stdout, NULL);  // assim, nada é "guardado temporariamente"
  setbuf(stderr, NULL);

  // === INÍCIO DA PARTIDA ===
  int h, w;
  scanf("AREA %i %i", &h, &w);  // dimensão da área de pesca: altura (h) x largura (w)
  // readData(h, w);               // lê os dados do jogo
  scanf(" ID %s", myId);     // por fim, sabe qual seu próprio id
  fprintf(stderr, "%s\n", myId);

  // === PARTIDA === 
  // fica num laço infinito, pois quem vai terminar seu programa é o SIMULADOR.
  while (1) {
    // LÊ OS DADOS DO JOGO E ATUALIZA OS DADOS DO BOT
    readData(h, w);

    // INSERIR UMA LÓGICA PARA ESCOLHER UMA AÇÃO A SER EXECUTADA

    // envia a ação escolhida (nesse exemplo, ir para esquerda)
    printf("RIGHT\n");

    // lê qual foi o resultado da ação (e eventualmente atualiza os dados do bot).
    scanf("%s", line);
    // fgets(line, MAX_LINE, stdin);
  }

  return 0;
}