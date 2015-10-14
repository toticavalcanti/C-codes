#include <stdio.h> /* Instru��o de pr�-processamento, habilita nosso programa a usar essa biblioteca
de entradas e sa�das, possui fun��es como scanf e printf*/
#include <stdlib.h>/*Instru��o de pr�-processamento, habilita nosso programa a usar essa biblioteca,
para poder usar o system("PAUSE"); */
#include <locale.h> /*Instru��o de pr�-processamento, habilita nosso programa a usar essa biblioteca,
para usar caracteres como: �, �, � ,� etc. No printf( )*/
#include <string.h>

void main(void)
{
    int tentativa, l;
    char nome[20], senha[15], saudacao[25], sexo;

    /*Ativa a configura��o da biblioteca locale.h para portugu�s*/
    setlocale(LC_ALL, "Portuguese"); //Ativa a configura��o da biblioteca locale.h para portugu�s

    printf("\n Qual o seu nome?\n ");
    gets (nome); //Captura o nome, pegando caracter por caracter at� que o usu�rio aperte o enter
    fflush(stdin); //Limpa o buffer do teclado


    printf("\n Sexo M ou F ? \n ");
    scanf("%c",&sexo);
    fflush(stdin);

    if ((sexo=='M') || (sexo=='m'))
    {
        strcpy (saudacao," Sr.");
    }
    else
    {
        strcpy (saudacao," Sra.");
    }

    tentativa = 3;
    while (tentativa > 0)
    {
        printf("\n\n%s %s, Digite a sua senha: \n ", saudacao, nome);
        gets(senha);
        fflush(stdin);
        if ( strcmp (senha,"provaav1") == 0)
        {
            tentativa = 0;
            printf(" \nSenha Correta \n Voc� digitou a senha \n");
            for(l = 0; l < strlen (senha); l++)
            printf(" %c ", senha[l]);
        }
        else
        {
            tentativa--;
            if (tentativa > 0)
                printf("\n Senha Errada!!!\n Voc� tem mais %d chances!!!", tentativa);
            else
                printf(" Chances Esgotadas!!!");
        }
   }

    system("pause");
}
