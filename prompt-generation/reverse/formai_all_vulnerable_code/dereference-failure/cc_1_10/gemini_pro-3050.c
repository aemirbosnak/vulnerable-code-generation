//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the maximum length of an email address
#define MAX_EMAIL_LENGTH 255

// Define the maximum length of a subject line
#define MAX_SUBJECT_LENGTH 255

// Define the maximum length of an email body
#define MAX_BODY_LENGTH 1024

// Declare the subscriber struct
typedef struct subscriber {
    char email[MAX_EMAIL_LENGTH];
} subscriber;

// Declare the mailing list struct
typedef struct mailing_list {
    subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
} mailing_list;

// Create a new mailing list
mailing_list* create_mailing_list() {
    mailing_list* list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    return list;
}

// Add a subscriber to the mailing list
void add_subscriber(mailing_list* list, char* email) {
    if (list->num_subscribers < MAX_SUBSCRIBERS) {
        strcpy(list->subscribers[list->num_subscribers].email, email);
        list->num_subscribers++;
    } else {
        printf("Error: The mailing list is full.\n");
    }
}

// Remove a subscriber from the mailing list
void remove_subscriber(mailing_list* list, char* email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i + 1; j < list->num_subscribers; j++) {
                list->subscribers[j - 1] = list->subscribers[j];
            }
            list->num_subscribers--;
            break;
        }
    }
}

// Send an email to all subscribers on the mailing list
void send_email(mailing_list* list, char* subject, char* body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("Sending email to: %s\n", list->subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
    }
}

// Print the subscribers on the mailing list
void print_subscribers(mailing_list* list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s\n", list->subscribers[i].email);
    }
}

// Get the number of subscribers on the mailing list
int get_num_subscribers(mailing_list* list) {
    return list->num_subscribers;
}

// Get the subscriber at the specified index
subscriber get_subscriber(mailing_list* list, int index) {
    return list->subscribers[index];
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list* list) {
    free(list);
}

int main() {
    // Create a new mailing list
    mailing_list* list = create_mailing_list();

    // Add some subscribers to the mailing list
    add_subscriber(list, "alice@example.com");
    add_subscriber(list, "bob@example.com");
    add_subscriber(list, "carol@example.com");

    // Print the subscribers on the mailing list
    printf("Subscribers:\n");
    print_subscribers(list);

    // Send an email to all subscribers on the mailing list
    send_email(list, "Hello, world!", "This is a test email.");

    // Get the number of subscribers on the mailing list
    int num_subscribers = get_num_subscribers(list);
    printf("Number of subscribers: %d\n", num_subscribers);

    // Get the subscriber at the specified index
    subscriber subscriber = get_subscriber(list, 0);
    printf("Subscriber at index 0: %s\n", subscriber.email);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}