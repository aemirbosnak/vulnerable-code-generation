//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 100

// Define the structure of a subscriber
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
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

// Add a subscriber to the mailing list
void add_subscriber(mailing_list *list, char *name, char *email) {
    // Check if the list is full
    if (list->num_subscribers == MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full\n");
        return;
    }

    // Copy the subscriber's name and email address to the list
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);

    // Increment the number of subscribers
    list->num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list *list, char *email) {
    // Find the subscriber's index in the list
    int index = -1;
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            index = i;
            break;
        }
    }

    // Check if the subscriber was found
    if (index == -1) {
        printf("Error: Subscriber not found\n");
        return;
    }

    // Shift the subscribers down to fill the gap
    for (int i = index; i < list->num_subscribers - 1; i++) {
        strcpy(list->subscribers[i].name, list->subscribers[i + 1].name);
        strcpy(list->subscribers[i].email, list->subscribers[i + 1].email);
    }

    // Decrement the number of subscribers
    list->num_subscribers--;
}

// Send an email to all subscribers on the mailing list
void send_email(mailing_list *list, char *subject, char *body) {
    // Iterate over the subscribers and send an email to each one
    for (int i = 0; i < list->num_subscribers; i++) {
        // Create the email message
        char message[1024];
        sprintf(message, "To: %s <%s>\nSubject: %s\n\n%s\n",
                list->subscribers[i].name, list->subscribers[i].email, subject, body);

        // Send the email
        printf("Sending email to %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("%s\n", message);
    }
}

// Print the mailing list
void print_mailing_list(mailing_list *list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list *list) {
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Smith", "jane.smith@example.com");
    add_subscriber(list, "Bob Jones", "bob.jones@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Send an email to all subscribers on the mailing list
    send_email(list, "Test email", "This is a test email.");

    // Remove a subscriber from the mailing list
    remove_subscriber(list, "bob.jones@example.com");

    // Print the mailing list again
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}