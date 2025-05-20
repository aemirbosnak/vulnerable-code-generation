//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Create a node
struct node {
    int data;
    struct node *next;
};

// Insert a node at the beginning of the list
void insertAtBeginning(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert a node at the end of the list
void insertAtEnd(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Insert a node after a given node
void insertAfter(struct node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be null");
        return;
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Delete a node from the beginning of the list
void deleteAtBeginning(struct node **head) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void deleteAtEnd(struct node **head) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete a node after a given node
void deleteAfter(struct node *prevNode) {
    if (prevNode == NULL) {
        printf("Previous node cannot be null");
        return;
    }

    if (prevNode->next == NULL) {
        printf("No node after the given node");
        return;
    }

    struct node *temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

// Print the list
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAfter(head, 30);
    insertAtBeginning(&head, 40);
    insertAtEnd(&head, 50);
    insertAfter(head->next->next, 60);

    printList(head);

    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteAfter(head->next);

    printList(head);

    return 0;
}