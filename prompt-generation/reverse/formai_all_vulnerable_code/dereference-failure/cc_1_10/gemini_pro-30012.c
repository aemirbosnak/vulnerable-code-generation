//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple linked list to store passwords
typedef struct {
    char *site;
    char *username;
    char *password;
    struct node *next;
} node;

// Create a new node
node *create_node(char *site, char *username, char *password) {
    node *new_node = malloc(sizeof(node));
    new_node->site = strdup(site);
    new_node->username = strdup(username);
    new_node->password = strdup(password);
    new_node->next = NULL;
    return new_node;
}

// Add a new node to the list
void add_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Find a node in the list
node *find_node(node *head, char *site) {
    while (head != NULL) {
        if (strcmp(head->site, site) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Delete a node from the list
void delete_node(node **head, node *node_to_delete) {
    if (*head == node_to_delete) {
        *head = node_to_delete->next;
        free(node_to_delete->site);
        free(node_to_delete->username);
        free(node_to_delete->password);
        free(node_to_delete);
    } else {
        node *current = *head;
        while (current->next != node_to_delete) {
            current = current->next;
        }
        current->next = node_to_delete->next;
        free(node_to_delete->site);
        free(node_to_delete->username);
        free(node_to_delete->password);
        free(node_to_delete);
    }
}

// Print the list
void print_list(node *head) {
    while (head != NULL) {
        printf("%s %s %s\n", head->site, head->username, head->password);
        head = head->next;
    }
}

// Free the list
void free_list(node *head) {
    while (head != NULL) {
        node *next = head->next;
        free(head->site);
        free(head->username);
        free(head->password);
        free(head);
        head = next;
    }
}

// Main function
int main() {
    // Create a new list
    node *head = NULL;

    // Add some nodes to the list
    add_node(&head, create_node("google.com", "username1", "password1"));
    add_node(&head, create_node("facebook.com", "username2", "password2"));
    add_node(&head, create_node("twitter.com", "username3", "password3"));

    // Print the list
    print_list(head);

    // Find a node in the list
    node *google_node = find_node(head, "google.com");

    // Delete a node from the list
    delete_node(&head, google_node);

    // Print the list again
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}