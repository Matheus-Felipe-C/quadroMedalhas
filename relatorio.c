#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerEntrada()
{
    FILE *entrada = fopen("entrada.txt", "r");

    if (entrada == NULL)
        return NULL;

    // Move o ponteiro até o fim do arquivo
    fseek(entrada, 0, SEEK_END);
    // Devolve o número de caracteres em um arquivo
    int length = ftell(entrada);
    // Move o ponteiro de volta ao início do arquivo
    fseek(entrada, 0, SEEK_SET);

    // Cria uma string dinâmica usando malloc
    char *string = malloc(
                       sizeof(char) *
                       (length +
                        1)); // Length + 1 é pra dar espaço ao caracter que termina a string

    // Lendo o conteúdo do arquivo em si
    char c;
    int i = 0;

    while ((c = fgetc(entrada)) != EOF)
    {
        string[i] = c;
        i++;
    }

    string[i] = '\0';

    fclose(entrada);

    return string;
}

int editarEntrada(int quantMedalha, int pais, int modalidade, int tipoMedalha)
{
    char *data = lerEntrada();
    if (data == NULL)
    {
        printf("Nao foi possivel ler o arquivo\n");
        return 1;
    }

    int i, j = 4, cont = 0, linhas = 0, colunas, dataSize = strlen(data);

    // Calcula o número de linhas e colunas
    for (i = 0; i < dataSize; i++)
    {
        if (data[i] == '\n')
            linhas++;

        if (linhas == 2)
        {
            //Como caracteres são números,
            //ao diminior o '0' transforma o caractere me número
            //E ao somar um número a '0' o transforma de volta em caractere
            colunas = (int)(data[i - 1] - '0') * 3;
            linhas = (int)data[0] - '0';
            break;
        }
    }

    int medalhas[linhas][colunas]; // Matriz que deverá possuir os dados em si

    // Adiciona o valor para a matriz medalhas
    for (i = 0; i < linhas; i++)
    {
        while (j < dataSize)
        {
            if (data[j] == '\n')
            {
                j++;
                cont = 0;
                break;
            }
            if (data[j] != ' ')
            {
                medalhas[i][cont] = data[j] - '0';
                cont++;
            }
            j++;
        }
    }

    // Edita as medalhas da categoria selecionada
    medalhas[pais-1][tipoMedalha-1 + 3 * modalidade-3] = quantMedalha;

    //Salvar os valores no arquivo entrada.txt
    //FILE *entrada = fopen("entrada.txt", "w");
    char novaEntrada[dataSize];
    cont = 3;
    int repeticoes = 0;

    novaEntrada[0] = data[0];
    novaEntrada[1] = '\n';
    novaEntrada[2] = data[2];

    for (i = 0; i < linhas; i++)
    {
        novaEntrada[cont] = '\n';
        cont++;
        repeticoes = 0;
        for (j = 0; j < colunas; j++)
        {
            if (repeticoes > 2)
            {
                novaEntrada[cont] = ' ';
                novaEntrada[cont+1] = ' ';
                novaEntrada[cont+2] = ' ';
                cont += 3;
                repeticoes = 0;
            }
            novaEntrada[cont] = medalhas[i][j] + '0';
            novaEntrada[cont+1] = ' ';
            cont += 2;
            repeticoes++;

        }
    }
    novaEntrada[cont] = '\0';
    FILE *entrada = fopen("entrada.txt", "w");

    fprintf(entrada, "%s", novaEntrada);
    printf("Entrada atualizada com sucesso!");
    fclose(entrada);

    free(data);
    return 0;
}

void gerarRelatorioInicial()
{
    char *data = lerEntrada();

    if (data == NULL)
    {
        printf("Nao foi possivel ler o arquivo\n");
        exit(1);
    }

    int i, j = 4, cont = 0, linhas = 0, colunas;
    int dataSize = strlen(data);

    // Calcula o número de linhas e colunas
    for (i = 0; i < dataSize; i++)
    {
        if (data[i] == '\n')
            linhas++;

        if (linhas == 2)
        {
            //Como caracteres são números,
            //ao diminior o '0' transforma o caractere me número
            //E ao somar um número a '0' o transforma de volta em caractere
            colunas = (int)(data[i - 1] - '0') * 3;
            linhas = (int)data[0] - '0';
            break;
        }
    }
    int medalhas[linhas][colunas]; // Matriz que deverá possuir os dados em si

    // Adiciona o valor para a matriz medalhas
    for (i = 0; i < linhas; i++)
    {
        while (j < dataSize)
        {
            if (data[j] == '\n')
            {
                j++;
                cont = 0;
                break;
            }
            if (data[j] != ' ')
            {
                medalhas[i][cont] = data[j] - '0';
                cont++;
            }
            j++;
        }
    }
    // Relatório inicial
    colunas = 3;
    int totalProvas = 0, relatorio[linhas][colunas];;
    float percProvas = 0;
    FILE *arquivo = fopen("relatorio.txt", "w");

    fprintf(arquivo, "%s", "Quadro de Medalhas Inicial\n     ");
    fprintf(arquivo, "%s", "Ouro|Prata|Bronze\n");

    //Calcula a soma de medalhas e total de provas
    for (i = 0; i < linhas; i++)
    {
        fprintf(arquivo, "P%d    ", i+1);
        for (j = 0; j < colunas; j++)
        {
            relatorio[i][j] = medalhas[i][j] + medalhas[i][j + 3];
            fprintf(arquivo, "%d    ", relatorio[i][j]);
            totalProvas += relatorio[i][j];
        }
        fprintf(arquivo, "\n");
    }

    percProvas = 100 * (totalProvas / 306.0) ;

    fprintf(arquivo, "\nQuantidade Inicial de provas disputadas: %d\n", totalProvas);
    fprintf(arquivo,"Percentual de provas disputadas: %.2f%%\n\n",percProvas);

}

void gerarRelatorioFinal();
