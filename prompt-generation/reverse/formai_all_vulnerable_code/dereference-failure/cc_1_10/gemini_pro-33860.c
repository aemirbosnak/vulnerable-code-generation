//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 255

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 255

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Define the maximum number of messages
#define MAX_MESSAGES 100

// Define the structure of a subscriber
typedef struct subscriber {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
    int subscribed;
} subscriber_t;

// Define the structure of a message
typedef struct message {
    char subject[MAX_MESSAGE_LENGTH];
    char body[MAX_MESSAGE_LENGTH];
    int sent;
} message_t;

// Define the structure of the mailing list manager
typedef struct mailing_list_manager {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
    message_t messages[MAX_MESSAGES];
    int num_messages;
} mailing_list_manager_t;

// Create a new mailing list manager
mailing_list_manager_t *create_mailing_list_manager() {
    mailing_list_manager_t *manager = malloc(sizeof(mailing_list_manager_t));
    manager->num_subscribers = 0;
    manager->num_messages = 0;
    return manager;
}

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list_manager_t *manager, char *email, char *name) {
    if (manager->num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    strcpy(manager->subscribers[manager->num_subscribers].email, email);
    strcpy(manager->subscribers[manager->num_subscribers].name, name);
    manager->subscribers[manager->num_subscribers].subscribed = 1;
    manager->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list_manager_t *manager, char *email) {
    int i;

    for (i = 0; i < manager->num_subscribers; i++) {
        if (strcmp(manager->subscribers[i].email, email) == 0) {
            manager->subscribers[i].subscribed = 0;
            return;
        }
    }

    printf("Error: Subscriber not found.\n");
}

// Send a message to all subscribers
void send_message(mailing_list_manager_t *manager, char *subject, char *body) {
    int i;

    for (i = 0; i < manager->num_subscribers; i++) {
        if (manager->subscribers[i].subscribed) {
            printf("Sending message to %s (%s)\n", manager->subscribers[i].name, manager->subscribers[i].email);
            // Send the message to the subscriber
        }
    }

    strcpy(manager->messages[manager->num_messages].subject, subject);
    strcpy(manager->messages[manager->num_messages].body, body);
    manager->messages[manager->num_messages].sent = 1;
    manager->num_messages++;
}

// Print the list of subscribers
void print_subscribers(mailing_list_manager_t *manager) {
    int i;

    printf("Subscribers:\n");
    for (i = 0; i < manager->num_subscribers; i++) {
        printf("%s (%s)\n", manager->subscribers[i].name, manager->subscribers[i].email);
    }
}

// Print the list of messages
void print_messages(mailing_list_manager_t *manager) {
    int i;

    printf("Messages:\n");
    for (i = 0; i < manager->num_messages; i++) {
        printf("%s\n", manager->messages[i].subject);
    }
}

// Free the memory allocated for the mailing list manager
void free_mailing_list_manager(mailing_list_manager_t *manager) {
    free(manager);
}

// Main function
int main() {
    mailing_list_manager_t *manager;

    // Create a new mailing list manager
    manager = create_mailing_list_manager();

    // Add some subscribers to the mailing list
    add_subscriber(manager, "john@example.com", "John Doe");
    add_subscriber(manager, "jane@example.com", "Jane Doe");

    // Send a message to all subscribers
    send_message(manager, "Hello, world!", "This is a test message.");

    // Print the list of subscribers
    print_subscribers(manager);

    // Print the list of messages
    print_messages(manager);

    // Free the memory allocated for the mailing list manager
    free_mailing_list_manager(manager);

    return 0;
}