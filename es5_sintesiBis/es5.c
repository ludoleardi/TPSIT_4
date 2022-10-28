// Creare un file csv con cognome, nome, data di nascita (annomesegiorno senza separatori)
// Scorrere il file con la funzione FGETS e STRTOK
// Stampare in ordine DECRESCENTE utilizzando puntatori e allocazione dinamica (MALLOC)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

typedef struct
{
    char *cognome;
    char *nome;
    int datanascita;
} Persona;

/*
Funzione: conta righe file
@param: puntatore a file già aperto
@return: numero righe, int
*/
int contaRighe()
{
    int r = 0;
    char tmp[SIZE];
    FILE *fp;

    // apro il file
    fp = fopen("date.csv", "r");
    if (fp == NULL)
    {
        printf("Impossibile aprire il file!\n");
    }
    else
    {
        printf("File aperto correttamente!\n");
        while (fgets(tmp, SIZE, fp))
        {
            r++;
        }
    }
    fclose(fp);
    return r;
}

/*
Funzione: salva dati file in tabella
@param: puntatore a tabella
@param: lunghezza file
@return: void
*/

void salvaDati(Persona *pers)
{
    FILE *fp;
    Persona *pos = pers; //salvo la posizione iniziale del puntatore
    char riga[SIZE];
    char tmp[SIZE];

    fp = fopen("date.csv", "r");
    if (fp == NULL)
    {
        printf("Impossibile aprire il file!\n");
    }
    else
    {
        printf("\nLeggo file...\n");
        fgets(tmp, SIZE, fp);
        printf("%s", tmp);
        while(fgets(riga, SIZE, fp))
        {
            pers->cognome = strdup(strtok(riga, ","));
            pers->nome = strdup(strtok(NULL, ","));
            pers->datanascita = atoi(strtok(NULL, ","));

            printf("%s, %s, %d\n", pers->cognome, pers->nome, pers->datanascita);
            pers++;
        }
    }

    pers = pos; //resetto il puntatore
}

/*
Funzione: riordina tabella in ordine decrescente
@param: tabella
@param: lunghezza tabella
@return: void
*/
void bubblesort(Persona* a, int dim){
    Persona temp;
    Persona* posizione = a;
    for(int sup = dim - 2; sup > 0; sup--){
        for(int k = 0; k < sup; k++){
            if(a->datanascita > (a + 1)->datanascita){
                temp = *a;
                *a = *(a + 1);
                *(a + 1) = temp;
            }
            a++;
        }
        a = posizione;
    }
    
}


/*
Funzione: stampa tabella
@param: tabella
@param: lunghezza tabella
*/
void stampaTab(Persona* pers, int len)
{
    Persona *pos = pers; //salvo la posizione iniziale del puntatore
    
    printf("\nTabella ordinata: \n");
    for(pers = pos; pers < pos + len -1; pers++)
    {
        printf("%s, %s, %d\n", pers->cognome, pers->nome, pers->datanascita);
    }

    pers = pos; //resetto il puntatore
}

int main()
{
    Persona *anagrafe;
    int lenFile;

    // calcolo la lunghezza del file
    lenFile = contaRighe();
    //debug: printf("%d\n", lenFile);

    // dichiaro la tabella e alloco lo spazio in memoria
    anagrafe = (Persona *)malloc(lenFile * sizeof(Persona));

    salvaDati(anagrafe);
    bubblesort(anagrafe, lenFile);
    stampaTab(anagrafe, lenFile);

    // chiusura
    free(anagrafe);
    return 0;
}