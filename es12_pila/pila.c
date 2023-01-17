#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct stack_node{
    char p;
    struct stack_node* next;
}Stack_node;

void push(struct stack_node **head, struct stack_node *element) {
    if(head == NULL) {
        *head = element;
        element->next = NULL;
    }
    else {
        element->next = *head;
        *head = element;
    }
}

Stack_node *pop(Stack_node **head){
    Stack_node *ret = *head;
    if(head == NULL){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void stampa(Stack_node *l){
     printf("%c - %p \n",l->p, l->next);
        if(l->next!=NULL){
            stampa(l->next);
        }
        printf("\n");
}

int main(){
    char s[MAX];
    printf("Inserire parentesi:");
    fflush(stdin);
    gets(s);

    //printf("%s", s);

    Stack_node* lista;

    //ciclo dove vado ad inserire i caratteri della stringa in una lista
    for(int k=0; k<strlen(s); k++){
        Stack_node *elem;
        elem = (Stack_node*)malloc(sizeof(Stack_node));

        elem->p=s[k];
        elem->next=NULL;
        push(&lista,elem);
    }

    stampa(lista);

    //ciclo dove faccio la pop delle parentesi
    for(int i=0; i<strlen(s); i++){
        /*if(strcmp(s[i],"{")==0 || strcmp(s[i],"[")==0 || strcmp(s[i],"(")==0){
            pop(&lista);
        }*/

        switch(s[i]){
        case '{':
            pop(&lista);
        case '[':
            pop(&lista);
        case '(':
            pop(&lista);
        }

    }

    stampa(lista);

}