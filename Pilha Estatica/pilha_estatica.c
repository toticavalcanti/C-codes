#include <stdio.h>/* Instru��o de pr�-processamento, habilita nosso programa a usar essa
                    Biblioteca de entrada e sa�da, possui fun��es como scanf e printf*/

#include <stdlib.h>/*Instru��o de pr�-processamento, habilita nosso programa a usar essa biblioteca,
                    para poder usar o system("PAUSE"); */

#include <locale.h> /*Instru��o de pr�-processamento, habilita nosso programa a usar essa biblioteca,
para usar caracteres como: �, �, � ,� etc. No printf( )*/

//Defini��o do tipo
#define MAX 10

//Estrutura do tipo pilha
typedef struct
{
    int vNo[MAX];
    int topo;
} TPilha;
//Prot�tipos das fun��es
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

//fun��o pop, retira o n� do topo da pilha
int retiraPilha(TPilha *pPilha, int *pNo)
{
    //Se a pilha estiver vazia retorna zero
    if(pilhaVazia(pPilha))
        return 0;

    //Se chegou aqui, � porque a pilha n�o est� vazia
    //No endere�o de pNo � armazenado o n� que ser� retirado, que est� no topo da pilha.



    *pNo = pPilha->vNo[pPilha->topo];//acessa o vNo de pPilha da struct TPilha e pega o no do topo.
    //Decrementa o topo da pilha j� que um n� foi retirado
    pPilha->topo--;
    //retorna 1 indicando que o n� foi retirado do topo
    return 1;

}

//M�todos de acesso
void leNo(int *pNo)
{
    scanf("%d", pNo);
}

//Imprime o valor no n�
void escreveNo(int *pNo)
{
    printf("%d", *pNo);
}

//Inicializa pilha2
void inicializaPilha(TPilha *pPilha)
{
    pPilha->topo = -1;
}

//Inser��o de um n� no topo da pilha, fun��o push
int inserePilha(TPilha *pPilha, int *pNo)
{
    if(pilhaCheia(pPilha))
        return 0;
    pPilha->topo++;
    pPilha->vNo[pPilha->topo] = *pNo;
    return 1;
}

//Verifica se a pilha est� vazia
int pilhaVazia(TPilha *pPilha)
{
//Se o topo tiver -1, a pilha estar� vazia
    if(pPilha->topo == -1)
        return 1;//Retorna 1 indicando que a pilha est� vazia
    return 0; //Se n�o est� vazia, retorna zero
}

//Verifica se a pilha est� cheia
int pilhaCheia(TPilha *pPilha)
{
//Verifica se a pilha est� cheia, isto �, se o topo for igual ao tamanho definidp
//para a pilha menos um , nesse caso MAX -1
    if(pPilha->topo == MAX-1)
        return 1;
    return 0;
}

//Fun��o que imprime no console a resposta
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
            printf("%5d", pPilha->vNo[i]);//Imprime cada elemento retirado da pilha, OBS: no final a pilha estar� vazia
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

//Apresenta as op��es do menu e retorna o valor escolhido pelo usu�rio
int menu(void)
{
    int opcao;

    printf("Escolha uma op��o:\n");
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
        exibe(pilha, &no); //Exibe os n�meros inseridos
        break;

    case 3:
        printf("\nDigite o n�mero inteiro para ser inserido na pilha est�tica:\n");
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
        printf("\nComando inv�lido\n\n");
    }
}

int main()
{
    int op;
    TPilha pilha;

    /*Ativa a configura��o da biblioteca locale.h para portugu�s*/
    setlocale(LC_ALL, "Portuguese"); //Ativa a configura��o da biblioteca locale.h para portugu�s

//Chama a fun��o menu ( ) e o valor retornado � atribu�do a opcao
    inicializaPilha(&pilha);
    do
    {
        op = menu();
        opcao(&pilha,op);
    }
    while(op);

    //Se o usu�rio digitar qualquer coisa que n�o seja 1
    printf("Finalizado!\n\n\n");

    system("PAUSE");
    return 0;
}
