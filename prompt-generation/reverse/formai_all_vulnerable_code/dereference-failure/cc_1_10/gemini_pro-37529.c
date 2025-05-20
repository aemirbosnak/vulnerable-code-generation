//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone_entry {
    char *name;
    char *phone_number;
};

struct phone_book {
    int num_entries;
    struct phone_entry *entries;
};

struct phone_book *create_phone_book() {
    struct phone_book *book = malloc(sizeof(struct phone_book));
    book->num_entries = 0;
    book->entries = NULL;
    return book;
}

void add_phone_entry(struct phone_book *book, char *name, char *phone_number) {
    struct phone_entry *new_entry = malloc(sizeof(struct phone_entry));
    new_entry->name = name;
    new_entry->phone_number = phone_number;

    book->num_entries++;
    book->entries = realloc(book->entries, book->num_entries * sizeof(struct phone_entry));
    book->entries[book->num_entries - 1] = *new_entry;
}

void print_phone_book(struct phone_book *book) {
    for (int i = 0; i < book->num_entries; i++) {
        printf("%s: %s\n", book->entries[i].name, book->entries[i].phone_number);
    }
}

void free_phone_book(struct phone_book *book) {
    for (int i = 0; i < book->num_entries; i++) {
        free(book->entries[i].name);
        free(book->entries[i].phone_number);
    }
    free(book->entries);
    free(book);
}

int main() {
    struct phone_book *book = create_phone_book();

    add_phone_entry(book, "John Doe", "555-1234");
    add_phone_entry(book, "Jane Smith", "555-5678");
    add_phone_entry(book, "Bob Jones", "555-9012");

    print_phone_book(book);

    free_phone_book(book);

    return 0;
}