//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
struct subscriber {
    char name[50];
    char email[50];
};

// Define the structure of the mailing list
struct mailing_list {
    struct subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
};

// Create a new mailing list
struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to the mailing list
void add_subscriber(struct mailing_list *list, char *name, char *email) {
    if (list->num_subscribers < MAX_SUBSCRIBERS) {
        strcpy(list->subscribers[list->num_subscribers].name, name);
        strcpy(list->subscribers[list->num_subscribers].email, email);
        list->num_subscribers++;
    } else {
        printf("Error: The mailing list is full.\n");
    }
}

// Remove a subscriber from the mailing list
void remove_subscriber(struct mailing_list *list, char *name) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            list->num_subscribers--;
            for (int j = i; j < list->num_subscribers; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            break;
        }
    }
}

// Send a message to all subscribers on the mailing list
void send_message(struct mailing_list *list, char *message) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("Sending message to %s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("%s\n", message);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(struct mailing_list *list) {
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    struct mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Bob Smith", "bob.smith@example.com");

    // Send a message to all subscribers on the mailing list
    send_message(list, "Hello, world!");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "John Doe");

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}