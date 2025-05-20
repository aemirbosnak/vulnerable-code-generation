//FormAI DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone_book_entry {
    char name[50];
    char phone_number[11];
};

struct phone_book {
    struct phone_book_entry *entries;
    int num_entries;
};

void add_entry(struct phone_book *book, char *name, char *phone_number) {
    struct phone_book_entry *new_entry = realloc(book->entries, (book->num_entries + 1) * sizeof(struct phone_book_entry));
    if (new_entry == NULL) {
        printf("Error: unable to allocate memory for new entry\n");
        return;
    }
    book->entries = new_entry;
    book->num_entries++;

    struct phone_book_entry *entry = &book->entries[book->num_entries - 1];
    strcpy(entry->name, name);
    strcpy(entry->phone_number, phone_number);

    printf("%s has been added to the phone book\n", name);
}

void lookup_entry(struct phone_book *book, char *name) {
    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            printf("The phone number for %s is %s\n", name, book->entries[i].phone_number);
            return;
        }
    }
    printf("%s was not found in the phone book\n", name);
}

int main() {
    struct phone_book book = {NULL, 0};

    add_entry(&book, "Alice", "1234567890");
    add_entry(&book, "Bob", "2345678901");
    add_entry(&book, "Charlie", "3456789012");

    lookup_entry(&book, "Alice");
    lookup_entry(&book, "Charlie");
    lookup_entry(&book, "Dave");

    return 0;
}