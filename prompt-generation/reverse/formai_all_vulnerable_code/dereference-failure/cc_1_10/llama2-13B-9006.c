//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store phone book entries
typedef struct {
    char name[50]; // Name of the person
    char number[20]; // Phone number of the person
} phone_entry;

// Function to initialize the phone book
void init_phone_book(phone_entry **phone_book) {
    *phone_book = calloc(10, sizeof(phone_entry));
    int i;
    for (i = 0; i < 10; i++) {
        strcpy((*phone_book)[i].name, "Unnamed Entry");
        (*phone_book)[i].number[0] = '\0';
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_entry **phone_book, char *name, char *number) {
    int i;
    for (i = 0; i < 10; i++) {
        if ((*phone_book)[i].name[0] == '\0') {
            strcpy((*phone_book)[i].name, name);
            strcpy((*phone_book)[i].number, number);
            break;
        }
    }
    if (i == 10) {
        printf("Phone book is full! No more entries can be added.\n");
    }
}

// Function to search for an entry in the phone book
int search_entry(phone_entry **phone_book, char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp((*phone_book)[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to delete an entry from the phone book
void delete_entry(phone_entry **phone_book, int index) {
    if (index >= 0 && index < 10) {
        strcpy((*phone_book)[index].name, "Deleted Entry");
        strcpy((*phone_book)[index].number, "N/A");
    }
}

// Function to print the phone book
void print_phone_book(phone_entry **phone_book) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d: %s %s\n", i, (*phone_book)[i].name, (*phone_book)[i].number);
    }
}

int main() {
    phone_entry **phone_book;
    init_phone_book(&phone_book);

    // Add some entries to the phone book
    add_entry(phone_book, "John Doe", "555-1234");
    add_entry(phone_book, "Jane Doe", "555-5678");
    add_entry(phone_book, "Bob Smith", "555-9012");

    // Search for an entry
    int index = search_entry(phone_book, "Jane Doe");
    if (index != -1) {
        printf("Jane Doe's number is: %s\n", (*phone_book)[index].number);
    } else {
        printf("Jane Doe is not in the phone book.\n");
    }

    // Delete an entry
    delete_entry(phone_book, 1);

    // Print the phone book
    print_phone_book(phone_book);

    return 0;
}