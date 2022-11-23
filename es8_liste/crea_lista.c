/*crea  una  lista e la  stampa*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int valore;
    struct node *next;
} Node;

void stampaLista(Node *lista)
{
    Node *l;
    l = lista;
    printf("%d - %p \n", l->valore, l->next);
    if(l->next != NULL){
        stampaLista(l->next);
    }
    printf("\n");
}

int contaElementi(Node *lista, int cont)
{
    cont++;
    if (lista->next != NULL)
    {
        cont = contaElementi(lista->next, cont);
    }
    return cont;
}

void insertHead(struct node** head, int newVal){
    struct node* newHead = (struct node*)malloc(sizeof(struct node));

    newHead->valore = newVal;
    newHead->next = (*head);

    (*head) = newHead;
}

void insertOrdered(Node** head, Node* elem){
    Node* curr = *head, *prev = NULL;

    while(curr != NULL){
        if(elem->valore <= curr->valore){
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL)
        *head = elem;
    else
        prev->next = elem;
    elem->next = curr;
}

int main()
{
    int n;
    Node *lista;
    Node *l;
    lista = NULL;

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            Node* tmp = (Node*)malloc(sizeof(Node));
            tmp->valore = n;
            tmp->next = NULL;
            /*
            if (lista == NULL) //  prima  iterazione  
            {
                lista = (Node *)malloc(sizeof(Node));
                l = lista;
            }
            else // iterazioni  successive  
            {
                l->next = (Node *)malloc(sizeof(Node));
                l = l->next;
            }
            */
            insertOrdered(&lista, tmp);
            //l->valore = n;
            //l->next = NULL;
        }
    } while (n >= 0);

    /*l = lista;
    //insertHead(&l, 9);

    l = lista;
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->valore = 3;
    insertOrdered(&l, tmp);
    */

    printf("numeri  inseriti: \n");
    stampaLista(lista);
    printf("Numero di elementi: %d", contaElementi(lista, 0));

    return 0;
}