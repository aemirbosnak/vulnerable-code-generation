//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a subscriber
typedef struct subscriber {
    char *name;
    char *email;
    struct subscriber *next;
} subscriber;

// A struct to represent a mailing list
typedef struct mailing_list {
    char *name;
    subscriber *subscribers;
    int num_subscribers;
} mailing_list;

// Create a new subscriber
subscriber *create_subscriber(char *name, char *email) {
    subscriber *new_subscriber = malloc(sizeof(subscriber));
    new_subscriber->name = strdup(name);
    new_subscriber->email = strdup(email);
    new_subscriber->next = NULL;
    return new_subscriber;
}

// Create a new mailing list
mailing_list *create_mailing_list(char *name) {
    mailing_list *new_mailing_list = malloc(sizeof(mailing_list));
    new_mailing_list->name = strdup(name);
    new_mailing_list->subscribers = NULL;
    new_mailing_list->num_subscribers = 0;
    return new_mailing_list;
}

// Add a subscriber to a mailing list
void add_subscriber(mailing_list *list, subscriber *new_subscriber) {
    new_subscriber->next = list->subscribers;
    list->subscribers = new_subscriber;
    list->num_subscribers++;
}

// Send an email to all subscribers on a mailing list
void send_email(mailing_list *list, char *subject, char *body) {
    subscriber *current_subscriber = list->subscribers;
    while (current_subscriber != NULL) {
        printf("Sending email to %s at %s\n", current_subscriber->name, current_subscriber->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        current_subscriber = current_subscriber->next;
    }
}

// Print the details of a mailing list
void print_mailing_list(mailing_list *list) {
    printf("Mailing list: %s\n", list->name);
    printf("Number of subscribers: %d\n", list->num_subscribers);
    subscriber *current_subscriber = list->subscribers;
    while (current_subscriber != NULL) {
        printf("Subscriber: %s (%s)\n", current_subscriber->name, current_subscriber->email);
        current_subscriber = current_subscriber->next;
    }
}

// Free the memory allocated for a mailing list and its subscribers
void free_mailing_list(mailing_list *list) {
    subscriber *current_subscriber = list->subscribers;
    while (current_subscriber != NULL) {
        subscriber *next_subscriber = current_subscriber->next;
        free(current_subscriber->name);
        free(current_subscriber->email);
        free(current_subscriber);
        current_subscriber = next_subscriber;
    }
    free(list->name);
    free(list);
}

int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list("My Mailing List");

    // Add some subscribers to the mailing list
    subscriber *subscriber1 = create_subscriber("John Doe", "john.doe@example.com");
    add_subscriber(list, subscriber1);
    subscriber *subscriber2 = create_subscriber("Jane Doe", "jane.doe@example.com");
    add_subscriber(list, subscriber2);

    // Send an email to all subscribers on the mailing list
    send_email(list, "Hello from the mailing list!", "This is a test email.");

    // Print the details of the mailing list
    print_mailing_list(list);

    // Free the memory allocated for the mailing list and its subscribers
    free_mailing_list(list);

    return 0;
}