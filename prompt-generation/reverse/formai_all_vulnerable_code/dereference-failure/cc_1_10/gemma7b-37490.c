//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVES 10

typedef struct Node
{
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

void Hanoi(Node* head, int moves)
{
    if (moves > MAX_MOVES)
    {
        return;
    }

    if (head == NULL)
    {
        return;
    }

    Hanoi(insertAtTail(head, head->data), moves + 1);

    printf("Move %d:  Disk %d from Peg A to Peg C\n", moves, head->data);

    free(head);
}

int main()
{
    Node* head = insertAtTail(NULL, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);

    Hanoi(head, 0);

    return 0;
}