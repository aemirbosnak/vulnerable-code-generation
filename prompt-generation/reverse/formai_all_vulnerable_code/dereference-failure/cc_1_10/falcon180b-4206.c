//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("\n%d is pushed to the stack", new_data);
}

// Function to add a node at the beginning of the list
void push2(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("\n%d is pushed to the stack", new_data);
}

// Function to remove a node from the beginning of the list
void pop(struct Node** head_ref) {
    struct Node* temp = (*head_ref);
    (*head_ref) = (*head_ref)->next;
    free(temp);
    printf("\nThe topmost element from the stack is popped");
}

// Function to check if the list is empty
int isEmpty(struct Node* head) {
    if (head == NULL)
        return 1;
    else
        return 0;
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    // Testing push function
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    // Testing pop function
    pop(&head);

    // Testing push2 function
    push2(&head, 50);

    // Testing printList function
    printf("\nList after pushing 50 at the beginning: ");
    printList(head);

    // Testing isEmpty function
    if (isEmpty(head))
        printf("\nList is empty");
    else
        printf("\nList is not empty");

    return 0;
}