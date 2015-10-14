
#include <stdio.h> /* Instrução de pré-processamento, habilita nosso programa a usar essa biblioteca
de entradas e saídas, possui funções como scanf e printf*/
#include <stdlib.h>/*Instrução de pré-processamento, habilita nosso programa a usar essa biblioteca,
para poder usar o system("PAUSE"); */
#include <locale.h> /*Instrução de pré-processamento, habilita nosso programa a usar essa biblioteca,
para usar caracteres como: ç, Ç, Â ,â etc. No printf( )*/
#include <string.h>

void main(void)
{
    int tentativa, l;
    char nome[20], senha[15], saudacao[25], sexo;

    /*Ativa a configuração da biblioteca locale.h para português*/
    setlocale(LC_ALL, "Portuguese"); //Ativa a configuração da biblioteca locale.h para português

    printf("\n Qual o seu nome?\n ");
    gets (nome); //Captura o nome, pegando caracter por caracter até que o usuário aperte o enter
    fflush(stdin); //Limpa o buffer do teclado


    printf("\n Sexo M ou F ? \n ");
    scanf("%c",&sexo); // Captura o caracter referente ao sexo
    fflush(stdin);

	//Se sexo contiver um M ou m, strcpy( ) copia a string " Sr." para o array saudacao
    if ((sexo=='M') || (sexo=='m'))
    {
        strcpy (saudacao," Sr.");
    }
    else // Caso contrário strcpy( ) copia a string " Sra." para o array saudacao
    {
        strcpy (saudacao," Sra.");
    }

    tentativa = 3;
    while (tentativa > 0) // enquanto tentativa for maior que 3
    {
        printf("\n\n%s %s, Digite a sua senha: \n ", saudacao, nome);
        gets(senha); // captura a senha digitada 
        fflush(stdin);
	// strcmp ( ) compara a string referente a senha digitada pelo usuário com a string "provaav1".
        if ( strcmp (senha,"provaav1") == 0) // Se o usuário digitar provaav1, a senha estará correta, a execução entra no if.
        {
            tentativa = 0; //Zera tentativas, já que a senha está correta
            printf(" \nSenha Correta \n Você digitou a senha \n");
		//Percorre caracter por caracter da string senha.
            for(l = 0; l < strlen (senha); l++) 
            printf(" %c ", senha[l]); //imprime cada caracter da string
        }
        else // caso contrário, isto é, o usuário digitou algo diferente de "provaav1".
        {
            tentativa--; // decrementa tentativa
            if (tentativa > 0)
                printf("\n Senha Errada!!!\n Você tem mais %d chances!!!", tentativa);
            else
                printf(" Chances Esgotadas!!!");
        }
   }

    system("pause");
}
