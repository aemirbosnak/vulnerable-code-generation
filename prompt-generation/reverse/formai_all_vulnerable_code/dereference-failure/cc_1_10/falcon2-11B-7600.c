//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void Insert(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Delete(Node** head_ref)
{
    Node* temp = *head_ref;
    Node* prev = *head_ref;

    while(temp!= NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void Traverse(Node* head)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 3);
    Insert(&head, 4);
    Insert(&head, 5);

    printf("Linked List before deletion: ");
    Traverse(head);
    printf("\n");

    Delete(&head);
    printf("Linked List after deletion: ");
    Traverse(head);
    printf("\n");

    return 0;
}