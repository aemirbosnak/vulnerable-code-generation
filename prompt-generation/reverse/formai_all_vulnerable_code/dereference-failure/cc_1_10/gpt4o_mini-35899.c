//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new Node with cheerful data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    printf("🎉 New Node with data %d created! 🎉\n", data);
    return newNode;
}

// Add a node at the end of the linked list
void append(Node** head, int newData) {
    Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
        printf("Yay! Head Node added with value %d\n", newData);
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    printf("🎉 Node with value %d appended to the list! 🎈\n", newData);
}

// Display the entire linked list
void displayList(Node* node) {
    if (node == NULL) {
        printf("The list is empty! 😢\n");
        return;
    }
    printf("🌈 Here comes a joyful list: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL 🌟\n");
}

// Delete the first occurrence of a specific value
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("🎉 Node with value %d deleted from the head! 🎈\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("🎈 Node with value %d not found! Can't delete! ☹️\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("🎉 Node with value %d has been joyfully deleted! 🎊\n", key);
}

// Free the linked list
void freeList(Node* node) {
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
    printf("All nodes have been released into the wild! 🦋\n");
}

// Main function to demonstrate the linked list operations
int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n🎈 Welcome to the Linked List Adventure! 🎠\n");
        printf("1. Add a Node\n");
        printf("2. Display List\n");
        printf("3. Delete a Node\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to add: ");
                scanf("%d", &value);
                append(&head, value);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                freeList(head);
                printf("Goodbye! Hope to see you again in the Linked List Adventure! 🎉🌈\n");
                return 0;
            default:
                printf("Oops! That’s not a valid option! 🤔\n");
                break;
        }
    }

    return 0;
}