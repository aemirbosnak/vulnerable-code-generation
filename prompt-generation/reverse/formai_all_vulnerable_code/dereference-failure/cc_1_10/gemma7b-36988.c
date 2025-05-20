//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_DATA_SIZE 1024

typedef struct Node {
    char data[MAX_DATA_SIZE];
    struct Node* next;
} Node;

struct IndexTable {
    int key;
    Node* head;
};

void insertData(struct IndexTable* table, char* data) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (table->head == NULL) {
        table->head = newNode;
    } else {
        table->head->next = newNode;
    }
}

int searchData(struct IndexTable* table, char* key) {
    Node* current = table->head;
    while (current) {
        if (strcmp(current->data, key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    struct IndexTable* table = malloc(sizeof(struct IndexTable));
    table->key = 0;
    table->head = NULL;

    insertData(table, "John Doe");
    insertData(table, "Jane Doe");
    insertData(table, "Peter Pan");

    if (searchData(table, "Jane Doe") == 1) {
        printf("Jane Doe is in the database.\n");
    }

    return 0;
}