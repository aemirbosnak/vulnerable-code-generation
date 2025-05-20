//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

void printList(Node* head) {
    if (head != NULL) {
        printf("%d -> ", head->data);
        printList(head->next);
    }
}

void reverseListRecursive(Node** head) {
    Node* current = *head;
    Node* next = NULL;
    Node* previous = NULL;

    if (current == NULL || current->next == NULL) {
        *head = current;
        return;
    }

    reverseListRecursive(&(current->next));
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;

    *head = previous;
}

int main() {
    Node* head = NULL;

    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 20);

    printf("Original List: ");
    printList(head);

    reverseListRecursive(&head);

    printf("\nReversed List: ");
    printList(head);

    return EXIT_SUCCESS;
}