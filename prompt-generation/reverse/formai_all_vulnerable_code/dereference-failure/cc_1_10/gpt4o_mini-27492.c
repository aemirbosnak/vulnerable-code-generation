//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a single node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef, *prev = NULL;
    
    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }
    
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in the linked list
    if (temp == NULL) return;
    
    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to search for a node by value
int searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu-driven function for linked list operations
void menu() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (searchNode(head, data))
                    printf("Node with value %d found.\n", data);
                else
                    printf("Node with value %d not found.\n", data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}