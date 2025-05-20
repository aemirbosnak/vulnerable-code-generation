//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 50

// Define the structure of a subscriber
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

// Define the structure of the mailing list
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    if (list == NULL) {
        return NULL;
    }

    list->num_subscribers = 0;

    return list;
}

// Add a subscriber to the mailing list
int add_subscriber(mailing_list* list, char* name, char* email) {
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        return -1;
    }

    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;

    return 0;
}

// Remove a subscriber from the mailing list
int remove_subscriber(mailing_list* list, char* email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->num_subscribers - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->num_subscribers--;
            return 0;
        }
    }

    return -1;
}

// Send an email to all subscribers on the mailing list
int send_email(mailing_list* list, char* subject, char* body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        // Send an email to the subscriber
    }

    return 0;
}

// Print the mailing list
void print_mailing_list(mailing_list* list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list* list) {
    free(list);
}

int main() {
    // Create a new mailing list
    mailing_list* list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Peter Parker", "peter.parker@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Send an email to all subscribers on the mailing list
    send_email(list, "Hello from the mailing list", "This is a test email.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "peter.parker@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}