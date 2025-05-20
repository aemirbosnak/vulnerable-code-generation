//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Linked list node
struct node {
    char *email;
    struct node *next;
};

// Email client
struct email_client {
    struct node *head;
    int count;
};

// Function to create a new email client
struct email_client *new_email_client() {
    struct email_client *client = malloc(sizeof(struct email_client));
    client->head = NULL;
    client->count = 0;
    return client;
}

// Function to add an email to the client
void add_email(struct email_client *client, char *email) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->email = email;
    new_node->next = client->head;
    client->head = new_node;
    client->count++;
}

// Function to get an email from the client
char *get_email(struct email_client *client, int index) {
    if (index < 0 || index >= client->count) {
        return NULL;
    }
    struct node *current_node = client->head;
    for (int i = 0; i < index; i++) {
        current_node = current_node->next;
    }
    return current_node->email;
}

// Function to delete an email from the client
void delete_email(struct email_client *client, int index) {
    if (index < 0 || index >= client->count) {
        return;
    }
    if (index == 0) {
        client->head = client->head->next;
    } else {
        struct node *current_node = client->head;
        for (int i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        current_node->next = current_node->next->next;
    }
    client->count--;
}

// Function to print the client's emails
void print_emails(struct email_client *client) {
    struct node *current_node = client->head;
    while (current_node != NULL) {
        printf("%s\n", current_node->email);
        current_node = current_node->next;
    }
}

// Function to free the client's memory
void free_email_client(struct email_client *client) {
    struct node *current_node = client->head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node->email);
        free(current_node);
        current_node = next_node;
    }
    free(client);
}

// Main function
int main() {
    // Create a new email client
    struct email_client *client = new_email_client();

    // Add some emails to the client
    add_email(client, "alice@example.com");
    add_email(client, "bob@example.com");
    add_email(client, "charlie@example.com");

    // Get an email from the client
    char *email = get_email(client, 1);
    printf("The second email is: %s\n", email);

    // Delete an email from the client
    delete_email(client, 1);

    // Print the client's emails
    print_emails(client);

    // Free the client's memory
    free_email_client(client);

    return 0;
}