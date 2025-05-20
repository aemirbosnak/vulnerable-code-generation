//Gemma-7B DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    struct Node* next;
    char* data;
} Node;

Node* head = NULL;

void* inv_malloc(size_t size) {
    if (size > MAX_SIZE) {
        return NULL;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(size);

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }

    return newNode->data;
}

void inv_free(void* ptr) {
    Node* prev = NULL;
    Node* current = head;

    while (current) {
        if (current->data == ptr) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            free(current->data);
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }

    return;
}

int main() {
    inv_malloc(10);
    inv_malloc(20);
    inv_malloc(30);
    inv_malloc(40);
    inv_free(inv_malloc(20));
    inv_free(inv_malloc(30));

    return 0;
}