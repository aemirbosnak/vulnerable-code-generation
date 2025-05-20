//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 100
#define MAX_NUMBER_LEN 15

typedef struct Entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
    struct Entry *next;
} Entry;

typedef struct PhoneBook {
    Entry *entries[MAX_ENTRIES];
    int num_entries;
} PhoneBook;

PhoneBook *newPhoneBook() {
    PhoneBook *book = (PhoneBook *)malloc(sizeof(PhoneBook));
    book->entries[0] = NULL;
    book->num_entries = 0;
    return book;
}

void addEntry(PhoneBook *book, char *name, char *number) {
    Entry *entry = (Entry *)malloc(sizeof(Entry));
    strncpy(entry->name, name, MAX_NAME_LEN);
    strncpy(entry->number, number, MAX_NUMBER_LEN);
    entry->next = NULL;
    if (book->num_entries == MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    book->entries[book->num_entries] = entry;
    book->num_entries++;
}

void deleteEntry(PhoneBook *book, char *name) {
    Entry *current = book->entries[0];
    Entry *prev = NULL;

    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(current->name, name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                book->entries[0] = current->next;
            }
            free(current);
            book->num_entries--;
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Entry not found.\n");
}

void searchEntry(PhoneBook *book, char *name) {
    Entry *current = book->entries[0];

    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(current->name, name) == 0) {
            printf("%s\t%s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }

    printf("Entry not found.\n");
}

void printPhoneBook(PhoneBook *book) {
    Entry *current = book->entries[0];

    for (int i = 0; i < book->num_entries; i++) {
        printf("%s\t%s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    PhoneBook *phoneBook = newPhoneBook();

    addEntry(phoneBook, "John", "1234567890");
    addEntry(phoneBook, "Jane", "9876543210");
    addEntry(phoneBook, "Bob", "5555555555");

    searchEntry(phoneBook, "Jane");
    searchEntry(phoneBook, "Jack");

    printPhoneBook(phoneBook);

    deleteEntry(phoneBook, "Jane");

    printPhoneBook(phoneBook);

    return 0;
}