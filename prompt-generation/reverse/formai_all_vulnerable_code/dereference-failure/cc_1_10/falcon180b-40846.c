//Falcon-180B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for a node in the linked list
struct node {
    char *data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(char *data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = (char *) malloc(strlen(data) + 1);
    if (new_node->data == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the linked list
void add_node(struct node **head, char *data) {
    struct node *new_node = create_node(data);
    struct node *last_node = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *current_node = head;
    while (current_node!= NULL) {
        printf("%s -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Function to free the memory used by the linked list
void free_list(struct node *head) {
    struct node *current_node = head;
    while (current_node!= NULL) {
        free(current_node->data);
        free(current_node);
        current_node = current_node->next;
    }
}

int main() {
    struct node *head = NULL;
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        char string[10];
        sprintf(string, "%d", i);
        add_node(&head, string);
    }
    printf("Original list:\n");
    print_list(head);
    free_list(head);
    printf("List after freeing memory:\n");
    print_list(head);
    return 0;
}