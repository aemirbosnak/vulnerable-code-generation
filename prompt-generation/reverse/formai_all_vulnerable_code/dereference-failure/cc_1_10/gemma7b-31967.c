//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1024

typedef struct Node {
    struct Node* next;
    char* data;
} Node;

Node* head = NULL;

void* alloc(int size) {
    if (size <= 0) return NULL;
    Node* newNode = malloc(sizeof(Node) + size);
    if (newNode == NULL) return NULL;

    newNode->next = head;
    head = newNode;
    newNode->data = (char*)newNode + sizeof(Node);
    return newNode->data;
}

void free(void* ptr) {
    if (ptr == NULL) return;

    Node* prev = NULL;
    Node* current = head;

    while (current) {
        if (current->data == ptr) {
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

    return;
}

int main() {
    alloc(10);
    alloc(20);
    alloc(30);
    free(alloc(40));
    free(alloc(50));

    return 0;
}