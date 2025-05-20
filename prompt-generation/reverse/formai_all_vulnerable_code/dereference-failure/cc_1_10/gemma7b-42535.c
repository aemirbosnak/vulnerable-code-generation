//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct IndexTable {
    Node** table;
    int size;
    int capacity;
};

void insert(struct IndexTable* table, char data) {
    if (table->size >= table->capacity) {
        table->table = realloc(table->table, (table->capacity * 2) * sizeof(Node*));
        table->capacity *= 2;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    table->table[table->size++] = newNode;
}

int search(struct IndexTable* table, char data) {
    for (int i = 0; i < table->size; i++) {
        if (table->table[i]->data == data) {
            return i;
        }
    }

    return -1;
}

int main() {
    struct IndexTable* table = malloc(sizeof(struct IndexTable));
    table->size = 0;
    table->capacity = MAX_SIZE;
    table->table = malloc(MAX_SIZE * sizeof(Node*));

    insert(table, 'a');
    insert(table, 'b');
    insert(table, 'c');
    insert(table, 'd');
    insert(table, 'e');

    int index = search(table, 'c');

    if (index != -1) {
        printf("Index of character 'c' is: %d\n", index);
    } else {
        printf("Character 'c' not found.\n");
    }

    return 0;
}