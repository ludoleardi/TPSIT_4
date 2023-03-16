#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME 50
#define TMAX 4
#define TMIN 1

typedef struct cliente{
    int servizio;
    struct cliente* next;
} Cliente;

//funzione enqueue inserisce elementi
void enqueue(struct cliente **head, struct cliente **tail, struct cliente *element){
    if(*head == NULL){
        *head = element;
    }else{
        (*tail)->next = element;
    }
    *tail = element;
    element->next=NULL;
}

//funzione dequeue per l'estrazione del dato
struct cliente* dequeue(struct cliente **head, struct cliente **tail){
    struct cliente *ret = *head;
     if(head == NULL){
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
    int attesa;
    Cliente* cl;
    Cliente* head = NULL;
    Cliente* tail = NULL;
    srand(time(NULL));
    
    attesa = rand() % TMAX + TMIN;
    printf("Attesa: %d\n", attesa);

    for(int k = 0; k < TIME; k++){
        printf("Minuto %d\n", k);
        if(attesa == k){
            cl = (Cliente*)malloc(sizeof(Cliente));
            cl->servizio = k + rand() % TMAX + TMIN;
            attesa = k + rand() % TMAX + TMIN;
            printf("Servizio: %d\n", cl->servizio);
            enqueue(&head, &tail, cl);
        }

        if(head != NULL && head->servizio == k){
            free(dequeue(&head, &tail));
            printf("Finito\n");
        }
    }
}