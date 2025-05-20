//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to represent a phone book entry
struct phone_entry {
    char name[50];  // Name of the person
    char number[20]; // Phone number
};

// Declare an array to store all phone book entries
struct phone_entry phone_book[10];

// Function to add a new entry to the phone book
void add_entry(char *name, char *number) {
    int i; // Iterator for array index

    // Check if the name is already in the phone book
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Name already in the phone book, so just update the number
            strcpy(phone_book[i].number, number);
            return;
        }
    }

    // If the name is not in the phone book, add a new entry
    strcpy(phone_book[i].name, name);
    strcpy(phone_book[i].number, number);
    i++;
}

// Function to search the phone book for a specific name
struct phone_entry *find_entry(char *name) {
    int i; // Iterator for array index

    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return &phone_book[i];
        }
    }

    return NULL; // Not found
}

// Function to print all entries in the phone book
void print_phone_book() {
    int i; // Iterator for array index

    for (i = 0; i < 10; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
    }
}

int main() {
    // Add some entries to the phone book
    add_entry("John Doe", "555-1234");
    add_entry("Jane Doe", "555-5678");
    add_entry("Bob Smith", "555-9012");

    // Search the phone book for a specific name
    struct phone_entry *entry = find_entry("Jane Doe");
    if (entry != NULL) {
        printf("Found Jane Doe's number: %s\n", entry->number);
    } else {
        printf("Not found\n");
    }

    // Print the entire phone book
    print_phone_book();

    return 0;
}