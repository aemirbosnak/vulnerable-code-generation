//FormAI DATASET v1.0 Category: Data structures visualization ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node *insertSorted(Node *head, int value) {
    Node *newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    if (value < head->value) {
        newNode->next = head;
        return newNode;
    }
    Node *current = head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    printf("Welcome to the Linked List Visualization Program!\n");

    Node *head = NULL;
    int input = 0;

    while (input != -1) {
        printf("Enter a value to insert (-1 to exit): ");
        scanf("%d", &input);
        if (input != -1) {
            head = insertSorted(head, input);
            printList(head);
        }
    }

    printf("Thanks for using the Linked List Visualization Program!\n");
    return 0;
}