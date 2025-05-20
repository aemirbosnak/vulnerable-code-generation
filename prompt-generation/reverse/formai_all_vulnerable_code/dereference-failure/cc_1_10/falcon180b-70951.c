//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct node {
    int data;
    int index;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int data, int index) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->index = index;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a node in the list
void insertNode(struct node **head, int data, int index) {
    struct node *newnode = createNode(data, index);
    newnode->next = *head;
    *head = newnode;
}

// Function to search for a node in the list
struct node *searchNode(struct node *head, int data) {
    struct node *current = head;
    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct node *head) {
    struct node *current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

// Function to sort the list
void sortList(struct node **head) {
    struct node *current = *head;
    struct node *temp;
    while (current!= NULL) {
        temp = current->next;
        while (temp!= NULL) {
            if (current->index > temp->index) {
                int tempdata = current->data;
                current->data = temp->data;
                temp->data = tempdata;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

int main() {
    struct node *head = NULL;

    // Insert nodes
    insertNode(&head, 5, 3);
    insertNode(&head, 2, 1);
    insertNode(&head, 8, 5);
    insertNode(&head, 1, 2);
    insertNode(&head, 4, 4);

    // Print the list
    printf("Original list:\n");
    printList(head);
    printf("\n");

    // Sort the list
    sortList(&head);

    // Print the sorted list
    printf("Sorted list:\n");
    printList(head);

    return 0;
}