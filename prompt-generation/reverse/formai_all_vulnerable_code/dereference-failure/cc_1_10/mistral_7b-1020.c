//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char name[50];
    int size;
    struct Node* next;
    struct HashNode* hash;
} Node;

typedef struct HashNode {
    Node* data;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    int size;
    HashNode** data;
} HashTable;

int hashFunction(char* str, int size) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += str[i];
    }
    return hash % size;
}

void createHashTable(HashTable* table, int size) {
    table->size = size;
    table->data = (HashNode**)calloc(size, sizeof(HashNode*));
}

void insertFile(HashTable* table, char* name, int size) {
    int index = hashFunction(name, table->size);
    if (table->data[index] == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        strcpy(newNode->name, name);
        newNode->size = size;
        newNode->next = NULL;
        HashNode* newHashNode = (HashNode*)malloc(sizeof(HashNode));
        newHashNode->data = newNode;
        newHashNode->next = table->data[index];
        table->data[index] = newHashNode;
    } else {
        Node* current = table->data[index]->data;
        while (current != NULL && strcmp(current->name, name) != 0) {
            current = current->next;
        }
        if (current == NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            strcpy(newNode->name, name);
            newNode->size = size;
            newNode->next = current;
            table->data[index]->data = newNode;
        }
    }
}

void displayFiles(HashTable* table) {
    printf("Files in the futuristic file system:\n");
    for (int i = 0; i < table->size; i++) {
        if (table->data[i] != NULL) {
            printf("Index %d:\n", i);
            HashNode* current = table->data[i];
            Node* data = current->data;
            while (data != NULL) {
                printf("Name: %s, Size: %d\n", data->name, data->size);
                data = data->next;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    HashTable table;
    createHashTable(&table, 10);
    for (int i = 0; i < 20; i++) {
        char name[50];
        int size = rand() % 100 + 1;
        sprintf(name, "File%d", i);
        insertFile(&table, name, size);
    }
    displayFiles(&table);
    return 0;
}