//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 50
#define HASH_TABLE_SIZE 100

// Linked list structure for storing key-value pairs
typedef struct node {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct node* next;
} Node;

// Hash table structure
typedef struct {
    Node* head;
} HashTable;

// Hash function
int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % HASH_TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* hashTable, char* key, char* value) {
    int index = hash(key);

    // Check if key already exists in hash table
    Node* curr = hashTable[index].head;
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {  // Key already exists
            strcpy(curr->value, value);
            return;
        }
        curr = curr->next;
    }

    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;

    // Insert node at beginning of linked list at index
    newNode->next = hashTable[index].head;
    hashTable[index].head = newNode;
}

// Function to search for a key in the hash table and return its value
char* search(HashTable* hashTable, char* key) {
    int index = hash(key);

    // Traverse linked list at index and search for key
    Node* curr = hashTable[index].head;
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {  // Key found
            return curr->value;
        }
        curr = curr->next;
    }

    // Key not found
    return NULL;
}

// Main function
int main() {
    HashTable hashTable[HASH_TABLE_SIZE];

    // Insert key-value pairs into hash table
    insert(hashTable, "apple", "a fruit");
    insert(hashTable, "banana", "a fruit");
    insert(hashTable, "carrot", "a vegetable");
    insert(hashTable, "desk", "a piece of furniture");

    // Search for values based on keys
    printf("apple: %s\n", search(hashTable, "apple"));
    printf("banana: %s\n", search(hashTable, "banana"));
    printf("carrot: %s\n", search(hashTable, "carrot"));
    printf("desk: %s\n", search(hashTable, "desk"));

    // Update values for existing keys
    insert(hashTable, "apple", "a type of computer");
    printf("apple: %s\n", search(hashTable, "apple"));

    return 0;
}