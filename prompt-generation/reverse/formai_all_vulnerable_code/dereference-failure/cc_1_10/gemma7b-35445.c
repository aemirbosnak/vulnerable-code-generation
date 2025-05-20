//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
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

void search(Node* head, int target) {
    while (head) {
        if (head->data == target) {
            printf("Target found!\n");
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
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    search(head, 30);
    search(head, 60);

    return 0;
}