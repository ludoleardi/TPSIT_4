#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} Node;

int main()
{
    Node *head;
    Node *tail;
    int n;

    do
    {
        printf("Inserisci un numero o -1 per terminare: ");
        scanf("%d", &n);
        if(n>=0){
            Node* tmp = (Node*)malloc(sizeof(Node));
            tmp->val = n;
            tmp->next = NULL;
        }
    } while (n != 0);
}