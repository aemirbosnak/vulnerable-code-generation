//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers.
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name.
#define MAX_NAME_LENGTH 50

// Define the maximum length of an email address.
#define MAX_EMAIL_LENGTH 100

// Define the structure of a subscriber.
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

// Define the structure of the mailing list.
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list.
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to the mailing list.
void add_subscriber(mailing_list* list, char* name, char* email) {
    if (list->num_subscribers == MAX_SUBSCRIBERS) {
        printf("Error: The mailing list is full.\n");
        return;
    }

    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list.
void remove_subscriber(mailing_list* list, char* name) {
    int i;

    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            break;
        }
    }

    if (i == list->num_subscribers) {
        printf("Error: The subscriber is not found.\n");
        return;
    }

    for (; i < list->num_subscribers - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }

    list->num_subscribers--;
}

// Print the mailing list.
void print_mailing_list(mailing_list* list) {
    int i;

    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s: %s\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Free the memory allocated for the mailing list.
void free_mailing_list(mailing_list* list) {
    free(list);
}

int main() {
    // Create a new mailing list.
    mailing_list* list = create_mailing_list();

    // Add some subscribers to the mailing list.
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Bill Smith", "bill.smith@example.com");

    // Print the mailing list.
    print_mailing_list(list);

    // Remove a subscriber from the mailing list.
    remove_subscriber(list, "Bill Smith");

    // Print the mailing list again.
    print_mailing_list(list);

    // Free the memory allocated for the mailing list.
    free_mailing_list(list);

    return 0;
}