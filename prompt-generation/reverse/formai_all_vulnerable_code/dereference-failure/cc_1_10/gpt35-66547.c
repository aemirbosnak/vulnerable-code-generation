//FormAI DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// define a struct to represent each node in the linked list
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// function to add a new node to the end of the linked list
void insertNode(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* node = *head;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = newNode;
    }
}

// function to delete a node from the linked list
void deleteNode(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->val == value) {
        Node* nodeToDelete = *head;
        *head = (*head)->next;
        free(nodeToDelete);
        printf("Node with value %d deleted successfully\n", value);
        return;
    }
    Node* node = *head;
    while (node->next != NULL && node->next->val != value) {
        node = node->next;
    }
    if (node->next == NULL) {
        printf("Node with value %d not found\n", value);
        return;
    }
    Node* nodeToDelete = node->next;
    node->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node with value %d deleted successfully\n", value);
}

// function to print the values of all nodes in the linked list
void printList(Node* head) {
    printf("List: ");
    Node* node = head;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    deleteNode(&head, 20);
    printList(head);
    return 0;
}