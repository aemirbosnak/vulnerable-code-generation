//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void append(struct Node** head, int data) {
    struct Node* node = createNode(data);
    struct Node* temp = *head;
    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
    node->next = NULL;
    return;
}

// Function to add a node at the beginning of the list
void prepend(struct Node** head, int data) {
    struct Node* node = createNode(data);
    node->next = *head;
    *head = node;
    return;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element not found\n");
    } else {
        struct Node* node = temp->next;
        temp->next = temp->next->next;
        free(node);
    }
    return;
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data;
    while (1) {
        printf("1. Append\n2. Prepend\n3. Delete\n4. Print\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                prepend(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}