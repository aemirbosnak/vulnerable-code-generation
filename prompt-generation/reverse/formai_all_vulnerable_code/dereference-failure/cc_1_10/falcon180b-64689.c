//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function prototypes
Node *create_node(char *data);
void add_node(Node **head, char *data);
void print_list(Node *head);
void free_list(Node *head);

int main() {
    // Test case
    Node *head = NULL;
    add_node(&head, "Hello");
    add_node(&head, "World");
    print_list(head);
    free_list(head);

    return 0;
}

// Function to create a new node with given data
Node *create_node(char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the list
void add_node(Node **head, char *data) {
    Node *new_node = create_node(data);
    Node *temp = *head;

    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = new_node;
}

// Function to print the list
void print_list(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
}

// Function to free the memory allocated for the list
void free_list(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        free(temp->data);
        free(temp);
        temp = temp->next;
    }
}