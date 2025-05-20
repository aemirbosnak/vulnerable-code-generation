//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by key
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Function to find the length of the linked list
int lengthOfList(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Main function to demonstrate linked list operations
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Print List\n");
        printf("5. Reverse List\n");
        printf("6. Length of List\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data of node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("Current Linked List: ");
                printList(head);
                break;
            case 5:
                reverseList(&head);
                printf("Linked List Reversed.\n");
                break;
            case 6:
                printf("Length of List: %d\n", lengthOfList(head));
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}