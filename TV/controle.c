#include <stdio.h>
#include <windows.h> // vou precisar dessa lib pros comandos "system"

#define DESLIGADA 0
#define LIGADA 1
// criando atalhos pra nomear o estado do aparelho

struct Aparelho
{
    int Estado;
    int Canal;
    int Volume;
    int Cor;
};
typedef struct Aparelho Aparelho;
Aparelho TV;
// declarando a structure aparelho, criando um atalho pra inicializar ela e declarando um Aparelho global de nome TV

void ligar_desligar();
void mudar_volume();
void mudar_canal();
void mudar_cor(); 
//declaracao das funcoes que eu vou usar 

// Atributos de cor são especificados por DOIS dígitos hexadecimais. O primeiro
// corresponde à cor de tela de fundo; o segundo à cor do texto. Cada
// dígito pode ter apenas um dos seguintes valores:
// 0 = Preto        8 = Cinza
// 1 = Azul         9 = Azul claro
// 2 = Verde        A = Verde claro
// 3 = Verde-água   B = Verde-água claro
// 4 = Vermelho     C = Vermelho claro
// 5 = Roxo         D = Lilás
// 6 = Amarelo      E = Amarelo claro
// 7 = Branco       F = Branco brilhante
     
int main(int argc, char const *argv[])
{
    TV.Estado = DESLIGADA;
    TV.Canal = 10;
    TV.Volume = 10;
    // inicializando valores do aparelho global TV pra nao causar erros de memoria no programa

    int escolha; // variavel para usar no switch de input do controle
    inicio: // placa de direcao de "goto" para retornar o usuario ao menu, usado com fim de looping
    system("cls");

    if (TV.Estado == DESLIGADA)
    {
        printf(
        ".===============.\n"
        "| .-----------. |\n"
        "| | / / / / / | |\n"
        "| |/ / / / / /| |\n"
        "| | / / / / / | |   __\n"
        "| '-----------'o|  |o.|\n"
        "|===============|  |::|\n"
        "|###############|  |::|\n"
        "'==============='  '--'\n");
        // representa uma tv desligada
    }
    else
    {
        printf(
        ".===============.\n"
        "| .-----------. |\n"
        "| |  PampoTV  | |\n"
        "| | Volume: %d| |\n"
        "| | Canal: %d | |   __\n"
        "| '-----------'o|  |o.|\n"
        "|===============|  |::|\n"
        "|###############|  |::|\n"
        "'==============='  '--'\n"
        , TV.Volume, TV.Canal);
    }
    
    printf("\nCONTROLE:\n");
    printf("\n-----------------------------------");
    printf("\n(0) Ligar/Desligar a TV");
    printf("\n(1) Aumentar/Diminuir o volume");
    printf("\n(2) Mudar o canal");
    printf("\n(3) Mudar a cor da TV");
    printf("\n-----------------------------------");
    printf("\n\nInsira o numero da sua escolha: ");
    scanf("%d",&escolha);

    switch (escolha)
    {
    case 0: //estado
        if (TV.Estado == DESLIGADA)
        {
            ligar_desligar(1);
        }
        else
        {
            ligar_desligar(0);
        }
        break;

    case 1: // volume
        printf("\n\n(1)Aumentar o volume em 10 - Valor maximo de 90");
        printf("\n\n(0)Diminuir o volume em 10 - Valor minimo de 10");
        printf("\nInsira o numero da sua escolha: ");
        scanf("%d",&escolha);
        
        switch (escolha)
        {
        case 1:
            mudar_volume(1);
            break;
        
        case 0:
            mudar_volume(-1);
        }

        break;

    case 2: // canal
        printf("\n\n(1)Aumentar o canal em 5 - Valor maximo de 90");
        printf("\n(0)Diminuir o canal em 5 - Valor minimo de 10");
        printf("\n(2)Inserir o numero do canal pelo teclado");
        printf("\nInsira o simbolo da sua escolha: ");
        scanf("%d",&escolha);

        switch (escolha)
        {
        case 1:
            mudar_canal(5);
            break;
        
        case 0:
            mudar_canal(-5);
            break;
        
        case 2:
            printf("\nInsira o canal para o qual voce deseja ir: ");
            mudar_canal(1);
        }

        break;
    
    case 3: // cor
        printf("\n\nEscolha uma das seguintes cores:");
        printf("\n(0) Azul");
        printf("\n(1) Verde");
        printf("\n(2) Verde-agua");
        printf("\n(3) Vermelho");
        printf("\n(4) Roxo");
        printf("\n(5) Amarelo");
        printf("\n(6) Preto (Padrao)");
        printf("\nInsira um numero da sua escolha: ");
        scanf("%d",&escolha);

        switch (escolha)
        {
        case 0:
            mudar_cor(1);
            break;
        
        case 1:
            mudar_cor(2);
            break;

        case 2:
            mudar_cor(3);
            break;

        case 3:
            mudar_cor(4);
            break;

        case 4:
            mudar_cor(5);
            break;

        case 5:
            mudar_cor(6);
            break;

        case 6:
            mudar_cor(7);
        }
    }
    // caso nao tenha entendido algo, olhe as funcoes abaixo. sao bem auto-explicativas

    goto inicio; //serve como um looping de programa, ele vai voltar pro comeco
    return 0;
}

void ligar_desligar(int escolha) //a funcoes "primordial", muda o estado "booleano" da TV
{
    switch (escolha)
    {
    case 1:
        TV.Estado = LIGADA;
        break;
    
    case 0:
        TV.Estado = DESLIGADA;
    }
}   

void mudar_canal(int escolha) // permite o usuario mudar o canal de 5 em 5 ou digitar manualmente o numero do canal, alem de limitar o alcance
{
    if (TV.Estado == LIGADA)
    {
        switch (escolha)
        {
        case 5:
            TV.Canal += 5;
            break;
        
        case -5:
            TV.Canal -= 5;
            break;
        
        case 1:
            scanf("%d",&TV.Canal);
        }

        if (TV.Canal > 90)
        {
            TV.Canal = 90;
        }
        else if (TV.Canal < 10)
        {
            TV.Canal = 10;
        }
    }
}

void mudar_volume(int escolha) // essa funcao permite o usuario alterar o volume de 10 em 10, e delimita o alcance do volume
{ 
    if (TV.Estado == LIGADA)
    {
        switch (escolha)
        {
        case -1:
            TV.Volume -= 10;
            if (TV.Volume < 10)
            {
                TV.Volume = 10;
            }
            break;

        case 1:
            TV.Volume += 10;
            if (TV.Volume > 90)
            {
                TV.Volume = 90;
            }
        }
    }
}

void mudar_cor(int escolha) // essa funcao usa o comando color do cmd do windows (comentado logo antes da funcao main) para alterar a cor do plano de fundo do programa
{
    if (TV.Estado == LIGADA)
    {    
        switch (escolha)
        {
        case 1:
            system("color 17");
            break;
        
        case 2:
            system("color 27");
            break;

        case 3:
            system("color 37");
            break;
        
        case 4:
            system("color 47");
            break;

        case 5:
            system("color 57");
            break;

        case 6:
            system("color 67");
            break;
            
        case 7:
            system("color 07");
        }
    }
}