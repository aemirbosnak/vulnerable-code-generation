//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PHONE_BOOK_MAX_NAME_LENGTH 256
#define PHONE_BOOK_MAX_PHONE_NUMBER_LENGTH 20

typedef struct phone_book_entry {
    char name[PHONE_BOOK_MAX_NAME_LENGTH];
    char phone_number[PHONE_BOOK_MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry_t;

typedef struct phone_book {
    phone_book_entry_t entries[10];
    size_t num_entries;
} phone_book_t;

void add_entry(phone_book_t *book, const char *name, const char *phone_number);
void remove_entry(phone_book_t *book, const char *name);
void search_entry(phone_book_t *book, const char *name, bool *found);
void print_all_entries(phone_book_t *book);

phone_book_t *create_phone_book() {
    phone_book_t *book = malloc(sizeof(phone_book_t));
    book->num_entries = 0;
    return book;
}

void add_entry(phone_book_t *book, const char *name, const char *phone_number) {
    if (book->num_entries == sizeof(book->entries) / sizeof(book->entries[0])) {
        printf("Phone book is full! Cannot add any more entries.\n");
        return;
    }

    strcpy(book->entries[book->num_entries].name, name);
    strcpy(book->entries[book->num_entries].phone_number, phone_number);
    book->num_entries++;
}

void remove_entry(phone_book_t *book, const char *name) {
    int i;
    for (i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            break;
        }
    }

    if (i < book->num_entries) {
        memset(&book->entries[i], 0, sizeof(book->entries[0]));
        book->num_entries--;
    } else {
        printf("Entry not found in phone book.\n");
    }
}

void search_entry(phone_book_t *book, const char *name, bool *found) {
    int i;
    for (i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            *found = true;
            break;
        }
    }

    if (*found) {
        printf("Found entry: %s\n", name);
    } else {
        printf("Entry not found in phone book.\n");
    }
}

void print_all_entries(phone_book_t *book) {
    int i;
    for (i = 0; i < book->num_entries; i++) {
        printf("%d. %s %s\n", i + 1, book->entries[i].name, book->entries[i].phone_number);
    }
}

int main() {
    phone_book_t *book = create_phone_book();

    // Add some entries
    add_entry(book, "John Doe", "555-1234");
    add_entry(book, "Jane Doe", "555-5678");
    add_entry(book, "Jim Brown", "555-9012");

    // Search for an entry
    const char *name = "Jane Doe";
    bool found = false;
    search_entry(book, name, &found);

    // Remove an entry
    remove_entry(book, "Jane Doe");

    // Print all entries
    print_all_entries(book);

    // Free the phone book
    free(book);

    return 0;
}