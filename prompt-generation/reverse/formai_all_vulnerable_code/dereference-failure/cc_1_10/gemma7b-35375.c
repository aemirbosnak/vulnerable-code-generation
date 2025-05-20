//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(Node));
    tail = head;

    // Give the first node a name
    strcpy(head->name, "A");

    // Insert the first node into the list
    tail->next = NULL;

    // Allocate memory for the second node
    tail = malloc(sizeof(Node));
    tail->next = NULL;

    // Give the second node a name
    strcpy(tail->name, "B");

    // Insert the second node into the list
    tail->next = head;

    // Allocate memory for the third node
    tail = malloc(sizeof(Node));
    tail->next = NULL;

    // Give the third node a name
    strcpy(tail->name, "C");

    // Insert the third node into the list
    tail->next = head;

    // Traverse the list and print the name of each node
    for (Node* current = head; current; current = current->next)
    {
        printf("%s ", current->name);
    }

    // Free the memory allocated for the nodes
    free(head);
    free(tail);

    return 0;
}