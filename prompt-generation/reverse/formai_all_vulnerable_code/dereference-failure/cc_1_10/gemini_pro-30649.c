//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct subscriber {
    char *email;
    bool subscribed;
} subscriber_t;

// Define the structure of the mailing list
typedef struct mailing_list {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list_t;

// Create a new mailing list
mailing_list_t *create_mailing_list() {
    mailing_list_t *list = malloc(sizeof(mailing_list_t));
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to the mailing list
void add_subscriber(mailing_list_t *list, char *email) {
    if (list->num_subscribers < MAX_SUBSCRIBERS) {
        list->subscribers[list->num_subscribers].email = strdup(email);
        list->subscribers[list->num_subscribers].subscribed = true;
        list->num_subscribers++;
    } else {
        printf("Error: The mailing list is full.\n");
    }
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list_t *list, char *email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i].subscribed = false;
            break;
        }
    }
}

// Send an email to all subscribers
void send_email(mailing_list_t *list, char *subject, char *body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (list->subscribers[i].subscribed) {
            printf("Sending email to %s...\n", list->subscribers[i].email);
            printf("Subject: %s\n", subject);
            printf("Body: %s\n", body);
        }
    }
}

// Free the memory allocated for the mailing list
void destroy_mailing_list(mailing_list_t *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        free(list->subscribers[i].email);
    }
    free(list);
}

int main() {
    // Create a new mailing list
    mailing_list_t *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "john@example.com");
    add_subscriber(list, "mary@example.com");
    add_subscriber(list, "bob@example.com");

    // Send an email to all subscribers
    send_email(list, "Hello", "This is a test email.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob@example.com");

    // Send another email to all subscribers
    send_email(list, "Goodbye", "This is a goodbye email.");

    // Free the memory allocated for the mailing list
    destroy_mailing_list(list);

    return 0;
}