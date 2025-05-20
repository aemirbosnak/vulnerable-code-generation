//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone_entry {
    char* name;
    char* number;
} phone_entry;

typedef struct phone_book {
    phone_entry* entries;
    int num_entries;
} phone_book;

phone_book* create_phone_book() {
    phone_book* book = malloc(sizeof(phone_book));
    book->entries = NULL;
    book->num_entries = 0;
    return book;
}

void add_entry(phone_book* book, char* name, char* number) {
    book->entries = realloc(book->entries, (book->num_entries + 1) * sizeof(phone_entry));
    book->entries[book->num_entries].name = name;
    book->entries[book->num_entries].number = number;
    book->num_entries++;
}

char* get_number(phone_book* book, char* name) {
    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            return book->entries[i].number;
        }
    }
    return NULL;
}

void print_phone_book(phone_book* book) {
    for (int i = 0; i < book->num_entries; i++) {
        printf("%s: %s\n", book->entries[i].name, book->entries[i].number);
    }
}

void free_phone_book(phone_book* book) {
    for (int i = 0; i < book->num_entries; i++) {
        free(book->entries[i].name);
        free(book->entries[i].number);
    }
    free(book->entries);
    free(book);
}

int main() {
    phone_book* book = create_phone_book();

    add_entry(book, "Alice", "555-1212");
    add_entry(book, "Bob", "555-1213");
    add_entry(book, "Carol", "555-1214");

    printf("Alice's number is %s\n", get_number(book, "Alice"));

    print_phone_book(book);

    free_phone_book(book);

    return 0;
}