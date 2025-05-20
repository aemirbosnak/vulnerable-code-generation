//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure definition
struct Node {
    char data[MAX_SIZE];
    int size;
    struct Node* next;
};

// Function to create a new node with given data and size
struct Node* createNode(char data[], int size) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct Node** head, char data[], int size) {
    struct Node* newNode = createNode(data, size);
    struct Node* temp = *head;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = NULL;
}

// Function to search for a pattern in the list and return its index
int searchPattern(struct Node* head, char pattern[]) {
    struct Node* temp = head;
    int index = 0;

    while (temp!= NULL) {
        if (strcmp(temp->data, pattern) == 0)
            return index;

        temp = temp->next;
        index++;
    }

    return -1;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "apple", 5);
    addNode(&head, "banana", 6);
    addNode(&head, "cherry", 7);
    addNode(&head, "date", 4);
    addNode(&head, "elderberry", 9);

    // Search for a pattern in the list
    int result = searchPattern(head, "cherry");

    // Print the result
    if (result == -1)
        printf("Pattern not found.\n");
    else
        printf("Pattern found at index %d.\n", result);

    return 0;
}