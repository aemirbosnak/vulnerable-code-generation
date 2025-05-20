//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
typedef struct node {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(node** headRef, int newData) {
    node* newNode = createNode(newData);
    node* temp = *headRef;
    newNode->next = temp;
    *headRef = newNode;
}

void printList(node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;

    // Push elements onto the stack
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    // Print the elements in the stack
    printf("Stack elements are: ");
    printList(head);

    // Pop an element from the stack
    node* temp = head;
    head = head->next;
    free(temp);

    // Print the elements in the stack after popping an element
    printf("Stack elements after popping an element are: ");
    printList(head);

    return 0;
}