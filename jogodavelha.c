#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char tab[3][3], jogador1[100], jogador2[100], nome_arq[104];;
FILE *bin;
int dificuldade=0, num_partida=1, contajog=0;
typedef struct velha
{
  int partida;
  char jogVelha[3][3];
  char resultado;
}partida;

void clrscr() //LIMPA A TELA
{
  printf("\33[H\33[2J");
}

void exibe_c()
{
  printf("\t1 | 2 | 3\n\t4 | 5 | 6\n\t7 | 8 | 9\n"); //EXIBE TABULEIRO COM AS POSICOES
  printf("\n\n");
}

void exibe_t() //EXIBE TABULEIRO ATUAL
{
  printf("\t%c | %c | %c\n", tab[0][0], tab[0][1], tab[0][2]);
  printf("\t%c | %c | %c\n", tab[1][0], tab[1][1], tab[1][2]);
  printf("\t%c | %c | %c\n", tab[2][0], tab[2][1], tab[2][2]);
}

int verpos(int posicao, char jog) //VERIFICA SE A POSICAO ESTA PREENCHIDA(1 PARA JOG, 2 PARA NAO JOG E 0 PARA VAZIO)
{
  switch(posicao)
  {
    case 1:
      if(tab[0][0]==' ')
        return 0;
      else if(tab[0][0]==jog)
        return 1;
      else
        return 2;

    case 2:
      if(tab[0][1]==' ')
        return 0;
      else if(tab[0][1]==jog)
        return 1;
      else
        return 2;

    case 3:
      if(tab[0][2]==' ')
        return 0;
      else if(tab[0][2]==jog)
        return 1;
      else
        return 2;

    case 4:
      if(tab[1][0]==' ')
        return 0;
      else if(tab[1][0]==jog)
        return 1;
      else
        return 2;

    case 5:
      if(tab[1][1]==' ')
        return 0;
      else if(tab[1][1]==jog)
        return 1;
      else
        return 2;

    case 6:
      if(tab[1][2]==' ')
        return 0;
      else if(tab[1][2]==jog)
        return 1;
      else
        return 2;

    case 7:
      if(tab[2][0]==' ')
        return 0;
      else if(tab[2][0]==jog)
        return 1;
      else
        return 2;

    case 8:
      if(tab[2][1]==' ')
        return 0;
      else if(tab[2][1]==jog)
        return 1;
      else
        return 2;

    case 9:
      if(tab[2][2]==' ')
        return 0;
      else if(tab[2][2]==jog)
        return 1;
      else
        return 2;
  }
}

int jogada_usuario(int lin, int col, char jog) //FAZ A JOGADA DO USUARIO
{
  if(tab[lin][col]=='O' || tab[lin][col]=='X') //RETORNA DOIS E A POSICAO JA ESTIVER PREENCHIDA
  {
    return 2;
  }
  else if(lin < 0 || lin > 3 || col > 3 || col < 0) //RETORNA UM SE A POSICAO INFORMADA NAO EXISTIR
  {
    return 1;
  }
  else //RETORNA ZERO SE A JOGADA FOR REALIZADA
  {
    tab[lin][col]=jog;
    return 0;
  }
}

