//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 100

// Define the structure of a subscriber
typedef struct subscriber {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} subscriber_t;

// Define the structure of the mailing list
typedef struct mailing_list {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list_t;

// Create a new mailing list
mailing_list_t *create_mailing_list() {
    mailing_list_t *list = malloc(sizeof(mailing_list_t));
    if (list == NULL) {
        return NULL;
    }
    list->num_subscribers = 0;
    return list;
}

// Free the memory allocated for a mailing list
void free_mailing_list(mailing_list_t *list) {
    free(list);
}

// Add a subscriber to a mailing list
int add_subscriber(mailing_list_t *list, char *email) {
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        return -1;
    }
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].subscribed = 1;
    list->num_subscribers++;
    return 0;
}

// Remove a subscriber from a mailing list
int remove_subscriber(mailing_list_t *list, char *email) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i].subscribed = 0;
            return 0;
        }
    }
    return -1;
}

// Send a message to all subscribers on a mailing list
int send_message(mailing_list_t *list, char *message) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (list->subscribers[i].subscribed) {
            printf("Sending message to %s\n", list->subscribers[i].email);
        }
    }
    return 0;
}

// Print the contents of a mailing list
void print_mailing_list(mailing_list_t *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s\n", list->subscribers[i].email);
    }
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list_t *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "alice@example.com");
    add_subscriber(list, "bob@example.com");
    add_subscriber(list, "charlie@example.com");

    // Print the contents of the mailing list
    print_mailing_list(list);

    // Send a message to all subscribers on the mailing list
    send_message(list, "Hello, world!");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob@example.com");

    // Print the contents of the mailing list
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}