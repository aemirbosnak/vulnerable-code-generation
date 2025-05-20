//Gemma-7B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_MEMORY 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *head = NULL;

void *my_malloc(int size) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (char *)malloc(size);
    newNode->next = head;
    head = newNode;
    return newNode->data;
}

void my_free(void *ptr) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr) {
        if (curr->data == ptr) {
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
    my_malloc(10);
    my_malloc(20);
    my_malloc(30);

    my_free(my_malloc(10));
    my_free(my_malloc(20));

    return 0;
}