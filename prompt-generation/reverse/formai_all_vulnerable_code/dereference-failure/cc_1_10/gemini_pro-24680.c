//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 100

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1000

// Define the structure of a subscriber
typedef struct subscriber {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} subscriber;

// Define the structure of a mailing list
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list* list, char* email) {
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: The mailing list is full.\n");
        return;
    }

    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].subscribed = 1;
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list* list, char* email) {
    int i;

    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i].subscribed = 0;
            return;
        }
    }

    printf("Error: The subscriber is not found.\n");
}

// Send a message to all subscribers on the mailing list
void send_message(mailing_list* list, char* message) {
    int i;

    for (i = 0; i < list->num_subscribers; i++) {
        if (list->subscribers[i].subscribed) {
            printf("Sending message to %s: %s\n", list->subscribers[i].email, message);
        }
    }
}

// Print the contents of the mailing list
void print_mailing_list(mailing_list* list) {
    int i;

    printf("Mailing list:\n");
    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s (%s)\n", list->subscribers[i].email, list->subscribers[i].subscribed ? "subscribed" : "unsubscribed");
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list* list) {
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list* list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "alice@example.com");
    add_subscriber(list, "bob@example.com");
    add_subscriber(list, "charlie@example.com");

    // Send a message to all subscribers on the mailing list
    send_message(list, "Hello world!");

    // Print the contents of the mailing list
    print_mailing_list(list);

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob@example.com");

    // Print the contents of the mailing list
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}