//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHONE_BOOK_MAX_NAME_LENGTH 25
#define PHONE_BOOK_MAX_PHONE_NUMBER_LENGTH 15
#define PHONE_BOOK_MAX_ADDRESS_LENGTH 50

typedef struct {
    char name[PHONE_BOOK_MAX_NAME_LENGTH];
    char phone_number[PHONE_BOOK_MAX_PHONE_NUMBER_LENGTH];
    char address[PHONE_BOOK_MAX_ADDRESS_LENGTH];
} phone_book_entry;

phone_book_entry *phone_book = NULL;
int num_entries = 0;

void add_entry(phone_book_entry *entry) {
    if (num_entries == 0) {
        phone_book = malloc(sizeof(phone_book_entry) * 10);
    } else {
        phone_book = realloc(phone_book, sizeof(phone_book_entry) * (num_entries + 1));
    }
    entry->name[strcspn(entry->name, "\n")] = 0;
    entry->phone_number[strcspn(entry->phone_number, "\n")] = 0;
    entry->address[strcspn(entry->address, "\n")] = 0;
    phone_book[num_entries] = *entry;
    num_entries++;
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%d. %s %s %s\n", i + 1, phone_book[i].name, phone_book[i].phone_number, phone_book[i].address);
    }
}

int main() {
    phone_book_entry entry1 = {"John", "555-1234", "123 Main St."};
    phone_book_entry entry2 = {"Jane", "555-5678", "456 Elm St."};
    phone_book_entry entry3 = {"Bob", "555-9012", "789 Oak St."};

    add_entry(&entry1);
    add_entry(&entry2);
    add_entry(&entry3);

    print_entries();

    return 0;
}