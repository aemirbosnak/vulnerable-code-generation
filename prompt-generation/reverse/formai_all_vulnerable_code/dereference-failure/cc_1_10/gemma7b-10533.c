//Gemma-7B DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_ retries 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert(Node* head, int data) {
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

int search(Node* head, int data) {
    while (head) {
        if (head->data == data) {
            return 1;
        } else if (head->next) {
            head = head->next;
        } else {
            return 0;
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;

    head = insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    if (search(head, 20) == 1) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}