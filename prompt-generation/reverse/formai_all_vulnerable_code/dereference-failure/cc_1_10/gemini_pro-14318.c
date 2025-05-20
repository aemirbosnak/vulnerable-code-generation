//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of a subscriber's name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a subscriber's email address
#define MAX_EMAIL_LENGTH 50

// Define the structure of a subscriber
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber_t;

// Define the structure of the mailing list
typedef struct mailing_list {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list_t;

// Create a new mailing list
mailing_list_t* create_mailing_list() {
    mailing_list_t* mailing_list = malloc(sizeof(mailing_list_t));
    mailing_list->num_subscribers = 0;
    return mailing_list;
}

// Add a subscriber to the mailing list
void add_subscriber(mailing_list_t* mailing_list, char* name, char* email) {
    if (mailing_list->num_subscribers < MAX_SUBSCRIBERS) {
        strcpy(mailing_list->subscribers[mailing_list->num_subscribers].name, name);
        strcpy(mailing_list->subscribers[mailing_list->num_subscribers].email, email);
        mailing_list->num_subscribers++;
    } else {
        printf("Error: The mailing list is full.\n");
    }
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list_t* mailing_list, char* email) {
    int i;
    for (i = 0; i < mailing_list->num_subscribers; i++) {
        if (strcmp(mailing_list->subscribers[i].email, email) == 0) {
            mailing_list->num_subscribers--;
            mailing_list->subscribers[i] = mailing_list->subscribers[mailing_list->num_subscribers];
            break;
        }
    }
}

// Send a message to all subscribers on the mailing list
void send_message(mailing_list_t* mailing_list, char* subject, char* body) {
    int i;
    for (i = 0; i < mailing_list->num_subscribers; i++) {
        printf("To: %s <%s>\n", mailing_list->subscribers[i].name, mailing_list->subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n\n", body);
    }
}

// Print the mailing list
void print_mailing_list(mailing_list_t* mailing_list) {
    int i;
    for (i = 0; i < mailing_list->num_subscribers; i++) {
        printf("%s <%s>\n", mailing_list->subscribers[i].name, mailing_list->subscribers[i].email);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list_t* mailing_list) {
    free(mailing_list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list_t* mailing_list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(mailing_list, "John Doe", "john.doe@example.com");
    add_subscriber(mailing_list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(mailing_list, "Bob Smith", "bob.smith@example.com");

    // Print the mailing list
    printf("Mailing list:\n");
    print_mailing_list(mailing_list);

    // Send a message to all subscribers on the mailing list
    send_message(mailing_list, "Hello, world!", "This is a test message.");

    // Remove a subscriber from the mailing list
    remove_subscriber(mailing_list, "bob.smith@example.com");

    // Print the mailing list again
    printf("\nMailing list after removing Bob Smith:\n");
    print_mailing_list(mailing_list);

    // Free the memory allocated for the mailing list
    free_mailing_list(mailing_list);

    return 0;
}