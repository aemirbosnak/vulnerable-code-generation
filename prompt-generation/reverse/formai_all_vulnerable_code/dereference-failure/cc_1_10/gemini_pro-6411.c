//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of subscribers and the maximum length of a subscriber's email address
#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 256

// Define the structure of a subscriber
typedef struct {
    char email[MAX_EMAIL_LENGTH];
    bool subscribed;
} subscriber;

// Define the structure of the mailing list
typedef struct {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    if (list == NULL) {
        return NULL;
    }

    list->num_subscribers = 0;
    return list;
}

// Free the memory allocated for a mailing list
void free_mailing_list(mailing_list* list) {
    free(list);
}

// Add a subscriber to a mailing list
bool add_subscriber(mailing_list* list, char* email) {
    // Check if the mailing list is full
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        return false;
    }

    // Check if the subscriber is already on the list
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            return false;
        }
    }

    // Add the subscriber to the list
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].subscribed = true;
    list->num_subscribers++;

    return true;
}

// Remove a subscriber from a mailing list
bool remove_subscriber(mailing_list* list, char* email) {
    // Find the subscriber in the list
    int index = -1;
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            index = i;
            break;
        }
    }

    // Check if the subscriber was found
    if (index == -1) {
        return false;
    }

    // Remove the subscriber from the list
    for (int i = index; i < list->num_subscribers - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }

    list->num_subscribers--;

    return true;
}

// Send a message to all subscribers on a mailing list
void send_message(mailing_list* list, char* message) {
    // Iterate over the subscribers and send the message to each one
    for (int i = 0; i < list->num_subscribers; i++) {
        if (list->subscribers[i].subscribed) {
            printf("Sending message to %s\n", list->subscribers[i].email);
        }
    }
}

// Print the subscribers on a mailing list
void print_subscribers(mailing_list* list) {
    // Iterate over the subscribers and print their email addresses
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s\n", list->subscribers[i].email);
    }
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list* list = create_mailing_list();

    // Add some subscribers to the list
    add_subscriber(list, "alice@example.com");
    add_subscriber(list, "bob@example.com");
    add_subscriber(list, "charlie@example.com");

    // Print the subscribers on the list
    print_subscribers(list);

    // Send a message to the subscribers on the list
    send_message(list, "Hello, world!");

    // Remove a subscriber from the list
    remove_subscriber(list, "bob@example.com");

    // Print the subscribers on the list
    print_subscribers(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}