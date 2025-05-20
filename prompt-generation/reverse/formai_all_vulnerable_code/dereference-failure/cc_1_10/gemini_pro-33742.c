//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a node in a linked list that stores a single email address.
struct email_node {
    char *email;
    struct email_node *next;
};

// This is the mailing list, which is a linked list of email nodes.
struct mailing_list {
    struct email_node *head;
    struct email_node *tail;
    int size;
};

// Create a new mailing list.
struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Add an email address to the mailing list.
void add_email(struct mailing_list *list, char *email) {
    // Create a new email node.
    struct email_node *node = malloc(sizeof(struct email_node));
    node->email = malloc(strlen(email) + 1);
    strcpy(node->email, email);
    node->next = NULL;

    // Add the new node to the end of the list.
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

// Remove an email address from the mailing list.
void remove_email(struct mailing_list *list, char *email) {
    // Find the node with the given email address.
    struct email_node *current = list->head;
    while (current != NULL && strcmp(current->email, email) != 0) {
        current = current->next;
    }

    // If the node was found, remove it from the list.
    if (current != NULL) {
        if (current == list->head) {
            list->head = current->next;
        } else {
            struct email_node *previous = list->head;
            while (previous->next != current) {
                previous = previous->next;
            }
            previous->next = current->next;
        }
        free(current->email);
        free(current);
        list->size--;
    }
}

// Print the mailing list.
void print_mailing_list(struct mailing_list *list) {
    struct email_node *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Free the memory used by the mailing list.
void free_mailing_list(struct mailing_list *list) {
    struct email_node *current = list->head;
    while (current != NULL) {
        struct email_node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    free(list);
}

// The main function.
int main() {
    // Create a new mailing list.
    struct mailing_list *list = create_mailing_list();

    // Add some email addresses to the list.
    add_email(list, "john@example.com");
    add_email(list, "mary@example.com");
    add_email(list, "bob@example.com");

    // Print the mailing list.
    printf("The mailing list:\n");
    print_mailing_list(list);

    // Remove an email address from the list.
    remove_email(list, "bob@example.com");

    // Print the mailing list again.
    printf("\nThe mailing list after removing bob@example.com:\n");
    print_mailing_list(list);

    // Free the memory used by the mailing list.
    free_mailing_list(list);

    return 0;
}