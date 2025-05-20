//Gemma-7B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC 1024

typedef struct Node {
    struct Node* next;
    void* data;
} Node;

Node* head = NULL;

void* alloc(int size) {
    if (head == NULL) {
        head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        head->data = (void*)malloc(size);
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->next = head;
        head = newNode;
        newNode->data = (void*)malloc(size);
    }
    return head->data;
}

void free(void* data) {
    Node* prev = NULL;
    Node* current = head;

    while (current) {
        if (current->data == data) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Error: Data not found.\n");
}

int main() {
    void* data = alloc(10);
    data = alloc(20);
    free(data);
    free(data);

    return 0;
}