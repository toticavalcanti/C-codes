#include <stdio.h>/* Instru��o de pr�-processamento, habilita nosso programa a usar essa
                    Biblioteca de entrada e sa�da, possui fun��es como scanf e printf*/
#include <stdlib.h>/*Instru��o de pr�-processamento, habilita nosso programa a usar essa biblioteca,
para poder usar o system("PAUSE"); */
#include <locale.h> /*Instru��o de pr�-processamento, habilita nosso programa a usar essa biblioteca,
para usar caracteres como: �, �, � ,� etc. No printf( )*/

struct TNode
{
    int num;
    struct node *prox;
};
typedef struct TNode node;

int tam;

int menu(void);
void inicia(node *PILHA);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void libera(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);


int main(void)
{

    /*Ativa a configura��o da biblioteca locale.h para portugu�s*/
    setlocale(LC_ALL, "Portuguese"); //Ativa a configura��o da biblioteca locale.h para portugu�s

    node *PILHA = (node *) malloc(sizeof(node));

    if(!PILHA)
    {
        printf("Sem mem�ria dispon�vel!\n");
        exit(1);
    }
    else
    {
        inicia(PILHA);
        int opt;

        do
        {
            opt = menu();
            opcao(PILHA,opt);
        }
        while(opt);

        free(PILHA);
        return 0;
    }
}

void inicia(node *PILHA)
{
    PILHA->prox = NULL;
    tam=0;
}

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

void opcao(node *PILHA, int op)
{
    node *tmp;
    switch(op)
    {
    case 0:
        libera(PILHA);
        break;

    case 1:
        libera(PILHA);
        inicia(PILHA);
        break;

    case 2:
        exibe(PILHA);
        break;

    case 3:
        push(PILHA);
        break;

    case 4:
        tmp= pop(PILHA);
        if(tmp != NULL)
            printf("Retirado: %3d\n\n", tmp->num);
        break;

    default:
        printf("Comando inv�lido\n\n");
    }
}

int vazia(node *PILHA)
{
    if(PILHA->prox == NULL)
        return 1;
    else
        return 0;
}

node *aloca()
{
    node *novo=(node *) malloc(sizeof(node));
    if(!novo)
    {
        printf("Sem mem�ria dispon�vel!\n");
        exit(1);
    }
    else
    {
        printf("\nDigite um n�mero inteiro para inserir na PILHA:\n ");
        scanf("%d", &novo->num);
        return novo;
    }
}


void exibe(node *PILHA)
{
    if(vazia(PILHA))
    {
        printf("\nPILHA vazia!\n\n");
        return ;
    }

    node *tmp;
    tmp = PILHA->prox;
    printf("\nPILHA:");
    while( tmp != NULL)
    {
        printf("%5d", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n        ");
    int count;
    for(count=0 ; count < tam ; count++)
        printf("  ^  ");
    printf("\nOrdem:");
    for(count=0 ; count < tam ; count++)
        printf("%5d", count+1);


    printf("\n\n");
}

void libera(node *PILHA)
{
    if(!vazia(PILHA))
    {
        node *proxNode,
             *atual;

        atual = PILHA->prox;
        while(atual != NULL)
        {
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}

void push(node *PILHA)
{
    node *novo = aloca();
    novo->prox = NULL;

    if(vazia(PILHA))
        PILHA->prox=novo;
    else
    {
        node *tmp = PILHA->prox;

        while(tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
    tam++;
}


node *pop(node *PILHA)
{
    if(PILHA->prox == NULL)
    {
        printf("PILHA vazia!\n\n");
        return NULL;
    }
    else
    {
        node *ultimo = PILHA->prox,
              *penultimo = PILHA;

        while(ultimo->prox != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }

        penultimo->prox = NULL;
        tam--;
        return ultimo;
    }
}
