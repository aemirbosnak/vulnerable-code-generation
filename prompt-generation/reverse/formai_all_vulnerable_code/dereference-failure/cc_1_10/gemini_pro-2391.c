//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the mailing list
struct mailing_list {
    char **emails;
    int num_emails;
    int capacity;
};

void mailing_list_init(struct mailing_list *list) {
    list->emails = NULL;
    list->num_emails = 0;
    list->capacity = 0;
}

// Add an email to the mailing list
void mailing_list_add(struct mailing_list *list, char *email) {
    // Resize the list if necessary
    if (list->num_emails == list->capacity) {
        list->capacity *= 2;
        list->emails = realloc(list->emails, list->capacity * sizeof(char *));
    }

    // Add the email to the list
    list->emails[list->num_emails++] = strdup(email);
}

// Remove an email from the mailing list
void mailing_list_remove(struct mailing_list *list, char *email) {
    int i;

    // Find the email in the list
    for (i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            break;
        }
    }

    // If the email was found, remove it from the list
    if (i < list->num_emails) {
        for (i++; i < list->num_emails; i++) {
            list->emails[i - 1] = list->emails[i];
        }
        list->num_emails--;
    }
}

// Send a message to all emails on the mailing list
void mailing_list_send_message(struct mailing_list *list, char *message) {
    int i;

    // Send the message to each email on the list
    for (i = 0; i < list->num_emails; i++) {
        printf("Sending message to %s: %s\n", list->emails[i], message);
    }
}

// Free the memory allocated for the mailing list
void mailing_list_free(struct mailing_list *list) {
    int i;

    // Free the memory allocated for each email
    for (i = 0; i < list->num_emails; i++) {
        free(list->emails[i]);
    }

    // Free the memory allocated for the list itself
    free(list->emails);
}

// A simple test program
int main() {
    struct mailing_list list;

    // Initialize the mailing list
    mailing_list_init(&list);

    // Add some emails to the mailing list
    mailing_list_add(&list, "alice@example.com");
    mailing_list_add(&list, "bob@example.com");
    mailing_list_add(&list, "carol@example.com");

    // Send a message to the mailing list
    mailing_list_send_message(&list, "Hello, world!");

    // Remove an email from the mailing list
    mailing_list_remove(&list, "bob@example.com");

    // Free the memory allocated for the mailing list
    mailing_list_free(&list);

    return 0;
}