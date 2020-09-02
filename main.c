#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define DIM 7
#define DIm 3

void inicio() //Tela inicial.
{
    printf("\n\n\n ========================================================================\n");
    printf("                            ***************\n");
    printf("                            JOGO DA MEMÓRIA\n");
    printf("                            ***************\n");
    printf("                      Seja bem vindo ao nosso jogo.\n");
    printf(" ========================================================================\n");
    printf("                         Jogo desenvolvido por:\n");
    printf("\n                          Mariana de Luca Reis\n");
    printf("                                   &\n");
    printf("                         Tiago Carnevalli Elias\n");
    printf(" ========================================================================\n");
    printf("\n                   Precione Enter para começar...");
    fflush(stdin);
    getchar();
    system("cls");
}

void dimensao(int *dL, int *dC) //Dimensões do tabuleiro.
{
    do
    {
        printf("\n Informe o número de linhas do seu tabueleiro (De %i até %i): ",DIm,DIM);
        scanf("%d",dL);
        fflush(stdin);
        system("cls");
        if(*dL<DIm || *dL>DIM)
        {
            printf("\n Quantidade de linhas inválida! Informe outra...");
            fflush(stdin);
            getchar();
            system("cls");
        }
    }
    while(*dL<DIm || *dL>DIM);
    do
    {
        printf("\n Informe o número de colunas do seu tabueleiro (De %i até %i): ",DIm,DIM);
        scanf("%d",dC);
        fflush(stdin);
        system("cls");
        if(*dC<DIm || *dC>DIM)
        {
            printf("\n Quantidade de colunas inválida! Informe outra...");
            fflush(stdin);
            getchar();
            system("cls");
        }
    }
    while(*dC<DIm || *dC>DIM);

    printf("\n Seu tablueiro terá %i linhas e %i colunas.\n",*dL,*dC);
    printf(" Boa escolha!\n");
}

void tabuleiro(char tab[DIM][DIM],int dL, int dC) //Tabuleiro montado.
{
    int l,c;
    printf("\n    ");
    for (c=1; c<=dC; c++)
    {
        printf("%2i ",c);
    }
    printf("\n");
    for (l=0; l<dL; l++)
    {
        printf(" ");
        printf("%2i ",l+1);
        for (c=0; c<dC; c++)
        {
            printf("[%c]",tab[l][c]);
        }
        printf("\n");
    }
}

void mostrarTab(char tab[DIM][DIM],int dL,int dC) //Mostra o tabueleiro por alguns segundos para memorizar as posições.
{
    int i,t;
    t=((dL*dC)*0.3);
    Sleep(3000);
    system("cls");
    printf("\n Você tem %i segundos para memorizar.\n Preparado?",t);
    fflush(stdin);
    getchar();
    system("cls");
    for(i=t; i>=0; i--)
    {
        printf("\n Restam %i segundos.\n",i);
        tabuleiro(tab,dL,dC);
        Sleep(1000); //"S" maiúsculo por ser uma função do SO. 1000 é uma variável de tempo.//
        system("cls");
    }
}

void layout(char tab[DIM][DIM],int dL, int dC) //Limpa o tabuleiro.
{
    int l,c;
    for (l=0; l<dL; l++)
    {
        for (c=0; c<dC; c++)
        {
            tab[l][c]=' ';
        }
    }
}

void letras(char tab[DIM][DIM],int dL, int dC) //Posiciona as letras aleatoriamente.
{
    srand(time(NULL));
    int l,c,i,s;
    for(s=65; s<((dL*dC)/2)+65; s++)
    {
        for(i=0; i<=1; i++)
        {
            l=rand()%dL;
            c=rand()%dC;
            if(tab[l][c]==32)
            {
                tab[l][c]=s;
            }
            else
            {
                i--;
            }
            //printf(" %i - %i / l-%i c-%i\n", i, s, l, c);
            //printf(" %i e %c\n",tab[l][c],tab[l][c]);
        }
    }
    for(l=0; l<dL; l++)
    {
        for(c=0; c<dC; c++)
        {
            if(tab[l][c]==32)
            {
                tab[l][c]=63;
            }
        }
    }
}

