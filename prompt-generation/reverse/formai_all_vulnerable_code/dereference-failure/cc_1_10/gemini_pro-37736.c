//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A linked list node to store a subscriber
struct Subscriber {
    char email[100];
    struct Subscriber *next;
};

// The mailing list
struct MailingList {
    char name[100];
    struct Subscriber *head;
    int num_subscribers;
};

// Create a new mailing list
struct MailingList *create_mailing_list(char *name) {
    struct MailingList *list = malloc(sizeof(struct MailingList));
    strcpy(list->name, name);
    list->head = NULL;
    list->num_subscribers = 0;
    return list;
}

// Subscribe an email to a mailing list
void subscribe(struct MailingList *list, char *email) {
    // Create a new subscriber
    struct Subscriber *subscriber = malloc(sizeof(struct Subscriber));
    strcpy(subscriber->email, email);
    subscriber->next = NULL;

    // Add the subscriber to the mailing list
    if (list->head == NULL) {
        list->head = subscriber;
    } else {
        struct Subscriber *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = subscriber;
    }

    list->num_subscribers++;
}

// Unsubscribe an email from a mailing list
void unsubscribe(struct MailingList *list, char *email) {
    // Find the subscriber to unsubscribe
    struct Subscriber *current = list->head;
    struct Subscriber *prev = NULL;
    while (current != NULL && strcmp(current->email, email) != 0) {
        prev = current;
        current = current->next;
    }

    // If the subscriber was found, remove it from the mailing list
    if (current != NULL) {
        if (prev == NULL) {
            list->head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        list->num_subscribers--;
    }
}

// Send an email to all subscribers of a mailing list
void send_email(struct MailingList *list, char *subject, char *body) {
    // Iterate through the subscribers and send an email to each one
    struct Subscriber *current = list->head;
    while (current != NULL) {
        // The actual sending of the email would go here, but this is just a simulation
        printf("Sending email to: %s\n", current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        current = current->next;
    }
}

// Print the details of a mailing list
void print_mailing_list(struct MailingList *list) {
    printf("Mailing List: %s\n", list->name);
    printf("Number of subscribers: %d\n", list->num_subscribers);
    printf("Subscribers:\n");
    struct Subscriber *current = list->head;
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

// Free the memory allocated for a mailing list
void free_mailing_list(struct MailingList *list) {
    struct Subscriber *current = list->head;
    while (current != NULL) {
        struct Subscriber *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    // Create a new mailing list
    struct MailingList *list = create_mailing_list("My Mailing List");

    // Subscribe some emails to the mailing list
    subscribe(list, "alice@example.com");
    subscribe(list, "bob@example.com");
    subscribe(list, "charlie@example.com");

    // Print the details of the mailing list
    print_mailing_list(list);

    // Send an email to all subscribers of the mailing list
    send_email(list, "Hello from the mailing list!", "This is just a test email.");

    // Unsubscribe an email from the mailing list
    unsubscribe(list, "alice@example.com");

    // Print the details of the mailing list again
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}