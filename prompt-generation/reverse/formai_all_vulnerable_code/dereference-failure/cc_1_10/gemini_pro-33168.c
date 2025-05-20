//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list of subscribers
typedef struct subscriber {
    char *email;
    struct subscriber *next;
} subscriber;

// The mailing list
typedef struct mailing_list {
    subscriber *head;
    subscriber *tail;
    int size;
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Free the memory used by the mailing list
void free_mailing_list(mailing_list *list) {
    subscriber *current = list->head;
    while (current != NULL) {
        subscriber *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    free(list);
}

// Add a new subscriber to the mailing list
int add_subscriber(mailing_list *list, char *email) {
    subscriber *new_subscriber = malloc(sizeof(subscriber));
    if (new_subscriber == NULL) {
        return 1;
    }
    new_subscriber->email = strdup(email);
    new_subscriber->next = NULL;
    if (list->head == NULL) {
        list->head = new_subscriber;
        list->tail = new_subscriber;
    } else {
        list->tail->next = new_subscriber;
        list->tail = new_subscriber;
    }
    list->size++;
    return 0;
}

// Remove a subscriber from the mailing list
int remove_subscriber(mailing_list *list, char *email) {
    subscriber *current = list->head;
    subscriber *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            if (current == list->tail) {
                list->tail = previous;
            }
            free(current->email);
            free(current);
            list->size--;
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return 1;
}

// Send a message to all subscribers on the mailing list
int send_message(mailing_list *list, char *subject, char *body) {
    subscriber *current = list->head;
    while (current != NULL) {
        // Send the message to the current subscriber
        printf("Sending message to %s:\n", current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        current = current->next;
    }
    return 0;
}

// Print the list of subscribers
void print_subscribers(mailing_list *list) {
    subscriber *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Get a line of input from the user
char *get_input() {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

// The main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "alice@example.com");
    add_subscriber(list, "bob@example.com");
    add_subscriber(list, "charlie@example.com");

    // Print the list of subscribers
    printf("Subscribers:\n");
    print_subscribers(list);

    // Send a message to all subscribers on the mailing list
    send_message(list, "Hello, world!", "This is a test message.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob@example.com");

    // Print the list of subscribers
    printf("\nSubscribers:\n");
    print_subscribers(list);

    // Free the memory used by the mailing list
    free_mailing_list(list);

    return 0;
}