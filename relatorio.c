#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerEntrada() {
    FILE *entrada = fopen("entrada.txt", "r");

    if (entrada == NULL) return NULL;

    //Move o ponteiro até o fim do arquivo
    fseek(entrada, 0, SEEK_END);
    //Devolve o número de caracteres em um arquivo
    int length = ftell(entrada);
    //Move o ponteiro de volta ao início do arquivo
    fseek(entrada, 0, SEEK_SET);

    //Cria uma string dinâmica usando malloc
    char *string = malloc(sizeof(char) * (length+1)); //Lenght + 1 é pra dar espaço ao caracter que termina a string

    //Lendo o conteúdo do arquivo em si
    char c;
    int i = 0;

    while ( (c = fgetc(entrada) ) != EOF) {
        string[i] = c;
        i++;
    }

    string[i] = '\0';

    fclose(entrada);

    return string;

}

int editarEntrada() {
   return 0;
}

int gerarRelatorio() {
    return 0;
}

