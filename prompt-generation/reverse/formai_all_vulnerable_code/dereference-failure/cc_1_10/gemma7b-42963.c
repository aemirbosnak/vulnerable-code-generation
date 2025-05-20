//Gemma-7B DATASET v1.0 Category: Memory management ; Style: excited
#include <stdlib.h>
#include <string.h>

#define MAX_ALLOC 10

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *head = NULL;

void alloc_mem(char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (char *)malloc(MAX_ALLOC);
    memcpy(newNode->data, str, MAX_ALLOC);
    newNode->next = head;
    head = newNode;
}

void free_mem(char *str) {
    Node *prev = NULL;
    Node *curr = head;

    while (curr) {
        if (curr->data == str) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            free(curr->data);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    return;
}

int main() {
    alloc_mem("John Doe");
    alloc_mem("Jane Doe");
    alloc_mem("Peter Pan");

    free_mem("Jane Doe");

    return 0;
}