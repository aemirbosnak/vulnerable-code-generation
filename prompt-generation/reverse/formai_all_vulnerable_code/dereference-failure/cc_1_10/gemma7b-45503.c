//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int Search(Node* head, int target) {
    while (head) {
        if (head->data == target) {
            return 1;
        } else if (head->data < target) {
            head = head->next;
        } else {
            return 0;
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;
    InsertAtTail(head, 10);
    InsertAtTail(head, 20);
    InsertAtTail(head, 30);
    InsertAtTail(head, 40);
    InsertAtTail(head, 50);

    if (Search(head, 30) == 1) {
        printf("Target found!\n");
    } else {
        printf("Target not found.\n");
    }

    return 0;
}