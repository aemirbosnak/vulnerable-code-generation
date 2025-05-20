//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 50

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1000

// Declare the subscriber struct
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

// Declare the mailing list struct
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
    char message[MAX_MESSAGE_LENGTH];
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    strcpy(list->message, "");
    return list;
}

// Add a subscriber to a mailing list
void add_subscriber(mailing_list *list, char *name, char *email) {
    if (list->num_subscribers < MAX_SUBSCRIBERS) {
        strcpy(list->subscribers[list->num_subscribers].name, name);
        strcpy(list->subscribers[list->num_subscribers].email, email);
        list->num_subscribers++;
    } else {
        printf("Error: Mailing list is full.\n");
    }
}

// Remove a subscriber from a mailing list
void remove_subscriber(mailing_list *list, char *name) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            for (int j = i + 1; j < list->num_subscribers; j++) {
                list->subscribers[j - 1] = list->subscribers[j];
            }
            list->num_subscribers--;
            break;
        }
    }
}

// Send a message to all subscribers on a mailing list
void send_message(mailing_list *list, char *message) {
    strcpy(list->message, message);
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("Sending message to %s at %s:\n%s\n",
               list->subscribers[i].name,
               list->subscribers[i].email,
               message);
    }
}

// Print the subscribers on a mailing list
void print_subscribers(mailing_list *list) {
    printf("Subscribers:\n");
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s (%s)\n",
               list->subscribers[i].name,
               list->subscribers[i].email);
    }
}

// Free the memory allocated for a mailing list
void free_mailing_list(mailing_list *list) {
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Bob Smith", "bob.smith@example.com");

    // Print the subscribers on the mailing list
    print_subscribers(list);

    // Send a message to all subscribers on the mailing list
    send_message(list, "Hello, everyone!\n\nThis is a test message.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "Bob Smith");

    // Print the subscribers on the mailing list
    print_subscribers(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}