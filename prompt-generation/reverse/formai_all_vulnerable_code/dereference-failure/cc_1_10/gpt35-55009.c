//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define structure for node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert node at the beginning of list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning.\n");
    return head;
}

// Function to insert node at the end of list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at end.\n");
    return head;
}

// Function to delete node from beginning of list
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        Node* temp = head;
        head = head->next;
        printf("Node deleted from beginning.\n");
        free(temp);
    }
    return head;
}

// Function to delete node from end of list
Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        if (head->next == NULL) {
            printf("Node deleted from end.\n");
            free(head);
            head = NULL;
        } else {
            Node* secondLastNode = head;
            while (secondLastNode->next->next != NULL) {
                secondLastNode = secondLastNode->next;
            }
            Node* lastNode = secondLastNode->next;
            secondLastNode->next = NULL;
            printf("Node deleted from end.\n");
            free(lastNode);
        }
    }
    return head;
}

// Function to display the list
void display(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("The list is: ");
        Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    int choice, data;
    do {
        printf("\n");
        printf("1: Insert node at beginning\n");
        printf("2: Insert node at end\n");
        printf("3: Delete node from beginning\n");
        printf("4: Delete node from end\n");
        printf("5: Display the list\n");
        printf("0: Exit\n");
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
            display(head);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
    printf("Goodbye!\n");
    return 0;
}