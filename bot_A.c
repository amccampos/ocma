/********************************************************************
  Bot-exemplo
  
  Após receber as informações iniciais do jogo, a cada rodada esse
  bot irá se movimentar para esquerda.
  Cabe a você agora aprimorar sua estratégia!!!
 ********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 50

typedef struct POSICAO{
  int x, y;
} Posicao;

// Estrutura dos bots
typedef struct Player {
  char id[MAX_STR];
  Posicao posicao;
} Bot;

/* ADAPTAR EM FUNÇÃO DE COMO OS DADOS SERÃO ARMAZENADOS NO SEU BOT */
Bot * readData(int h, int w, int areaDePesca[h][w], int *nBots) {
  char id[MAX_STR];
  int n;

  // lê os dados da área de pesca
  for (int i = 0; i < h; i++) {   
    for (int j = 0; j < w; j++) {
      scanf("%i", &areaDePesca[i][j]);
    }
  }
  // lê os dados dos bots
  scanf(" BOTS %i", &n);
  *nBots = n;
  // o " " antes de BOTS é necessário para ler o '\n' da linha anterior
  Bot *bots = malloc(n * sizeof(Bot));
  for (int i = 0; i < n; i++) {
    scanf("%s %i %i", bots[i].id, &bots[i].posicao.x, &bots[i].posicao.y); // lê o id dos bots e suas posições
  }
  return bots;
}

int main() {
  char line[MAX_STR];   // dados temporários
  char myId[MAX_STR];   // identificador do bot em questão
  int nBots;            // quantidade de bots
  Bot *bots;            // vetor de bots
  Bot myBot;            // bot em questão
  Posicao posicaoPassada; // posição anterior do bot

  setbuf(stdin, NULL);   // stdin, stdout e stderr não terão buffers
  setbuf(stdout, NULL);  // assim, nada é "guardado temporariamente"
  setbuf(stderr, NULL);

  // === INÍCIO DA PARTIDA ===
  int h, w;
  scanf("AREA %i %i", &h, &w);  // lê a dimensão da área de pesca: altura (h) x largura (w)
  int areaDePesca[h][w];
  scanf(" ID %s", myBot.id);        // ...e o id do bot
  // obs: o " " antes de ID é necessário para ler o '\n' da linha anterior

  // Para "debugar", é possível enviar dados para a saída de erro padrão (stderr).
  // Esse dado não será enviado para o simulador, apenas para o terminal.
  // A linha seguinte é um exemplo. Pode removê-la se desejar.
  //fprintf(stderr, "Meu id = %s\n", myId);

  // === PARTIDA === 
  // O bot entra num laço infinito, mas não se preocupe porque o simulador irá matar
  // o processo quando o jogo terminar.
  while (1) {
    memset(areaDePesca, 0, sizeof(areaDePesca)); // zera a área de pesca

    // LÊ OS DADOS DO JOGO E ATUALIZA OS DADOS DO BOT
    bots = readData(h, w, areaDePesca, &nBots);

    // guarda a posição anterior do bot
    posicaoPassada = myBot.posicao;
    //fprintf(stderr, "Posição anterior: %i %i\n", posicaoPassada.x, posicaoPassada.y);
    // procura meu bot na lista de bots
    for (int i = 0; i < nBots; i++) {
      if (strcmp(bots[i].id, myBot.id) == 0) {
        strcpy(myBot.id, bots[i].id);
        myBot.posicao = bots[i].posicao;
        break;
      }
    }
    //fprintf(stderr, "My bot: %s %i %i\n", myBot.id, myBot.posicao.x, myBot.posicao.y);
    /*
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        fprintf(stderr, "%i ", areaDePesca[i][j]);
      }
      fprintf(stderr, "\n");
    }
    */
    /*
    fprintf(stderr, "Tem %i bots, sao: ", nBots);
    for (int i = 0; i < nBots; i++) {
      fprintf(stderr, "%s %d %d, ", bots[i].id, bots[i].posicao.x, bots[i].posicao.y);
    }
    fprintf(stderr, "\n");
    */
    // INSIRA UMA LÓGICA PARA ESCOLHER UMA AÇÃO A SER EXECUTADA

    // envia a ação escolhida (nesse exemplo, ir para esquerda)
    printf("RIGHT\n");

    // lê qual foi o resultado da ação (e eventualmente atualiza os dados do bot).
    scanf("%s", line);
  }

  return 0;
}