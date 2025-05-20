//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void search(Node* head, char target) {
    while (head) {
        if (head->data == target) {
            printf("Target found.\n");
            return;
        } else if (head->data < target) {
            head = head->next;
        } else {
            printf("Target not found.\n");
            return;
        }
    }

    printf("Target not found.\n");
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    search(head, 'c');
    search(head, 'f');

    return 0;
}