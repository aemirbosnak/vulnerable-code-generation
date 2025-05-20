//Gemma-7B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1024

typedef struct Node {
    struct Node* next;
    void* data;
} Node;

Node* head = NULL;

void insert(void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

void print() {
    Node* current = head;
    while (current) {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    print();

    free(head);
    head = NULL;

    insert(60);
    insert(70);
    insert(80);
    insert(90);

    print();

    return 0;
}