//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
    char search_key[MAX_SIZE];
    struct Index* next;
};

void insert(struct Index* index, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* temp = index->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    index->size++;
}

char* search(struct Index* index, char* key) {
    Node* temp = index->head;
    while (temp) {
        if (strcmp(temp->data, key) == 0) {
            return temp->data;
        }
        temp = temp->next;
    }

    return NULL;
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;

    insert(index, "John Doe");
    insert(index, "Jane Doe");
    insert(index, "Peter Pan");

    char* data = search(index, "Jane Doe");
    if (data) {
        printf("Data: %s\n", data);
    } else {
        printf("Data not found.\n");
    }

    return 0;
}