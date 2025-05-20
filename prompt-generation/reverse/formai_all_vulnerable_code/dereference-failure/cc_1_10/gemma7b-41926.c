//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void traverse(Node* head) {
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }
}

Node* search(Node* head, char target) {
    while (head) {
        if (head->data == target) {
            return head;
        } else if (head->next) {
            head = head->next;
        } else {
            return NULL;
        }
    }
}

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data = 'a';
    head->next = malloc(sizeof(Node));
    head->next->data = 'b';
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 'c';
    head->next->next->next = NULL;

    traverse(head);

    Node* result = search(head, 'b');
    if (result) {
        printf("Found: %c", result->data);
    } else {
        printf("Not found");
    }

    return 0;
}