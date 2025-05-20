//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers in the mailing list
#define MAX_SUBSCRIBERS 1000

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 256

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Define the structure of a subscriber
typedef struct subscriber {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} subscriber_t;

// Define the structure of a mailing list
typedef struct mailing_list {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list_t;

// Create a new mailing list
mailing_list_t *create_mailing_list() {
    mailing_list_t *mailing_list = malloc(sizeof(mailing_list_t));
    if (mailing_list == NULL) {
        return NULL;
    }

    mailing_list->num_subscribers = 0;

    return mailing_list;
}

// Add a new subscriber to the mailing list
int add_subscriber(mailing_list_t *mailing_list, char *email) {
    if (mailing_list->num_subscribers >= MAX_SUBSCRIBERS) {
        return -1;
    }

    strcpy(mailing_list->subscribers[mailing_list->num_subscribers].email, email);
    mailing_list->subscribers[mailing_list->num_subscribers].subscribed = 1;
    mailing_list->num_subscribers++;

    return 0;
}

// Remove a subscriber from the mailing list
int remove_subscriber(mailing_list_t *mailing_list, char *email) {
    int i;

    for (i = 0; i < mailing_list->num_subscribers; i++) {
        if (strcmp(mailing_list->subscribers[i].email, email) == 0) {
            mailing_list->subscribers[i].subscribed = 0;
            return 0;
        }
    }

    return -1;
}

// Send a message to all subscribers in the mailing list
int send_message(mailing_list_t *mailing_list, char *message) {
    int i;

    for (i = 0; i < mailing_list->num_subscribers; i++) {
        if (mailing_list->subscribers[i].subscribed) {
            printf("To: %s\n", mailing_list->subscribers[i].email);
            printf("Subject: %s\n", message);
            printf("Body: %s\n", message);
        }
    }

    return 0;
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list_t *mailing_list) {
    free(mailing_list);
}

int main() {
    mailing_list_t *mailing_list = create_mailing_list();
    add_subscriber(mailing_list, "john@example.com");
    add_subscriber(mailing_list, "jane@example.com");
    send_message(mailing_list, "Hello, world!");
    remove_subscriber(mailing_list, "john@example.com");
    free_mailing_list(mailing_list);

    return 0;
}