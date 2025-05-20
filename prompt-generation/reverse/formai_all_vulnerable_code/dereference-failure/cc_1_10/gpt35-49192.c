//FormAI DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the linked list node
typedef struct Node {
    int data;
    struct Node *next;
} node;

// Function to add node at the beginning of the list
void push(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to add node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be null\n");
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to add node at the end of the list
void append(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    node *last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to delete a node from the list
void delete_node(node **head, int key) {
    node *temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void print_list(node *head) {
    node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    node *head = NULL;
    int choice = 0, data = 0, key = 0;
    while(1) {
        printf("Choose an operation:\n1. Add node at the beginning\n2. Add node after a given node\n3. Add node at the end\n4. Delete a node\n5. Print the list\n6. Quit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data:\n");
                scanf("%d", &data);
                push(&head, data);
                printf("%d added to the beginning of the list\n", data);
                break;
            case 2:
                printf("Enter the data of the previous node:\n");
                scanf("%d", &key);
                printf("Enter the data:\n");
                scanf("%d", &data);
                insert_after(head, data);
                printf("%d added after %d\n", data, key);
                break;
            case 3:
                printf("Enter the data:\n");
                scanf("%d", &data);
                append(&head, data);
                printf("%d added to the end of the list\n", data);
                break;
            case 4:
                printf("Enter the data of the node to be deleted:\n");
                scanf("%d", &key);
                delete_node(&head, key);
                printf("%d deleted from the list\n", key);
                break;
            case 5:
                print_list(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}