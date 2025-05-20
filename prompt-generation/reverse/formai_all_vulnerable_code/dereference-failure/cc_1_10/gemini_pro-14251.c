//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone_entry {
    char *name;
    char *number;
};

struct phone_book {
    struct phone_entry *entries;
    int num_entries;
};

struct phone_book *create_phone_book() {
    struct phone_book *book = malloc(sizeof(struct phone_book));
    book->entries = NULL;
    book->num_entries = 0;
    return book;
}

void add_entry(struct phone_book *book, char *name, char *number) {
    struct phone_entry *new_entry = malloc(sizeof(struct phone_entry));
    new_entry->name = strdup(name);
    new_entry->number = strdup(number);
    book->entries = realloc(book->entries, sizeof(struct phone_entry) * (book->num_entries + 1));
    book->entries[book->num_entries++] = *new_entry;
}

char *get_number(struct phone_book *book, char *name) {
    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            return book->entries[i].number;
        }
    }
    return NULL;
}

void print_phone_book(struct phone_book *book) {
    for (int i = 0; i < book->num_entries; i++) {
        printf("%s: %s\n", book->entries[i].name, book->entries[i].number);
    }
}

void free_phone_book(struct phone_book *book) {
    for (int i = 0; i < book->num_entries; i++) {
        free(book->entries[i].name);
        free(book->entries[i].number);
    }
    free(book->entries);
    free(book);
}

int main() {
    struct phone_book *book = create_phone_book();

    add_entry(book, "John Doe", "555-123-4567");
    add_entry(book, "Jane Doe", "555-234-5678");
    add_entry(book, "Peter Parker", "555-345-6789");

    char *number = get_number(book, "John Doe");
    printf("John Doe's number is: %s\n", number);

    print_phone_book(book);

    free_phone_book(book);

    return 0;
}