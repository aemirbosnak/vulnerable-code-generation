//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the indexing system structure
typedef struct IndexNode {
    char key[20];
    struct IndexNode* next;
} IndexNode;

// Function to insert a key into the indexing system
void insertKey(IndexNode** head, char* key) {
    IndexNode* newNode = (IndexNode*)malloc(sizeof(IndexNode));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a key in the indexing system
IndexNode* searchKey(IndexNode* head, char* key) {
    IndexNode* current = head;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current;
        } else if (strcmp(current->key, key) > 0) {
            current = current->next;
        }
    }

    return NULL;
}

int main() {
    IndexNode* head = NULL;

    // Insert some keys into the indexing system
    insertKey(&head, "John Doe");
    insertKey(&head, "Jane Doe");
    insertKey(&head, "Peter Pan");

    // Search for a key in the indexing system
    IndexNode* foundNode = searchKey(head, "Jane Doe");

    // Print the found key
    if (foundNode) {
        printf("Found key: %s\n", foundNode->key);
    } else {
        printf("Key not found\n");
    }

    return 0;
}