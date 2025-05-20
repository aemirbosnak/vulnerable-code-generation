//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: scalable
// PhoneBook.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} entry_t;

entry_t* phone_book;
int num_entries;

void init_phone_book(void) {
    phone_book = malloc(MAX_ENTRIES * sizeof(entry_t));
    num_entries = 0;
}

void add_entry(const char* name, const char* phone_number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full, cannot add any more entries\n");
        return;
    }
    entry_t* new_entry = malloc(sizeof(entry_t));
    strcpy(new_entry->name, name);
    strcpy(new_entry->phone_number, phone_number);
    phone_book[num_entries] = *new_entry;
    num_entries++;
}

void print_phone_book(void) {
    printf("Phone Book:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d: %s %s\n", i, phone_book[i].name, phone_book[i].phone_number);
    }
}

int main(void) {
    init_phone_book();

    // Add some entries
    add_entry("John Doe", "555-1234");
    add_entry("Jane Doe", "555-5678");
    add_entry("Bob Smith", "555-9012");

    // Print the phone book
    print_phone_book();

    return 0;
}