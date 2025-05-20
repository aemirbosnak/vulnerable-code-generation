//FormAI DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initialize the linked list
void initializeList(Node **head) {
    *head = NULL;
}

// Insert node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert node at the end of the list
void insertAtEnd(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
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

// Insert node at a specific position in the list
void insertAtPosition(Node **head, int data, int position) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        int i = 1;

        while (i < position - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Delete node from the beginning of the list
void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty!");
    } else {
        Node *current = *head;
        *head = (*head)->next;
        free(current);
    }
}

// Delete node from the end of the list
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty!");
    } else {
        if ((*head)->next == NULL) {
            free(*head);
            *head = NULL;
        } else {
            Node *current = *head;

            while (current->next->next != NULL) {
                current = current->next;
            }

            free(current->next);
            current->next = NULL;
        }
    }
}

// Delete node from a specific position in the list
void deleteFromPosition(Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty!");
    } else {
        Node *current = *head;
        int i = 1;

        if (position == 1) {
            *head = (*head)->next;
            free(current);
        } else {
            while (i < position - 1 && current->next->next != NULL) {
                current = current->next;
                i++;
            }

            Node *toDelete = current->next;
            current->next = current->next->next;
            free(toDelete);
        }
    }
}

// Print the linked list
void printList(Node *head) {
    if (head == NULL) {
        printf("List is empty!");
    } else {
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
    }
}

// Main function
int main() {
    Node *head;
    initializeList(&head);

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original list: ");
    printList(head);

    insertAtBeginning(&head, 0);
    printf("\nList after inserting 0 at the beginning: ");
    printList(head);

    insertAtPosition(&head, 9, 4);
    printf("\nList after inserting 9 at position 4: ");
    printList(head);

    deleteFromBeginning(&head);
    printf("\nList after deleting from the beginning: ");
    printList(head);

    deleteFromEnd(&head);
    printf("\nList after deleting from the end: ");
    printList(head);

    deleteFromPosition(&head, 3);
    printf("\nList after deleting from position 3: ");
    printList(head);

    return 0;
}