//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found\n");
        return head;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 15);
    head = insertAtBeginning(head, 1);

    printf("Linked List: ");
    printList(head);

    head = deleteNode(head, 10);
    printf("After deleting 10: ");
    printList(head);

    head = deleteNode(head, 5);
    printf("After deleting 5: ");
    printList(head);

    head = deleteNode(head, 15);
    printf("After deleting 15: ");
    printList(head);

    head = deleteNode(head, 100);
    printf("After deleting 100: ");
    printList(head);

    return 0;
}