//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct node {
    char data;
    struct node* next;
} node;

void compress(node* head) {
    node* current = head;
    node* previous = NULL;
    int count = 0;
    char prevChar = '\0';

    while (current) {
        if (previous && current->data == prevChar) {
            count++;
        } else {
            if (previous) {
                printf("%c%d ", previous->data, count);
            }
            prevChar = current->data;
            count = 1;
        }

        previous = current;
        current = current->next;
    }

    if (previous) {
        printf("%c%d ", previous->data, count);
    }
}

int main() {
    node* head = NULL;
    head = malloc(sizeof(node));
    head->data = 'a';
    head->next = malloc(sizeof(node));
    head->next->data = 'a';
    head->next->next = malloc(sizeof(node));
    head->next->next->data = 'b';
    head->next->next->next = malloc(sizeof(node));
    head->next->next->next->data = 'a';

    compress(head);

    return 0;
}