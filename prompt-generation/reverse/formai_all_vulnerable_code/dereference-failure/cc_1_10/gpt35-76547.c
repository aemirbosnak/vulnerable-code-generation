//FormAI DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define structs for LinkedList nodes and Stack elements
struct LinkedListNode {
    int value;
    struct LinkedListNode* next;
};

struct StackElement {
    int value;
    struct StackElement* next;
};

// Function to push a new element to the top of the stack
void push(struct StackElement** top, int value) {
    struct StackElement* newElement = (struct StackElement*) malloc(sizeof(struct StackElement));
    newElement->value = value;
    newElement->next = *top;
    *top = newElement;
}

// Function to pop the top element from the stack
int pop(struct StackElement** top) {
    if (*top == NULL) {
        printf("Error: Stack is empty!\n");
        return -1;
    }
    struct StackElement* elementToRemove = *top;
    int poppedValue = elementToRemove->value;
    *top = (*top)->next;
    free(elementToRemove);
    return poppedValue;
}

// Function to print out the current state of the LinkedList and Stack
void visualize(struct LinkedListNode* head, struct StackElement* top) {
    printf("\n========== Current State of Data Structures ==========\n");
    // Visualize LinkedList
    printf("LinkedList: ");
    struct LinkedListNode* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("NULL\n");

    // Visualize Stack
    printf("Stack: ");
    struct StackElement* currentElement = top;
    while (currentElement != NULL) {
        printf("%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    printf("\n");
}

int main() {
    // Create a simple LinkedList and push/pop elements from a Stack
    struct LinkedListNode* head = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
    head->value = 1;
    head->next = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
    head->next->value = 2;
    head->next->next = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
    head->next->next->value = 3;
    head->next->next->next = NULL;

    struct StackElement* top = NULL;
    push(&top, 3);
    push(&top, 2);
    push(&top, 1);
    pop(&top);

    // Visualize the current state of the data structures
    visualize(head, top);

    return 0;
}