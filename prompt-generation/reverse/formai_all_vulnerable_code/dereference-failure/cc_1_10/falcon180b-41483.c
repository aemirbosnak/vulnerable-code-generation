//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VAL_LENGTH 1000
#define MAX_NUM_ENTRIES 1000

// Node structure for linked list
typedef struct node {
    char key[MAX_KEY_LENGTH];
    char val[MAX_VAL_LENGTH];
    struct node* next;
} Node;

// Hash table structure
typedef struct {
    Node* entries[MAX_NUM_ENTRIES]; // Array of linked lists
} HashTable;

// Function to calculate hash value of a key
int hash(char* key) {
    int sum = 0;
    while(*key) {
        sum += *key;
        key++;
    }
    return sum % MAX_NUM_ENTRIES;
}

// Function to add an entry to the hash table
void addEntry(HashTable* table, char* key, char* val) {
    int index = hash(key);
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->val, val);
    newNode->next = table->entries[index];
    table->entries[index] = newNode;
}

// Function to search for a key in the hash table
char* searchEntry(HashTable* table, char* key) {
    int index = hash(key);
    Node* currNode = table->entries[index];
    while(currNode!= NULL) {
        if(strcmp(currNode->key, key) == 0) {
            return currNode->val;
        }
        currNode = currNode->next;
    }
    return NULL;
}

// Function to print all entries in the hash table
void printEntries(HashTable* table) {
    for(int i=0; i<MAX_NUM_ENTRIES; i++) {
        Node* currNode = table->entries[i];
        while(currNode!= NULL) {
            printf("%s -> %s\n", currNode->key, currNode->val);
            currNode = currNode->next;
        }
    }
}

int main() {
    HashTable table;
    memset(table.entries, 0, sizeof(table.entries));

    // Add some entries to the hash table
    addEntry(&table, "apple", "red");
    addEntry(&table, "banana", "yellow");
    addEntry(&table, "cherry", "red");

    // Search for a key in the hash table
    char* result = searchEntry(&table, "banana");
    if(result!= NULL) {
        printf("Value for key 'banana': %s\n", result);
    } else {
        printf("Key 'banana' not found.\n");
    }

    // Print all entries in the hash table
    printEntries(&table);

    return 0;
}