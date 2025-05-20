//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mailing list is a collection of email addresses.
struct mailing_list {
    // The number of email addresses in the list.
    int size;

    // The email addresses in the list.
    char **emails;
};

// Create a new mailing list.
struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->size = 0;
    list->emails = NULL;
    return list;
}

// Add an email address to the mailing list.
void add_email(struct mailing_list *list, char *email) {
    list->emails = realloc(list->emails, (list->size + 1) * sizeof(char *));
    list->emails[list->size++] = strdup(email);
}

// Remove an email address from the mailing list.
void remove_email(struct mailing_list *list, char *email) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            free(list->emails[i]);
            for (int j = i + 1; j < list->size; j++) {
                list->emails[j - 1] = list->emails[j];
            }
            list->size--;
            return;
        }
    }
}

// Print the email addresses in the mailing list.
void print_mailing_list(struct mailing_list *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s\n", list->emails[i]);
    }
}

// Free the memory allocated for the mailing list.
void free_mailing_list(struct mailing_list *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

// Main function.
int main() {
    // Create a new mailing list.
    struct mailing_list *list = create_mailing_list();

    // Add some email addresses to the mailing list.
    add_email(list, "john@example.com");
    add_email(list, "mary@example.com");
    add_email(list, "bob@example.com");

    // Print the email addresses in the mailing list.
    printf("Mailing list:\n");
    print_mailing_list(list);

    // Remove an email address from the mailing list.
    remove_email(list, "bob@example.com");

    // Print the email addresses in the mailing list.
    printf("Mailing list (after removing bob@example.com):\n");
    print_mailing_list(list);

    // Free the memory allocated for the mailing list.
    free_mailing_list(list);

    return 0;
}