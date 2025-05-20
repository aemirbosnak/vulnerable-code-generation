//FormAI DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** array;
    int size;
} HashTable;

int hash(int key, int size) {
    return key % size;
}

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashTable* createTable(int size) {
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->array = (Node**)malloc(size * sizeof(Node*));
    newTable->size = size;

    for (int i = 0; i < size; i++) {
        newTable->array[i] = NULL;
    }

    return newTable;
}

void insert(HashTable* table, int key, int value) {
    int index = hash(key, table->size);
    Node* head = table->array[index];

    while (head != NULL) {
        if (head->key == key) {
            head->value = value;
            return;
        }

        head = head->next;
    }

    Node* newNode = createNode(key, value);
    newNode->next = table->array[index];
    table->array[index] = newNode;
}

int search(HashTable* table, int key) {
    int index = hash(key, table->size);
    Node* head = table->array[index];

    while (head != NULL) {
        if (head->key == key) {
            return head->value;
        }

        head = head->next;
    }

    return -1;
}

void delete(HashTable* table, int key) {
    int index = hash(key, table->size);
    Node* head = table->array[index];
    Node* prev = NULL;

    while (head != NULL) {
        if (head->key == key) {
            if (prev == NULL) {
                table->array[index] = head->next;
            } else {
                prev->next = head->next;
            }

            free(head);
            return;
        }

        prev = head;
        head = head->next;
    }
}

void printTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        printf("[%d]: ", i);

        Node* head = table->array[i];

        while (head != NULL) {
            printf("(%d, %d) -> ", head->key, head->value);
            head = head->next;
        }

        printf("NULL\n");
    }
}

int main() {
    HashTable* table = createTable(MAX_SIZE);

    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 3, 30);
    insert(table, 4, 40);
    insert(table, 5, 50);

    printf("Hash table contents:\n");
    printTable(table);

    printf("\n");

    printf("Searching for key 4: %d\n", search(table, 4));
    printf("Searching for key 6: %d\n", search(table, 6));

    printf("\n");

    delete(table, 2);

    printf("Hash table contents after deleting key 2:\n");
    printTable(table);

    return 0;
}