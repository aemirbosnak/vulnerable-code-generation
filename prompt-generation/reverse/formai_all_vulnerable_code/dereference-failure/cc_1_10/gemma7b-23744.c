//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    int key;
    struct Node* head;
};

void insert(struct Index* index, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data[0] = data;
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        struct Node* temp = index->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(struct Index* index, char data) {
    struct Node* temp = index->head;
    while (temp) {
        if (temp->data[0] == data) {
            printf("Data found: %c\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("Data not found: %c\n", data);
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->key = 0;
    index->head = NULL;

    insert(index, 'a');
    insert(index, 'b');
    insert(index, 'c');
    insert(index, 'd');

    search(index, 'b');
    search(index, 'e');

    return 0;
}