int ataca(char jog) //VERIFICA POSSIBILIDADE DE VITORIA PARA O SIMBOLO INFORMADO(JOG)
{
  if(verpos(1, jog)==1 && verpos(2, jog)==1 && verpos(3, jog)==0)
  {
    if(!jogada_usuario(0, 2, jog))
      return 1;
  }
  else if(verpos(1, jog)==1 && verpos(2, jog)==0 && verpos(3, jog)==1)
  {
    if(!jogada_usuario(0, 1, jog))
      return 1;
  }
  else if(verpos(1, jog)==0 && verpos(2, jog)==1 && verpos(3, jog)==1)
  {
    if(!jogada_usuario(0, 0, jog))
      return 1;
  }
  else if(verpos(4, jog)==1 && verpos(5, jog)==1 && verpos(6, jog)==0)
  {
    if(!jogada_usuario(1, 2, jog))
      return 1;
  }
  else if(verpos(4, jog)==1 && verpos(5, jog)==0 && verpos(6, jog)==1)
  {
    if(!jogada_usuario(1, 1, jog))
      return 1;
  }
  else if(verpos(4, jog)==0 && verpos(5, jog)==1 && verpos(6, jog)==1)
  {
    if(!jogada_usuario(1, 0, jog))
      return 1;
  }
  else if(verpos(7, jog)==1 && verpos(8, jog)==1 && verpos(9, jog)==0)
  {
    if(!jogada_usuario(2, 2, jog))
      return 1;
  }
  else if(verpos(7, jog)==1 && verpos(8, jog)==0 && verpos(9, jog)==1)
  {
    if(!jogada_usuario(2, 1, jog))
      return 1;
  }
  else if(verpos(7, jog)==0 && verpos(8, jog)==1 && verpos(9, jog)==1)
  {
    if(!jogada_usuario(2, 0, jog))
      return 1;
  }
  else if(verpos(1, jog)==1 && verpos(4, jog)==1 && verpos(7, jog)==0)
  {
    if(!jogada_usuario(2, 0, jog))
      return 1;
  }
  else if(verpos(1, jog)==1 && verpos(4, jog)==0 && verpos(7, jog)==1)
  {
    if(!jogada_usuario(1, 0, jog))
      return 1;
  }
  else if(verpos(1, jog)==0 && verpos(4, jog)==1 && verpos(7, jog)==1)
  {
    if(!jogada_usuario(0, 0, jog))
      return 1;
  }
  else if(verpos(2, jog)==1 && verpos(5, jog)==1 && verpos(8, jog)==0)
  {
    if(!jogada_usuario(2, 1, jog))
      return 1;
  }
  else if(verpos(2, jog)==1 && verpos(5, jog)==0 && verpos(8, jog)==1)
  {
    if(!jogada_usuario(1, 1, jog))
      return 1;
  }
  else if(verpos(2, jog)==0 && verpos(5, jog)==1 && verpos(8, jog)==1)
  {
    if(!jogada_usuario(0, 1, jog))
      return 1;
  }
  else if(verpos(3, jog)==1 && verpos(6, jog)==1 && verpos(9, jog)==0)
  {
    if(!jogada_usuario(2, 2, jog))
      return 1;
  }
  else if(verpos(3, jog)==1 && verpos(6, jog)==0 && verpos(9, jog)==1)
  {
    if(!jogada_usuario(1, 2, jog))
      return 1;
  }
  else if(verpos(3, jog)==0 && verpos(6, jog)==1 && verpos(9, jog)==1)
  {
    if(!jogada_usuario(0, 2, jog))
      return 1;
  }
  else if(verpos(1, jog)==1 && verpos(5, jog)==1 && verpos(9, jog)==0)
  {
    if(!jogada_usuario(2, 2, jog))
      return 1;
  }
  else if(verpos(1, jog)==1 && verpos(5, jog)==0 && verpos(9, jog)==1)
  {
    if(!jogada_usuario(1, 1, jog))
      return 1;
  }
  else if(verpos(1, jog)==0 && verpos(5, jog)==1 && verpos(9, jog)==1)
  {
    if(!jogada_usuario(0, 0, jog))
      return 1;
  }
  else if(verpos(7, jog)==1 && verpos(5, jog)==1 && verpos(3, jog)==0)
  {
    if(!jogada_usuario(0, 2, jog))
      return 1;
  }
  else if(verpos(7, jog)==1 && verpos(5, jog)==0 && verpos(3, jog)==1)
  {
    if(!jogada_usuario(1, 1, jog))
      return 1;
  }
  else if(verpos(7, jog)==0 && verpos(5, jog)==1 && verpos(3, jog)==1)
  {
    if(!jogada_usuario(2, 0, jog))
      return 1;
  }
  else  return 0;
}

int defende(char jog) //VERIFICA NECESSIDADE DE DEFESA
{
  if(verpos(1, jog)==2 && verpos(2, jog)==2 && verpos(3, jog)==0)
  {
    if(!jogada_usuario(0, 2, jog))
      return 1;
  }
  else if(verpos(1, jog)==2 && verpos(2, jog)==0 && verpos(3, jog)==2)
  {
    if(!jogada_usuario(0, 1, jog))
      return 1;
  }
  else if(verpos(1, jog)==0 && verpos(2, jog)==2 && verpos(3, jog)==2)
  {
    if(!jogada_usuario(0, 0, jog))
      return 1;
  }
  else if(verpos(4, jog)==2 && verpos(5, jog)==2 && verpos(6, jog)==0)
  {
    if(!jogada_usuario(1, 2, jog))
      return 1;
  }
  else if(verpos(4, jog)==2 && verpos(5, jog)==0 && verpos(6, jog)==2)
  {
    if(!jogada_usuario(1, 1, jog))
      return 1;
  }
  else if(verpos(4, jog)==0 && verpos(5, jog)==2 && verpos(6, jog)==2)
  {
    if(!jogada_usuario(1, 0, jog))
      return 1;
  }
  else if(verpos(7, jog)==2 && verpos(8, jog)==2 && verpos(9, jog)==0)
  {
    if(!jogada_usuario(2, 2, jog))
      return 1;
  }
  else if(verpos(7, jog)==2 && verpos(8, jog)==0 && verpos(9, jog)==2)
  {
    if(!jogada_usuario(2, 1, jog))
      return 1;
  }
  else if(verpos(7, jog)==0 && verpos(8, jog)==2 && verpos(9, jog)==2)
  {
    if(!jogada_usuario(2, 0, jog))
      return 1;
  }
  else if(verpos(1, jog)==2 && verpos(4, jog)==2 && verpos(7, jog)==0)
  {
    if(!jogada_usuario(2, 0, jog))
      return 1;
  }
  else if(verpos(1, jog)==2 && verpos(4, jog)==0 && verpos(7, jog)==2)
  {
    if(!jogada_usuario(1, 0, jog))
      return 1;
  }
  else if(verpos(1, jog)==0 && verpos(4, jog)==2 && verpos(7, jog)==2)
  {
    if(!jogada_usuario(0, 0, jog))
      return 1;
  }
  else if(verpos(2, jog)==2 && verpos(5, jog)==2 && verpos(8, jog)==0)
  {
    if(!jogada_usuario(2, 1, jog))
      return 1;
  }
  else if(verpos(2, jog)==2 && verpos(5, jog)==0 && verpos(8, jog)==2)
  {
    if(!jogada_usuario(1, 1, jog))
      return 1;
  }
  else if(verpos(2, jog)==0 && verpos(5, jog)==2 && verpos(8, jog)==2)
  {
    if(!jogada_usuario(0, 1, jog))
      return 1;
  }
  else if(verpos(3, jog)==2 && verpos(6, jog)==2 && verpos(9, jog)==0)
  {
    if(!jogada_usuario(2, 2, jog))
      return 1;
  }
  else if(verpos(3, jog)==2 && verpos(6, jog)==0 && verpos(9, jog)==2)
  {
    if(!jogada_usuario(1, 2, jog))
      return 1;
  }
  else if(verpos(3, jog)==0 && verpos(6, jog)==2 && verpos(9, jog)==2)
  {
    if(!jogada_usuario(0, 2, jog))
      return 1;
  }
  else if(verpos(1, jog)==2 && verpos(5, jog)==2 && verpos(9, jog)==0)
  {
    if(!jogada_usuario(2, 2, jog))
      return 1;
  }
  else if(verpos(1, jog)==1 && verpos(5, jog)==0 && verpos(9, jog)==1)
  {
    if(!jogada_usuario(1, 1, jog))
      return 1;
  }
  else if(verpos(1, jog)==0 && verpos(5, jog)==2 && verpos(9, jog)==2)
  {
    if(!jogada_usuario(0, 0, jog))
      return 1;
  }
  else if(verpos(7, jog)==2 && verpos(5, jog)==2 && verpos(3, jog)==0)
  {
    if(!jogada_usuario(0, 2, jog))
      return 1;
  }
  else if(verpos(7, jog)==2 && verpos(5, jog)==0 && verpos(3, jog)==2)
  {
    if(!jogada_usuario(1, 1, jog))
      return 1;
  }
  else if(verpos(7, jog)==0 && verpos(5, jog)==2 && verpos(3, jog)==2)
  {
    if(!jogada_usuario(2, 0, jog))
      return 1;
  }
  else
    return 0;
}

