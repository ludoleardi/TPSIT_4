#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024
#define LENGHT 100

typedef struct
{
    int rank;
    char name[SIZE];
    char platform[SIZE];
    int year;
    char genre[SIZE];
    char publisher[SIZE];
    float naSales;
    float euSales;
    float jpSales;
    float otherSales;
    float globalSales;
} Row;

int main()
{
    char riga[SIZE];
    Row data[LENGHT];
    int cont = 0;

    FILE *fp;
    fp = fopen("vgsales.csv", "r");
    
    if(fp == NULL)
    {
        printf("Il file non esiste!\n");
        return 1;
    }

    printf("File aperto correttamente!\n\n");

    fgets(riga, SIZE, fp);
    printf("%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", strtok(riga, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","));

    while(cont < LENGHT)
    {
        fgets(riga, SIZE, fp);
        data[cont].rank = atoi(strtok(riga, ","));
        strcpy(data[cont].name, strtok(NULL, ","));
        strcpy(data[cont].platform, strtok(NULL, ","));
        data[cont].year = atoi(strtok(NULL, ","));
        strcpy(data[cont].genre, strtok(NULL, ","));
        strcpy(data[cont].publisher, strtok(NULL, ","));
        data[cont].naSales = atof(strtok(NULL, ","));
        data[cont].euSales = atof(strtok(NULL, ","));
        data[cont].jpSales = atof(strtok(NULL, ","));
        data[cont].otherSales = atof(strtok(NULL, ","));
        data[cont].globalSales = atof(strtok(NULL, ","));
        printf("%d, %s, %s, %d, %s, %s, %f, %f, %f, %f, %f\n", data[cont].rank, data[cont].name, data[cont].platform, data[cont].year, data[cont].genre, data[cont].publisher, data[cont].naSales, data[cont].euSales, data[cont].jpSales, data[cont].otherSales, data[cont].globalSales);
        cont++;
    }

    fclose(fp);
    return 1;
}