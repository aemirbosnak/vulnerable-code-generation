//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct FibonacciNode {
    int value;
    struct FibonacciNode *next;
} FibonacciNode;

FibonacciNode *createFibonacciNode(int value) {
    FibonacciNode *node = (FibonacciNode *)malloc(sizeof(FibonacciNode));
    node->value = value;
    node->next = NULL;
    return node;
}

void insertFibonacciNode(FibonacciNode **head, int value) {
    FibonacciNode *newNode = createFibonacciNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        FibonacciNode *currentNode = *head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void printFibonacciSequence(FibonacciNode *head) {
    FibonacciNode *currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    FibonacciNode *head = NULL;
    insertFibonacciNode(&head, 0);
    insertFibonacciNode(&head, 1);
    for (int i = 2; i < n; i++) {
        FibonacciNode *currentNode = head;
        FibonacciNode *previousNode = NULL;
        while (currentNode != NULL) {
            if (currentNode->next == NULL) {
                previousNode = currentNode;
            }
            currentNode = currentNode->next;
        }
        int newValue = previousNode->value + currentNode->value;
        insertFibonacciNode(&head, newValue);
    }

    printf("The Fibonacci sequence is: ");
    printFibonacciSequence(head);

    return 0;
}