void alt(char jog) //LISTA DE PRIORIDADES PARA JOGADAS(CENTRO, CANTO, BORDA)
{
  if(verpos(5, jog)==0)
  {
    if(!jogada_usuario(1, 1, jog))
      exit;
  }
  else if(verpos(1, jog)==0)
  {
    if(!jogada_usuario(0, 0, jog))
      exit;
  }
  else if(verpos(3, jog)==0)
  {
    if(!jogada_usuario(0, 2, jog))
      exit;
  }
  else if(verpos(7, jog)==0)
  {
    if(!jogada_usuario(2, 0, jog))
      exit;
  }
  else if(verpos(9, jog)==0)
  {
    if(!jogada_usuario(2, 2, jog))
      exit;
  }
  else if(verpos(2, jog)==0)
  {
    if(!jogada_usuario(0, 1, jog))
      exit;
  }
  else if(verpos(4, jog)==0)
  {
    if(!jogada_usuario(1, 0, jog))
      exit;
  }
  else if(verpos(6, jog)==0)
  {
    if(!jogada_usuario(1, 2, jog))
      exit;
  }
  else if(verpos(8, jog)==0)
  {
    if(!jogada_usuario(2, 1, jog))
      exit;
  }
}

void jogada_facil(char jog) //JOGADA DEFINIDA ALEATORIAMENTE
{
  srand(time(NULL));
  int lin, col, res;
  while(1)
  {
    lin = rand() % 3;
    col = rand() % 3;
    if(!jogada_usuario(lin, col, jog))
      break;
  }
  exit;
}

void jogada_medio(char jog) //SE CONSEGUIR GANHAR, SE PRECISAR DEFENDE, CASO CONTRARIO JOGADA FACIL(ALEATORIA)
{
  if(ataca(jog))
    exit;
  else if(defende(jog))
    exit;
  else
  {
    jogada_facil(jog);
  }
}

void jogada_dificil(char jog) //PREVE AS 4 PRIMEIRA RODADAS, DEPOIS JOGA PELA LISTA DE PRIORIDADES(ATACAR, DEFENDER, ALT(CENTRO, CANTO, BORDA))
{
  if(contajog==0)//PRIMEIRA RODADA(SEMPRE NO CANTO)
  {
    if(!jogada_usuario(0, 0, jog))
      exit;
  }
  else if(contajog==1)//SEGUNDA RODADA(TENTA JOGAR NO CENTRO, CASO NAO CONSIGA, JOGA NO CANTO)
  {
    if(verpos(5, jog)==0)
    {
      if(!jogada_usuario(1, 1, jog))
        exit;
    }
    else
    {
      if(!jogada_usuario(0, 0, jog))
        exit;
    }
  }
  else if(contajog==2)//TERCEIRA RODADA
  {

    if(verpos(5, jog)==2 || verpos(3, jog)==2)//SE A POSICAO 5 OU 3 ESTIVER PREENCHIDA JOGA NA POSICAO 9
    {
      if(!jogada_usuario(2, 2, jog))
        exit;
    }
    else if(verpos(2, jog)==2 || verpos(6, jog)==2 || verpos(8, 2)==2)//SE A POSICAO 2, 6, OU 8 ESTIVER PREENCHIDASJOGA NA POSICAO 7
    {
      if(!jogada_usuario(2, 0, jog))
        exit;
    }
    else if(verpos(4, jog)==2 || verpos(7, jog)==2)//SE A POSICAO 4 OU 7 ESTIVER PREENCHIDA JOGA NA POSICAO 3
    {
      if(!jogada_usuario(0, 2, jog))
        exit;
    }
  }
  else if(contajog==3)//QUARTA RODADA
  {
    if((verpos(1, jog)==2 &&  && verpos(9, jog)==2) || (verpos(7, jog)==2 && verpos(5, jog)==1 && verpos(3, jog)==2))//NAO POSSIBILITA O ADVERSARIO FORMA UM GARFO
    {
      if(!jogada_usuario(0, 1, jog))
        exit;
    }
    else if(ataca(jog)) //TENTA GANHAR
      exit;
    else if(defende(jog)) //TENTA DEFENDER
      exit;
    else
    {
      alt(jog); //ENTRA NA LISTA DE PRIORIDADES
      exit;
    }
  }
  else if(contajog>3)//DEMAIS JOGADAS
  {
    if(ataca(jog)) //TENTA GANHAR
      exit;
    else if(defende(jog)) //TENTA DEFENDER
      exit;
    else
    {
      alt(jog); //ENTRA NA LISTA DE PRIORIDADES
      exit;
    }
  }
}

