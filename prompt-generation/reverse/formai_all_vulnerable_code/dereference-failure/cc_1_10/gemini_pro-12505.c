//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A single subscriber in the mailing list.
struct subscriber {
    char *name;
    char *email;
};

// The mailing list itself.
struct mailing_list {
    struct subscriber *subscribers;
    int num_subscribers;
};

// Create a new mailing list.
struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->subscribers = NULL;
    list->num_subscribers = 0;
    return list;
}

// Add a new subscriber to the mailing list.
void add_subscriber(struct mailing_list *list, char *name, char *email) {
    struct subscriber *new_subscriber = malloc(sizeof(struct subscriber));
    new_subscriber->name = strdup(name);
    new_subscriber->email = strdup(email);
    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(struct subscriber));
    list->subscribers[list->num_subscribers++] = *new_subscriber;
}

// Remove a subscriber from the mailing list by name.
void remove_subscriber(struct mailing_list *list, char *name) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            break;
        }
    }

    if (i < list->num_subscribers) {
        free(list->subscribers[i].name);
        free(list->subscribers[i].email);
        list->num_subscribers--;
        for (; i < list->num_subscribers; i++) {
            list->subscribers[i] = list->subscribers[i + 1];
        }
        list->subscribers = realloc(list->subscribers, list->num_subscribers * sizeof(struct subscriber));
    }
}

// Send a message to all subscribers on the mailing list.
void send_message(struct mailing_list *list, char *message) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("Sending message to %s (%s): %s\n", list->subscribers[i].name, list->subscribers[i].email, message);
    }
}

// Free the memory used by the mailing list.
void free_mailing_list(struct mailing_list *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        free(list->subscribers[i].name);
        free(list->subscribers[i].email);
    }
    free(list->subscribers);
    free(list);
}

// Main function.
int main() {
    // Create a new mailing list.
    struct mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list.
    add_subscriber(list, "John Smith", "john@example.com");
    add_subscriber(list, "Jane Doe", "jane@example.com");
    add_subscriber(list, "Bob Jones", "bob@example.com");

    // Send a message to all subscribers on the mailing list.
    send_message(list, "Hello, world!");

    // Remove a subscriber from the mailing list.
    remove_subscriber(list, "John Smith");

    // Send another message to all subscribers on the mailing list.
    send_message(list, "Goodbye, John!");

    // Free the memory used by the mailing list.
    free_mailing_list(list);

    return 0;
}