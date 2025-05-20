//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;
    int i = 0;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            previous = current;
            printf("%d ", current->data);
            if (count > 1) {
                printf("%d ", count);
            }
            count = 1;
        }

        i++;
    }

    printf("\n");
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;

    Node* second = (Node*)malloc(sizeof(Node));
    second->data = 1;

    Node* third = (Node*)malloc(sizeof(Node));
    third->data = 2;

    Node* fourth = (Node*)malloc(sizeof(Node));
    fourth->data = 2;

    Node* fifth = (Node*)malloc(sizeof(Node));
    fifth->data = 3;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    compress(head);

    return 0;
}