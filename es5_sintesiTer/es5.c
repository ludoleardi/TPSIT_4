// Creare un file csv con cognome, nome, data di nascita (annomesegiorno senza separatori)
// Scorrere il file con la funzione FGETS e STRTOK
// Stampare in ordine DECRESCENTE utilizzando puntatori e allocazione dinamica (MALLOC)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024
#define PATH "date.csv"

typedef struct
{
    char *cognome;
    char *nome;
    int data;
} Persona;

// calcola lunghezza file
int lunghezza()
{
    FILE *fp;
    char riga[SIZE];
    int r = 0;
    
    fp = fopen(PATH, "r"); //apro il file
    if(fp != NULL) //controllo l'apertura
    {
        while(fgets(riga, SIZE, fp))
        {
            r++;
        }
    }
    else
    {
        printf("Impossibile aprire il file!\n");
        return 0;
    }
    fclose(fp);
    printf("Righe: %d\n", r-1);
    return r-1; //tolgo 1, riga di intestazione
}

// carica dati in tabella
void caricaDati(Persona* pers, int len)
{
    Persona* pos = pers; //salvo la posizione iniziale del puntatore
    char riga[SIZE];
    FILE *fp;
    fp = fopen(PATH, "r"); //non controllo più apertura corretta, controllo dimensione nel main
    
    //stampo intestazione
    fgets(riga, SIZE, fp);
    printf("\n%s\n", riga);

    while(fgets(riga, SIZE, fp))
    {
        pers->cognome = strdup(strtok(riga, ","));
        pers->nome = strdup(strtok(NULL, ","));
        pers->data = atoi(strtok(NULL, ","));

        printf("%s, %s, %d\n", pers->cognome, pers->nome, pers->data);
        pers++;
    }
    fclose(fp);
    pers = pos; //resetto il puntatore
}

// riordina tabella
void bubbleSort(Persona* pers, int len)
{
    Persona* pos = pers; //salvo la posizione iniziale del puntatore
    Persona tmp; //struttura temporanea per lo scambio

    printf("Riordino...\n");
    for(int i = 0; i < len; i++)
    {
        for(int k = 0; k < len; k++)
        {
            if(pers->data > (pers + 1)->data)
            {
                tmp = *pers;
                *pers = *(pers + 1);
                *(pers + 1) = tmp;
            }
            pers++;
        }
        pers = pos;
    }

    pers = pos; //resetto il puntatore
}

// stampa tabella
void stampa(Persona* pers, int len)
{
    Persona* pos = pers; //salvo la posizione iniziale del puntatore

    printf("\nTabella ordinata:\n");
    for(int i = 0; i < len; i++)
    {
        printf("%s, %s, %d\n", pers->cognome, pers->nome, pers->data);
        pers++;
    }

    pers = pos; //resetto la posizione del puntatore
}

// main
int main()
{
    int len = lunghezza();
    Persona *anagrafe;

    if(len > 0)
    {
        anagrafe = (Persona*) malloc(len * sizeof(Persona));
        
        caricaDati(anagrafe, len);
        bubbleSort(anagrafe, len);
        stampa(anagrafe, len);
    }
    else
    {
        printf("Errore nella lettura del file!\n");
    }

    free(anagrafe);
}