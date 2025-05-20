//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insert(Node** head, char data)
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

void traverse(Node* head)
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

    // Multiplayer part
    int numPlayers = 2;
    char** playerData = (char**)malloc(numPlayers * sizeof(char*));
    for (int i = 0; i < numPlayers; i++)
    {
        playerData[i] = (char*)malloc(MAX_SIZE * sizeof(char));
    }

    // Insert data for each player
    insert(&head, playerData[0][0] = 'a');
    insert(&head, playerData[0][1] = 'b');
    insert(&head, playerData[0][2] = 'c');
    insert(&head, playerData[1][0] = 'd');
    insert(&head, playerData[1][1] = 'e');

    // Traverse and print data for each player
    traverse(head);
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Player %d's data: ", i + 1);
        traverse(head);
    }

    return 0;
}