//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000

// Node structure for linked list
typedef struct node {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
    int count;
    struct node* next;
} Node;

// Linked list structure
Node* head = NULL;

// Function to insert a new entry
void insert(char* key, char* value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->count = 1;
    newNode->next = head;
    head = newNode;
}

// Function to search for an entry
Node* search(char* key) {
    Node* currNode = head;
    while (currNode!= NULL) {
        if (strcmp(currNode->key, key) == 0) {
            return currNode;
        }
        currNode = currNode->next;
    }
    return NULL;
}

// Function to delete an entry
void delete(char* key) {
    Node* currNode = head;
    Node* prevNode = NULL;
    while (currNode!= NULL) {
        if (strcmp(currNode->key, key) == 0) {
            if (prevNode == NULL) {
                head = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to print all entries
void printAll() {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%s -> %s (%d)\n", currNode->key, currNode->value, currNode->count);
        currNode = currNode->next;
    }
}

int main() {
    insert("apple", "fruit");
    insert("banana", "fruit");
    insert("orange", "fruit");
    insert("carrot", "vegetable");
    insert("potato", "vegetable");

    printAll();

    Node* foundNode = search("banana");
    if (foundNode!= NULL) {
        printf("Found %s -> %s (%d)\n", foundNode->key, foundNode->value, foundNode->count);
    } else {
        printf("Not found\n");
    }

    delete("banana");

    printAll();

    return 0;
}