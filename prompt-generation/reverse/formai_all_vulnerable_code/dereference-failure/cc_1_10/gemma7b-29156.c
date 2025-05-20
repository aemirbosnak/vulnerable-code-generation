//Gemma-7B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
    struct Node* next;
    void* data;
    int size;
} Node;

Node* head = NULL;

void* alloc(int size) {
    if (head == NULL) {
        head = malloc(sizeof(Node));
        head->next = NULL;
        head->size = 0;
        head->data = malloc(size);
        head->size = size;
    } else {
        Node* newNode = malloc(sizeof(Node));
        newNode->next = head;
        head = newNode;
        newNode->size = size;
        newNode->data = malloc(size);
    }
    return head->data;
}

void free(void* data) {
    Node* current = head;
    Node* previous = NULL;
    while (current) {
        if (current->data == data) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    return;
}

int main() {
    alloc(10);
    alloc(20);
    alloc(30);
    free(alloc(10));
    free(alloc(20));
    return 0;
}