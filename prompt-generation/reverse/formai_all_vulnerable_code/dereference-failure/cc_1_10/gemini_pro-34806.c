//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
// A Claude Shannon-inspired mailing list manager in C
// (Yes, the information theorist Claude Shannon, not the mathematician)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the doubly linked list that represents a mailing list subscriber
typedef struct subscriber {
    char *email;
    struct subscriber *next;
    struct subscriber *prev;
} subscriber_t;

// The mailing list itself is represented as a doubly linked list of subscribers
typedef struct mailing_list {
    subscriber_t *head;
    subscriber_t *tail;
    int size;
} mailing_list_t;

// Create a new mailing list
mailing_list_t *create_mailing_list() {
    mailing_list_t *list = malloc(sizeof(mailing_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list_t *list, char *email) {
    subscriber_t *new_subscriber = malloc(sizeof(subscriber_t));
    new_subscriber->email = strdup(email);
    new_subscriber->next = NULL;
    new_subscriber->prev = NULL;

    if (list->head == NULL) {
        list->head = new_subscriber;
        list->tail = new_subscriber;
    } else {
        new_subscriber->next = list->head;
        list->head->prev = new_subscriber;
        list->head = new_subscriber;
    }

    list->size++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list_t *list, char *email) {
    subscriber_t *current = list->head;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (current == list->head) {
                list->head = current->next;
            } else {
                current->prev->next = current->next;
            }

            if (current == list->tail) {
                list->tail = current->prev;
            } else {
                current->next->prev = current->prev;
            }

            free(current->email);
            free(current);
            list->size--;
            return;
        }

        current = current->next;
    }
}

// Send a message to all subscribers on the mailing list
void send_message(mailing_list_t *list, char *message) {
    subscriber_t *current = list->head;

    while (current != NULL) {
        printf("Sending message to %s: %s\n", current->email, message);
        current = current->next;
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list_t *list) {
    subscriber_t *current = list->head;

    while (current != NULL) {
        subscriber_t *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }

    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list_t *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "alice@example.com");
    add_subscriber(list, "bob@example.com");
    add_subscriber(list, "charlie@example.com");

    // Send a message to all subscribers on the mailing list
    send_message(list, "Hello, world!");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob@example.com");

    // Send a message to all subscribers on the mailing list again
    send_message(list, "Goodbye, Bob!");

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}