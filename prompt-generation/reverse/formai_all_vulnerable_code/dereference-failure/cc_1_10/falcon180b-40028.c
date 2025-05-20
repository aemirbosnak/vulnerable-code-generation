//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct entry {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Entry;

typedef struct node {
    Entry entry;
    struct node* next;
} Node;

Node* hashTable[MAX_ENTRIES];

unsigned int hash(char* key) {
    unsigned int sum = 0;
    int i = 0;
    while (key[i]) {
        sum += key[i];
        i++;
    }
    return sum % MAX_ENTRIES;
}

void insert(char* key, char* value) {
    unsigned int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->entry.key, key);
    strcpy(newNode->entry.value, value);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void printTable() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        Node* currNode = hashTable[i];
        while (currNode!= NULL) {
            printf("%s - %s\n", currNode->entry.key, currNode->entry.value);
            currNode = currNode->next;
        }
    }
}

int main() {
    hashTable[0] = NULL;
    insert("apple", "red");
    insert("banana", "yellow");
    insert("cherry", "red");
    insert("date", "brown");
    printTable();
    return 0;
}