void jogada_computador(char jog, int nivel) //REALIZA A JOGADA DO COMPUTADOR DE ACORDO COM A DIFICULDADE RECEBIDA
{
  if(nivel == 1) //DIFICULDADE 1(ALEATORIA)
  {
    jogada_facil(jog);
    exit;
  }
  else if(nivel == 2) //DIFICULDADE 2
  {
    jogada_medio(jog);
    exit;
  }
  else if(nivel == 3) //DIFICULDADE 3
  {
    jogada_dificil(jog);
  }
}

void inicializa_velha() //INICIALIZA A VELHA COM VAZIO(' ')
{
  int a, b;

  for(a=0;a<3;a++)
  {
    for(b=0;b<3;b++)
    {
      tab[a][b]=' ';
    }
  }
}

int verifica_ganhador(char jog) //VERIFICA SE O SIMBOLO INFORMADO GANHOU
{
  int a;

  if(tab[0][0]==tab[1][1] && tab[1][1]==tab[2][2] && tab[0][0]==jog)
  return 1;
  else if(tab[2][0]==tab[1][1] && tab[1][1]==tab[0][2] && tab[2][0]==jog)
  return 1;
  else
  {
    for(a=0;a<3;a++)
    {
      if(tab[a][0]==tab[a][1] && tab[a][1]==tab[a][2] && tab[a][0]==jog)
      return 1;
      else if(tab[0][a]==tab[1][a] && tab[1][a]==tab[2][a] && tab[0][a]==jog)
      return 1;
    }
  }
  return 0;
}

int menu() //RETORNA 1 PARA JOGAR CONTRA COMPUTADOR, 2 PARA JOGAR CONTRA USUARIO
{
  int op;
  dificuldade=0;
  printf("1 - Jogar contra o computador\n2 - Jogar contra outro usuario\nEscolha seu oponente: ");
  scanf("%d", &op);
  while(op < 1 || op > 2)
  {
    printf("Opcao inexistente, digite novamente: ");
    scanf("%d", &op);
  }
  if(op == 1)
  {
    printf("Escolha o nivel do computador:\n1 - Facil\n2 - Medio\n3 - Dificil\n");
    while(dificuldade < 1 || dificuldade > 3)
    {
      scanf("%d", &dificuldade);
      if(dificuldade >=1 && dificuldade <=3)
      {
        break;
      }
      printf("Dificuldade: %d", dificuldade);
      printf("Dificuldade inexistente, digite novamente: ");
    }
    return 1;
  }
  else
  {
    return 2;
  }
}

void escolha_simb(char *jog1, char *jog2) //FUNCAO PARA DEFINICAO DOS SIMBOLOS DOS JOGADORES
{
  char s1=0, s2=0;

  if(dificuldade!=0)//SE A DIFICULDADE NAO FOR ZERO, A PARTIDA SERA CONTRA O COMPTUTADOR
  {
    printf("Informe o simbolo do computador: ");
  }
  else
  {
    printf("Informe o simbolo de %s: ", jogador1);
  }
  while(s1!='X' && s1!='O')
  {
    scanf("%c", &s1); //ENQUANTO SIMBOLO NAO FOR IGUAL A X OU O REALIZA A LEITURA
    getchar();
    s1 = toupper(s1);
    if(s1 == 'X' || s1 == 'O')
    {
      *jog1 = s1;
      break;
    }
    printf("Simbolo invalido digite novamente: ");
  }
  printf("Informe o simbolo de %s: ", jogador2);
  while((s2!='X' && s2!='O') && s2!=s1) //ENQUANTO SIMBOLO NAO FOR IGUAL A X OU O E DIFERENTE DE S1 REALIZA A LEITURA
  {
    scanf("%c", &s2);
    getchar();
    s2 = toupper(s2);
    if((s2 == 'X' || s2 == 'O') && s2!=s1)
    {
      *jog2 = s2;
      break;
    }
    s2=0;
    printf("Simbolo invalido, digite novamente: ");
  }
}

