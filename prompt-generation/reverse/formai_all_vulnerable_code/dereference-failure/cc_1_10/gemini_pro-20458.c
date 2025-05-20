//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A phonebook entry
typedef struct phonebook_entry {
    char *name;
    char *number;
} phonebook_entry;

// A phonebook
typedef struct phonebook {
    phonebook_entry *entries;
    int num_entries;
} phonebook;

// Create a new phonebook
phonebook *create_phonebook() {
    phonebook *pb = malloc(sizeof(phonebook));
    pb->entries = NULL;
    pb->num_entries = 0;
    return pb;
}

// Add an entry to the phonebook
void add_entry(phonebook *pb, char *name, char *number) {
    pb->entries = realloc(pb->entries, (pb->num_entries + 1) * sizeof(phonebook_entry));
    pb->entries[pb->num_entries].name = strdup(name);
    pb->entries[pb->num_entries].number = strdup(number);
    pb->num_entries++;
}

// Find an entry in the phonebook by name
phonebook_entry *find_entry(phonebook *pb, char *name) {
    for (int i = 0; i < pb->num_entries; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            return &pb->entries[i];
        }
    }
    return NULL;
}

// Print the phonebook
void print_phonebook(phonebook *pb) {
    for (int i = 0; i < pb->num_entries; i++) {
        printf("%s: %s\n", pb->entries[i].name, pb->entries[i].number);
    }
}

// Free the memory allocated for the phonebook
void free_phonebook(phonebook *pb) {
    for (int i = 0; i < pb->num_entries; i++) {
        free(pb->entries[i].name);
        free(pb->entries[i].number);
    }
    free(pb->entries);
    free(pb);
}

// Main function
int main() {
    // Create a phonebook
    phonebook *pb = create_phonebook();

    // Add some entries to the phonebook
    add_entry(pb, "Alice", "123-456-7890");
    add_entry(pb, "Bob", "987-654-3210");
    add_entry(pb, "Carol", "111-222-3333");

    // Find an entry in the phonebook
    phonebook_entry *entry = find_entry(pb, "Bob");
    if (entry != NULL) {
        printf("Found Bob's number: %s\n", entry->number);
    } else {
        printf("Bob not found in phonebook\n");
    }

    // Print the phonebook
    print_phonebook(pb);

    // Free the memory allocated for the phonebook
    free_phonebook(pb);

    return 0;
}