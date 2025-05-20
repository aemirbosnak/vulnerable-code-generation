//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list
struct node {
    char *name;
    int balance;
    struct node *next;
};

// The head of the linked list
struct node *head = NULL;

// Create a new node
struct node *create_node(char *name, int balance) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->name = strdup(name);
    new_node->balance = balance;
    new_node->next = NULL;
    return new_node;
}

// Add a new node to the linked list
void add_node(char *name, int balance) {
    struct node *new_node = create_node(name, balance);
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Find a node in the linked list by name
struct node *find_node(char *name) {
    struct node *current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->name, name) == 0) {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// Delete a node from the linked list by name
void delete_node(char *name) {
    struct node *current_node = head;
    struct node *previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->name, name) == 0) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node->name);
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

// Print the linked list
void print_list() {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->name, current_node->balance);
        current_node = current_node->next;
    }
}

// Free the linked list
void free_list() {
    struct node *current_node = head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node->name);
        free(current_node);
        current_node = next_node;
    }
    head = NULL;
}

int main() {
    // Add some nodes to the linked list
    add_node("Alice", 100);
    add_node("Bob", 200);
    add_node("Carol", 300);

    // Print the linked list
    print_list();

    // Find a node in the linked list
    struct node *node = find_node("Bob");
    if (node != NULL) {
        printf("Found node: %s, balance: %d\n", node->name, node->balance);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the linked list
    delete_node("Carol");

    // Print the linked list
    print_list();

    // Free the linked list
    free_list();

    return 0;
}