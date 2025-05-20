//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a mailing list
typedef struct mailing_list {
    char **subscribers;
    int num_subscribers;
    int capacity;
} mailing_list;

// Function to create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->subscribers = malloc(sizeof(char *) * 10);
    list->num_subscribers = 0;
    list->capacity = 10;
    return list;
}

// Function to add a subscriber to the mailing list
void add_subscriber(mailing_list *list, char *subscriber) {
    // Check if the list is full
    if (list->num_subscribers == list->capacity) {
        // Double the capacity of the list
        list->capacity *= 2;
        list->subscribers = realloc(list->subscribers, sizeof(char *) * list->capacity);
    }

    // Add the subscriber to the list
    list->subscribers[list->num_subscribers] = malloc(strlen(subscriber) + 1);
    strcpy(list->subscribers[list->num_subscribers], subscriber);
    list->num_subscribers++;
}

// Function to remove a subscriber from the mailing list
void remove_subscriber(mailing_list *list, char *subscriber) {
    // Find the index of the subscriber in the list
    int index = -1;
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i], subscriber) == 0) {
            index = i;
            break;
        }
    }

    // If the subscriber was not found, do nothing
    if (index == -1) {
        return;
    }

    // Remove the subscriber from the list
    free(list->subscribers[index]);
    list->num_subscribers--;

    // Shift the subscribers after the removed subscriber to the left
    for (int i = index; i < list->num_subscribers; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }
}

// Function to send a message to all subscribers on the mailing list
void send_message(mailing_list *list, char *message) {
    // Loop through the subscribers and send the message to each one
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("Sending message to %s: %s\n", list->subscribers[i], message);
    }
}

// Function to print the mailing list
void print_mailing_list(mailing_list *list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s\n", list->subscribers[i]);
    }
}

// Function to free the memory allocated for the mailing list
void free_mailing_list(mailing_list *list) {
    // Free the memory allocated for each subscriber
    for (int i = 0; i < list->num_subscribers; i++) {
        free(list->subscribers[i]);
    }

    // Free the memory allocated for the list
    free(list);
}

// Driver code
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the list
    add_subscriber(list, "Alice");
    add_subscriber(list, "Bob");
    add_subscriber(list, "Carol");
    add_subscriber(list, "Dave");
    add_subscriber(list, "Eve");

    // Print the mailing list
    print_mailing_list(list);

    // Send a message to all subscribers on the list
    send_message(list, "Hello everyone!");

    // Remove a subscriber from the list
    remove_subscriber(list, "Carol");

    // Print the mailing list
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}