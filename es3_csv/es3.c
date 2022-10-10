#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024
#define LENGHT 100

typedef struct
{
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float naSales;
    float euSales;
    float jpSales;
    float otherSales;
    float globalSales;
} Row;

int main()
{
    char riga[SIZE];
    Row* data = (Row*) malloc(16600 * sizeof(Row));

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

    while(!feof(fp))
    {
        fgets(riga, SIZE, fp);
        data->rank = atoi(strtok(riga, ","));
        data->name = strtok(NULL, ",");
        data->platform = strtok(NULL, ",");
        data->year = atoi(strtok(NULL, ","));
        data->genre = strtok(NULL, ",");
        data->publisher = strtok(NULL, ",");
        data->naSales = atof(strtok(NULL, ","));
        data->euSales = atof(strtok(NULL, ","));
        data->jpSales = atof(strtok(NULL, ","));
        data->otherSales = atof(strtok(NULL, ","));
        data->globalSales = atof(strtok(NULL, ","));
        printf("%d, %s, %s, %d, %s, %s, %f, %f, %f, %f, %f\n", data->rank, data->name, data->platform, data->year, data->genre, data->publisher, data->naSales, data->euSales, data->jpSales, data->otherSales, data->globalSales);
        data++;
    }

    free(data);

    fclose(fp);
    return 1;
}