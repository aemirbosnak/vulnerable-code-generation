//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store a subscriber's data
typedef struct subscriber {
    char *email;
    char *name;
    bool subscribed;
} subscriber;

// Structure to store the mailing list
typedef struct mailing_list {
    size_t size;
    size_t capacity;
    subscriber *subscribers;
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list(size_t initial_capacity) {
    mailing_list *list = malloc(sizeof(mailing_list));
    if (!list) {
        return NULL;
    }

    list->size = 0;
    list->capacity = initial_capacity;
    list->subscribers = malloc(sizeof(subscriber) * initial_capacity);
    if (!list->subscribers) {
        free(list);
        return NULL;
    }

    return list;
}

// Free the resources used by a mailing list
void free_mailing_list(mailing_list *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->subscribers[i].email);
        free(list->subscribers[i].name);
    }

    free(list->subscribers);
    free(list);
}

// Add a new subscriber to a mailing list
bool add_subscriber(mailing_list *list, char *email, char *name) {
    // Check if the mailing list is full
    if (list->size == list->capacity) {
        // Double the capacity of the mailing list
        list->capacity *= 2;
        list->subscribers = realloc(list->subscribers, sizeof(subscriber) * list->capacity);
        if (!list->subscribers) {
            return false;
        }
    }

    // Add the new subscriber to the mailing list
    list->subscribers[list->size].email = strdup(email);
    list->subscribers[list->size].name = strdup(name);
    list->subscribers[list->size].subscribed = true;
    list->size++;

    return true;
}

// Remove a subscriber from a mailing list
bool remove_subscriber(mailing_list *list, char *email) {
    // Find the subscriber to remove
    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            // Remove the subscriber from the mailing list
            free(list->subscribers[i].email);
            free(list->subscribers[i].name);
            list->size--;

            // Move the remaining subscribers down one position
            for (size_t j = i; j < list->size; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }

            return true;
        }
    }

    return false;
}

// Send an email to all subscribers in a mailing list
bool send_email(mailing_list *list, char *subject, char *body) {
    // Send the email to each subscriber
    for (size_t i = 0; i < list->size; i++) {
        if (list->subscribers[i].subscribed) {
            // Send the email
            printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
            printf("Subject: %s\n", subject);
            printf("Body: %s\n", body);
            printf("\n");
        }
    }

    return true;
}

// Print the subscribers in a mailing list
void print_mailing_list(mailing_list *list) {
    printf("Mailing list:\n");
    for (size_t i = 0; i < list->size; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list(10);

    // Add some subscribers to the mailing list
    add_subscriber(list, "john.doe@example.com", "John Doe");
    add_subscriber(list, "jane.doe@example.com", "Jane Doe");
    add_subscriber(list, "bob.smith@example.com", "Bob Smith");

    // Print the subscribers in the mailing list
    print_mailing_list(list);

    // Send an email to all subscribers in the mailing list
    send_email(list, "Welcome to the mailing list!", "This is a test email.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "jane.doe@example.com");

    // Print the subscribers in the mailing list
    print_mailing_list(list);

    // Free the resources used by the mailing list
    free_mailing_list(list);

    return 0;
}