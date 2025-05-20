//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct subscriber {
    char name[50];
    char email[100];
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
void add_subscriber(mailing_list_t *list, const char *name, const char *email) {
    // Check if the list is full
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: The mailing list is full.\n");
        return;
    }

    // Copy the subscriber's information into the list
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);

    // Increment the number of subscribers
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list_t *list, const char *email) {
    // Find the subscriber in the list
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            break;
        }
    }

    // Check if the subscriber was found
    if (i == list->num_subscribers) {
        printf("Error: The subscriber was not found.\n");
        return;
    }

    // Remove the subscriber from the list
    for (; i < list->num_subscribers - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }

    // Decrement the number of subscribers
    list->num_subscribers--;
}

// Send a message to all subscribers on the mailing list
void send_message(mailing_list_t *list, const char *subject, const char *body) {
    // Iterate over the subscribers and send the message to each one
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n\n", body);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list_t *list) {
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list_t *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "Ada Lovelace", "ada@lovelace.com");
    add_subscriber(list, "Charles Babbage", "charles@babbage.com");
    add_subscriber(list, "Grace Hopper", "grace@hopper.com");

    // Send a message to all subscribers on the mailing list
    send_message(list, "Hello, world!", "This is a test message.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "Charles Babbage");

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}