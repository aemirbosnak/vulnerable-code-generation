//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mailing list entry
typedef struct Entry {
    char name[256];
    char email[256];
    struct Entry *next;
} Entry;

// The mailing list
Entry *list = NULL;

// Create a new entry
Entry *create_entry(char *name, char *email) {
    Entry *entry = malloc(sizeof(Entry));
    strcpy(entry->name, name);
    strcpy(entry->email, email);
    entry->next = NULL;
    return entry;
}

// Add an entry to the list
void add_entry(Entry *entry) {
    if (list == NULL) {
        list = entry;
    } else {
        Entry *current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = entry;
    }
}

// Print the list
void print_list() {
    Entry *current = list;
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

// Send an email to the list
void send_email(char *subject, char *body) {
    Entry *current = list;
    while (current != NULL) {
        // Send the email to the current entry
        // ...
        current = current->next;
    }
}

// Free the list
void free_list() {
    Entry *current = list;
    while (current != NULL) {
        Entry *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Add some entries to the list
    add_entry(create_entry("John Doe", "john.doe@example.com"));
    add_entry(create_entry("Jane Doe", "jane.doe@example.com"));
    add_entry(create_entry("Bob Smith", "bob.smith@example.com"));

    // Print the list
    printf("Mailing list:\n");
    print_list();

    // Send an email to the list
    send_email("Hello there", "This is a test email.");

    // Free the list
    free_list();

    return 0;
}