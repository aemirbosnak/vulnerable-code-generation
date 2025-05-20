//FormAI DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int value;
    struct List* next;
} List;

// Function to create a new List node
List* createNode(int value)
{
    List* newNode = (List*)malloc(sizeof(List));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the List
void append(List** head, int value)
{
    List* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    List* currentNode = *head;

    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    return;
}

// Function to print the List
void printList(List* node)
{
    if (node == NULL)
        return;

    printf("%d -> ", node->value);
    printList(node->next);
}

int main()
{
    List* head = NULL;

    // Constructing a List of numbers 1 to 10
    for (int i = 1; i <= 10; i++) {
        append(&head, i);
    }

    // Printing the List
    printf("The List: ");
    printList(head);
    printf("NULL\n");

    return 0;
}