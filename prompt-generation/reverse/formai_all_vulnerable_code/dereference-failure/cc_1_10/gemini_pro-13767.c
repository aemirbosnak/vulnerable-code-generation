//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Create a node for the mailing list
typedef struct node {
    char *email;
    struct node *next;
} node;

// Create a new node with the given email address
node *new_node(char *email) {
    node *n = malloc(sizeof(node));
    n->email = strdup(email);
    n->next = NULL;
    return n;
}

// Add a new node to the mailing list
void add_node(node **head, node *new) {
    if (*head == NULL) {
        *head = new;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}

// Print the mailing list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Free the mailing list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
}

// Subscribe to the mailing list
void subscribe(node **head, char *email) {
    node *new = new_node(email);
    add_node(head, new);
}

// Unsubscribe from the mailing list
void unsubscribe(node **head, char *email) {
    node *current = *head;
    node *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->email);
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    node *head = NULL;

    // Subscribe some people to the mailing list
    subscribe(&head, "alice@example.com");
    subscribe(&head, "bob@example.com");
    subscribe(&head, "charlie@example.com");

    // Print the mailing list
    print_list(head);

    // Unsubscribe someone from the mailing list
    unsubscribe(&head, "bob@example.com");

    // Print the mailing list again
    print_list(head);

    // Free the mailing list
    free_list(head);

    return 0;
}