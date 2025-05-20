//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct subscriber {
    char name[50];
    char email[50];
} subscriber;

// Define the structure of the mailing list
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

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list *list, char *name, char *email) {
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->num_subscribers--;
            for (; i < list->num_subscribers; i++) {
                strcpy(list->subscribers[i].name, list->subscribers[i + 1].name);
                strcpy(list->subscribers[i].email, list->subscribers[i + 1].email);
            }
            break;
        }
    }
}

// Send an email to all subscribers on the mailing list
void send_email(mailing_list *list, char *subject, char *body) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        // Send the email to the subscriber
    }
}

// Print the mailing list
void print_mailing_list(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Free the memory used by the mailing list
void free_mailing_list(mailing_list *list) {
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Send an email to all subscribers on the mailing list
    send_email(list, "Hello, world!", "This is an email from the mailing list manager.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "john.doe@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Free the memory used by the mailing list
    free_mailing_list(list);

    return 0;
}