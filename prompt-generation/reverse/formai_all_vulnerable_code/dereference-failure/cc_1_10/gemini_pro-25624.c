//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers that can be stored in the mailing list.
#define MAX_SUBSCRIBERS 100

// Define the maximum length of an email address.
#define MAX_EMAIL_LENGTH 255

// Define the structure of a subscriber.
typedef struct subscriber {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} subscriber;

// Define the structure of the mailing list.
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list.
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a new subscriber to the mailing list.
void add_subscriber(mailing_list* list, char* email) {
    // Check if the mailing list is full.
    if (list->num_subscribers == MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }

    // Check if the email address is valid.
    if (!is_valid_email(email)) {
        printf("Invalid email address.\n");
        return;
    }

    // Check if the subscriber is already subscribed to the mailing list.
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Subscriber is already subscribed to the mailing list.\n");
            return;
        }
    }

    // Add the new subscriber to the mailing list.
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].subscribed = 1;
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list.
void remove_subscriber(mailing_list* list, char* email) {
    // Check if the subscriber is subscribed to the mailing list.
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            // Unsubscribe the subscriber.
            list->subscribers[i].subscribed = 0;
            return;
        }
    }

    // The subscriber is not subscribed to the mailing list.
    printf("Subscriber is not subscribed to the mailing list.\n");
}

// Send an email to all subscribers on the mailing list.
void send_email(mailing_list* list, char* subject, char* body) {
    // Iterate over the subscribers in the mailing list.
    for (int i = 0; i < list->num_subscribers; i++) {
        // Check if the subscriber is subscribed.
        if (list->subscribers[i].subscribed) {
            // Send the email to the subscriber.
            printf("Sending email to %s\n", list->subscribers[i].email);
        }
    }
}

// Print the mailing list to the console.
void print_mailing_list(mailing_list* list) {
    // Iterate over the subscribers in the mailing list.
    for (int i = 0; i < list->num_subscribers; i++) {
        // Print the subscriber's email address.
        printf("%s\n", list->subscribers[i].email);
    }
}

// Check if an email address is valid.
int is_valid_email(char* email) {
    // Check if the email address contains an "@" symbol.
    if (strchr(email, '@') == NULL) {
        return 0;
    }

    // Check if the email address contains a "." symbol.
    if (strchr(email, '.') == NULL) {
        return 0;
    }

    // The email address is valid.
    return 1;
}

int main() {
    // Create a new mailing list.
    mailing_list* list = create_mailing_list();

    // Add some subscribers to the mailing list.
    add_subscriber(list, "john@doe.com");
    add_subscriber(list, "jane@doe.com");
    add_subscriber(list, "bill@bob.com");

    // Send an email to all subscribers on the mailing list.
    send_email(list, "Hello World", "This is an email from the mailing list manager.");

    // Print the mailing list to the console.
    print_mailing_list(list);

    return 0;
}