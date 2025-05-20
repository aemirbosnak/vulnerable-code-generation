//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WINDOW_SIZE 128

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* window = NULL;
    int windowSize = 0;
    int count = 0;
    int prevCount = 0;
    int i = 0;
    int flag = 0;

    while (head) {
        if (windowSize < MAX_WINDOW_SIZE) {
            windowSize++;
            if (window == NULL) {
                window = head;
            } else {
                window = window->next;
            }
            head = head->next;
        } else {
            prevCount = count;
            count = 0;
            while (window && window->data != head->data) {
                count++;
                window = window->next;
            }
            if (count > 0) {
                printf("%d ", prevCount);
                printf("%d ", count);
            }
            head = head->next;
        }
    }

    if (prevCount > 0) {
        printf("%d ", prevCount);
        printf("%d ", count);
    }
}

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 2;

    compress(head);

    return 0;
}