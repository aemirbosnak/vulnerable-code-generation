//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

int main()
{
    Node* head = NULL;
    head = insertAtTail(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtTail(head, 40);

    // Paranoia: Check if the list is tampered with
    if (head == NULL || head->next == NULL)
    {
        printf("List tampered with!\n");
    }
    else
    {
        // Print the list
        while (head)
        {
            printf("%d ", head->data);
            head = head->next;
        }

        printf("\n");
    }

    return 0;
}