//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum number of subscribers and the maximum length of a subscriber's email address
#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 50

// Declares the subscriber data structure
typedef struct subscriber {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} subscriber;

// Declares the mailing list data structure
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Creates a new mailing list
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Adds a new subscriber to the mailing list
void add_subscriber(mailing_list* list, char* email) {
    if (list->num_subscribers < MAX_SUBSCRIBERS) {
        strcpy(list->subscribers[list->num_subscribers].email, email);
        list->subscribers[list->num_subscribers].subscribed = 1;
        list->num_subscribers++;
    } else {
        printf("Error: The mailing list is full.\n");
    }
}

// Removes a subscriber from the mailing list
void remove_subscriber(mailing_list* list, char* email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i].subscribed = 0;
            break;
        }
    }
}

// Sends an email to all subscribers on the mailing list
void send_email(mailing_list* list, char* subject, char* body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (list->subscribers[i].subscribed) {
            printf("Sending email to %s:\n", list->subscribers[i].email);
            printf("Subject: %s\n", subject);
            printf("Body: %s\n", body);
        }
    }
}

// Prints the mailing list
void print_mailing_list(mailing_list* list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s\n", list->subscribers[i].email);
    }
}

// Main function
int main() {
    // Creates a new mailing list
    mailing_list* list = create_mailing_list();

    // Adds some subscribers to the mailing list
    add_subscriber(list, "john@example.com");
    add_subscriber(list, "mary@example.com");
    add_subscriber(list, "bob@example.com");

    // Prints the mailing list
    print_mailing_list(list);

    // Sends an email to all subscribers on the mailing list
    send_email(list, "Hello from the mailing list!", "This is a test email.");

    // Removes a subscriber from the mailing list
    remove_subscriber(list, "bob@example.com");

    // Prints the mailing list
    print_mailing_list(list);

    return 0;
}