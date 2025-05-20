//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a subscriber
typedef struct subscriber {
    char name[50];
    char email[50];
    struct subscriber *next;
} subscriber;

// Function to create a new subscriber
subscriber *create_subscriber(char *name, char *email) {
    subscriber *new_subscriber = (subscriber *)malloc(sizeof(subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;
    return new_subscriber;
}

// Function to add a subscriber to the mailing list
void add_subscriber(subscriber **head, subscriber *new_subscriber) {
    if (*head == NULL) {
        *head = new_subscriber;
    } else {
        subscriber *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_subscriber;
    }
}

// Function to print the mailing list
void print_mailing_list(subscriber *head) {
    subscriber *current = head;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->email);
        current = current->next;
    }
}

// Function to send an email to all subscribers
void send_email(subscriber *head, char *subject, char *body) {
    subscriber *current = head;
    while (current != NULL) {
        // Send email to current subscriber using SMTP or other email sending library
        printf("Sending email to %s %s\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    // Create a new mailing list
    subscriber *head = NULL;

    // Add some subscribers to the mailing list
    add_subscriber(&head, create_subscriber("John Doe", "johndoe@example.com"));
    add_subscriber(&head, create_subscriber("Jane Doe", "janedoe@example.com"));
    add_subscriber(&head, create_subscriber("Bob Smith", "bobsmith@example.com"));

    // Print the mailing list
    printf("Mailing List:\n");
    print_mailing_list(head);

    // Send an email to all subscribers
    send_email(head, "Thank You for Subscribing!", "This is a test email to all subscribers on the mailing list.");

    return 0;
}