//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct subscriber {
    char name[50];
    char email[50];
} subscriber;

// Define the structure of the mailing list
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a new subscriber to the mailing list
void add_subscriber(mailing_list *list, char *name, char *email) {
    // Check if the list is full
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: The mailing list is full.\n");
        return;
    }

    // Add the new subscriber to the list
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list *list, char *email) {
    // Find the subscriber to remove
    int index = -1;
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            index = i;
            break;
        }
    }

    // If the subscriber was not found, return
    if (index == -1) {
        printf("Error: The subscriber was not found.\n");
        return;
    }

    // Remove the subscriber from the list
    for (int i = index; i < list->num_subscribers - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }
    list->num_subscribers--;
}

// Send a message to all subscribers
void send_message(mailing_list *list, char *subject, char *body) {
    // Iterate over the subscribers and send the message
    for (int i = 0; i < list->num_subscribers; i++) {
        // TODO: Implement the code to send the message
        printf("Sending message to %s (%s):\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
    }
}

// Print the contents of the mailing list
void print_mailing_list(mailing_list *list) {
    // Iterate over the subscribers and print their information
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Free the memory used by the mailing list
void free_mailing_list(mailing_list *list) {
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the list
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Bob Smith", "bob.smith@example.com");

    // Print the contents of the mailing list
    printf("Mailing list:\n");
    print_mailing_list(list);

    // Send a message to all subscribers
    send_message(list, "Hello, world!", "This is a test message.");

    // Remove a subscriber from the list
    remove_subscriber(list, "bob.smith@example.com");

    // Print the contents of the mailing list
    printf("\nMailing list after removing a subscriber:\n");
    print_mailing_list(list);

    // Free the memory used by the mailing list
    free_mailing_list(list);

    return 0;
}