//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
};

void insert(struct Index* index, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* temp = index->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    index->size++;
}

char search(struct Index* index, char data) {
    Node* temp = index->head;
    while (temp) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;

    insert(index, 'a');
    insert(index, 'b');
    insert(index, 'c');
    insert(index, 'd');

    if (search(index, 'b') == 1) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}