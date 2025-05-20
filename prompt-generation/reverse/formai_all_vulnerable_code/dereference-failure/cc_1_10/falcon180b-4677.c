//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char data[MAX_SIZE];
    struct node* next;
};

// Function to create a new node with given data
struct node* create_node(char* data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

// Function to search for a given string in the linked list
struct node* search(struct node* head, char* str) {
    struct node* curr_node = head;
    while (curr_node!= NULL) {
        if (strcmp(curr_node->data, str) == 0) {
            return curr_node;
        }
        curr_node = curr_node->next;
    }
    return NULL;
}

// Function to print the linked list
void print_list(struct node* head) {
    struct node* curr_node = head;
    while (curr_node!= NULL) {
        printf("%s -> ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct node* head = NULL;
    char str[MAX_SIZE];

    // Create a linked list with some strings
    head = create_node("apple");
    head->next = create_node("banana");
    head->next->next = create_node("cherry");
    head->next->next->next = create_node("date");

    // Get user input for search string
    printf("Enter a string to search: ");
    scanf("%s", str);

    // Search for the given string in the linked list
    struct node* result = search(head, str);

    // Print the linked list and the result of the search
    printf("Linked List:\n");
    print_list(head);
    if (result!= NULL) {
        printf("Found '%s' in the linked list.\n", result->data);
    } else {
        printf("'%s' not found in the linked list.\n", str);
    }

    return 0;
}