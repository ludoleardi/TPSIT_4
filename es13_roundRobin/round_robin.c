#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define LENGHT 20
#define MAX_RAND 4
#define MIN_RAND 1
#define MIN_TEMP 50
#define MAX_TEMP 200
#define T_CPU 30

typedef struct process{
    int pid;
    char stato[LENGHT];
    int time;
    struct process *next;
}Process;

int is_empty(Process* head){
    if(head == NULL) return 1;
    else return 0;
}

//funzione che stampa 
void stampaCoda(Process *pr){
    while(pr != NULL){
       printf("%d, %s, %d\n", pr->pid, pr->stato, pr->time);
        pr = pr->next;
    }
}


//funzione enqueu inserisce elementi
void enqueu(struct process **head, struct process **tail, struct process *element){
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }
    *tail = element;
    element->next=NULL;
}

//funzione dequeu per l'estrazione del dato
struct process * dequeu(struct process **head, struct process **tail){
    struct process *ret = *head;
     if(is_empty(*head)){
         return NULL;
     }else{
         *head = ret->next;
     }

     if(*head == NULL){
         *tail = NULL;
     }
     return ret;
}


int main(){
    //head e tail del nuovo processo
    Process* NL_h = NULL;
    Process* NL_t = NULL;
    
    //head e tail del processo pronto
    Process* RL_h = NULL;
    Process* RL_t = NULL;

    //head e tail del processo termnato 
    Process* TL_h = NULL;
    Process* TL_t = NULL;

    //creo il processo
    Process *process;

    //variabile per il tempo random assegnato al processo
    int temp=0;

    //variabile per assegnare il nuovo tempo in caso di tempo insufficente nella cpu
    int new_temp=0;

    srand(time(NULL));

    //creo il numero di processi random
    int n_process;
    n_process=rand()%MAX_RAND+MIN_RAND;
    printf("Numero di processi: %d \n", n_process);

    //ciclo dove alloco i processi
    for(int k=0; k<n_process; k++){
        temp=0;//assegno 0 al tempo
        
        //alloco il processo
        process=(Process*)malloc(sizeof(Process));

        //assegno all'identificatore il valore di k 
        process->pid=k;

        //assegno il nuovo stato
        strcpy(process->stato, "NUOVO");

        //assegno un tempo random al processo necessario alla sua esecuzioen
        temp=rand()%MAX_TEMP+MIN_TEMP;
        process->time=temp;

        //aggiungo il processo
        enqueu(&NL_h, &NL_t, process);
    }

    //controllo se li ha caricati
    printf("CARICAMENTO ESEGUITO \n");
    stampaCoda(NL_h);
    printf("\n");



    //passo dallo stato nuovo a quello pronto quindi estraggo dal nuovo e lo aggiungo a quello pronto
    for(int i=0; i<n_process; i++){

        //estraggo dal nuovo processo
        Process *process= dequeu(&NL_h, &NL_t);

        //cambio lo stato
        strcpy(process->stato, "PRONTO");

        //aggiungo il processo alla lista dei pronti
        enqueu(&RL_h, &RL_t, process);
    }

    //controllo se i processi sono stati caricati nella lista dei ready
    printf("CARICAMENTO NEI PRONTI \n");
    stampaCoda(RL_h);
    printf("\n");

    //controllo che nella lista dei ready ci siano ancora elementi e se ci sono entro nel ciclo
    while(RL_h!=NULL){

        //tolgo dalla ready
        process = dequeu(&RL_h, &RL_t);

        //controllo che il tempo a disposizione dalla cpu sia sufficiente
        if(process->time+T_CPU>MAX_TEMP){
            //assegno al tempo del processo il restante da eseguire
            new_temp=(process->time+T_CPU)-MAX_TEMP;
            process->time=new_temp;

            //lo inserisco di nuovo nella ready 
            enqueu(&RL_h, &RL_t, process);

            //messaggio di segnalazione
            printf("\n TEMPO INSUFFICIENTE : processo numero %d \n", process->pid);

        }else{//se il tempo è sufficente lo eseguo e lo termino
            //cambio lo stato
            strcpy(process->stato, "ESEGUIBILE");

            //aggiungo ai terminati
            enqueu(&TL_h, &TL_t, process);
        } 
    }

    //stampo la coda dei processi terminati per vedere se è andato a buon fine
    printf("PROCESSO TERMINATO \n");
    stampaCoda(TL_h);

}