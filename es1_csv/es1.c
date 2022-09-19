#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024
#define LENGHT 16600

int main()
{
    int rank[LENGHT];
    char name[SIZE][LENGHT];
    int cont = 0;

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
        fscanf(fp, "%d,%s", &rank[cont], name[cont]);
        printf("%d,%s", rank[cont], name[cont]);
        cont ++;
    }

    fclose(fp);
    return 1;
}