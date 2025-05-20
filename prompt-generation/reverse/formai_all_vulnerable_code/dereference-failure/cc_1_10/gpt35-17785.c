//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void display(Node *head)
{
    Node *current;
    for (current = head; current != NULL; current = current->next)
    {
        printf("%d ", current->data);
    }
}

void insert(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void delete(Node **head, int key)
{
    Node *current = *head, *prev;

    if (current != NULL && current->data == key)
    {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return;
    }

    prev->next = current->next;
    free(current);
}

int main()
{
    Node *head = NULL;

    printf("Inserting 3 at the beginning of the list...\n");
    insert(&head, 3);
    display(head);

    printf("\nInserting 5 at the beginning of the list...\n");
    insert(&head, 5);
    display(head);

    printf("\nInserting 7 at the beginning of the list...\n");
    insert(&head, 7);
    display(head);

    printf("\nDeleting 5 from the list...\n");
    delete(&head, 5);
    display(head);

    printf("\nDeleting 3 from the list...\n");
    delete(&head, 3);
    display(head);

    printf("\nInserting 10 at the beginning of the list...\n");
    insert(&head, 10);
    display(head);

    printf("\nDeleting 7 from the list...\n");
    delete(&head, 7);
    display(head);

    return 0;
}