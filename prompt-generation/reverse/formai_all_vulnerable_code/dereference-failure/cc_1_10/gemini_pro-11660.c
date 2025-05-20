//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a mailing list entry
typedef struct mailing_list_entry {
    char name[50];
    char email[50];
} mailing_list_entry;

// Structure to store the mailing list
typedef struct mailing_list {
    mailing_list_entry *entries;
    int num_entries;
} mailing_list;

// Function to create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->entries = NULL;
    list->num_entries = 0;
    return list;
}

// Function to add an entry to a mailing list
void add_entry_to_mailing_list(mailing_list *list, char *name, char *email) {
    // Reallocate the entries array to make room for the new entry
    list->entries = realloc(list->entries, (list->num_entries + 1) * sizeof(mailing_list_entry));

    // Copy the name and email into the new entry
    strcpy(list->entries[list->num_entries].name, name);
    strcpy(list->entries[list->num_entries].email, email);

    // Increment the number of entries in the list
    list->num_entries++;
}

// Function to remove an entry from a mailing list
void remove_entry_from_mailing_list(mailing_list *list, int index) {
    // Check if the index is valid
    if (index < 0 || index >= list->num_entries) {
        printf("Invalid index\n");
        return;
    }

    // Shift the entries after the one being removed to the left
    for (int i = index; i < list->num_entries - 1; i++) {
        list->entries[i] = list->entries[i + 1];
    }

    // Decrement the number of entries in the list
    list->num_entries--;

    // Reallocate the entries array to free up the memory used by the removed entry
    list->entries = realloc(list->entries, list->num_entries * sizeof(mailing_list_entry));
}

// Function to print a mailing list
void print_mailing_list(mailing_list *list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list->num_entries; i++) {
        printf("%s (%s)\n", list->entries[i].name, list->entries[i].email);
    }
}

// Main function
int main() {
    // Create a new mailing list
    mailing_list *list = create_mailing_list();

    // Add some entries to the mailing list
    add_entry_to_mailing_list(list, "John Doe", "john.doe@example.com");
    add_entry_to_mailing_list(list, "Jane Doe", "jane.doe@example.com");
    add_entry_to_mailing_list(list, "Bob Smith", "bob.smith@example.com");

    // Print the mailing list
    print_mailing_list(list);

    // Remove an entry from the mailing list
    remove_entry_from_mailing_list(list, 1);

    // Print the mailing list again
    print_mailing_list(list);

    // Free the memory used by the mailing list
    free(list->entries);
    free(list);

    return 0;
}