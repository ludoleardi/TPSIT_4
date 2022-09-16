#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

typedef struct
{

} Tabella;

int main()
{
    char riga[SIZE];

    FILE *fp;
    fp = fopen("vgsales.csv", "r");

    if(fp == NULL)
    {
        printf("Il file non esiste!\n");
        return 0;
    }

    printf("File aperto correttamente!\n");

    while(!feof(fp))
    {
        fgets(riga, SIZE, fp);
    }

    fclose(fp);
    return 1;
}