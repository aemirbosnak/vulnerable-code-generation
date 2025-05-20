//Falcon2-11B DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node
{
    int data;
    struct node* next;
} node;

void insert(node** head_ref, int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void delete(node** head_ref)
{
    node* current = *head_ref;
    node* prev = *head_ref;

    while (current!= NULL && current->next!= NULL)
    {
        prev = current;
        current = current->next;
    }

    if (current!= NULL)
    {
        prev->next = current->next;
        free(current);
    }
}

void print_list(node* head)
{
    node* current = head;

    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    node* head = NULL;

    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 7);
    insert(&head, 2);
    insert(&head, 8);
    insert(&head, 1);

    print_list(head);

    delete(&head);
    delete(&head);
    delete(&head);

    printf("\n");

    return 0;
}