//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a mailing list entry
typedef struct mailing_list_entry {
    char *name;
    char *email;
    struct mailing_list_entry *next;
} mailing_list_entry;

// Function to add an entry to the mailing list
void add_entry(mailing_list_entry **head, char *name, char *email) {
    mailing_list_entry *new_entry = malloc(sizeof(mailing_list_entry));
    new_entry->name = strdup(name);
    new_entry->email = strdup(email);
    new_entry->next = *head;
    *head = new_entry;
}

// Function to print the mailing list
void print_list(mailing_list_entry *head) {
    mailing_list_entry *current = head;
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

// Function to free the mailing list
void free_list(mailing_list_entry *head) {
    mailing_list_entry *current = head;
    while (current != NULL) {
        mailing_list_entry *next = current->next;
        free(current->name);
        free(current->email);
        free(current);
        current = next;
    }
}

int main() {
    // Create the head of the mailing list
    mailing_list_entry *head = NULL;

    // Add some entries to the mailing list
    add_entry(&head, "Romeo Montague", "romeo@montague.com");
    add_entry(&head, "Juliet Capulet", "juliet@capulet.com");
    add_entry(&head, "Tybalt Capulet", "tybalt@capulet.com");
    add_entry(&head, "Mercutio Montague", "mercutio@montague.com");
    add_entry(&head, "Nurse", "nurse@capulet.com");

    // Print the mailing list
    print_list(head);

    // Free the mailing list
    free_list(head);

    return 0;
}