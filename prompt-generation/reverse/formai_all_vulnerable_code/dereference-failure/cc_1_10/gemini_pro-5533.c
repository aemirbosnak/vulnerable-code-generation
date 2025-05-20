//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Defining the node structure
struct node {
    int data;
    struct node *next;
};
// Initializing the head of the linked list
struct node *head = NULL;
// Function to insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
// Function to insert a node at the end of the linked list
void insert_at_end(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
// Function to insert a node at a specific position in the linked list
void insert_at_position(int data, int position) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (position == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
// Function to delete a node from the beginning of the linked list
void delete_from_beginning() {
    if (head == NULL) {
        printf("Linked list is empty!\n");
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
// Function to delete a node from the end of the linked list
void delete_from_end() {
    if (head == NULL) {
        printf("Linked list is empty!\n");
    } else {
        struct node *temp = head;
        struct node *prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            head = NULL;
        } else {
            prev->next = NULL;
        }
        free(temp);
    }
}
// Function to delete a node from a specific position in the linked list
void delete_from_position(int position) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
    } else {
        struct node *temp = head;
        struct node *prev = NULL;
        for (int i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}
// Function to search for a node in the linked list
int search(int data) {
    struct node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}
// Function to print the linked list
void print_list() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Driver code
int main() {
    // Inserting nodes at the beginning of the linked list
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_beginning(30);
    // Inserting nodes at the end of the linked list
    insert_at_end(40);
    insert_at_end(50);
    insert_at_end(60);
    // Inserting a node at a specific position in the linked list
    insert_at_position(70, 4);
    // Printing the linked list
    printf("Linked list: ");
    print_list();
    // Deleting a node from the beginning of the linked list
    delete_from_beginning();
    // Deleting a node from the end of the linked list
    delete_from_end();
    // Deleting a node from a specific position in the linked list
    delete_from_position(3);
    // Printing the linked list
    printf("Linked list after deletions: ");
    print_list();
    // Searching for a node in the linked list
    int data = 50;
    int position = search(data);
    if (position == -1) {
        printf("Node not found!\n");
    } else {
        printf("Node found at position: %d\n", position);
    }
    return 0;
}