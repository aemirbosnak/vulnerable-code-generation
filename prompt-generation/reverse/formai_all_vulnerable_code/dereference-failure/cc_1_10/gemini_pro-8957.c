//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void printList(Node *head) {
    printf("The list is: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtHead(Node **head, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node **head, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAfter(Node *prev, int data) {
    if (prev == NULL) {
        printf("Previous node cannot be null.\n");
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

void deleteAtHead(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtTail(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void deleteNode(Node **head, Node *node) {
    if (*head == NULL || node == NULL) {
        printf("List or node is empty.\n");
        return;
    }

    if (node == *head) {
        deleteAtHead(head);
        return;
    }

    Node *current = *head;
    while (current->next != node) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Node not found.\n");
        return;
    }

    current->next = node->next;
    free(node);
}

int main() {
    Node *head = NULL;

    printf("Inserting 10, 20, 30, 40, 50 at the head.\n");
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    insertAtHead(&head, 40);
    insertAtHead(&head, 50);
    printList(head);

    printf("Inserting 60, 70, 80, 90, 100 at the tail.\n");
    insertAtTail(&head, 60);
    insertAtTail(&head, 70);
    insertAtTail(&head, 80);
    insertAtTail(&head, 90);
    insertAtTail(&head, 100);
    printList(head);

    printf("Inserting 15 after node with data 10.\n");
    insertAfter(head->next, 15);
    printList(head);

    printf("Deleting node with data 10.\n");
    deleteNode(&head, head->next);
    printList(head);

    printf("Deleting node at head.\n");
    deleteAtHead(&head);
    printList(head);

    printf("Deleting node at tail.\n");
    deleteAtTail(&head);
    printList(head);

    printf("Freeing the list.\n");
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}