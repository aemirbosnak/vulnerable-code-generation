//FormAI DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node and return a pointer to it
Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* node = createNode(data);
    node->next = *head;
    *head = node;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* node = createNode(data);

    // If the list is empty, make the new node the head
    if(*head == NULL) {
        *head = node;
        return;
    }

    // Traverse the list to the end and insert the new node
    Node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

// Function to delete the first node of the linked list
void deleteAtBeginning(Node** head) {
    if(*head == NULL) {
        printf("Error: List is empty!\n");
        return;
    }

    Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node of the linked list
void deleteAtEnd(Node** head) {
    if(*head == NULL) {
        printf("Error: List is empty!\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
}

// Function to display the linked list
void display(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Display linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteAtBeginning(&head);
                break;
            case 4:
                deleteAtEnd(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 6);

    return 0;
}