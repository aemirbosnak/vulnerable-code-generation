//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mailing list manager in the style of Dennis Ritchie

// A mailing list is a collection of email addresses.
struct mailing_list {
    char **emails;
    int num_emails;
};

// Create a new mailing list.
struct mailing_list *new_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->emails = NULL;
    list->num_emails = 0;
    return list;
}

// Add an email address to the mailing list.
void add_email(struct mailing_list *list, char *email) {
    list->emails = realloc(list->emails, (list->num_emails + 1) * sizeof(char *));
    list->emails[list->num_emails] = strdup(email);
    list->num_emails++;
}

// Remove an email address from the mailing list.
void remove_email(struct mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            free(list->emails[i]);
            list->emails[i] = list->emails[list->num_emails - 1];
            list->num_emails--;
            break;
        }
    }
}

// Print the mailing list.
void print_mailing_list(struct mailing_list *list) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        printf("%s\n", list->emails[i]);
    }
}

// Free the memory used by the mailing list.
void free_mailing_list(struct mailing_list *list) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

// Main function.
int main() {
    // Create a new mailing list.
    struct mailing_list *list = new_mailing_list();

    // Add some email addresses to the mailing list.
    add_email(list, "dennis@bell-labs.com");
    add_email(list, "ken@bell-labs.com");
    add_email(list, "brian@bell-labs.com");

    // Print the mailing list.
    print_mailing_list(list);

    // Remove an email address from the mailing list.
    remove_email(list, "brian@bell-labs.com");

    // Print the mailing list again.
    print_mailing_list(list);

    // Free the memory used by the mailing list.
    free_mailing_list(list);

    return 0;
}