#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
        strtmp = strdup(strtok(riga, ";")); // salvo la prima colonna del csv in una variabile temporanea
        strtmp = strdup(strtok(NULL, ";")); // salvo il cognome dello studente attuale
        if (strcmp(strtmp, cognome) == 0)   // verifico se il cognome presente nella riga del file corrisponde a quello cercato
        {
            cercato.cognome = strtmp;
            cercato.cifra = cercato.cifra + atoi(strtok(NULL, ";"));
        }
    }
    fclose(fp);
    printf("%s: %d\n", cercato.cognome, cercato.cifra);
}

// salvo i dati in una tabella, una riga per studente
void report(Studente *pagamenti, int len)
{
    Studente *pos;   // salvo la posizione iniziale del puntatore
    Studente *salva = pagamenti; // prima cella libera della tabella

    FILE *fp;
    fp = fopen(PATH, "r");
    char riga[SIZE];
    char *strtmp;
    bool salvato;
    int n = 0;
    while (fgets(riga, SIZE, fp))
    {
        printf("Riga %d\n", n);
        strtmp = strdup(strtok(riga, ";")); // salvo la data in una variabile temporanea
        strtmp = strdup(strtok(NULL, ";")); // salvo il cognome nella variabile temporanea per verificare se esiste già
        salvato = false;
        pos = pagamenti;
        while (salvato == false && pos < pagamenti + ((n) * sizeof(Studente)))
        {
            printf("%s - %s\n", strtmp, pos->cognome);
            if (salva != pagamenti && strcmp(strtmp, pos->cognome) == 0)
            {
                printf("Caso 1\n");
                pagamenti->cifra = pagamenti->cifra + atoi(strtok(NULL, ";"));
                salvato = true;
                n++;
            }
            printf("Fine if\n");
            pos++;
        }
        if (salvato == false)
        {
            salva->cognome = strtmp;
            salva->cifra = atoi(strtok(NULL, ";"));
            printf("Caso 2: %s\n",salva->cognome);
            salva++;
            n++;
        }
    }
}

// stampo la tabella
void stampaReport(Studente *persona, int len)
{
    Studente *pos;

    for (pos = persona; pos < persona + (len * sizeof(Studente)); pos++)
    {
        if (pos->cifra == 100)
        {
            printf("%s: %d\n", pos->cognome, pos->cifra);
        }
        else
        {
            printf("%s: %d ---- DA CONTROLLARE\n", pos->cognome, pos->cifra);
        }
    }
}

int main()
{
    int len = lunghezza();

    if (len != 0)
    {
        Studente *pagamenti = (Studente *)malloc(len * sizeof(Studente)); // alloco lo spazio in memoria per la tabella
        // printf("%d", len);
        calcolaTot(len);
        verificaPagamento("Leardi");
        printf("Elaboro report...\n");
        report(pagamenti, len);
        printf("Stampo report...\n");
        stampaReport(pagamenti, len);
        free(pagamenti);
    }
    else
    {
        printf("Dati non disponibili.\n");
    }
}