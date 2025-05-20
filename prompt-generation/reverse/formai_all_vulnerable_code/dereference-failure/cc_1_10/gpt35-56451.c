//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printList(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Current Linked List:\n");
    printf("HEAD -> ");

    Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node **head, int data) {
    Node *newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;

    printf("Pushed %d onto the stack!\n\n", data);
}

void pop(Node **head) {
    if (*head == NULL) {
        printf("Cannot pop from an empty stack!\n\n");
        return;
    }

    Node *temp = *head;
    *head = temp->next;

    int data = temp->data;
    free(temp);

    printf("Popped %d from the stack!\n\n", data);
}

int main() {
    Node *stack = NULL;

    printf("Welcome to the Stack Data Structure Visualization!\n\n");

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printList(stack);

    pop(&stack);

    printList(stack);

    push(&stack, 4);
    push(&stack, 5);

    printList(stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    printList(stack);

    return 0;
}