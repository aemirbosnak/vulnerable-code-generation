//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define maximum length of strings
#define MAX_STRING_LENGTH 100

// Define node structure for linked list
typedef struct node {
    char string[MAX_STRING_LENGTH];
    int count;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char* string, int count) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->string, string);
    newNode->count = count;
    newNode->next = NULL;
    return newNode;
}

// Function to add a string to the index
void addString(Node** head, char* string) {
    Node* current = *head;
    while (current!= NULL) {
        if (strcmp(current->string, string) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    current = createNode(string, 1);
    current->next = *head;
    *head = current;
}

// Function to print the index
void printIndex(Node* head) {
    while (head!= NULL) {
        printf("%s: %d\n", head->string, head->count);
        head = head->next;
    }
}

int main() {
    // Initialize head of linked list
    Node* head = NULL;

    // Add strings to the index
    addString(&head, "knight");
    addString(&head, "king");
    addString(&head, "queen");
    addString(&head, "prince");
    addString(&head, "princess");

    // Print the index
    printf("Index:\n");
    printIndex(head);

    return 0;
}