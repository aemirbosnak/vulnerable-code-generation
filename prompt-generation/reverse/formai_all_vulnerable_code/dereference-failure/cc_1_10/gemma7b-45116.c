//Gemma-7B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void printList(Node* head)
{
    while (head)
    {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    insertAtTail(&head, 'a');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'd');
    insertAtTail(&head, 'e');

    printList(head);

    return 0;
}