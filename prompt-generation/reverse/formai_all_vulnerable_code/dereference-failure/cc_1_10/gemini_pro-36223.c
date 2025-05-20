//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A phone book entry
struct entry {
    char *name;
    char *number;
};

// A phone book
struct phonebook {
    struct entry *entries;
    int num_entries;
};

// Create a new phone book
struct phonebook *create_phonebook() {
    struct phonebook *pb = malloc(sizeof(struct phonebook));
    pb->entries = NULL;
    pb->num_entries = 0;
    return pb;
}

// Add an entry to a phone book
void add_entry(struct phonebook *pb, char *name, char *number) {
    pb->entries = realloc(pb->entries, (pb->num_entries + 1) * sizeof(struct entry));
    pb->entries[pb->num_entries].name = strdup(name);
    pb->entries[pb->num_entries].number = strdup(number);
    pb->num_entries++;
}

// Find an entry in a phone book
struct entry *find_entry(struct phonebook *pb, char *name) {
    for (int i = 0; i < pb->num_entries; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            return &pb->entries[i];
        }
    }
    return NULL;
}

// Print a phone book
void print_phonebook(struct phonebook *pb) {
    for (int i = 0; i < pb->num_entries; i++) {
        printf("%s: %s\n", pb->entries[i].name, pb->entries[i].number);
    }
}

// Free a phone book
void free_phonebook(struct phonebook *pb) {
    for (int i = 0; i < pb->num_entries; i++) {
        free(pb->entries[i].name);
        free(pb->entries[i].number);
    }
    free(pb->entries);
    free(pb);
}

int main() {
    // Create a new phone book
    struct phonebook *pb = create_phonebook();

    // Add some entries to the phone book
    add_entry(pb, "Alice", "555-1212");
    add_entry(pb, "Bob", "555-1213");
    add_entry(pb, "Carol", "555-1214");

    // Find an entry in the phone book
    struct entry *entry = find_entry(pb, "Bob");

    // Print the entry
    if (entry != NULL) {
        printf("Name: %s\n", entry->name);
        printf("Number: %s\n", entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Print the entire phone book
    print_phonebook(pb);

    // Free the phone book
    free_phonebook(pb);

    return 0;
}