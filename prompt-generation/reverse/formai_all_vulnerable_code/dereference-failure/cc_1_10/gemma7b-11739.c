//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void initialize(Node* head) {
    head = (Node*)malloc(sizeof(Node));
    head->data = '\0';
    head->next = NULL;
}

void insert(Node* head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head->next == NULL) {
        head->next = newNode;
    } else {
        head->next->next = newNode;
    }
}

void search(Node* head, char target) {
    while (head) {
        if (head->data == target) {
            printf("Target found!\n");
            return;
        } else {
            head = head->next;
        }
    }

    printf("Target not found.\n");
}

int main() {
    Node* head = NULL;
    initialize(head);

    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');
    insert(head, 'e');

    search(head, 'c');

    return 0;
}