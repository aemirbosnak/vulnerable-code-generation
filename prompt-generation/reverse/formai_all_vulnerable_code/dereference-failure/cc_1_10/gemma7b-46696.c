//Gemma-7B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC 10

typedef struct Node {
    struct Node* next;
    int data;
} Node;

Node* head = NULL;

void insert(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void traverse() {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void free_mem() {
    Node* temp = head;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    traverse();
    free_mem();
    traverse();
    return 0;
}