//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers and messages.
#define MAX_SUBSCRIBERS 100
#define MAX_MESSAGES 1000

// Define the subscriber structure.
typedef struct subscriber {
    char name[50];
    char email[50];
} subscriber_t;

// Define the message structure.
typedef struct message {
    char subject[50];
    char body[1000];
    int sender;
    int recipients[100];
    int num_recipients;
} message_t;

// Define the mailing list manager structure.
typedef struct mailing_list_manager {
    subscriber_t subscribers[MAX_SUBSCRIBERS];
    message_t messages[MAX_MESSAGES];
    int num_subscribers;
    int num_messages;
} mailing_list_manager_t;

// Create a new mailing list manager.
mailing_list_manager_t* create_mailing_list_manager() {
    mailing_list_manager_t* manager = (mailing_list_manager_t*)malloc(sizeof(mailing_list_manager_t));
    manager->num_subscribers = 0;
    manager->num_messages = 0;
    return manager;
}

// Add a new subscriber to the mailing list.
void add_subscriber(mailing_list_manager_t* manager, char* name, char* email) {
    strcpy(manager->subscribers[manager->num_subscribers].name, name);
    strcpy(manager->subscribers[manager->num_subscribers].email, email);
    manager->num_subscribers++;
}

// Send a new message to the mailing list.
void send_message(mailing_list_manager_t* manager, char* subject, char* body, int sender, int* recipients, int num_recipients) {
    strcpy(manager->messages[manager->num_messages].subject, subject);
    strcpy(manager->messages[manager->num_messages].body, body);
    manager->messages[manager->num_messages].sender = sender;
    for (int i = 0; i < num_recipients; i++) {
        manager->messages[manager->num_messages].recipients[i] = recipients[i];
    }
    manager->messages[manager->num_messages].num_recipients = num_recipients;
    manager->num_messages++;
}

// Print the contents of the mailing list.
void print_mailing_list(mailing_list_manager_t* manager) {
    printf("Subscribers:\n");
    for (int i = 0; i < manager->num_subscribers; i++) {
        printf("%s (%s)\n", manager->subscribers[i].name, manager->subscribers[i].email);
    }
    printf("\nMessages:\n");
    for (int i = 0; i < manager->num_messages; i++) {
        printf("Subject: %s\n", manager->messages[i].subject);
        printf("Body: %s\n", manager->messages[i].body);
        printf("Sender: %s\n", manager->subscribers[manager->messages[i].sender].name);
        printf("Recipients:\n");
        for (int j = 0; j < manager->messages[i].num_recipients; j++) {
            printf("- %s\n", manager->subscribers[manager->messages[i].recipients[j]].name);
        }
        printf("\n");
    }
}

// Free the memory allocated for the mailing list manager.
void free_mailing_list_manager(mailing_list_manager_t* manager) {
    free(manager);
}

// Main function.
int main() {
    // Create a new mailing list manager.
    mailing_list_manager_t* manager = create_mailing_list_manager();

    // Add some subscribers to the mailing list.
    add_subscriber(manager, "John Doe", "john.doe@example.com");
    add_subscriber(manager, "Jane Smith", "jane.smith@example.com");
    add_subscriber(manager, "Bob Jones", "bob.jones@example.com");

    // Send some messages to the mailing list.
    send_message(manager, "Welcome to the mailing list!", "This is a welcome message to the mailing list.", 0, NULL, 0);
    send_message(manager, "Important announcement", "This is an important announcement.", 0, (int[]){1, 2}, 2);

    // Print the contents of the mailing list.
    print_mailing_list(manager);

    // Free the memory allocated for the mailing list manager.
    free_mailing_list_manager(manager);

    return 0;
}