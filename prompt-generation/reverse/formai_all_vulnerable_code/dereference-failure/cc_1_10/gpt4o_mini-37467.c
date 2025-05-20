//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int value) {
    if (*head == NULL) {
        *head = createNode(value);
    } else {
        insertNode(&((*head)->next), value);
    }
}

void printList(Node *head) {
    if (head == NULL) {
        return;
    }
    printf("%d -> ", head->value);
    printList(head->next);
}

void freeList(Node *head) {
    if (head == NULL) {
        return;
    }
    freeList(head->next);
    free(head);
}

int computeSum(Node *head) {
    if (head == NULL) {
        return 0;
    }
    return head->value + computeSum(head->next);
}

int computeMax(Node *head) {
    if (head == NULL) {
        return -1; // Assuming values are non-negative
    }
    int maxInRest = computeMax(head->next);
    return (head->value > maxInRest) ? head->value : maxInRest;
}

void insertSorted(Node **head, int value) {
    if (*head == NULL || (*head)->value >= value) {
        Node *newNode = createNode(value);
        newNode->next = *head;
        *head = newNode;
    } else {
        insertSorted(&((*head)->next), value);
    }
}

void removeNode(Node **head, int value) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->value == value) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        removeNode(&((*head)->next), value);
    }
}

void reverseList(Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Node *rest = (*head)->next;
    reverseList(&rest);
    (*head)->next->next = *head;
    (*head)->next = NULL;
    *head = rest;
}

int main() {
    Node *head = NULL;

    // Inserting values into the list
    for (int i = 10; i > 0; i--) {
        insertNode(&head, i);
    }

    printf("Original List: ");
    printList(head);
    printf("NULL\n");

    // Computing sum
    int sum = computeSum(head);
    printf("Sum of elements: %d\n", sum);

    // Finding max
    int max = computeMax(head);
    printf("Maximum element: %d\n", max);

    // Inserting in sorted order
    insertSorted(&head, 5);
    printf("List after inserting 5 in sorted order: ");
    printList(head);
    printf("NULL\n");

    // Removing a node
    removeNode(&head, 5);
    printf("List after removing 5: ");
    printList(head);
    printf("NULL\n");

    // Reversing the list
    reverseList(&head);
    printf("Reversed List: ");
    printList(head);
    printf("NULL\n");

    // Freeing memory
    freeList(head);
    return 0;
}