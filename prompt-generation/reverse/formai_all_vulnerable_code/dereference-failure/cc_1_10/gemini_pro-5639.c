//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char *email;
    char *name;
    struct subscriber *next;
};

struct mailing_list {
    struct subscriber *head;
    int count;
};

struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void free_mailing_list(struct mailing_list *list) {
    struct subscriber *current = list->head;
    while (current) {
        struct subscriber *next = current->next;
        free(current->email);
        free(current->name);
        free(current);
        current = next;
    }
    free(list);
}

int add_subscriber(struct mailing_list *list, char *email, char *name) {
    if (!list || !email || !name) {
        return -1;
    }

    // Check if the subscriber is already in the list
    struct subscriber *current = list->head;
    while (current) {
        if (strcmp(current->email, email) == 0) {
            return -2;
        }
        current = current->next;
    }

    // Create a new subscriber
    struct subscriber *new_subscriber = malloc(sizeof(struct subscriber));
    if (!new_subscriber) {
        return -3;
    }
    new_subscriber->email = strdup(email);
    new_subscriber->name = strdup(name);
    new_subscriber->next = NULL;

    // Add the new subscriber to the list
    if (list->head) {
        new_subscriber->next = list->head;
    }
    list->head = new_subscriber;
    list->count++;

    return 0;
}

int remove_subscriber(struct mailing_list *list, char *email) {
    if (!list || !email) {
        return -1;
    }

    // Find the subscriber to remove
    struct subscriber *current = list->head;
    struct subscriber *previous = NULL;
    while (current && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    // If the subscriber was not found, return -2
    if (!current) {
        return -2;
    }

    // Remove the subscriber from the list
    if (previous) {
        previous->next = current->next;
    } else {
        list->head = current->next;
    }
    free(current->email);
    free(current->name);
    free(current);
    list->count--;

    return 0;
}

int send_email(struct mailing_list *list, char *subject, char *body) {
    if (!list || !subject || !body) {
        return -1;
    }

    // Iterate over the subscribers and send an email to each one
    struct subscriber *current = list->head;
    while (current) {
        // TODO: Send an email to current->email with subject and body
        current = current->next;
    }

    return 0;
}

int main() {
    // Create a new mailing list
    struct mailing_list *list = create_mailing_list();

    // Add some subscribers to the list
    add_subscriber(list, "alice@example.com", "Alice");
    add_subscriber(list, "bob@example.com", "Bob");
    add_subscriber(list, "charlie@example.com", "Charlie");

    // Send an email to all subscribers
    send_email(list, "Hello", "This is a test email");

    // Remove a subscriber from the list
    remove_subscriber(list, "bob@example.com");

    // Send another email to all subscribers
    send_email(list, "Goodbye", "This is a goodbye email");

    // Free the mailing list
    free_mailing_list(list);

    return 0;
}