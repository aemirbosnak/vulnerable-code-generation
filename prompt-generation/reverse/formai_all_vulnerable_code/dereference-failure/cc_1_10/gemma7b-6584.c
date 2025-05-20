//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 10

typedef struct HashNode {
    char data[256];
    struct HashNode* next;
} HashNode;

void hash_insert(HashNode** head, char* data) {
    HashNode* newNode = malloc(sizeof(HashNode));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int hash_search(HashNode* head, char* data) {
    for (HashNode* current = head; current; current = current->next) {
        if (strcmp(current->data, data) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {

    HashNode* hashTable = NULL;

    // Simulate post-apocalyptic data retrieval
    char* data1 = "This is the first piece of data";
    hash_insert(&hashTable, data1);

    char* data2 = "This is the second piece of data";
    hash_insert(&hashTable, data2);

    char* data3 = "This is the third piece of data";
    hash_insert(&hashTable, data3);

    // Check if data exists in the hash table
    if (hash_search(hashTable, data2) == 1) {
        printf("Data found: %s\n", data2);
    } else {
        printf("Data not found: %s\n", data2);
    }

    return 0;
}