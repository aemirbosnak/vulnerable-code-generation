//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char name[50];
    char email[50];
    struct subscriber *next;
};

struct mailing_list {
    struct subscriber *head;
};

void add_subscriber(struct mailing_list *list, const char *name, const char *email) {
    struct subscriber *new_subscriber = (struct subscriber *)malloc(sizeof(struct subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;

    if (!list->head) {
        list->head = new_subscriber;
    } else {
        // Find the last subscriber
        struct subscriber *current = list->head;
        while (current->next) {
            current = current->next;
        }
        // Add the new subscriber to the end of the list
        current->next = new_subscriber;
    }
}

void remove_subscriber(struct mailing_list *list, const char *email) {
    struct subscriber *current = list->head;
    struct subscriber *prev = NULL;

    while (current) {
        if (!strcmp(current->email, email)) {
            if (!prev) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void send_email(struct mailing_list *list, const char *subject, const char *message) {
    struct subscriber *current = list->head;

    while (current) {
        // Send an email to the subscriber
        printf("Sending email to %s <%s>\n", current->name, current->email);
        printf("Subject: %s\n", subject);
        printf("Message: %s\n", message);

        current = current->next;
    }
}

int main() {
    struct mailing_list list;
    list.head = NULL;

    // Add some subscribers
    add_subscriber(&list, "John Smith", "john.smith@example.com");
    add_subscriber(&list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(&list, "Bob Jones", "bob.jones@example.com");

    // Remove a subscriber
    remove_subscriber(&list, "jane.doe@example.com");

    // Send an email to all subscribers
    send_email(&list, "Hello from the mailing list!", "This is just a test email.");

    // Free the memory allocated for the mailing list
    struct subscriber *current = list.head;
    while (current) {
        struct subscriber *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}