//Creare un file csv con cognome, nome, data di nascita (annomesegiorno senza separatori)
//Scorrere il file con la funzione FGETS e STRTOK
//Stampare in ordine DECRESCENTE utilizzando puntatori e allocazione dinamica (MALLOC)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024
#define PERS 4

typedef struct
{
    char *nome;
    char *cognome;
    int data;
} Persona;

int main()
{
    //dichiarazione variabili
    FILE *fp;
    char riga[SIZE];
    Persona *data = (Persona*) malloc(PERS * sizeof(Persona));
    Persona *point = data;
    Persona tmp;

    //apertura file e controllo
    fp = fopen("date.csv", "r");
    if(fp == NULL)
    {
        printf("Impossibile aprire il file!\n");
        return 1;
    }

    //lettura e stampa riga intestazione
    fgets(riga, SIZE, fp);
    printf("%s, %s, %s", strtok(riga, ","), strtok(NULL, ","), strtok(NULL, ","));
    
    //lettura dati e salvataggio in tabella
    while(!feof(fp))
    {
        fgets(riga, SIZE, fp);
        data->cognome = strtok(riga, ",");
        data->nome = strtok(NULL, ",");
        data->data = atoi(strtok(NULL, ","));
        printf("%s %s %d\n", data->cognome, data->nome, data->data);
        data++;
    }

    //ordinamento tabella DECRESCENTE
    for(int i = 0; i < PERS - 1; i++)
    {
        for(point = data; point < (data + PERS) - 1 - i; point++)
        {
            if(point->data < (point+1)->data)
            {
                tmp = *point;

                point = (point+1);

                
            }
        }
    }

    printf("%s %s %d\n", data[1].cognome, data[1].nome, data[1].data);


    //stampa dati
    for(point = data; point < (data + PERS); point++)
    {
        //printf("%s %s %d\n", point->cognome, point->nome, point->data);
    }

    free(data);
    fclose(fp);
}