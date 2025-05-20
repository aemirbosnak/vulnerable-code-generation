//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
    return (*head);
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = (*head);
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = newNode;
    return (*head);
}

// Function to delete a node from the linked list
struct Node* deleteNode(struct Node** head, int data) {
    struct Node* current = (*head);
    struct Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current!= NULL) {
        if (prev == NULL) {
            (*head) = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        return (*head);
    }
    return (*head);
}

// Function to reverse the linked list
struct Node* reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = (*head);
    struct Node* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head) = prev;
    return (*head);
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice;

    printf("Welcome to the Linked List Operations Program!\n");
    while (1) {
        printf("1. Insert at the beginning\n2. Insert at the end\n3. Delete a node\n4. Reverse the list\n5. Print the list\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertAtBeginning(&head, 10);
                break;
            case 2:
                head = insertAtEnd(&head, 20);
                break;
            case 3:
                head = deleteNode(&head, 10);
                break;
            case 4:
                head = reverseList(&head);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}