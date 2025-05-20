//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the phone book structure
typedef struct {
    char *name;
    char *number;
} phone_book_entry_t;

// Define the phone book array
phone_book_entry_t phone_book[10];

// Define a function to add an entry to the phone book
void add_entry(char *name, char *number) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Entry already exists, do nothing
            return;
        }
    }
    // Entry does not exist, add it to the end of the array
    phone_book[i].name = name;
    phone_book[i].number = number;
    i++;
}

// Define a function to search the phone book for a specific name
phone_book_entry_t *search(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return &phone_book[i];
        }
    }
    return NULL;
}

// Define a function to delete an entry from the phone book
void delete(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Found the entry, remove it from the array
            memmove(&phone_book[i], &phone_book[i + 1], (10 - i - 1) * sizeof(phone_book_entry_t));
            i--;
            break;
        }
    }
}

int main() {
    // Add some entries to the phone book
    add_entry("John Doe", "555-1234");
    add_entry("Jane Doe", "555-5678");
    add_entry("Bob Smith", "555-9012");

    // Search the phone book for a specific name
    phone_book_entry_t *entry = search("John Doe");
    if (entry != NULL) {
        printf("Found John Doe's number: %s\n", entry->number);
    } else {
        printf("No such name in the phone book\n");
    }

    // Delete an entry from the phone book
    delete("Jane Doe");

    // Search the phone book again
    entry = search("Jane Doe");
    if (entry == NULL) {
        printf("Jane Doe has been deleted\n");
    } else {
        printf("Jane Doe's number is still in the phone book\n");
    }

    return 0;
}