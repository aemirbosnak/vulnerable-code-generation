//Falcon-180B DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// function prototypes
void push(Node** head, int data);
void pop(Node** head);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // push some elements onto the stack
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    // print the stack
    printf("Stack:\n");
    printList(head);

    // pop some elements off the stack
    pop(&head);
    pop(&head);

    // print the updated stack
    printf("\nStack after popping 2 elements:\n");
    printList(head);

    return 0;
}

// push an element onto the stack
void push(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// pop an element off the stack
void pop(Node** head) {
    if (*head == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// print the elements in the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack:\n");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}