//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char key[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    Node* head;
    int size;
} Index;

void insert_node(Index* index, char key[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* current = index->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    index->size++;
}

char search_node(Index* index, char key[]) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->key[0];
        }
        current = current->next;
    }

    return '\0';
}

int main() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->head = NULL;
    index->size = 0;

    insert_node(index, "apple");
    insert_node(index, "banana");
    insert_node(index, "cherry");
    insert_node(index, "orange");

    char search_key = search_node(index, "banana");

    if (search_key) {
        printf("%c\n", search_key);
    } else {
        printf("Key not found\n");
    }

    return 0;
}