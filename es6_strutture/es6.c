#include <stdio.h>
#include <stdlib.h>

#define LUNG 20

typedef struct node{
    char nome[LUNG];
    struct node *next;
} Node;

int main()
{
    Node *lista = (Node*) malloc(sizeof(Node));
    Node *temp = (Node*) malloc(sizeof(Node));
    Node *terzo = (Node*) malloc(sizeof(Node));
    printf("Inserisci un nome: ");
    gets(lista->nome);
    lista->next = NULL;
    printf("Nome: %s\n", lista->nome);

    printf("Inserisci un nome: ");
    gets(temp->nome);
    printf("Nome: %s\n", temp->nome);
    temp->next = NULL;
    lista->next = temp;
    printf("%s\n", lista->next->nome);

    printf("Inserisci un nome: ");
    gets(terzo->nome);
    printf("Nome: %s\n", terzo->nome);
    terzo->next = NULL;
    lista->next->next = terzo;
    printf("%s\n", terzo->nome);

    printf("%s, %s, %s\n", lista->nome, lista->next->nome, lista->next->next->nome);

    free(lista);
    free(temp);
    return 0;
}