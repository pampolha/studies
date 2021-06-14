
#include <stdio.h>
int main(int argc, char const *argv[])
{   
    int qntd;  

    printf("Por favor, digite a quantidade de elementos que serao organizados: ");
    scanf("%d",&qntd);

    float vetor[qntd][qntd];
    int valorAtual;
    
    for (valorAtual = 0; valorAtual < qntd; valorAtual++)
    {
        printf("\nDigite o %d) numero: ", valorAtual+1);
        scanf("%f",&vetor[valorAtual][valorAtual]);
    }
    
    printf("\nOs numeros apresentados foram: ");
    for (valorAtual = 0; valorAtual < qntd; valorAtual++)
    {
        printf("%.2f, ",vetor[valorAtual][valorAtual]);
    }
    
    int proximoValor;
    float troca;

    for (valorAtual = 0; valorAtual < qntd; valorAtual++) 
    {
        for (proximoValor = valorAtual + 1; proximoValor < qntd; proximoValor++) 
        {
            if (vetor[valorAtual][valorAtual] > vetor[proximoValor][proximoValor])
            {
                troca = vetor[valorAtual][valorAtual];
                vetor[valorAtual][valorAtual] = vetor[proximoValor][proximoValor];
                vetor[proximoValor][proximoValor] = troca;   
            }
        }
    }
    
    printf("\n\nOs elementos apos a organizacao foram: ");
    for (valorAtual = 0; valorAtual < qntd; valorAtual++)
    {
        printf("%.2f, ", vetor[valorAtual][valorAtual]);
    }
    
    getch(); 
    return 0;
}
//algoritmos de ordenacao > selection sort > vantagens e desvantagens