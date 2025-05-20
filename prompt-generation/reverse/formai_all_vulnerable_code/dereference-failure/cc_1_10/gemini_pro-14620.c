//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our awesome phone book!
typedef struct PhoneBookEntry {
    char *name;
    char *number;
} PhoneBookEntry;

// Create a new phone book entry
PhoneBookEntry *create_entry(char *name, char *number) {
    PhoneBookEntry *entry = malloc(sizeof(PhoneBookEntry));
    entry->name = strdup(name);
    entry->number = strdup(number);
    return entry;
}

// Find an entry in the phone book by name
PhoneBookEntry *find_entry(PhoneBookEntry *entries, int num_entries, char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            return &entries[i];
        }
    }
    return NULL;
}

// Print the phone book
void print_phone_book(PhoneBookEntry *entries, int num_entries) {
    printf("Our Super Cool Phone Book:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }
}

// Add a new entry to the phone book
void add_entry(PhoneBookEntry **entries, int *num_entries, char *name, char *number) {
    *entries = realloc(*entries, (*num_entries + 1) * sizeof(PhoneBookEntry));
    (*entries)[*num_entries] = *create_entry(name, number);
    (*num_entries)++;
}

// Delete an entry from the phone book
void delete_entry(PhoneBookEntry **entries, int *num_entries, char *name) {
    int index = -1;
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp((*entries)[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        free((*entries)[index].name);
        free((*entries)[index].number);
        for (int i = index; i < *num_entries - 1; i++) {
            (*entries)[i] = (*entries)[i + 1];
        }
        (*num_entries)--;
        *entries = realloc(*entries, *num_entries * sizeof(PhoneBookEntry));
    }
}

int main() {
    // Let's create our awesome phone book!
    PhoneBookEntry *entries = NULL;
    int num_entries = 0;

    // Here are some of our cool contacts
    add_entry(&entries, &num_entries, "Alice", "123-456-7890");
    add_entry(&entries, &num_entries, "Bob", "234-567-8901");
    add_entry(&entries, &num_entries, "Charlie", "345-678-9012");

    // Let's show off our phone book!
    print_phone_book(entries, num_entries);

    // Oh no, Alice changed her number!
    delete_entry(&entries, &num_entries, "Alice");
    add_entry(&entries, &num_entries, "Alice", "987-654-3210");

    // Let's see our updated phone book!
    print_phone_book(entries, num_entries);

    // Time to clean up our phone book
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].name);
        free(entries[i].number);
    }
    free(entries);

    return 0;
}