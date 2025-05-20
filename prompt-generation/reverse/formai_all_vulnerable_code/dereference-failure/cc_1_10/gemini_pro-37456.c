//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the linked list structure for subscribers
typedef struct subscriber {
    char name[50];
    char email[50];
    struct subscriber *next;
} subscriber_t;

// Declare the linked list structure for mailing lists
typedef struct mailing_list {
    char name[50];
    subscriber_t *subscribers;
    struct mailing_list *next;
} mailing_list_t;

// Function to create a new mailing list
mailing_list_t* create_mailing_list(char *name) {
    mailing_list_t *new_list = (mailing_list_t*)malloc(sizeof(mailing_list_t));
    strcpy(new_list->name, name);
    new_list->subscribers = NULL;
    new_list->next = NULL;
    return new_list;
}

// Function to add a new subscriber to a mailing list
void add_subscriber(mailing_list_t *list, char *name, char *email) {
    subscriber_t *new_subscriber = (subscriber_t*)malloc(sizeof(subscriber_t));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;

    // Add the new subscriber to the end of the list
    if (list->subscribers == NULL) {
        list->subscribers = new_subscriber;
    } else {
        subscriber_t *current = list->subscribers;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_subscriber;
    }
}

// Function to send an email to all subscribers on a mailing list
void send_email(mailing_list_t *list, char *subject, char *body) {
    subscriber_t *current = list->subscribers;
    while (current != NULL) {
        printf("Sending email to %s (%s):\n", current->name, current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        current = current->next;
    }
}

// Function to print the details of a mailing list
void print_mailing_list(mailing_list_t *list) {
    printf("Mailing List: %s\n", list->name);
    subscriber_t *current = list->subscribers;
    while (current != NULL) {
        printf("  Subscriber: %s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

// Main function
int main() {
    // Create a mailing list with the name "Awesome News"
    mailing_list_t *list = create_mailing_list("Awesome News");

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Smith", "john.smith@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Bob Jones", "bob.jones@example.com");

    // Print the details of the mailing list
    print_mailing_list(list);

    // Send an email to all subscribers on the mailing list
    send_email(list, "Welcome to Awesome News!", "This is the first issue of our exciting new newsletter.");

    return 0;
}