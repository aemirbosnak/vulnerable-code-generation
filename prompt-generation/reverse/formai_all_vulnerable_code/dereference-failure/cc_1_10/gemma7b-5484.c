//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC 10

typedef struct Node {
    struct Node* next;
    int data;
} Node;

Node* head = NULL;

void alloc_mem(int data) {
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

void free_mem(int data) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp) {
        if (temp->data == data) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            temp = NULL;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    alloc_mem(10);
    alloc_mem(20);
    alloc_mem(30);
    alloc_mem(40);

    free_mem(20);
    free_mem(30);

    printf("Head: %p\n", head);

    return 0;
}