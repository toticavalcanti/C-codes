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
}TPilha;
//Protótipos das funções
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
void removePilha(TPilha *pPilha);

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

//Inicializa pilha
void inicializaPilha(TPilha *pPilha)
{
 pPilha->topo = -1;
}

//Inserção de um nó no topo da pilha, função push
int inserePilha(TPilha *pPilha, int pNo)
{
 if(pilhaCheia(pPilha))
  return 0;
 pPilha->topo++;
 pPilha->vNo[pPilha->topo] = pNo;
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

//Função que faz a conversão utilizando as funções da pilha
void converteDecBin(TPilha *pPilha, int decimal)
{
    int quociente;
    int resto;

    inicializaPilha(pPilha);//Inicia a pilha e atribui ao tipo TPilha, referência para a variável chamada pPilha.
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

//Função que imprime no console a resposta
void printResposta(TPilha *pPilha, int decimal)
{
     int aux;

     if(pilhaVazia(pPilha))// se a pilha estiver vazia, imprime "Pilha vazia!"
     {
         printf("Pilha vazia!\n");
     }
     else
     {
         printf(" O equivalente em binario do decimal %d é: \n ", decimal);
         //Enquanto tiver elementos na pilha, retira e imprime cada um,
         //montando assim, o número binário referente ao decimal.
         while( retiraPilha(pPilha, &aux) )
         {
            escreveNo(&aux);//Imprime cada elemento da pilha
         }
     }
}

//Apresenta as opções do menu e retorna o valor escolhido pelo usuário
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

 /*Ativa a configuração da biblioteca locale.h para português*/
    setlocale(LC_ALL, "Portuguese"); //Ativa a configuração da biblioteca locale.h para português

//Chama a função menu ( ) e o valor retornado é atribuído a opcao
    opcao = menu();
    while(opcao == 1){
        printf("\n\n Insira um número decimal positivo inteiro para a conversao em binário: \n ");
        scanf("%d", &numeroDigitado);

        //Chammada da função converteDecBin( ) passando uma referência para a pilha
        //e uma cópia de númeroDigitado
        converteDecBin(&pilha, numeroDigitado);
        opcao = menu();
    }
    //Se o usuário digitar qualquer coisa que não seja 1
    printf("Finalizado!\n\n\n");

   system("PAUSE");
   return 0;
}
