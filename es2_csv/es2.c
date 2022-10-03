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
    Row data[LENGHT];
    Row* c = data;

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
        (*c).rank = atoi(strtok(riga, ","));
        (*c).name = strtok(NULL, ",");
        (*c).platform = strtok(NULL, ",");
        (*c).year = atoi(strtok(NULL, ","));
        (*c).genre = strtok(NULL, ",");
        (*c).publisher = strtok(NULL, ",");
        (*c).naSales = atof(strtok(NULL, ","));
        (*c).euSales = atof(strtok(NULL, ","));
        (*c).jpSales = atof(strtok(NULL, ","));
        (*c).otherSales = atof(strtok(NULL, ","));
        (*c).globalSales = atof(strtok(NULL, ","));
        printf("%d, %s, %s, %d, %s, %s, %f, %f, %f, %f, %f\n", (*c).rank, (*c).name, (*c).platform, (*c).year, (*c).genre, (*c).publisher, (*c).naSales, (*c).euSales, (*c).jpSales, (*c).otherSales, (*c).globalSales);
        c++;
    }

    fclose(fp);
    return 1;
}