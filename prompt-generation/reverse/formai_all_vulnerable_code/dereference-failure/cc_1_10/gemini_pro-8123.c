//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of email addresses that can be stored in the mailing list.
#define MAX_EMAILS 100

// Define the maximum length of an email address.
#define MAX_EMAIL_LENGTH 50

// Define the structure of a mailing list entry.
typedef struct mailing_list_entry {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} mailing_list_entry;

// Define the structure of a mailing list.
typedef struct mailing_list {
    mailing_list_entry entries[MAX_EMAILS];
    int num_entries;
} mailing_list;

// Create a new mailing list.
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    if (list == NULL) {
        return NULL;
    }

    list->num_entries = 0;

    return list;
}

// Free the memory allocated for a mailing list.
void free_mailing_list(mailing_list *list) {
    free(list);
}

// Add an email address to a mailing list.
int add_email_to_list(mailing_list *list, char *email) {
    // Check if the email address is already in the list.
    for (int i = 0; i < list->num_entries; i++) {
        if (strcmp(list->entries[i].email, email) == 0) {
            return 0;
        }
    }

    // Check if the list is full.
    if (list->num_entries == MAX_EMAILS) {
        return -1;
    }

    // Add the email address to the list.
    strcpy(list->entries[list->num_entries].email, email);
    list->entries[list->num_entries].subscribed = 1;
    list->num_entries++;

    return 1;
}

// Remove an email address from a mailing list.
int remove_email_from_list(mailing_list *list, char *email) {
    // Check if the email address is in the list.
    for (int i = 0; i < list->num_entries; i++) {
        if (strcmp(list->entries[i].email, email) == 0) {
            // Remove the email address from the list.
            for (int j = i + 1; j < list->num_entries; j++) {
                list->entries[j - 1] = list->entries[j];
            }
            list->num_entries--;

            return 1;
        }
    }

    return 0;
}

// Print the email addresses in a mailing list.
void print_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_entries; i++) {
        printf("%s\n", list->entries[i].email);
    }
}

// Get the number of email addresses in a mailing list.
int get_num_emails(mailing_list *list) {
    return list->num_entries;
}

// Check if an email address is subscribed to a mailing list.
int is_email_subscribed(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_entries; i++) {
        if (strcmp(list->entries[i].email, email) == 0) {
            return list->entries[i].subscribed;
        }
    }

    return 0;
}

// Subscribe an email address to a mailing list.
int subscribe_email(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_entries; i++) {
        if (strcmp(list->entries[i].email, email) == 0) {
            list->entries[i].subscribed = 1;
            return 1;
        }
    }

    return 0;
}

// Unsubscribe an email address from a mailing list.
int unsubscribe_email(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_entries; i++) {
        if (strcmp(list->entries[i].email, email) == 0) {
            list->entries[i].subscribed = 0;
            return 1;
        }
    }

    return 0;
}

// Send an email to all subscribed email addresses in a mailing list.
int send_email_to_mailing_list(mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->num_entries; i++) {
        if (list->entries[i].subscribed) {
            // Send an email to the email address.
        }
    }

    return 0;
}

// Main function
int main() {
    // Create a new mailing list.
    mailing_list *list = create_mailing_list();

    // Add some email addresses to the list.
    add_email_to_list(list, "john@example.com");
    add_email_to_list(list, "mary@example.com");
    add_email_to_list(list, "bob@example.com");

    // Print the email addresses in the list.
    print_mailing_list(list);

    // Get the number of email addresses in the list.
    int num_emails = get_num_emails(list);
    printf("Number of email addresses in the list: %d\n", num_emails);

    // Check if an email address is subscribed to the list.
    int is_subscribed = is_email_subscribed(list, "john@example.com");
    if (is_subscribed) {
        printf("john@example.com is subscribed to the list.\n");
    } else {
        printf("john@example.com is not subscribed to the list.\n");
    }

    // Subscribe an email address to the list.
    subscribe_email(list, "john@example.com");

    // Unsubscribe an email address from the list.
    unsubscribe_email(list, "mary@example.com");

    // Send an email to all subscribed email addresses in the list.
    send_email_to_mailing_list(list, "Subject", "Body");

    // Free the memory allocated for the mailing list.
    free_mailing_list(list);

    return 0;
}