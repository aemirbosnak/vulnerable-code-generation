//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct subscriber {
    char name[50];
    char email[50];
} subscriber_t;

// Define the structure of the mailing list
typedef struct mailing_list {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list_t;

// Create a new mailing list
mailing_list_t* create_mailing_list() {
    mailing_list_t* mailing_list = malloc(sizeof(mailing_list_t));
    mailing_list->num_subscribers = 0;
    return mailing_list;
}

// Add a subscriber to the mailing list
void add_subscriber(mailing_list_t* mailing_list, char* name, char* email) {
    if (mailing_list->num_subscribers < MAX_SUBSCRIBERS) {
        strcpy(mailing_list->subscribers[mailing_list->num_subscribers].name, name);
        strcpy(mailing_list->subscribers[mailing_list->num_subscribers].email, email);
        mailing_list->num_subscribers++;
    }
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list_t* mailing_list, char* email) {
    for (int i = 0; i < mailing_list->num_subscribers; i++) {
        if (strcmp(mailing_list->subscribers[i].email, email) == 0) {
            for (int j = i + 1; j < mailing_list->num_subscribers; j++) {
                mailing_list->subscribers[j - 1] = mailing_list->subscribers[j];
            }
            mailing_list->num_subscribers--;
            break;
        }
    }
}

// Send an email to all subscribers
void send_email(mailing_list_t* mailing_list, char* subject, char* body) {
    for (int i = 0; i < mailing_list->num_subscribers; i++) {
        // Send an email to the subscriber
    }
}

// Print the subscribers in the mailing list
void print_subscribers(mailing_list_t* mailing_list) {
    for (int i = 0; i < mailing_list->num_subscribers; i++) {
        printf("%s (%s)\n", mailing_list->subscribers[i].name, mailing_list->subscribers[i].email);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list_t* mailing_list) {
    free(mailing_list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list_t* mailing_list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(mailing_list, "John Smith", "john.smith@example.com");
    add_subscriber(mailing_list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(mailing_list, "Bill Jones", "bill.jones@example.com");

    // Print the subscribers in the mailing list
    printf("Subscribers:\n");
    print_subscribers(mailing_list);

    // Send an email to all subscribers
    send_email(mailing_list, "Test email", "This is a test email.");

    // Remove a subscriber from the mailing list
    remove_subscriber(mailing_list, "jane.doe@example.com");

    // Print the subscribers in the mailing list again
    printf("\nSubscribers after removing Jane Doe:\n");
    print_subscribers(mailing_list);

    // Free the memory allocated for the mailing list
    free_mailing_list(mailing_list);

    return 0;
}