void coordenada(int *lin, int *col) //ESCOLHA DO USUARIO(JOGADA), TRANFORMA A POSICAO INFORMADA PELO USUARIO EM COORDENADAS(LIN, COL)
{
  int pos;

  printf("Digite a posicao desejada: ");
  while(1)
  {
    scanf("%d", &pos);
    if(pos>0 && pos<10)
    {
      break;
    }
    printf("Posicao invalida, digite novamente: ");
  }
  switch (pos)
  {
    case 1:
      *lin = 0;
      *col = 0;
    break;
    case 2:
      *lin = 0;
      *col = 1;
    break;
    case 3:
      *lin = 0;
      *col = 2;
    break;
    case 4:
      *lin = 1;
      *col = 0;
    break;
    case 5:
      *lin = 1;
      *col = 1;
    break;
    case 6:
      *lin = 1;
      *col = 2;
    break;
    case 7:
      *lin = 2;
      *col = 0;
    break;
    case 8:
      *lin = 2;
      *col = 1;
    break;
    case 9:
      *lin = 2;
      *col = 2;
    break;
  }
}

void grava_txt(char sim1, char sim2) //GRAVA O ARQUIVO TXT COM O NOME E O SIMBOLO DOS DOIS JOGADORES
{
  FILE *txt;
  if((txt = fopen("jogadores.txt", "w+"))==NULL)
  {
    printf("Nao foi possivel abrir o arquivo txt\n");
    exit;
  }
  fprintf(txt, "%s; %c; %s; %c.\n", jogador1, sim1, jogador2, sim2);
  fclose(txt);
}

int grava_bin(char nome[104], partida jogo) //GRAVA O ARQUIVO BINARIO COM O NUMERO DA PARTIDA, O TABULEIRO E O RESULTADO
{
  FILE *bin;
  int a, b;
  if((bin = fopen(nome, "ab"))==NULL)
  {
    printf("Nao foi possivel abrir o arquivo binario\n");
    return 0;
  }

  jogo.partida = num_partida;
  for(a=0;a<3;a++)
  {
    for(b=0;b<3;b++)
    {
      jogo.jogVelha[a][b] = tab[a][b];
    }
  }
  if(verifica_ganhador('X'))
  {
    jogo.resultado='X';
  }
  else if(verifica_ganhador('O'))
  {
    jogo.resultado='O';
  }
  else
  {
    jogo.resultado='V';
  }
  fwrite(&jogo, sizeof(partida), 1, bin);
  fclose(bin);
}

partida le_bin(char nome[104], int num) //MOSTRAR RESULTADO DA PARTIDA DESEJADA
{
  FILE *bin;
  partida ret, nulo;
  int a, b;
  nulo.partida=9999; //VARIAVEL PARA RETORNO CASO A PARTIDA NAO SEJA ENCONTRADA
  for(a=0;a<3;a++)
  {
    for(b=0;b<3;b++)
    {
      nulo.jogVelha[a][b]=' ';
    }
  }
  nulo.resultado=' ';
  if((bin = fopen(nome, "rb"))==NULL) //ABRE O ARQUIVO PARA LEITURA
  {
    printf("Nao foi possivel abrir o arquivo binario para leitura\n");
    exit;
  }

  while(!feof(bin)) //ENQUANTO NAO TERMINAR O ARQUIVO
  {
    fread(&ret, sizeof(partida), 1, bin); //LE INFORMACOES DO TAMANHO DO TIPO PARTIDA
    if(ret.partida == num) //SE ACHAR O NUMERO RETORNO A VARIAVEL QUE CONTEM AS INFORMACOES DA PARTIDAS
    {
      return ret;
    }
  }
  return nulo; //SE NAO ACHAR RETORNO A VARIAVEL NULO
}

void impr() //IMPRIME  TODAS AS PARTIDAS
{
  FILE *bin, *txt;
  char jogador1[100], jogador2[100], simbolo1, simbolo2, string[300];
  partida jogo;
  int a, b=0, vit1=0, vit2=0, cont;

  for(a=0;a<100;a++) //INICIALIZA A VARIAVEL DOS NOMES(JOGADOR1 E JOGADOR2)
  {
    jogador1[a]=0;
    jogador2[a]=0;
  }
  if((txt = fopen("jogadores.txt", "r"))==NULL) //ABRE ARQUIVO TXT, COM NOME E SIMBOLO DOS JOGADORES
  {
    printf("Nao foi possivel abrir o arquivo texto para impressao\n");
    exit;
  } //LE SIMBOLO DO COMPUTADOR
  if((bin = fopen(nome_arq, "rb"))==NULL) //ABRE ARQUIVO BINARIO, COM O RESULTADO DAS PARTIDAS
  {
    printf("Nao foi possivel abrir o arquivo binario para impressao\n");
    exit;
  }
  fgets(string, 300, txt); //PEGA UMA LINHA(TODO O ARQUIVO) DO ARQUIVO TXT(NOMES E SIMBOLOS)
  a=0;
  while(string[a] != ';') //NOME DO JOGADOR1 ATE ENCONTRAR ';'
  {
    jogador1[a] = string[a];
    a++;
  }
  jogador1[a]='\0';
  a+=2; //PULA DUAS "CASAS"
  simbolo1 = string[a]; //SIMBOLO DO JOGADOR1
  a+=3; //PULA 3 "CASAS"
  while(string[a] != ';') //NOME DO JOGADOR1 ATE ENCONTRAR ';'
  {
    jogador2[b] = string[a];
    b++;
    a++;
  }
  jogador2[b]='\0';
  a+=2; //PULA DUAS "CASAS"
  simbolo2 = string[a]; //SIMBOLO DO JOGADOR2

  clrscr(); //LIMPA A TELA

  for(cont=0;cont<num_partida-1;cont++) //LE E IMPRIME TODAS AS PARTIDAS
  {
    fread(&jogo, sizeof(jogo), 1, bin);
    printf("Partida: %d\n", jogo.partida);
    for(a=0;a<3;a++)
    {
      printf("\t%c | %c | %c\n", jogo.jogVelha[a][0], jogo.jogVelha[a][1], jogo.jogVelha[a][2]);
    }
    if(jogo.resultado==simbolo1) //SE SIMBOLO1 GANHOU AUMENTA UMA VITORIA PARA JOGADOR1
    {
      printf("%s ganhou!\n", jogador1);
      vit1++;
    }
    else if(jogo.resultado==simbolo2) //SE SIMBOLO2 GANHOU AUMENTA UMA VITORIA PARA JOGADOR2
    {
      printf("%s ganhou!\n", jogador2);
      vit2++;
    }
    else //VELHA
      printf("Deu velha!\n");
  }
  printf("%s %d X %s %d\n", jogador1, vit1, jogador2, vit2); //MOSTRA NOMES DOS JOGADORES E VITORIAS
  if(vit1>vit2) //SE JOGADOR1 GANHOU MAIS QUE JOGADOR2
    printf("%s ganhou!", jogador1);
  else if(vit2>vit1) //SE JOGADOR2 GANHOU MAIS QUE JOGADOR1
    printf("%s ganhou!", jogador2);
  else //SE FOREM IGUAIS
    printf("Empate!");

}

