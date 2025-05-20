//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define PHONE_BOOK_MAX_SIZE 1000
#define PHONE_NUMBER_LENGTH 10
#define NAME_LENGTH 20

typedef struct phone_book_entry {
    char name[NAME_LENGTH];
    char phone_number[PHONE_NUMBER_LENGTH];
} phone_book_entry;

typedef struct phone_book {
    int size;
    phone_book_entry entries[PHONE_BOOK_MAX_SIZE];
} phone_book;

phone_book *create_phone_book() {
    phone_book *pb = (phone_book *)malloc(sizeof(phone_book));
    pb->size = 0;
    return pb;
}

void add_entry(phone_book *pb, char *name, char *phone_number) {
    if (pb->size == PHONE_BOOK_MAX_SIZE) {
        printf("Phone book is full! cannot add more entries\n");
        return;
    }

    phone_book_entry *entry = (phone_book_entry *)malloc(sizeof(phone_book_entry));
    strcpy(entry->name, name);
    strcpy(entry->phone_number, phone_number);
    pb->entries[pb->size++] = *entry;
}

void search_entry(phone_book *pb, char *name) {
    int i;
    for (i = 0; i < pb->size; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            printf("Found entry: %s %s\n", pb->entries[i].name, pb->entries[i].phone_number);
            return;
        }
    }
    printf("Entry not found\n");
}

void delete_entry(phone_book *pb, char *name) {
    int i;
    for (i = 0; i < pb->size; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            memmove(pb->entries + i, pb->entries + i + 1, (pb->size - i - 1) * sizeof(phone_book_entry));
            pb->size--;
            free(pb->entries[i].name);
            free(pb->entries[i].phone_number);
            return;
        }
    }
    printf("Entry not found\n");
}

void print_phone_book(phone_book *pb) {
    int i;
    for (i = 0; i < pb->size; i++) {
        printf("%d: %s %s\n", i, pb->entries[i].name, pb->entries[i].phone_number);
    }
}

int main() {
    phone_book *pb = create_phone_book();

    // Add some entries
    add_entry(pb, "John Doe", "1234567890");
    add_entry(pb, "Jane Doe", "9876543210");
    add_entry(pb, "Bob Smith", "5555555555");

    // Search for an entry
    search_entry(pb, "Jane Doe");

    // Delete an entry
    delete_entry(pb, "Bob Smith");

    // Print the phone book
    print_phone_book(pb);

    // Free the phone book
    free(pb);

    return 0;
}