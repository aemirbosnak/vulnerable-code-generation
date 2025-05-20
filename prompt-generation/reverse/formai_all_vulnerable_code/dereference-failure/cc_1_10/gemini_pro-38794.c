//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 25

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 50

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1000

// Define the structure of a subscriber
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber_t;

// Define the structure of a message
typedef struct message {
    char subject[MAX_MESSAGE_LENGTH];
    char body[MAX_MESSAGE_LENGTH];
} message_t;

// Define the structure of the mailing list
typedef struct mailing_list {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
    message_t messages[MAX_MESSAGE_LENGTH];
    int num_messages;
} mailing_list_t;

// Create a new mailing list
mailing_list_t *create_mailing_list() {
    mailing_list_t *mailing_list = malloc(sizeof(mailing_list_t));
    if (mailing_list == NULL) {
        return NULL;
    }

    mailing_list->num_subscribers = 0;
    mailing_list->num_messages = 0;

    return mailing_list;
}

// Add a new subscriber to the mailing list
int add_subscriber(mailing_list_t *mailing_list, char *name, char *email) {
    if (mailing_list->num_subscribers >= MAX_SUBSCRIBERS) {
        return -1;
    }

    strcpy(mailing_list->subscribers[mailing_list->num_subscribers].name, name);
    strcpy(mailing_list->subscribers[mailing_list->num_subscribers].email, email);
    mailing_list->num_subscribers++;

    return 0;
}

// Remove a subscriber from the mailing list
int remove_subscriber(mailing_list_t *mailing_list, char *email) {
    int i;

    for (i = 0; i < mailing_list->num_subscribers; i++) {
        if (strcmp(mailing_list->subscribers[i].email, email) == 0) {
            break;
        }
    }

    if (i == mailing_list->num_subscribers) {
        return -1;
    }

    for (i++; i < mailing_list->num_subscribers; i++) {
        mailing_list->subscribers[i - 1] = mailing_list->subscribers[i];
    }

    mailing_list->num_subscribers--;

    return 0;
}

// Send a message to all subscribers on the mailing list
int send_message(mailing_list_t *mailing_list, char *subject, char *body) {
    int i;

    for (i = 0; i < mailing_list->num_subscribers; i++) {
        // Send the message to the subscriber
    }

    return 0;
}

// Print the mailing list
void print_mailing_list(mailing_list_t *mailing_list) {
    int i;

    printf("Mailing list:\n");
    for (i = 0; i < mailing_list->num_subscribers; i++) {
        printf("  %s <%s>\n", mailing_list->subscribers[i].name, mailing_list->subscribers[i].email);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list_t *mailing_list) {
    free(mailing_list);
}

// Main function
int main() {
    mailing_list_t *mailing_list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(mailing_list, "John Doe", "john.doe@example.com");
    add_subscriber(mailing_list, "Jane Doe", "jane.doe@example.com");

    // Send a message to all subscribers on the mailing list
    send_message(mailing_list, "Hello, world!", "This is a test message.");

    // Print the mailing list
    print_mailing_list(mailing_list);

    // Free the memory allocated for the mailing list
    free_mailing_list(mailing_list);

    return 0;
}