//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct for a phone book entry
struct phone_book_entry {
    char name[50];
    char number[20];
};

// Define a function to read a phone book entry from the user
void read_entry(struct phone_book_entry *entry) {
    printf("Enter name: ");
    fgets(entry->name, 50, stdin);
    printf("Enter number: ");
    fgets(entry->number, 20, stdin);
}

// Define a function to search for a phone book entry
struct phone_book_entry *search_entry(struct phone_book_entry *entries, int num_entries, char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            return &entries[i];
        }
    }
    return NULL;
}

int main() {
    // Create an array of phone book entries
    struct phone_book_entry entries[10];
    int num_entries = 0;

    // Read phone book entries from the user
    while (1) {
        read_entry(&entries[num_entries]);
        num_entries++;

        // Check if the user wants to add another entry
        printf("Add another entry? (y/n): ");
        char answer = getchar();
        if (answer == 'n') {
            break;
        }
    }

    // Search for a phone book entry
    char search_name[] = "John";
    struct phone_book_entry *found_entry = search_entry(entries, num_entries, search_name);
    if (found_entry != NULL) {
        printf("Found entry for %s\n", found_entry->name);
    } else {
        printf("No entry found for %s\n", search_name);
    }

    // Free memory
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].name);
        free(entries[i].number);
    }
    free(entries);

    return 0;
}