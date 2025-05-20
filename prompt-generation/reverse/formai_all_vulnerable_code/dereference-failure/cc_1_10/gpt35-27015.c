//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
// Hello there, it's great to see you today! I am thrilled to show you a unique program that demonstrates the operations of a linked list in C. 
// Before we begin, let me tell you that we'll be implementing the famous Singly Linked List  in this program.
// So, let's get started!

#include <stdio.h>
#include <stdlib.h>

// let's define the struct of the node that will be used in the linked list
struct node {
    int data;
    struct node *next;
};

// First things first, let's implement the function for creating a new node
struct node *createNode(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    } else {
        newNode->data = data;
        newNode->next = NULL;
    }
    printf("New node created successfully!\n\n");
    return newNode;
}

// Now, let's implement the function for inserting a node at the beginning of the linked list
void insertAtBeginning(struct node **head, int data) {
    struct node *newHead = createNode(data);
    newHead->next = *head;
    *head = newHead;
    printf("Node with value %d was inserted at the beginning of the linked list successfully!\n\n", data);
}

// Let's implement the function for inserting a node at the end of the linked list
void insertAtEnd(struct node **head, int data) {
    struct node *temp = *head;
    struct node *newTail = createNode(data);
    if (*head == NULL) {
        *head = newTail;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTail;
    }
    printf("Node with value %d was inserted at the end of the linked list successfully!\n\n", data);
}

// Let's implement the function for inserting a node at a specific position of the linked list
void insertAtPosition(struct node **head, int data, int position) {
    int i;
    struct node *temp = *head;
    struct node *newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node with value %d was inserted at position %d of the linked list successfully!\n\n", data, position);
    } else {
        for (i = 1; i < position - 1; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("Position %d does not exist in the linked list. Node insertion failed!\n\n", position);
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node with value %d was inserted at position %d of the linked list successfully!\n\n", data, position);
    }
}

// Let's implement the function for deleting the first node of the linked list
void deleteFirstNode(struct node **head) {
    if (*head == NULL) {
        printf("Linked list is already empty. Node deletion failed!\n\n");
    } else {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("First node of the linked list was deleted successfully!\n\n");
    }
}

// Let's implement the function for deleting the last node of the linked list
void deleteLastNode(struct node **head) {
    if (*head == NULL) {
        printf("Linked list is already empty. Node deletion failed!\n\n");
    } else {
        struct node *temp = *head;
        struct node *prev = *head;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("Last node of the linked list was deleted successfully!\n\n");
    }
}

// Let's implement the function for deleting a node at a specific position of the linked list
void deleteNodeAtPosition(struct node **head, int position) {
    int i;
    struct node *temp = *head;
    struct node *prev;
    if (*head == NULL) {
        printf("Linked list is already empty. Node deletion failed!\n\n");
    } else if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Node at position %d of the linked list was deleted successfully!\n\n", position);
    } else {
        for (i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == NULL) {
                printf("Position %d does not exist in the linked list. Node deletion failed!\n\n", position);
                return;
            }
        }
        prev->next = temp->next;
        free(temp);
        printf("Node at position %d of the linked list was deleted successfully!\n\n", position);
    }
}

// Let's implement the function for displaying the linked list
void displayLinkedList(struct node *head) {
    printf("\nDisplaying the linked list:\n\n");
    if (head == NULL) {
        printf("Linked list is empty!\n\n");
    } else {
        struct node *temp = head;
        printf("%d ", temp->data);
        while (temp->next != NULL) {
            temp = temp->next;
            printf("%d ", temp->data);
        }
        printf("\n\n");
    }
}

// Main function to test the above functions
int main() {
    struct node *head = NULL;

    // Let's insert some nodes at the beginning
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    displayLinkedList(head);

    // Let's insert some nodes at the end
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);
    displayLinkedList(head);

    // Let's insert some nodes at specific positions
    insertAtPosition(&head, 35, 1);
    insertAtPosition(&head, 40, 6);
    insertAtPosition(&head, 50, 8);
    displayLinkedList(head);

    // Let's delete some nodes
    deleteFirstNode(&head);
    deleteLastNode(&head);
    deleteNodeAtPosition(&head, 3);
    displayLinkedList(head);

    return 0;
}