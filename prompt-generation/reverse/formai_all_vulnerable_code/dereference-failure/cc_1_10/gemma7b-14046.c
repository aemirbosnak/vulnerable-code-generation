//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data)
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

void graphColoring(Node* head)
{
    int color[MAX_Vertices] = {0};
    int currentColor = 1;

    while (head)
    {
        int nodeColor = color[head->data];
        if (nodeColor == 0)
        {
            color[head->data] = currentColor;
            currentColor++;
        }
        head = head->next;
    }

    for (int i = 0; i < MAX_Vertices; i++)
    {
        printf("Vertex %d has color %d\n", i, color[i]);
    }
}

int main()
{
    Node* head = NULL;
    insertAtTail(&head, 0);
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);

    graphColoring(head);

    return 0;
}