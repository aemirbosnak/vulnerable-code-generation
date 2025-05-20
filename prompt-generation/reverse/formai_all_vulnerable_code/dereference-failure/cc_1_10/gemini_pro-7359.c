//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the subscriber structure
typedef struct subscriber {
    char name[50];
    char email[50];
} subscriber;

// Define the mailing list structure
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to the mailing list
void add_subscriber(mailing_list* list, char* name, char* email) {
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full!\n");
        return;
    }

    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list* list, char* email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i + 1; j < list->num_subscribers; j++) {
                strcpy(list->subscribers[j - 1].name, list->subscribers[j].name);
                strcpy(list->subscribers[j - 1].email, list->subscribers[j].email);
            }
            list->num_subscribers--;
            return;
        }
    }

    printf("Error: Subscriber not found!\n");
}

// Send a message to all subscribers
void send_message(mailing_list* list, char* message) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("Sending message to %s (%s): %s\n", list->subscribers[i].name, list->subscribers[i].email, message);
    }
}

// Print the mailing list
void print_mailing_list(mailing_list* list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list->num_subscribers; i++) {
        printf(" - %s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list* list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Bob Smith", "bob.smith@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Send a message to all subscribers
    send_message(list, "Hello subscribers!");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob.smith@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Free the mailing list
    free(list);

    return 0;
}