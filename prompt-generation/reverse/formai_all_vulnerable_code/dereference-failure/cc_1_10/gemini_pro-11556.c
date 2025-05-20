//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Subscriber structure
typedef struct subscriber {
    char name[50];
    char email[50];
} subscriber;

// Mailing list structure
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to the mailing list
void add_subscriber(mailing_list *list, char *name, char *email) {
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

// Send an email to all subscribers on the mailing list
void send_email(mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        // Use an email library or framework here to send the email
        printf("Sending email to %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Print the details of all subscribers on the mailing list
void print_subscribers(mailing_list *list) {
    printf("Subscribers:\n");
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list *list) {
    free(list);
}

int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "Sherlock Holmes", "sherlock.holmes@221b.com");
    add_subscriber(list, "Dr. Watson", "john.watson@221b.com");
    add_subscriber(list, "Mycroft Holmes", "mycroft.holmes@britishgovernment.org");

    // Print the details of all subscribers
    print_subscribers(list);

    // Send an email to all subscribers
    send_email(list, "The Case of the Purloined Letter", "I have a most curious case to share with you...");

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}