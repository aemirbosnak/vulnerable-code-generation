//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtEnd(Node** head, int data);
void displayList(Node* head);
void deleteNode(Node** head, int key);
void searchNode(Node* head, int key);

// Main function to run the cheerful linked list program
int main() {
    Node* head = NULL;
    int choice, value;

    printf("🎉 Welcome to the Happy Linked List Program! 🎉\n");
    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert at end\n");
        printf("2. Display list\n");
        printf("3. Delete a node\n");
        printf("4. Search for a node\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("✨ Inserted %d at the end of the list! ✨\n", value);
                break;
            case 2:
                printf("Here is your happy list: ");
                displayList(head);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                searchNode(head, value);
                break;
            case 5:
                printf("🎈 Thank you for using the Happy Linked List Program! 🎈\n");
                break;
            default:
                printf("Oops! Please select a valid option! 🌈\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty! 😢\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL 🌟\n");
}

// Function to delete a node by value
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;  // Change head
        free(temp);          // Free old head
        printf("🥳 Deleted %d from the list! 🥳\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("😞 %d not found in the list!\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);  // Free memory
    printf("🥳 Deleted %d from the list! 🥳\n", key);
}

// Function to search for a node by value
void searchNode(Node* head, int key) {
    Node* temp = head;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    
    if (found) {
        printf("🎉 Hooray! %d found in the list! 🎉\n", key);
    } else {
        printf("😢 Oh no! %d not found in the list!\n", key);
    }
}