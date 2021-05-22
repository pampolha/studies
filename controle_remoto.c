#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Ao usar o format %c (char) e dar um número inteiro ao valor a ser formatado, o valor printado vai ser 
resgatado da tabela ASCII.

35 = #
48 = 0
49 = 1
88 = X

*/
int main(int argc, char const *argv[])
{
    novo: //placa de direcao para "goto" caso o usuario decida gerar um novo mapa
    srand(time(0));

    int mapa[10][20];//essa matriz será o mapa original, contendo as informacoes, agindo como "back-end"

    static int loop = 1;//variavel estatica(permanece com o primeiro valor atribuido) para loops de while

    int l = 0;
    int c = 0;
    //variaveis de contagem para uso em loops

    int obstaculo_linha;
    int obstaculo_coluna;
    //essas variaveis irao armazenar posicoes aleatorias para os obstaculos no mapa

    while (loop == 1) //construindo o mapa
    {
        obstaculo_linha = rand()%9;
        obstaculo_coluna = rand()%19;

        mapa[l][c] = 48;

        if (l == obstaculo_linha || c == obstaculo_coluna)
        {
            mapa[l][c] = 35;
        }
        
        if (c < 19)
        {
            c++;
        }
        else if (l >= 10)
        {
            break;
        }
        else 
        {
            c = 0;
            l++;
        }
    }

    int linha;        
    linha = rand()%9;    
    int coluna;          
    coluna = rand()%19; 
    //declaração e randomização das variáveis que vão armazenar as coordenadas iniciais da sonda.

    mapa[linha][coluna] = 88; //"colocando" a sonda espacial no mapa (X)

    inicio://placa de direcao para "goto" depois que a sonda tentar se movimentar

    l = 0;
    c = 0;
    //reset de valores pra efeito do loop seguinte

    system("cls"); //limpando o terminal pra nao ter que ficar rolando pra baixo

    printf("\t\t\t\t\t"); //centralizando a primeira linha do mapa

    while (loop == 1) //printando o mapa
    {
        if (mapa[l][c] == 35)
        {
            printf("%c", 48); //printando um 0 pois se o valor for 35 significa que e um obstaculo ainda nao descoberto
        }
        else if (mapa[l][c] == 1) //'1' foi um numero qualquer que eu escolhi pra definir o obstaculo que ja foi descoberto
        {
            printf("%c", 35);
        }
        else
        {
            printf("%c",mapa[l][c]);
        }

        if (c < 19)
        {
            c++;
        }
        else 
        {
            c = 0;
            l++;
            printf("\n\t\t\t\t\t");//centralizando o resto do mapa no terminal
        }

        if (l >= 10)
        {
            break;
        }
    }

    printf("\nInstrucoes:");
    printf("\nA sonda e representada com um X no mapa, terreno desconhecido com 0, terreno plano com 1 e obstaculos com #.");
    printf("\nInserir S, N, L ou O para direcionar o movimento da sonda (de acordo com os pontos cardinais).");
    printf("\nE entao o numero de casas a se mover, representado por um numero inteiro de 1 a 9.");
    printf("\nApos isso o usuario deve pressionar a tecla ENTER para confirmar o comando.");
    printf("\nCaso nao queira confirmar o comando, pressione qualquer outra tecla");
    printf("\nCaso a sonda nao consiga realizar o comando instruido, uma mensagem de FRACASSO sera printada.");
    printf("\nCaso o usuario deseje gerar um novo mapa para ser explorado, insira um comando de direcao 0 e movimento 0.");
    printf("\n\nInsira o comando de movimento: ");

    char direcao;    
    int movimento;
    //declaracao das variaveis indicando os controles da sonda 

    int movimentoI[1];//essa string serve so para o usuario inserir um comando, depois ela vai ser convertida em inteiro

    direcao = getch();
    printf("[%c",direcao);
    movimentoI[0] = getch();
    printf(" %c]",movimentoI[0]);
    //captando e formatando o comando da sonda

    char enter = getch(); //a variavel enter so vai servir pra detectar se o usuario pressionou a tecla enter ou nao

    if (enter != 13) // "13" e o valor ASCII para a tecla enter, esse if checa se o usuario nao pressionou enter
    {
        goto inicio;
    }
    
    movimento = atoi(movimentoI); //essa funcao "atoi" converte strings em inteiros, no caso ela vai converter a string "movimentoI" e inserir o valor convertido em "movimento"

    int orientacao; //essa variavel serve pra definir a orientacao vertical(0) ou horizontal(1) do movimento da sonda
    int sub_orientacao; //essa variavel representa o movimento para cima(0), baixo(1), direita(0) ou esquerda(1)
    
    if (direcao == 48 && movimento == 0)
    {
        goto novo;
    }
    // esse if serve pra redirecionar o programa para antes da geracao do mapa, a fim de gerar um novo mapa para o usuario

    if(direcao == 'n' || direcao == 'N')
    {
        orientacao = 0;
        sub_orientacao = 0;
    }
    else if (direcao == 's' || direcao == 'S')
    {
        orientacao = 0;
        sub_orientacao = 1;
    }
    else if (direcao == 'l' || direcao == 'L')
    {
        orientacao = 1;
        sub_orientacao = 0;
    }
    else if (direcao == 'o' || direcao == 'O')
    {
        orientacao = 1;
        sub_orientacao = 1;
    }
    else
    {
        printf("\nFRACASSO-Direcao nao reconhecida. Pressione qualquer tecla pra continuar...\n");
        getch();
        goto inicio;
    }
    //usei "if" porque switch nao permite operadores logicos
    
    if (orientacao == 0)
    {
        if (sub_orientacao == 0)
        {
            if (movimento > linha) 
            {
                printf("\nFRACASSO-Sonda tentou ir para fora do mapa. Pressione qualquer tecla pra continuar...\n");
                getch();
                goto inicio;
            }
        }
        else
        {
            if (movimento > 9-linha)
            {
                printf("\nFRACASSO-Sonda tentou ir para fora do mapa. Pressione qualquer tecla pra continuar...\n");
                getch();
                goto inicio;
            }
        } 
    }
    else
    {
        if (sub_orientacao == 0)
        {
            if (movimento > 19-coluna)
            {
                printf("\nFRACASSO-Sonda tentou ir para fora do mapa. Pressione qualquer tecla pra continuar...\n");
                getch();
                goto inicio;
            }
        }
        else
        {
            if (movimento > coluna)
            {
                printf("\nFRACASSO-Sonda tentou ir para fora do mapa. Pressione qualquer tecla pra continuar...\n");
                getch();
                goto inicio;
            }
        } 
    }
    // os condicionais acima servem para corrigir o usuario caso ele insira um comando que iria botar a sonda pra fora do mapa
    
    if (orientacao == 0)
    {
        if (sub_orientacao == 0)
        {
            for (int i = 0; i < movimento; i++)
            {
                if (mapa[linha-1][coluna] == 35 || mapa[linha-1][coluna] == 1)
                {
                    mapa[linha-1][coluna] = 1;
                    printf("\nFRACASSO-Obstaculo encontrado. Pressione qualquer tecla pra continuar...\n");
                    getch();
                    break;
                }
                
                linha = linha-1;

                mapa[linha][coluna] = 88;

                mapa[linha+1][coluna] = 49;
            }
        }
        else
        {
            for (int i = 0; i < movimento; i++)
            {
                if (mapa[linha+1][coluna] == 35 || mapa[linha+1][coluna] == 1)
                {
                    mapa[linha+1][coluna] = 1;
                    printf("\nFRACASSO-Obstaculo encontrado. Pressione qualquer tecla pra continuar...\n");
                    getch();
                    break;
                }

                linha = linha+1;

                mapa[linha][coluna] = 88;

                mapa[linha-1][coluna] = 49;
            }
        }
    }
    else
    {
        if (sub_orientacao == 0)
        {
            for (int i = 0; i < movimento; i++)
            {
                if (mapa[linha][coluna+1] == 35 || mapa[linha][coluna+1] == 1)
                {
                    mapa[linha][coluna+1] = 1;
                    printf("\nFRACASSO-Obstaculo encontrado. Pressione qualquer tecla pra continuar...\n");
                    getch();
                    break;
                }

                coluna = coluna+1;

                mapa[linha][coluna] = 88;

                mapa[linha][coluna-1] = 49;
            }
        }
        else
        {
            for (int i = 0; i < movimento; i++)
            {
                if (mapa[linha][coluna-1] == 35 || mapa[linha][coluna-1] == 1)
                {
                    mapa[linha][coluna-1] = 1;
                    printf("\nFRACASSO-Obstaculo encontrado. Pressione qualquer tecla pra continuar...\n");
                    getch();
                    break;
                }

                coluna = coluna-1;

                mapa[linha][coluna] = 88;

                mapa[linha][coluna+1] = 49;
            }
        }
    }          
    //essa sequencia de "if" serve pra detectar a direcao da sonda (com orientacao e sub_orientacao), evitar colisoes com obstaculos (com os if's mais interiores), preencher o caminho com '1's (com a ultima associacao dos loops), atualizar a posicao da sonda no mapa(com as duas associacoes abaixo dos if's) e associar um valor especifico (1) para obstaculos encontrados, para que permanecam no mapa 

    goto inicio; //esse goto tem a mesma funcao que um loop, quando o programa chega aqui significa que todas as acoes foram resolvidas e entao o fluxo e retornado ao ponto inicial

    return 0;
}

