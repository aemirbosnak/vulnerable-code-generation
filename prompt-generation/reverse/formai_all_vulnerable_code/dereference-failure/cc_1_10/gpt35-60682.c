//FormAI DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int data;
    struct node* next;
} Node;

// Hash table size
const int TABLE_SIZE = 128;

// Function to create a new node
Node* createNode(int key, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert a node into hash table
void insert(Node* hashTable[], int key, int data) {
    int index = hash(key);
    Node* newNode = createNode(key, data);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search for a node in hash table
void search(Node* hashTable[], int key) {
    int index = hash(key);
    Node* currentNode = hashTable[index];
    while(currentNode != NULL) {
        if(currentNode->key == key) {
            printf("Key found with data: %d\n", currentNode->data);
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Key not found.\n");
}

int main() {
    Node* hashTable[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; ++i) {
        hashTable[i] = NULL;
    }

    insert(hashTable, 1001, 2021);
    insert(hashTable, 2038, 2030);
    insert(hashTable, 5684, 2023);
    insert(hashTable, 1276, 2025);
    insert(hashTable, 8934, 2024);
    insert(hashTable, 4690, 2022);

    search(hashTable, 1001);
    search(hashTable, 2038);
    search(hashTable, 5684);
    search(hashTable, 1276);
    search(hashTable, 8934);
    search(hashTable, 4690);

    return 0;
}