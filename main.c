#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"

/**
  * @author Matheus Felipe
  */
int main()
{
    char input = '0';
    printf("Bem vindo(a) ao Quadro de Medalhas!\n\n");

    do
    {
        printf("\n--------------------------------------------------\n");
        printf("Digite um numero para escolher uma das opcoes abaixo:\n");
        printf("1 - Editar uma medalha\n2 - Gerar relatorio\n0 - Sair\n\n");
        printf("Sua escolha: ");
        scanf(" %c", &input);

        switch(input)
        {
            case '0':
                gerarRelatorioFinal();
                printf("\nObrigado por usar nossos servicos! Volte novamente!\n\n");
                return 0;
                break;

            case '1':
                int pais, modalidade, tipo, quantidade;

                printf("Digite qual pais voce ira querer mudar as medalhas\n\n");
                printf("Sua escolha: ");
                scanf("%d", &pais);

                printf("\nDigite qual modaliddade voce ira querer mudar as modalidades\n\n");
                printf("Sua escolha: ");
                scanf("%d", &modalidade);

                printf("\nDigite qual tipo de medalha voce quer modificar\n\nOpcoes:\n1 - Ouro\n2 - Prata\n3 - Bronze\n\n");
                printf("Sua escolha: ");
                scanf("%d", &tipo);

                printf("\nDigite qual a quantidade que ira ser adicionada\n\n");
                printf("Sua escolha: ");
                scanf("%d", &quantidade);

                editarEntrada(quantidade, pais, modalidade, tipo);
                break;

            case '2':
                printf("\nGerando relatorio...\n\n");
                gerarRelatorioInicial();
                printf("Relatorio gerado com sucesso!\n\n");
                break;

            default:
                printf("Opcao incorreta, por favor digite uma opcao correta\n");
                break;
        }

    } while (input != 0);

    return 0;
}
