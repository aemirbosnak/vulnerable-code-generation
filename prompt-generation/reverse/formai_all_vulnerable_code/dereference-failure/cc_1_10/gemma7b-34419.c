//Gemma-7B DATASET v1.0 Category: Email Client ; Style: systematic
#include <stdio.h>
#include <string.h>

// Define the email client structure
typedef struct email_client {
    char *name;
    char *email_address;
    char *password;
    struct email_client *next;
} email_client;

// Function to create a new email client
email_client *create_email_client(char *name, char *email_address, char *password) {
    email_client *new_client = malloc(sizeof(email_client));
    new_client->name = strdup(name);
    new_client->email_address = strdup(email_address);
    new_client->password = strdup(password);
    new_client->next = NULL;
    return new_client;
}

// Function to add a new email client to the list
void add_email_client(email_client *head, email_client *new_client) {
    if (head == NULL) {
        head = new_client;
    } else {
        new_client->next = head;
        head = new_client;
    }
}

// Function to print the email client list
void print_email_client_list(email_client *head) {
    email_client *current = head;
    while (current) {
        printf("%s (%s) - %s\n", current->name, current->email_address, current->password);
        current = current->next;
    }
}

int main() {
    // Create a new email client
    email_client *client = create_email_client("John Doe", "john.doe@example.com", "secret");

    // Add the client to the list
    add_email_client(NULL, client);

    // Print the email client list
    print_email_client_list(client);

    return 0;
}