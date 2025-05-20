//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a name or email address
#define MAX_LENGTH 100

// Define the structure of a subscriber
typedef struct subscriber {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    struct subscriber *next;
} subscriber;

// Define the head of the mailing list
subscriber *head = NULL;

// Function to add a subscriber to the mailing list
void add_subscriber(char *name, char *email) {
    // Create a new subscriber
    subscriber *new_subscriber = malloc(sizeof(subscriber));

    // Copy the name and email address into the new subscriber
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);

    // Set the next pointer of the new subscriber to the head of the mailing list
    new_subscriber->next = head;

    // Set the head of the mailing list to the new subscriber
    head = new_subscriber;
}

// Function to remove a subscriber from the mailing list
void remove_subscriber(char *email) {
    // Check if the mailing list is empty
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    // Check if the subscriber is the head of the mailing list
    if (strcmp(head->email, email) == 0) {
        // Set the head of the mailing list to the next subscriber
        head = head->next;

        // Free the memory allocated for the subscriber
        free(head);
        return;
    }

    // Find the subscriber to remove
    subscriber *current_subscriber = head;
    while (current_subscriber->next != NULL) {
        if (strcmp(current_subscriber->next->email, email) == 0) {
            // Set the next pointer of the current subscriber to the next subscriber of the subscriber to remove
            current_subscriber->next = current_subscriber->next->next;

            // Free the memory allocated for the subscriber to remove
            free(current_subscriber->next);
            return;
        }

        // Move to the next subscriber
        current_subscriber = current_subscriber->next;
    }

    // The subscriber was not found
    printf("The subscriber was not found.\n");
}

// Function to send an email to all subscribers on the mailing list
void send_email(char *subject, char *body) {
    // Check if the mailing list is empty
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    // Send the email to each subscriber
    subscriber *current_subscriber = head;
    while (current_subscriber != NULL) {
        // Send the email to the subscriber
        printf("Sending email to %s (%s)\n", current_subscriber->name, current_subscriber->email);

        // Move to the next subscriber
        current_subscriber = current_subscriber->next;
    }
}

// Function to print the mailing list
void print_mailing_list() {
    // Check if the mailing list is empty
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    // Print the mailing list
    subscriber *current_subscriber = head;
    while (current_subscriber != NULL) {
        // Print the subscriber
        printf("%s (%s)\n", current_subscriber->name, current_subscriber->email);

        // Move to the next subscriber
        current_subscriber = current_subscriber->next;
    }
}

// Main function
int main() {
    // Add some subscribers to the mailing list
    add_subscriber("John Doe", "johndoe@example.com");
    add_subscriber("Jane Doe", "janedoe@example.com");
    add_subscriber("Bob Smith", "bobsmith@example.com");

    // Print the mailing list
    print_mailing_list();

    // Send an email to all subscribers on the mailing list
    send_email("Hello", "This is a test email.");

    // Remove a subscriber from the mailing list
    remove_subscriber("johndoe@example.com");

    // Print the mailing list
    print_mailing_list();

    return 0;
}