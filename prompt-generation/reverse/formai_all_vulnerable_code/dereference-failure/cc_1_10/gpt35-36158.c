//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
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

    printf("Original Linked List: ");
    printList(head);

    //inserting a new node at the beginning
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 4;
    newNode->next = head;
    printf("\n\nInserting a new node at the beginning\n");
    printf("Linked List after Insertion: ");
    printList(newNode);

    //deleting the second node
    struct Node* temp = second;
    free(temp);
    head->next = third;
    printf("\n\nDeleting the second node\n");
    printf("Linked List after Deletion: ");
    printList(head);

    return 0;
}