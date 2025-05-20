//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of an email address
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

// Add a subscriber to the mailing list
void add_subscriber(mailing_list* list, char* email) {
    // Check if the subscriber is already on the list
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            return;
        }
    }

    // Add the subscriber to the list
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].subscribed = 1;
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list* list, char* email) {
    // Find the subscriber on the list
    int index = -1;
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            index = i;
            break;
        }
    }

    // If the subscriber was found, remove them from the list
    if (index != -1) {
        for (int i = index; i < list->num_subscribers - 1; i++) {
            list->subscribers[i] = list->subscribers[i + 1];
        }
        list->num_subscribers--;
    }
}

// Send a message to all subscribers on the mailing list
void send_message(mailing_list* list, char* message) {
    // Iterate over the subscribers
    for (int i = 0; i < list->num_subscribers; i++) {
        // Check if the subscriber is subscribed
        if (list->subscribers[i].subscribed) {
            // Send the message to the subscriber
            printf("Sending message to %s\n", list->subscribers[i].email);
            printf("%s\n", message);
        }
    }
}

// Print the subscribers on the mailing list
void print_subscribers(mailing_list* list) {
    // Iterate over the subscribers
    for (int i = 0; i < list->num_subscribers; i++) {
        // Print the subscriber's email address
        printf("%s\n", list->subscribers[i].email);
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
    add_subscriber(list, "john@example.com");
    add_subscriber(list, "mary@example.com");
    add_subscriber(list, "bob@example.com");

    // Print the subscribers on the mailing list
    printf("Subscribers:\n");
    print_subscribers(list);

    // Send a message to all subscribers on the mailing list
    printf("\nSending message:\n");
    send_message(list, "This is a test message.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob@example.com");

    // Print the subscribers on the mailing list
    printf("\nSubscribers after removing bob@example.com:\n");
    print_subscribers(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}