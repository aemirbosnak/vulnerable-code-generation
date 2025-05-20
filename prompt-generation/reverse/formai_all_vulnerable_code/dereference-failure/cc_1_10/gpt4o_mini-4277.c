//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void appendNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to delete a node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;
    
    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If the key was not present in the linked list
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    
    // Unlink the node from the linked list
    prev->next = temp->next;
    
    free(temp); // Free memory
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to search for a node by value
void searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("Node with value %d found.\n", key);
            return;
        }
        current = current->next;
    }
    printf("Node with value %d not found in the list.\n", key);
}

// Main function to drive the program
int main() {
    struct Node* head = NULL;
    int choice, value;
    
    printf("Welcome to the Linked List Program!\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Append Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Search Node\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                scanf("%d", &value);
                appendNode(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(head, value);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}