int jogar(char jogo[DIM][DIM], char tab[DIM][DIM], int dL, int dC) //Recebe as jogadas do usuário.
{
    int p1,p2,p3,p4,j,c=0,l,o,a,v;
    for(j=(dL*dC)/2; j>0; j--)
    {
        do
        {
            printf("\n Jogada de número %i.\n",c+1);
            tabuleiro(jogo,dL,dC);
            printf("\n Selecione a posição que deseja jogar");
            printf("\n Linha: ");
            scanf("%i",&p1);
            printf(" Coluna: ");
            scanf("%i",&p2);
            fflush(stdin);
            system("cls");
            if(p1<=0||p1>dL||p2<=0||p2>dC)
            {
                printf("\n Posição inválida. Tente novamente...");
            }
        }
        while(p1<=0||p1>dL||p2<=0||p2>dC);
        p1--;
        p2--;
        if(jogo[p1][p2]==32)
        {
            jogo[p1][p2]=tab[p1][p2];
            printf("\n Jogada de número %i.\n",c+1);
            tabuleiro(jogo,dL,dC);
            Sleep(500);
            fflush(stdin);
            system("cls");
        }
        else
        {
            printf("\n Esta posição já foi marcada. Tente novamente...");
            j++;
            continue;
        }
        do
        {
            printf("\n Jogada de número %i.\n",c+1);
            tabuleiro(jogo,dL,dC);
            printf("\n Selecione a posição que deseja jogar");
            printf("\n Linha: ");
            scanf("%i",&p3);
            printf(" Coluna: ");
            scanf("%i",&p4);
            fflush(stdin);
            system("cls");
            if(p3<=0||p3>dL||p4<=0||p4>dC)
            {
                printf("\n Posição inválida. Tente novamente...");
            }
        }
        while(p3<=0||p3>dL||p4<=0||p4>dC);
        p3--;
        p4--;
        if(jogo[p3][p4]==32)
        {
            jogo[p3][p4]=tab[p3][p4];
            printf("\n Jogada de número %i.\n",c+1);
            tabuleiro(jogo,dL,dC);
            Sleep(500);
            fflush(stdin);
            system("cls");
        }
        else
        {
            printf("\n Esta posição já foi marcada. Tente novamente...");
            jogo[p1][p2]=32;
            j++;
            continue;
        }
        if(jogo[p1][p2]!=jogo[p3][p4] && jogo[p1][p2]!=63 && jogo[p3][p4]!=63)
        {
            printf("\n Jogada de número %i.\n",c+1);
            tabuleiro(jogo,dL,dC);
            Sleep(4000);
            jogo[p1][p2]=32;
            jogo[p3][p4]=32;
            fflush(stdin);
            system("cls");
            j++;
        }
        if(jogo[p1][p2]==63)
        {
            for(l=0; l<dL; l++)
            {
                for(o=0; o<dC; o++)
                {
                    if(tab[l][o]==jogo[p3][p4]&&(l!=p3||o!=p4))
                    {
                        jogo[l][o]=tab[l][o];
                        printf("\n Jogada de número %i.\n",c+1);
                        tabuleiro(jogo,dL,dC);
                        Sleep(2000);
                        fflush(stdin);
                        system("cls");
                        jogo[l][o]=32;
                        jogo[p3][p4]=32;
                        j++;
                    }
                }
            }
        }
        if(jogo[p3][p4]==63)
        {
            for(l=0; l<dL; l++)
            {
                for(o=0; o<dC; o++)
                {
                    if(tab[l][o]==jogo[p1][p2]&&(l!=p1||o!=p2))
                    {
                        jogo[l][o]=tab[l][o];
                        printf("\n Jogada de número %i.\n",c+1);
                        tabuleiro(jogo,dL,dC);
                        Sleep(2000);
                        fflush(stdin);
                        system("cls");
                        jogo[l][o]=32;
                        jogo[p1][p2]=32;
                        j++;
                    }
                }
            }
        }
        //printf("J = %i",j);
        c++;
    }
    printf("\n Parabéns! Você achou todas as posições corretas.\n");
    tabuleiro(jogo,dL,dC);
    printf("\n Você fez %i jogadas.",c);
    a=((100*((dL*dC)/2))/c);
    printf("\n Sua taxa de acerto foi de %i %%.\n\n",a);
    v=(dL*dC)+((dL*dC)*0.2);
    if(c*2>v)
    {
        printf("\n Treine mais sua memória.\n");
    }
    else
    {
        printf("\n Você tem uma boa memória.\n");
    }
//   Espaço, na tabela ASCII, é 32.
//Símbolo ?, na tabela ASCII, é 63.
//  Letra A ,na tabela ASCII, é 65.
}

int main()
{
    setlocale(LC_CTYPE,"Portuguese");
    char tab[DIM][DIM],jogo[DIM][DIM];
    int dL,dC;
    inicio();
    dimensao(&dL,&dC);
    layout(tab,dL,dC);
    //tabuleiro(tab,dL,dC);
    letras(tab,dL,dC);
    mostrarTab(tab,dL,dC);
    //tabuleiro(tab,dL,dC);
    layout(jogo,dL,dC);
    jogar(jogo,tab,dL,dC);
    return 0;
}
