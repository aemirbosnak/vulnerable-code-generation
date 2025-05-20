//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;
    int size = 0;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            previous = current;
            size++;
            if (count > 1) {
                printf("%d ", count);
            }
            printf("%d ", current->data);
            count = 1;
        }
    }

    printf("\n");
    printf("Total number of nodes: %d\n", size);
}

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 1;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 2;
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 2;
    head->next->next->next->next = malloc(sizeof(Node));
    head->next->next->next->next->data = 3;

    compress(head);

    return 0;
}