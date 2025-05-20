//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct subscriber {
    char name[50];
    char email[50];
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

// Add a new subscriber to the mailing list
int add_subscriber(mailing_list_t *list, const char *name, const char *email) {
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        return -1;
    }
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].subscribed = 1;
    list->num_subscribers++;
    return 0;
}

// Remove a subscriber from the mailing list
int remove_subscriber(mailing_list_t *list, const char *name) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            list->subscribers[i].subscribed = 0;
            return 0;
        }
    }
    return -1;
}

// Send an email to all subscribed members of the mailing list
int send_email(mailing_list_t *list, const char *subject, const char *body) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (list->subscribers[i].subscribed) {
            // Send the email to the subscriber
        }
    }
    return 0;
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list_t *list) {
    free(list);
}

// Print the subscribers of the mailing list
void print_subscribers(mailing_list_t *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list_t *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe", "johndoe@example.com");
    add_subscriber(list, "Jane Doe", "janedoe@example.com");
    add_subscriber(list, "Bob Smith", "bobsmith@example.com");

    // Print the subscribers of the mailing list
    print_subscribers(list);

    // Send an email to all subscribed members of the mailing list
    send_email(list, "Hello", "This is a test email.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "Bob Smith");

    // Print the subscribers of the mailing list
    print_subscribers(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}