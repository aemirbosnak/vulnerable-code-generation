//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    int key;
    struct Node* ptr;
};

void insertNode(struct Node** head, char data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data[0] = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertIndex(struct Index** head, int key, char data) {
    struct Index* newNode = malloc(sizeof(struct Index));
    newNode->key = key;
    newNode->ptr = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->ptr = newNode;
    }
}

void searchIndex(struct Index* head, int key) {
    while (head) {
        if (head->key == key) {
            printf("Data: %s\n", head->ptr->data);
        }
        head = head->ptr;
    }
}

int main() {
    struct Node* head = NULL;
    struct Index* indexHead = NULL;

    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'c');
    insertNode(&head, 'd');
    insertNode(&head, 'e');

    insertIndex(&indexHead, 1, 'f');
    insertIndex(&indexHead, 2, 'g');
    insertIndex(&indexHead, 3, 'h');
    insertIndex(&indexHead, 4, 'i');
    insertIndex(&indexHead, 5, 'j');

    searchIndex(indexHead, 2);

    return 0;
}