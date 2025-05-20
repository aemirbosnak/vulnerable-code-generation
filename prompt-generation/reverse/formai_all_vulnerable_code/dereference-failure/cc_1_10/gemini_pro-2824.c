//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the mailing list struct
typedef struct mailing_list {
    char **emails;
    int num_emails;
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->emails = NULL;
    list->num_emails = 0;
    return list;
}

// Add an email to the mailing list
void add_email(mailing_list *list, char *email) {
    list->emails = realloc(list->emails, (list->num_emails + 1) * sizeof(char *));
    list->emails[list->num_emails] = strdup(email);
    list->num_emails++;
}

// Remove an email from the mailing list
void remove_email(mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            break;
        }
    }

    if (i < list->num_emails) {
        // Move the remaining emails down one slot
        for (int j = i + 1; j < list->num_emails; j++) {
            list->emails[j - 1] = list->emails[j];
        }

        // Decrease the number of emails in the list
        list->num_emails--;
    }
}

// Print the mailing list
void print_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_emails; i++) {
        printf("%s\n", list->emails[i]);
    }
}

// Free the memory allocated for the mailing list
void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_emails; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some emails to the list
    add_email(list, "john@example.com");
    add_email(list, "jane@example.com");
    add_email(list, "bob@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Remove an email from the list
    remove_email(list, "bob@example.com");

    // Print the mailing list again
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}