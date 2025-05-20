//FormAI DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node* head)
{
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void push(struct node** head, int data) 
{
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = (*head);
  (*head) = new_node;
}

void deleteNode(struct node** head, int key)
{
    struct node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) 
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void insertAfter(struct node* prev_node, int data)
{
    if (prev_node == NULL)
    {
        printf("Previous node cannot be NULL");
        return;
    }
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main()
{
    struct node *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    printf("Linked list before deletion: ");
    printList(head);
    printf("\n");

    deleteNode(&head, 2);

    printf("Linked list after deletion: ");
    printList(head);
    printf("\n");

    insertAfter(head->next, 4);

    printf("Linked list after insertion: ");
    printList(head);
    printf("\n");

    return 0;
}