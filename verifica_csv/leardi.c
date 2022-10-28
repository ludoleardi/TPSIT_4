#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024
#define PATH "4AROB_GITA.csv"
#define TOT 2200

typedef struct
{
    char *cognome;
    int cifra;
} Studente;

// calcolo la lunghezza del file
int lunghezza()
{
    FILE *fp;
    char riga[SIZE]; // salvo la riga
    int cont = 0;

    fp = fopen(PATH, "r");

    if (fp != NULL) // controllo corretta apertura del file
    {
        printf("File aperto correttamente, conto righe...\n");
        while (fgets(riga, SIZE, fp))
        {
            cont++;
        }
    }
    else
    {
        printf("Impossibile aprire il file!\n");
    }
    fclose(fp);
    return cont;
}

// calcolo totale degli incassi
void calcolaTot(int len)
{
    char riga[SIZE];
    char *strtmp;
    int tot = 0;
    FILE *fp;
    fp = fopen(PATH, "r");

    for (int i = 0; i < len; i++) // scorro tutte le righe del file
    {
        fgets(riga, SIZE, fp);
        strtmp = strdup(strtok(riga, ";")); // salvo in una stringa temporanea le prime due colonne del csv, non servono per il totale
        strtmp = strdup(strtok(NULL, ";"));
        tot = tot + atoi(strtok(NULL, ";")); // incremento il totale
    }

    printf("Totale incassi: %d euro\n", tot);
    if (tot > TOT) // la somma totale supera 2200
    {
        printf("Anomalia: %d euro in più.\n", tot - TOT);
    }
    else if (tot < TOT) // la somma totale non raggiunge 2200
    {
        printf("Anomalia %d euro in meno.\n", TOT - tot);
    }
    fclose(fp);
}

// ricerco una persona e salvo la somma pagata in una struttura
void verificaPagamento(char *cognome)
{
    FILE *fp;
    fp = fopen(PATH, "r");
    Studente cercato;
    cercato.cifra = 0; // inizializzo la somma versata dallo studente cercato

    char riga[SIZE];
    char *strtmp;

    printf("\nCerco studente... \n");
    while (fgets(riga, SIZE, fp)) // scorro il file
    {
        strtmp = strdup(strtok(riga, ";"));        // salvo la prima colonna del csv in una variabile temporanea
        strtmp = strdup(strtok(NULL, ";"));        // salvo il cognome dello studente attuale
        if (strcmp(strtmp, cognome) == 0) // verifico se il cognome presente nella riga del file corrisponde a quello cercato
        {
            cercato.cognome = strtmp;
            cercato.cifra = cercato.cifra + atoi(strtok(NULL, ";"));
        }
    }
    fclose(fp);
    printf("%s: %d\n", cercato.cognome, cercato.cifra);
}

/*
void report(Studente *pagamenti, int len)
{
    Studente* pos = pagamenti; //salvo la posizione iniziale del puntatore

    FILE *fp;
    fp = fopen(PATH, "r");
    int n = 0;
    char riga[SIZE];
    char *strtmp;
    while(fgets(riga, SIZE, fp))
    {
        strtmp = strdup(strtok(riga, ";")); //salvo la data in una variabile temporanea
        strtmp = strdup(strtok(NULL, ";")); //salvo il cognome nella variabile temporanea per verificare se esiste già
        for(int i = 0; i < len; i++)
        {
            if(strcmp(strtmp, ))
        }
    }

    pagamenti = pos; //resetto il puntatore
}
*/

int main()
{
    int len = lunghezza();
    Studente* pagamenti = (Studente*) malloc(len * sizeof(Studente)); //alloco lo spazio in memoria per la tabella

    if (len != 0)
    {
        // printf("%d", len);
        calcolaTot(len);
        verificaPagamento("Leardi");
        //report(pagamenti, len);
    }
    else
    {
        printf("Dati non disponibili.\n");
    }
}