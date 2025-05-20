//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phonebook_entry {
    char *name;
    char *number;
} phonebook_entry_t;

typedef struct phonebook {
    phonebook_entry_t *entries;
    int num_entries;
} phonebook_t;

phonebook_t *create_phonebook() {
    phonebook_t *phonebook = malloc(sizeof(phonebook_t));
    phonebook->entries = NULL;
    phonebook->num_entries = 0;
    return phonebook;
}

void add_entry(phonebook_t *phonebook, char *name, char *number) {
    phonebook->entries = realloc(phonebook->entries, (phonebook->num_entries + 1) * sizeof(phonebook_entry_t));
    phonebook_entry_t *entry = &phonebook->entries[phonebook->num_entries];
    entry->name = malloc(strlen(name) + 1);
    strcpy(entry->name, name);
    entry->number = malloc(strlen(number) + 1);
    strcpy(entry->number, number);
    phonebook->num_entries++;
}

void print_phonebook(phonebook_t *phonebook) {
    for (int i = 0; i < phonebook->num_entries; i++) {
        printf("%s: %s\n", phonebook->entries[i].name, phonebook->entries[i].number);
    }
}

void free_phonebook(phonebook_t *phonebook) {
    for (int i = 0; i < phonebook->num_entries; i++) {
        free(phonebook->entries[i].name);
        free(phonebook->entries[i].number);
    }
    free(phonebook->entries);
    free(phonebook);
}

int main() {
    phonebook_t *phonebook = create_phonebook();
    add_entry(phonebook, "John Doe", "555-1212");
    add_entry(phonebook, "Jane Doe", "555-1213");
    print_phonebook(phonebook);
    free_phonebook(phonebook);
    return 0;
}