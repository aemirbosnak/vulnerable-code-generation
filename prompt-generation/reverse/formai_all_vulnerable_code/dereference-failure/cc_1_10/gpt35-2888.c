//FormAI DATASET v1.0 Category: Linked list operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Insertion operation at the beginning of linked list
struct Node* insertBeginning(struct Node* head, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;

    // Update the head pointer
    head = newNode;

    return head;
}

// Insertion operation at the end of linked list
struct Node* insertEnd(struct Node* head, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the linked list is empty
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse to the end of the linked list
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Update the next pointer of last node
    current->next = newNode;

    return head;
}

// Deletion operation at the beginning of linked list
struct Node* deleteBeginning(struct Node* head) {
    // If the linked list is empty
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return head;
    }

    // Update the head pointer and free the memory
    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Deletion operation at the end of linked list
struct Node* deleteEnd(struct Node* head) {
    // If the linked list is empty
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return head;
    }

    // If linked list contains only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }

    // Traverse to the second last node of the linked list
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the last node and update the next pointer of second last node
    struct Node* temp = current->next;
    current->next = NULL;
    free(temp);

    return head;
}

// Display operation to print the linked list
void display(struct Node* head) {
    // If the linked list is empty
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    // Traverse through the linked list and print the node values
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;

    printf("1. Insert at beginning\n2. Insert at end\n3. Delete from beginning\n4. Delete from end\n5. Display\n6. Exit\n");

    while (1) {
        int choice, value;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insertBeginning(head, value);
                break;

            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;

            case 3:
                head = deleteBeginning(head);
                break;

            case 4:
                head = deleteEnd(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}