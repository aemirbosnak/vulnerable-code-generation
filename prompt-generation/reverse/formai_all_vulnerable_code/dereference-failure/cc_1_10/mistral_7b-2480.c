//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* reverseListRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* reversedList = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return reversedList;
}

int main() {
    Node* head = NULL;

    // Inserting elements at the beginning
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 15);
    printList(head); // Output: Linked List: 15 10 5

    // Inserting elements at the end
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 8);
    head = insertAtEnd(head, 12);
    printList(head); // Output: Linked List: 15 10 5 8 2

    // Reversing the linked list recursively
    head = reverseListRecursive(head);
    printList(head); // Output: Linked List: 2 8 5 10 15

    return 0;
}