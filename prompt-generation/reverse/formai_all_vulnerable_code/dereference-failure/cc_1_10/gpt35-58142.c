//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct phone_book_entry PhoneBookEntry;
typedef struct phone_book PhoneBook;

struct phone_book_entry {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    PhoneBookEntry* next;
};

struct phone_book {
    PhoneBookEntry* head;
};

PhoneBookEntry* createEntry(char* name, char* phone) {
    PhoneBookEntry* entry = (PhoneBookEntry*) malloc(sizeof(PhoneBookEntry));
    strcpy(entry->name, name);
    strcpy(entry->phone, phone);
    return entry;
}

void addEntry(PhoneBook* book, PhoneBookEntry* entry) {
    if (book->head == NULL) {
        book->head = entry;
    } else {
        entry->next = book->head;
        book->head = entry;
    }
}

void displayPhoneBook(PhoneBookEntry* entry) {
    if (entry == NULL) {
        return;
    }
    printf("%s: %s\n", entry->name, entry->phone);
    displayPhoneBook(entry->next);
}

void searchPhoneBook(PhoneBookEntry* entry, char* name) {
    if (entry == NULL) {
        return;
    }
    if (strcmp(entry->name, name) == 0) {
        printf("%s: %s\n", entry->name, entry->phone);
        return;
    }
    searchPhoneBook(entry->next, name);
}

int main() {
    PhoneBook book;
    book.head = NULL;

    addEntry(&book, createEntry("Alice", "123456"));
    addEntry(&book, createEntry("Bob", "546789"));
    addEntry(&book, createEntry("Charlie", "789456"));

    printf("Phone Book Entries:\n");
    displayPhoneBook(book.head);

    printf("\nSearch Results:\n");
    searchPhoneBook(book.head, "Bob");

    return 0;
}