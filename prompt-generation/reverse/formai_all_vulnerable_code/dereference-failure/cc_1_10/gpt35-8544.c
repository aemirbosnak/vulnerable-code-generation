//FormAI DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Declare global head
Node* head;

// Function to insert a new node at the beginning of the linked list
void insert(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// Function to delete a node from the beginning of the linked list
void delete() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

// Function to print the linked list
void printList() {
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL; // Initially, the list is empty
    int choice, val;
    do {
        // Display the menu
        printf("\tMenu\n");
        printf("==============================\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}