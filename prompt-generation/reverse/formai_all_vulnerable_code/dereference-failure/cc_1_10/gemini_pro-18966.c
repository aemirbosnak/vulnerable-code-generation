//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold a subscriber's email address and name
typedef struct subscriber {
    char *email;
    char *name;
} subscriber;

// Struct to hold the mailing list
typedef struct mailing_list {
    int num_subscribers;
    subscriber **subscribers;
} mailing_list;

// Function to create a new subscriber
subscriber *create_subscriber(char *email, char *name) {
    subscriber *new_subscriber = malloc(sizeof(subscriber));
    new_subscriber->email = strdup(email);
    new_subscriber->name = strdup(name);
    return new_subscriber;
}

// Function to create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *new_list = malloc(sizeof(mailing_list));
    new_list->num_subscribers = 0;
    new_list->subscribers = NULL;
    return new_list;
}

// Function to add a subscriber to a mailing list
void add_subscriber(mailing_list *list, subscriber *new_subscriber) {
    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber *));
    list->subscribers[list->num_subscribers++] = new_subscriber;
}

// Function to send an email to all subscribers on a mailing list
void send_email(mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        // Send an email to the subscriber at index i
        printf("To: %s <%s>\n", list->subscribers[i]->name, list->subscribers[i]->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n\n", body);
    }
}

// Function to free the memory allocated for a subscriber
void free_subscriber(subscriber *subscriber) {
    free(subscriber->email);
    free(subscriber->name);
    free(subscriber);
}

// Function to free the memory allocated for a mailing list
void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        free_subscriber(list->subscribers[i]);
    }
    free(list->subscribers);
    free(list);
}

int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, create_subscriber("john@example.com", "John Doe"));
    add_subscriber(list, create_subscriber("jane@example.com", "Jane Doe"));
    add_subscriber(list, create_subscriber("bob@example.com", "Bob Smith"));

    // Send an email to all subscribers on the mailing list
    send_email(list, "Welcome to the mailing list!", "This is a test email to make sure that the mailing list is working properly.");

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}