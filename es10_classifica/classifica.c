/*Vogliamo gestire una struttura dati che tenga in memoria solo i primi 5 posti di una classifica ordinata 
per punteggio massimo. Il tutto dovrà essere gestito con una Lista e i nodi andranno inseriti direttamente nel 
posto corretto della classifica in base al valore assegnato, non si dovrà fare un algoritmo di sort in fase successiva. 
Al termine di ogni inserimento potranno rimanere in memoria solo 5 nodi.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char* nome;
    int punti;
    struct node* next;
} Node;

int contaElementi(Node *lista, int cont)
{
    cont++;
    if (lista->next != NULL)
    {
        cont = contaElementi(lista->next, cont);
    }
    return cont;
}

void inserisciNodo(Node** head, Node* elem){
    Node* curr = *head, *prev = NULL;

    while(curr != NULL)
    {
        if(elem->punti <= curr->punti){
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if(prev==NULL){
        *head = elem;
    }
    else{
        prev->next = elem;
    }
    elem->next = curr;
}

void print(Node *head)
{
    Node *l;
    l = head;
    printf("%s: %d \n", l->nome, l->punti);
    if(l->next != NULL){
        print(l->next);
    }
    printf("\n");
}

void topFive(Node* head){
    Node* i = head;
    if(contaElementi(head, 0) > 5){
        while(i->next != NULL)
        {
            i = i->next;
        }
        free(i);

    }
}

int main(){
    int n;
    char p[1024];
    Node* classifica;

    do {
        printf("Inserisci un numero o -1 per terminare: ");
        scanf("%d", &n);
        if(n>=0){
            printf("Inserisci nome giocatore: ");
            fflush(stdin);
            scanf("%s", p);
            Node* tmp = (Node*)malloc(sizeof(Node));
            tmp->punti = n;
            tmp->nome = p;
            inserisciNodo(&classifica, tmp);
            //printf("Inserito %p\n", classifica);
            //printf("%d", classifica->punti);
            topFive(classifica);
            print(classifica);
        }

    } while(n >= 0);
}