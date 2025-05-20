//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
struct node {
    char data[MAX_SIZE];
    struct node* next;
};

// Function to create a new node
struct node* newNode(char* data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

// Function to search for a string in the linked list
struct node* search(struct node* head, char* str) {
    struct node* curr = head;
    while (curr!= NULL) {
        if (strcmp(curr->data, str) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* curr = head;
    while (curr!= NULL) {
        printf("%s -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create a linked list with 5 nodes
    struct node* head = NULL;
    head = newNode("apple");
    head->next = newNode("banana");
    head->next->next = newNode("cherry");
    head->next->next->next = newNode("date");
    head->next->next->next->next = newNode("elderberry");

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Search for a string in the linked list
    char* str = "banana";
    struct node* result = search(head, str);
    if (result!= NULL) {
        printf("'%s' found at position %d\n", str, 1);
    } else {
        printf("'%s' not found in the list\n", str);
    }

    return 0;
}