void jogar()
{
  char sim1, sim2, continuar='S';
  int a, lin, col, c, d, jogada, conta, contb;
  partida jogo;
  for(a=0;a<100;a++)
  {
    jogador1[a]=' ';
    jogador2[a]=' ';
  }
  clrscr();
  a = menu();
  clrscr();
  if(a==2) //CONTRA USUARIO
  {
    setbuf(stdin, NULL); //DEFINIR NOMES E SIMBOLOS
    printf("Digite o nome do jogador 1: ");
    fgets(jogador1, 100, stdin);
    jogador1[strcspn(jogador1, "\n")] = '\0';
    clrscr();
    setbuf(stdin, NULL);
    printf("Digite o nome do jogador 2: ");
    fgets(jogador2, 100, stdin);
    jogador2[strcspn(jogador2, "\n")] = '\0';
    setbuf(stdin, NULL);
    clrscr();
    escolha_simb(&sim1, &sim2);
    grava_txt(sim1, sim2); //GRAVA ARQUIVO TXT
    clrscr();
    while(continuar == 'S' || continuar == 's') //CONTINUAR JOGANDO
    {
      inicializa_velha(); //RESETA TABULEIRO
      contajog=0; //REINICIA CONTADOR DE JOGADAS
      if(num_partida % 2 != 0) //PARTIDAS IMPARES(JOGADOR1 COMECA)
      {
        while(1)
        {
          clrscr();
          exibe_c();
          exibe_t();
          while(1)
          {
            printf("Vez de %s\n", jogador1);
            coordenada(&lin, &col); //LE POSICAO DESEJADA
            jogada = jogada_usuario(lin, col, sim1); //REALIZA JOGADA
            if(jogada == 1)
            {
              printf("Posicao invalida\n");
            }
            else if(jogada == 2)
            {
              printf("Posicao ja preenchida\n");
            }
            else if(jogada == 0)
            {
              contajog++;
              break;
            }
          }
          if(verifica_ganhador(sim1)) //VERIFICA SE JOGADOR1 GANHOU
          {
            clrscr();
            exibe_t();
            printf("%s ganhou!\n", jogador1);
            grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
            num_partida++; //NUMERO DA PARTIDA + 1

            printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUER CONTINUAR JOGANDO
            continuar='o';
            while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
            {
              scanf("%c", &continuar);
              if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
                break;
            }
            break;
          }
          if(contajog==9) //PARA NOVE JOGADAS E NENHUM VENCEDOR(VELHA)
          {
            clrscr();
            exibe_t();
            printf("\tVelha!\n");
            grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
            num_partida++;
            printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUE CONTINUAR JOGANDO
            continuar='o';
            while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
            {
              scanf("%c", &continuar);
              if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
                break;
            }
            break;
          }
          clrscr();
          exibe_c();
          exibe_t();
          while(1)
          {
            printf("Vez de %s\n", jogador2);
            coordenada(&lin, &col); //LE POSICAO DESEJADA
            jogada = jogada_usuario(lin, col, sim2); //TENTA REALIZAR A JOGADA
            if(jogada == 1)
            {
              printf("Posicao invalida\n");
            }
            else if(jogada == 2)
            {
              printf("Posicao ja preenchida\n");
            }
            else if(jogada == 0)
            {
              contajog++;
              break;
            }
          }
          exibe_t();
          if(verifica_ganhador(sim2)) //VERIFICA SE JOGADOR2 GANHOU
          {
            clrscr();
            exibe_t();
            printf("%s ganhou!\n", jogador2);
            grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
            num_partida++;
            printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUER CONTINUAR JOGANDO
            continuar='o';
            while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
            {
              scanf("%c", &continuar);
              if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
                break;
            }
            break;
          }
        }
      }
      else if(num_partida % 2 == 0) //PARTIDAS PARES(JOGADOR2 COMECA)
      {
        while(1)
        {
          clrscr();
          exibe_c();
          exibe_t();
          while(1)
          {
            printf("Vez de %s\n", jogador2);
            coordenada(&lin, &col); //POSICAO DESEJADA
            jogada = jogada_usuario(lin, col, sim2); //TENTA REALIZAR JOGADA
            if(jogada == 1)
            {
              printf("Posicao invalida\n");
            }
            else if(jogada == 2)
            {
              printf("Posicao ja preenchida\n");
            }
            else if(jogada == 0)
            {
              contajog++;
              break;
            }
          }
          if(verifica_ganhador(sim2)) //VERIFICA SE JOGADOR2 GANHOU
          {
            clrscr();
            exibe_t();
            printf("%s ganhou!\n", jogador2);
            grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
            num_partida++;
            printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUER CONTINUAR JOGANDO
            continuar='o';
            while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
            {
              scanf("%c", &continuar);
              if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
                break;
            }
            break;
          }
          if(contajog==9) //PARA 9 RODADAS E NENHUM VENCEDOR(VELHA)
          {
            clrscr();
            exibe_t();
            printf("\tVelha!\n");
            grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
            num_partida++;
            printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUER CONTINUAR JOGANDO
            continuar='o';
            while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
            {
              scanf("%c", &continuar);
              if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
                break;
            }
            break;
          }
          clrscr();
          exibe_c();
          exibe_t();
          while(1)
          {
            printf("Vez de %s\n", jogador1);
            coordenada(&lin, &col); //LE POSICAO DESEJADA
            jogada = jogada_usuario(lin, col, sim1); //TENTA REALIZAR A JOGADA
            if(jogada == 1)
            {
              printf("Posicao invalida\n");
            }
            else if(jogada == 2)
            {
              printf("Posicao ja preenchida\n");
            }
            else if(jogada == 0)
            {
              contajog++;
              break;
            }
          }
          exibe_t();
          if(verifica_ganhador(sim1)) //VERIFICA SE JOGADOR1 GANHOU
          {
            clrscr();
            exibe_t();
            printf("%s ganhou!\n", jogador1);
            grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
            num_partida++;
            printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUR CONTINUAR JOGANDO
            continuar='o';
            while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
            {
              scanf("%c", &continuar);
              if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
                break;
            }
            break;
          }
        }
      }
    }
  }
  else if(a == 1) //CONTRA O COMPUTADOR
  {
    strcpy(jogador1, "Computador"); //DEFINE JOGADOR1 COMO "COMPUTADOR"
    setbuf(stdin, NULL);
    printf("Digite o nome do jogador: "); //NOME DO JOGADOR
    fgets(jogador2, 100, stdin);
    jogador2[strcspn(jogador2, "\n")] = '\0';
    setbuf(stdin, NULL);
    escolha_simb(&sim1, &sim2); //ESCOLHE SIMBOLOS
    grava_txt(sim1, sim2); //GRAVA ARQUIVO TXT(NOMES E SIMBOLOS)
    clrscr();

    //JOGAR
    clrscr();
    while(continuar == 'S' || continuar == 's') //VERIFICA SE USUARIO QUER CONTINUAR JOGANDO
    {
      inicializa_velha(); //INICIALIZA TABULEIRO COM ' '
      contajog=0; //REINICIA CONTADOR DE JOGADAS
      while(1){
      if(num_partida % 2 != 0) //PARTIDAS IMPARES(COMPUTADOR COMECA)
      {
        exibe_c();
        exibe_t();
        printf("Vez de %s", jogador1);
        jogada_computador(sim1, dificuldade); //REALIZA JOGADA DO COMPUTADOR(COM DIFICULDADE PASSADA)
        if(verifica_ganhador(sim1)) //VERIFCA SE COMPUTADOR GANHOU
        {
          clrscr();
          exibe_t();
          printf("%s ganhou!\n", jogador1);
          grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
          num_partida++;
          printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUE CONTINUAR JOGANDO
          continuar='o';
          while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
          {
            scanf("%c", &continuar);
            if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
              break;
          }
          break;
        }
        else
          contajog++;
        if(contajog==9) //PARA 9 RODADAS E NENHUM GANHADOR(VELHA)
        {
          clrscr();
          exibe_t();
          printf("\tVelha!\n");
          grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
          num_partida++;
          printf("Continuar jogando? (S/N)\n"); //VERIFICA SE O USUARIO QUER CONTINUAR JOGANDO
          continuar='o';
          while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
          {
            scanf("%c", &continuar);
            if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
              break;
          }
          break;
        }
        clrscr();
        exibe_c();
        exibe_t();
        while(1)
        {
          printf("Vez de %s\n", jogador2);
          coordenada(&lin, &col); //LE JOGADA DESEJADA
          jogada = jogada_usuario(lin, col, sim2); //TENTA REALIZAR JOGADA
          if(jogada == 1)
          {
            printf("Posicao invalida\n");
          }
          else if(jogada == 2)
          {
            printf("Posicao ja preenchida\n");
          }
          else if(jogada == 0)
          {
            contajog++;
            break;
          }
        }
        if(verifica_ganhador(sim2)) //VERIFICA SE O JOGADOR2 GANHOU
        {
          clrscr();
          exibe_t();
          printf("%s ganhou!\n", jogador2);
          grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
          num_partida++;
          printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUE CONTINUAR JOGANDO
          continuar='o';
          while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
          {
            scanf("%c", &continuar);
            if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
              break;
          }
          break;
        }
      }
      else if(num_partida % 2 == 0) //PARTIDAS PARES(JOGADOR COMECA)
      {
        clrscr();
        exibe_c();
        exibe_t();
        while(1)
        {
          printf("Vez de %s\n", jogador2);
          coordenada(&lin, &col); //LE POSICAO DESEJADA
          jogada = jogada_usuario(lin, col, sim2); //TENTA REALIZAR JOGADA
          if(jogada == 1)
          {
            printf("Posicao invalida\n");
          }
          else if(jogada == 2)
          {
            printf("Posicao ja preenchida\n");
          }
          else if(jogada == 0)
          {
            contajog++;
            break;
          }
        }
        if(verifica_ganhador(sim2)) //VERIFICA SE JOGADOR GANHOU
        {
          clrscr();
          exibe_t();
          printf("%s ganhou!\n", jogador2);
          grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
          num_partida++;
          printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUER CONTINUAR JOGANDO
          continuar='o';
          while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
          {
            scanf("%c", &continuar);
            if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
              break;
          }
          break;
        }
        if(contajog==9) //PARA 9 RODADAS E NENHUM VENCEDOR(VELHA)
        {
          clrscr();
          exibe_t();
          printf("\tVelha!\n");
          grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
          num_partida++;
          printf("Continuar jogando? (S/N)\n"); //VERIFICA SE JOGADOR QUER CONTINUAR JOGANDO
          continuar='o';
          while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
          {
            scanf("%c", &continuar);
            if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
              break;
          }
          break;
        }
        exibe_c();
        exibe_t();
        printf("Vez de %s", jogador1);
        jogada_computador(sim1, dificuldade); //REALIZA JOGADA DO COMPUTADOR(COM DIFICULDADE PASSADA)
        if(verifica_ganhador(sim1)) //VERIFICA SE COMPUTADOR GANHOU
        {
          clrscr();
          exibe_t();
          printf("%s ganhou!\n", jogador1);
          grava_bin(nome_arq, jogo); //GRAVA ARQUIVO BINARIO
          num_partida++;
          printf("Continuar jogando? (S/N)\n"); //VERIFICA SE USUARIO QUE CONTINUAR JOGANDO
          continuar='o';
          while(continuar!='N' || continuar!='n' || continuar!='S' || continuar!='s')
          {
            scanf("%c", &continuar);
            if(continuar=='N' || continuar=='n' || continuar=='S' || continuar=='s')
              break;
          }
          break;
        }
        else
          contajog++;
      }
    }
    }
  }
}

