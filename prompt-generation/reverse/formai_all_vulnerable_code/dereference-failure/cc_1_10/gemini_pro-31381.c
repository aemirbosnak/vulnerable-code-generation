//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers and the maximum length of a subscriber's name.
#define MAX_SUBSCRIBERS 100
#define MAX_NAME_LENGTH 50

// Define the data structure for a subscriber.
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    int subscribed;
} subscriber_t;

// Define the data structure for the mailing list.
typedef struct mailing_list {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list_t;

// Create a new mailing list.
mailing_list_t* create_mailing_list() {
    mailing_list_t* mailing_list = (mailing_list_t*)malloc(sizeof(mailing_list_t));
    mailing_list->num_subscribers = 0;
    return mailing_list;
}

// Add a subscriber to the mailing list.
void add_subscriber(mailing_list_t* mailing_list, char* name) {
    if (mailing_list->num_subscribers < MAX_SUBSCRIBERS) {
        strcpy(mailing_list->subscribers[mailing_list->num_subscribers].name, name);
        mailing_list->subscribers[mailing_list->num_subscribers].subscribed = 1;
        mailing_list->num_subscribers++;
    }
}

// Remove a subscriber from the mailing list.
void remove_subscriber(mailing_list_t* mailing_list, char* name) {
    for (int i = 0; i < mailing_list->num_subscribers; i++) {
        if (strcmp(mailing_list->subscribers[i].name, name) == 0) {
            mailing_list->subscribers[i].subscribed = 0;
            break;
        }
    }
}

// Send a message to all subscribers on the mailing list.
void send_message(mailing_list_t* mailing_list, char* message) {
    for (int i = 0; i < mailing_list->num_subscribers; i++) {
        if (mailing_list->subscribers[i].subscribed) {
            printf("Sending message to %s\n", mailing_list->subscribers[i].name);
            printf("%s\n", message);
        }
    }
}

// Print the subscribers on the mailing list.
void print_subscribers(mailing_list_t* mailing_list) {
    for (int i = 0; i < mailing_list->num_subscribers; i++) {
        printf("%s\n", mailing_list->subscribers[i].name);
    }
}

// Free the memory allocated for the mailing list.
void free_mailing_list(mailing_list_t* mailing_list) {
    free(mailing_list);
}

// Main function.
int main() {
    // Create a new mailing list.
    mailing_list_t* mailing_list = create_mailing_list();

    // Add some subscribers to the mailing list.
    add_subscriber(mailing_list, "Alice");
    add_subscriber(mailing_list, "Bob");
    add_subscriber(mailing_list, "Carol");

    // Print the subscribers on the mailing list.
    printf("Subscribers:\n");
    print_subscribers(mailing_list);

    // Send a message to all subscribers on the mailing list.
    printf("Sending message:\n");
    send_message(mailing_list, "Hello, world!");

    // Remove a subscriber from the mailing list.
    remove_subscriber(mailing_list, "Carol");

    // Print the subscribers on the mailing list.
    printf("Subscribers:\n");
    print_subscribers(mailing_list);

    // Free the memory allocated for the mailing list.
    free_mailing_list(mailing_list);

    return 0;
}