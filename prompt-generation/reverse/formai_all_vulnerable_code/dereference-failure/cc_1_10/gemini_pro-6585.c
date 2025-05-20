//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
void push(struct Node** head, int data) {
    struct Node *node = newNode(data);
    node->next = *head;
    *head = node;
}

// Function to print the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the linked list using recursion
struct Node* reverseList(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main() {
    struct Node *head = NULL;
    push(&head, 20);
    push(&head, 40);
    push(&head, 60);
    push(&head, 80);
    printf("Original Linked list: ");
    printList(head);
    head = reverseList(head);
    printf("Reversed Linked list: ");
    printList(head);
    return 0;
}