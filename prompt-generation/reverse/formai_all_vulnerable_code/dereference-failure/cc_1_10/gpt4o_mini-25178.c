//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void displayList(struct Node* node);
void searchList(struct Node* node, int key);

int main() {
    struct Node* head = NULL; // Initialize the head of the linked list
    int choice, value;

    // Simple menu-driven interface
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at end\n");
        printf("2. Delete a node\n");
        printf("3. Display list\n");
        printf("4. Search for a value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Current Linked List: ");
                displayList(head);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchList(head, value);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to create a new node and return its pointer
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end of the list.\n", data);
}

// Function to delete a node with the given key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        printf("Deleted %d from the list.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next; // Unlink the node from the list
    free(temp); // Free memory
    printf("Deleted %d from the list.\n", key);
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the linked list
void searchList(struct Node* node, int key) {
    int found = 0;
    while (node != NULL) {
        if (node->data == key) {
            found = 1;
            break;
        }
        node = node->next;
    }
    if (found) {
        printf("Value %d found in the list.\n", key);
    } else {
        printf("Value %d not found in the list.\n", key);
    }
}