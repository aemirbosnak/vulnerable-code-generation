//FormAI DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
Node *insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the linked list
Node *insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node from the beginning of the linked list
Node *deleteFromBeginning(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the linked list
Node *deleteFromEnd(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node *temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return head;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
    return head;
}

// Function to display the linked list
void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int choice, data;
    do {
        printf("1. Insert at beginning.\n");
        printf("2. Insert at end.\n");
        printf("3. Delete from beginning.\n");
        printf("4. Delete from end.\n");
        printf("5. Display list.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                head = deleteFromBeginning(head);
                break;
            case 4:
                head = deleteFromEnd(head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}