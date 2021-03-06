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
}TPilha;
//Prot�tipos das fun��es
int retiraPilha(TPilha *pPilha, int *pNo);
void leNo(int *pNo);
void escreveNo(int *pNo);
void inicializaPilha(TPilha *pPilha);
int inserePilha(TPilha *pPilha, int pNo);
int pilhaVazia(TPilha *pPilha);
int pilhaCheia(TPilha *pPilha);
void converteDecBin(TPilha *pPilha, int decimal);
void printResposta(TPilha *pPilha, int decimal);
int menu();


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

//Inicializa pilha
void inicializaPilha(TPilha *pPilha)
{
 pPilha->topo = -1;
}

//Inser��o de um n� no topo da pilha, fun��o push
int inserePilha(TPilha *pPilha, int pNo)
{
 if(pilhaCheia(pPilha))
  return 0;
 pPilha->topo++;
 pPilha->vNo[pPilha->topo] = pNo;
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

//Fun��o que faz a convers�o utilizando as fun��es da pilha
void converteDecBin(TPilha *pPilha, int decimal)
{
    int quociente;
    int resto;

    inicializaPilha(pPilha);//Inicia a pilha e atribui ao tipo TPilha, refer�ncia para a vari�vel chamada pPilha.
    quociente = decimal;
    if(quociente >= 2)
    {
         do
         {
                 resto = quociente % 2;
				 inserePilha(pPilha, resto); //Insere o resto na pilha
                 quociente = quociente / 2;
         }while( quociente > 0 );
    }
    else
      {
            resto =  quociente;
			inserePilha(pPilha, resto);
      }
    printResposta(pPilha, decimal);
}

//Fun��o que imprime no console a resposta
void printResposta(TPilha *pPilha, int decimal)
{
     int aux;

     if(pilhaVazia(pPilha))// se a pilha estiver vazia, imprime "Pilha vazia!"
     {
         printf("Pilha vazia!\n");
     }
     else
     {
         printf(" O equivalente em binario do decimal %d �: \n ", decimal);
         //Enquanto tiver elementos na pilha, retira e imprime cada um,
         //montando assim, o n�mero bin�rio referente ao decimal.
         while( retiraPilha(pPilha, &aux) )
         {
            escreveNo(&aux);//Imprime cada elemento da pilha
         }
     }
}

//Apresenta as op��es do menu e retorna o valor escolhido pelo usu�rio
int menu()
{
    int op;
    printf("\n\n 1 - Para converter um numero inteiro decimal positivo em binario: \n 2 - Para finalizar. \n ");
    scanf(" %d", &op);
    return op;
}

int main()
{
   int opcao;
   int numeroDigitado;
   TPilha pilha;

 /*Ativa a configura��o da biblioteca locale.h para portugu�s*/
    setlocale(LC_ALL, "Portuguese"); //Ativa a configura��o da biblioteca locale.h para portugu�s

//Chama a fun��o menu ( ) e o valor retornado � atribu�do a opcao
    opcao = menu();
    while(opcao == 1){
        printf("\n\n Insira um n�mero decimal positivo inteiro para a conversao em bin�rio: \n ");
        scanf("%d", &numeroDigitado);

        //Chammada da fun��o converteDecBin( ) passando uma refer�ncia para a pilha
        //e uma c�pia de n�meroDigitado
        converteDecBin(&pilha, numeroDigitado);
        opcao = menu();
    }
    //Se o usu�rio digitar qualquer coisa que n�o seja 1
    printf("Finalizado!\n\n\n");

   system("PAUSE");
   return 0;
}
