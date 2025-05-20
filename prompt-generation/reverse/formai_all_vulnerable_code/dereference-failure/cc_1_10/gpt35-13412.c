//FormAI DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("Initial linked list:\n");
    printList(head);

    // Adding a new node to the start of the linked list
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 0;
    newNode->next = head;
    head = newNode;

    printf("Linked list with new head:\n");
    printList(head);

    // Removing the second node from the linked list
    head->next = third;

    printf("Linked list with second node removed:\n");
    printList(head);

    return 0;
}