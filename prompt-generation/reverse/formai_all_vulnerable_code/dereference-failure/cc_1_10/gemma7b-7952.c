//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

int main()
{
    Node** head = (Node**)malloc(MAX * sizeof(Node));
    for (int i = 0; i < MAX; i++)
    {
        head[i] = NULL;
    }

    // Multiplayer Game Logic
    int player1 = 0, player2 = 1;

    // Player 1's turn
    printf("Player 1's turn:");
    int data1 = atoi(stdin);
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->data = data1;
    newNode1->next = head[player1];
    head[player1] = newNode1;

    // Player 2's turn
    printf("Player 2's turn:");
    int data2 = atoi(stdin);
    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->data = data2;
    newNode2->next = head[player2];
    head[player2] = newNode2;

    // Displaying the linked list
    printf("Linked List:");
    for (int i = 0; i < MAX; i++)
    {
        Node* current = head[i];
        while (current)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}