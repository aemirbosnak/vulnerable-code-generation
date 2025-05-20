//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct node* head) {
    struct node* curr = head;
    while (curr!= NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    // Create a new node with value 10
    struct node* newNode = createNode(10);
    head = newNode;

    // Create a new node with value 20
    newNode = createNode(20);
    newNode->next = head;
    head = newNode;

    // Create a new node with value 30
    newNode = createNode(30);
    newNode->next = newNode->next;
    head = newNode;

    printf("Linked List: ");
    printList(head);

    // Remove the last node from the list
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
    printf("\n");

    printf("Linked List after removing the last node: ");
    printList(head);

    return 0;
}