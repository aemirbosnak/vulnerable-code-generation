//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Struct for the linked list nodes
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the front of the linked list
void addFront(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
    printf("Added %d to the front of list.\n", data);
}

// Function to add a new node at the end of the linked list
void addEnd(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
    printf("Added %d to the end of list.\n", data);
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* temp_node = *head, *prev_node = NULL;
    if (temp_node != NULL && temp_node->data == key) {
        *head = temp_node->next;
        free(temp_node);
        printf("Deleted %d from the list.\n", key);
        return;
    }
    while (temp_node != NULL && temp_node->data != key) {
        prev_node = temp_node;
        temp_node = temp_node->next;
    }
    if (temp_node == NULL) {
        printf("%d not found in the list. Cannot delete.\n", key);
        return;
    }
    prev_node->next = temp_node->next;
    free(temp_node);
    printf("Deleted %d from the list.\n", key);
}

// Function to print the linked list
void printList(struct Node* node) {
    printf("Current list: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Declaring the head pointer as NULL to start with an empty linked list
    printf("Welcome to the Linked List Manager!\n");
    printf("Type 'A' to add a node to the front of the list.\n");
    printf("Type 'B' to add a node to the end of the list.\n");
    printf("Type 'D' to delete a node from the list.\n");
    printf("Type 'P' to print the current list.\n");
    printf("Type 'Q' to quit the program.\n\n");
    char option = ' ';
    int data = 0;
    while (option != 'Q') {
        printf("Enter your selection: ");
        scanf(" %c", &option);
        if (option == 'A') {
            printf("Enter data to add to the front of the list: ");
            scanf("%d", &data);
            addFront(&head, data);
        } else if (option == 'B') {
            printf("Enter data to add to the end of the list: ");
            scanf("%d", &data);
            addEnd(&head, data);
        } else if (option == 'D') {
            printf("Enter data to delete from the list: ");
            scanf("%d", &data);
            deleteNode(&head, data);
        } else if (option == 'P') {
            printList(head);
        } else if (option == 'Q') {
            printf("Goodbye!\n");
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }
    return 0;
}