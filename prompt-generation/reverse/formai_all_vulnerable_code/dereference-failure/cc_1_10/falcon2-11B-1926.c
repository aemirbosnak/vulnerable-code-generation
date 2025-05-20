//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone_book_entry {
    char name[50];
    char phone_number[20];
};

struct phone_book {
    int capacity;
    int size;
    struct phone_book_entry* entries;
};

void create_phone_book(struct phone_book* book, int capacity) {
    book->capacity = capacity;
    book->size = 0;
    book->entries = (struct phone_book_entry*)malloc(sizeof(struct phone_book_entry) * capacity);
}

void add_entry(struct phone_book* book, char* name, char* phone_number) {
    if (book->size == book->capacity) {
        printf("Phone book is full, cannot add entry.\n");
        return;
    }

    strcpy(book->entries[book->size].name, name);
    strcpy(book->entries[book->size].phone_number, phone_number);
    book->size++;
}

void delete_entry(struct phone_book* book, char* name) {
    int index = -1;
    for (int i = 0; i < book->size; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index!= -1) {
        for (int i = index; i < book->size - 1; i++) {
            book->entries[i] = book->entries[i + 1];
        }
        book->size--;
    } else {
        printf("Entry not found, cannot delete.\n");
    }
}

void display_entries(struct phone_book* book) {
    for (int i = 0; i < book->size; i++) {
        printf("%s (%s)\n", book->entries[i].name, book->entries[i].phone_number);
    }
}

int main() {
    int capacity = 10;
    struct phone_book phone_book;
    create_phone_book(&phone_book, capacity);

    char name[50];
    char phone_number[20];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone_number);
    add_entry(&phone_book, name, phone_number);

    printf("Current entries: ");
    display_entries(&phone_book);

    printf("Enter name to delete: ");
    scanf("%s", name);
    delete_entry(&phone_book, name);

    printf("Current entries: ");
    display_entries(&phone_book);

    return 0;
}