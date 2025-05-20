//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent a mailing list
typedef struct mailing_list {
    char **emails;  // Array of email addresses
    int size;       // Number of email addresses in the list
} mailing_list;

// Function to create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->emails = malloc(sizeof(char *));
    list->size = 0;
    return list;
}

// Function to add an email address to a mailing list
void add_email(mailing_list *list, char *email) {
    list->emails = realloc(list->emails, (list->size + 1) * sizeof(char *));
    list->emails[list->size] = strdup(email);
    list->size++;
}

// Function to remove an email address from a mailing list
void remove_email(mailing_list *list, char *email) {
    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (!strcmp(list->emails[i], email)) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Email not found\n");
        return;
    }
    for (int i = index + 1; i < list->size; i++) {
        list->emails[i - 1] = list->emails[i];
    }
    list->size--;
    list->emails = realloc(list->emails, (list->size) * sizeof(char *));
}

// Function to print a mailing list
void print_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s\n", list->emails[i]);
    }
}

// Function to free the memory allocated for a mailing list
void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

// Function to test the mailing list manager
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some email addresses to the list
    add_email(list, "john@doe.com");
    add_email(list, "jane@doe.com");
    add_email(list, "bob@smith.com");

    // Print the mailing list
    print_mailing_list(list);

    // Remove an email address from the list
    remove_email(list, "bob@smith.com");

    // Print the mailing list again
    print_mailing_list(list);

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    return 0;
}