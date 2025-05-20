//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of linked list
Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert at the end of linked list
Node* insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    Node *temp = head;

    // Check if the linked list is empty
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse the linked list till the end
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert at the end
    temp->next = newNode;
    return head;
}

// Function to insert at a given position in linked list
Node* insertAtPosition(Node *head, int data, int position) {
    Node *newNode = createNode(data);
    Node *temp = head;

    // Check if the position is valid
    if (position <= 0) {
        printf("Invalid position!\n");
        return head;
    }

    // Check if the linked list is empty
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse the linked list till the position
    for (int i = 1; i < position-1; i++) {
        temp = temp->next;

        // If the position is invalid
        if (temp == NULL) {
            printf("Invalid position!\n");
            return head;
        }
    }

    // Insert at the given position
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete from the beginning of linked list
Node* deleteFromBeginning(Node *head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return head;
    }

    Node *temp = head->next;
    free(head);
    return temp;
}

// Function to delete from the end of linked list
Node* deleteFromEnd(Node *head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    // Traverse the linked list till the end
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Delete the last node
    if (prev == NULL) {
        free(temp);
        return NULL;
    }
    else {
        prev->next = NULL;
        free(temp);
        return head;
    }
}

// Function to delete from a given position in linked list
Node* deleteFromPosition(Node *head, int position) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return head;
    }

    // Check if the position is valid
    if (position <= 0) {
        printf("Invalid position!\n");
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    // Traverse the linked list till the position
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;

        // If the position is invalid
        if (temp == NULL) {
            printf("Invalid position!\n");
            return head;
        }
    }

    // Delete the node at the given position
    if (prev == NULL) {
        head = temp->next;
        free(temp);
        return head;
    }
    else {
        prev->next = temp->next;
        free(temp);
        return head;
    }
}

// Function to display the linked list
void display(Node *head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node *head = NULL;
    int choice, data, position;

    // Display the menu
    printf("Cyberpunk Linked List Operations\n");
    printf("--------------------------------\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete from position\n");
    printf("7. Display\n");
    printf("8. Exit\n");

    // Iterate until the user chooses to exit
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("%d is inserted at the beginning\n\n", data);
                break;

            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("%d is inserted at the end\n\n", data);
                break;

            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                printf("%d is inserted at position %d\n\n", data, position);
                break;

            case 4:
                head = deleteFromBeginning(head);
                printf("Node is deleted from the beginning\n\n");
                break;

            case 5:
                head = deleteFromEnd(head);
                printf("Node is deleted from the end\n\n");
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                printf("Node is deleted from position %d\n\n", position);
                break;

            case 7:
                display(head);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n\n");
        }
    }

    return 0;
}