void main()
{
  partida saida;
  char *retorno;
  int x, opcao, partida;

  clrscr();
  printf("Digite o nome do arquivo que guardara o resultado das partidas: "); //LE NOME DO ARQUIVO BINARIO
  setbuf(stdin, NULL);
  fgets(nome_arq, 100, stdin);
  nome_arq[strcspn(nome_arq, "\n")] = '\0';
  retorno = strstr(nome_arq, ".bin"); //VERIFICA SE O NOME INFORMADO CONTEM ".BIN"
  if(retorno == NULL)
    strcat(nome_arq, ".bin"); //SE NAO TIVER, ADICIONA ".BIN"

  clrscr();
  jogar(); //REALIZA JOGO
  while(1)
  {
    opcao=-1;
    clrscr();
    printf("MENU\n");
    printf("1 - Resultado de partida\n2 - Resultado geral\n0 - Sair\n"); //VERIFICA SE JOGADOR QUER VER O RESULTADO DE UMA PARTIDA ESPECIFICA OU VER O RESULTADO GERAL
    while(opcao<0 || opcao>2)
    {
      scanf("%d", &opcao);
      if(opcao>=0 && opcao<=2)
        break;
      printf("Opcao invalida, por favor digite novamente: ");
    }
    if(opcao==0) //PARA 0, SAI DO PROGRAMA
      break;
    else if(opcao==1)
    {
      clrscr();
      printf("Digite o numero da partida desejada: ");
      scanf("%d", &partida); //LE PARTIDA DESEJADA
      saida = le_bin(nome_arq, partida);
      if(saida.partida==9999) //PARA PARTIDA NAO EXISTENTE
      {
        printf("Partida nao encontrada!\n");
        printf("\n\n");
        system("read -p \"Pressione enter para continuar\" saindo"); //IGUAL SYSTEM("PAUSE")
      }
      else
      {
        printf("Partida: %d\n", saida.partida); //IMPRIME NUMERO DA PARTIDA
        for(x=0;x<3;x++) //IMPRIME TABULEIRO DA PARTIDA DESEJADA
        {
          printf("\t%c | %c | %c\n", saida.jogVelha[x][0], saida.jogVelha[x][1], saida.jogVelha[x][2]);
        }
        printf("Resultado: %c", saida.resultado); //IMPRIME RESULTADO
        printf("\n\n");
        system("read -p \"Pressione enter para continuar\" saindo"); //IGUAL SYSTEM("PAUSE")
      }
    }
    else if(opcao==2)
    {
      impr(); //IMPRIME TODAS AS PARTIDAS E O RESULTADO FINAL
      printf("\n\n");
      system("read -p \"Pressione enter para continuar\" saindo"); //IGUAL SYSTEM("PAUSE")
    }
  }
}
