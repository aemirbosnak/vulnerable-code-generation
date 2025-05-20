//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple mailing list manager.

// A mailing list is a collection of email addresses.
struct mailing_list {
    char **emails;
    int num_emails;
};

// Create a new mailing list.
struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->emails = malloc(0);
    list->num_emails = 0;
    return list;
}

// Free a mailing list.
void free_mailing_list(struct mailing_list *list) {
    for (int i = 0; i < list->num_emails; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

// Add an email address to a mailing list.
void add_email_to_mailing_list(struct mailing_list *list, char *email) {
    list->emails = realloc(list->emails, (list->num_emails + 1) * sizeof(char *));
    list->emails[list->num_emails] = strdup(email);
    list->num_emails++;
}

// Remove an email address from a mailing list.
void remove_email_from_mailing_list(struct mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            break;
        }
    }
    if (i < list->num_emails) {
        list->emails[i] = list->emails[list->num_emails - 1];
        list->num_emails--;
    }
}

// Send an email to all the addresses on a mailing list.
void send_email_to_mailing_list(struct mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->num_emails; i++) {
        // TODO: Actually send the email.
        printf("Sending email to %s\n", list->emails[i]);
    }
}

// Print the contents of a mailing list.
void print_mailing_list(struct mailing_list *list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list->num_emails; i++) {
        printf("  %s\n", list->emails[i]);
    }
}

int main() {
    // Create a new mailing list.
    struct mailing_list *list = create_mailing_list();

    // Add some email addresses to the mailing list.
    add_email_to_mailing_list(list, "john@example.com");
    add_email_to_mailing_list(list, "mary@example.com");
    add_email_to_mailing_list(list, "bob@example.com");

    // Print the contents of the mailing list.
    print_mailing_list(list);

    // Send an email to all the addresses on the mailing list.
    send_email_to_mailing_list(list, "Hello, world!", "This is a test email.");

    // Free the mailing list.
    free_mailing_list(list);

    return 0;
}