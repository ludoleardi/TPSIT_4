#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next
};

int main()
{
    node *lista;
    lista = (node*) malloc(sizeof(node))

    printf("Inserire un nome: ");
    scanf("%s", lista->nome);

    return 0;
}