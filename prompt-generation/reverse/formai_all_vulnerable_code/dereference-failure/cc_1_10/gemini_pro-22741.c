//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program manages a mailing list.
// It can add, remove, and print the list of email addresses.

// The maximum number of email addresses that can be stored in the list.
#define MAX_EMAILS 100

// The structure of an email address.
typedef struct email {
    char *address;
    struct email *next;
} email;

// The head of the mailing list.
email *head = NULL;

// Add an email address to the mailing list.
void add_email(char *address) {
    // Create a new email address.
    email *new_email = malloc(sizeof(email));
    new_email->address = strdup(address);
    new_email->next = NULL;

    // Add the new email address to the mailing list.
    if (head == NULL) {
        head = new_email;
    } else {
        email *current_email = head;
        while (current_email->next != NULL) {
            current_email = current_email->next;
        }
        current_email->next = new_email;
    }
}

// Remove an email address from the mailing list.
void remove_email(char *address) {
    // Find the email address to remove.
    email *current_email = head;
    email *previous_email = NULL;
    while (current_email != NULL && strcmp(current_email->address, address) != 0) {
        previous_email = current_email;
        current_email = current_email->next;
    }

    // If the email address was found, remove it from the mailing list.
    if (current_email != NULL) {
        if (previous_email == NULL) {
            head = current_email->next;
        } else {
            previous_email->next = current_email->next;
        }
        free(current_email->address);
        free(current_email);
    }
}

// Print the mailing list.
void print_mailing_list() {
    // Print each email address in the mailing list.
    email *current_email = head;
    while (current_email != NULL) {
        printf("%s\n", current_email->address);
        current_email = current_email->next;
    }
}

// Get an email address from the user.
char *get_email_address() {
    // Prompt the user for an email address.
    printf("Enter an email address: ");

    // Read the email address from the user.
    char *address = malloc(100);
    scanf("%s", address);

    // Return the email address.
    return address;
}

// The main function.
int main() {
    // Add some email addresses to the mailing list.
    add_email("john@example.com");
    add_email("mary@example.com");
    add_email("bob@example.com");

    // Print the mailing list.
    printf("Mailing list:\n");
    print_mailing_list();

    // Get an email address from the user and add it to the mailing list.
    char *address = get_email_address();
    add_email(address);

    // Print the mailing list again.
    printf("Mailing list:\n");
    print_mailing_list();

    // Remove an email address from the mailing list.
    remove_email("bob@example.com");

    // Print the mailing list again.
    printf("Mailing list:\n");
    print_mailing_list();

    return 0;
}