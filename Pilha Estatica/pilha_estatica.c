#include <stdio.h>/* Instrução de pré-processamento, habilita nosso programa a usar essa
                    Biblioteca de entrada e saída, possui funções como scanf e printf*/

#include <stdlib.h>/*Instrução de pré-processamento, habilita nosso programa a usar essa biblioteca,
                    para poder usar o system("PAUSE"); */

#include <locale.h> /*Instrução de pré-processamento, habilita nosso programa a usar essa biblioteca,
para usar caracteres como: ç, Ç, Â ,â etc. No printf( )*/

//Definição do tipo
#define MAX 10

//Estrutura do tipo pilha
typedef struct
{
    int vNo[MAX];
    int topo;
} TPilha;
//Protótipos das funções
int retiraPilha(TPilha *pPilha, int *pNo);
void leNo(int *pNo);
void escreveNo(int *pNo);
void inicializaPilha(TPilha *pPilha);
int inserePilha(TPilha *pPilha, int *pNo);
int pilhaVazia(TPilha *pPilha);
int pilhaCheia(TPilha *pPilha);
void exibe(TPilha *pPilha, int *no);
int menu();
void opcao(TPilha *PILHA, int op);

//função pop, retira o nó do topo da pilha
int retiraPilha(TPilha *pPilha, int *pNo)
{
    //Se a pilha estiver vazia retorna zero
    if(pilhaVazia(pPilha))
        return 0;

    //Se chegou aqui, é porque a pilha não está vazia
    //No endereço de pNo é armazenado o nó que será retirado, que está no topo da pilha.



    *pNo = pPilha->vNo[pPilha->topo];//acessa o vNo de pPilha da struct TPilha e pega o no do topo.
    //Decrementa o topo da pilha já que um nó foi retirado
    pPilha->topo--;
    //retorna 1 indicando que o nó foi retirado do topo
    return 1;

}

//Métodos de acesso
void leNo(int *pNo)
{
    scanf("%d", pNo);
}

//Imprime o valor no nó
void escreveNo(int *pNo)
{
    printf("%d", *pNo);
}

//Inicializa pilha2
void inicializaPilha(TPilha *pPilha)
{
    pPilha->topo = -1;
}

//Inserção de um nó no topo da pilha, função push
int inserePilha(TPilha *pPilha, int *pNo)
{
    if(pilhaCheia(pPilha))
        return 0;
    pPilha->topo++;
    pPilha->vNo[pPilha->topo] = *pNo;
    return 1;
}

//Verifica se a pilha está vazia
int pilhaVazia(TPilha *pPilha)
{
//Se o topo tiver -1, a pilha estará vazia
    if(pPilha->topo == -1)
        return 1;//Retorna 1 indicando que a pilha está vazia
    return 0; //Se não está vazia, retorna zero
}

//Verifica se a pilha está cheia
int pilhaCheia(TPilha *pPilha)
{
//Verifica se a pilha está cheia, isto é, se o topo for igual ao tamanho definidp
//para a pilha menos um , nesse caso MAX -1
    if(pPilha->topo == MAX-1)
        return 1;
    return 0;
}

//Função que imprime no console a resposta
void exibe(TPilha *pPilha, int *no)
{
    int i = pPilha->topo;

    if(pilhaVazia(pPilha))// se a pilha estiver vazia, imprime "Pilha vazia!"
     {
         printf("\nPilha vazia!\n");
     }
     else
     {
         printf("\nPILHA:");
         while(i >= 0 )
         {
            printf("%5d", pPilha->vNo[i]);//Imprime cada elemento retirado da pilha, OBS: no final a pilha estará vazia
            i--;
         }
     }
    printf("\n        ");
    int count;
    for(count=0 ; count < MAX ; count++)
        printf("  ^  ");
    printf("\nOrdem:");
    for(count=0 ; count < MAX ; count++)
        printf("%5d", count+1);


    printf("\n\n");
}

//Apresenta as opções do menu e retorna o valor escolhido pelo usuário
int menu(void)
{
    int opcao;

    printf("Escolha uma opção:\n");
    printf("0 - Sair\n");
    printf("1 - Zerar PILHA\n");
    printf("2 - Exibir PILHA\n");
    printf("3 - PUSH, empilha os elementos\n");
    printf("4 - POP, desempilha os elementos\n");
    printf("\nOpcao:\n");
    scanf("%d", &opcao);

    return opcao;
}

void opcao(TPilha *pilha, int op)
{
    int no;

    switch(op)
    {
    case 0:
        break;

    case 1:
        free(pilha);
        inicializaPilha(pilha);
        break;

    case 2:
        exibe(pilha, &no); //Exibe os números inseridos
        break;

    case 3:
        printf("\nDigite o número inteiro para ser inserido na pilha estática:\n");
        scanf("%d", &no);
        inserePilha(pilha, &no);
        break;

    case 4:
        if(retiraPilha(pilha, &no))
            printf("\nRetirado: %3d\n\n", no);
        else
            printf("\nPilha Vazia!\n\n");
        break;

    default:
        printf("\nComando inválido\n\n");
    }
}

int main()
{
    int op;
    TPilha pilha;

    /*Ativa a configuração da biblioteca locale.h para português*/
    setlocale(LC_ALL, "Portuguese"); //Ativa a configuração da biblioteca locale.h para português

//Chama a função menu ( ) e o valor retornado é atribuído a opcao
    inicializaPilha(&pilha);
    do
    {
        op = menu();
        opcao(&pilha,op);
    }
    while(op);

    //Se o usuário digitar qualquer coisa que não seja 1
    printf("Finalizado!\n\n\n");

    system("PAUSE");
    return 0;
}
