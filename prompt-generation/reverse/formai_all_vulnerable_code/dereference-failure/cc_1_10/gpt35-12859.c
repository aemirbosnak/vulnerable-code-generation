//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive structure for phone book entries
struct phone_book_entry {
    char name[50];
    char phone_number[15];
    struct phone_book_entry *next;
};

// Function to add a new entry to the phone book
void add_entry(struct phone_book_entry *current, char name[50], char phone_number[15]) {
    if (current->next == NULL) {
        struct phone_book_entry *new_entry = malloc(sizeof(struct phone_book_entry));
        strcpy(new_entry->name, name);
        strcpy(new_entry->phone_number, phone_number);
        new_entry->next = NULL;
        current->next = new_entry;
    } else {
        add_entry(current->next, name, phone_number);
    }
}

// Function to search for an entry in the phone book
void search_entry(struct phone_book_entry *current, char name[50]) {
    if (current == NULL) {
        printf("Entry not found.\n");
    } else if (strcmp(current->name, name) == 0) {
        printf("Name: %s\nPhone Number: %s\n", current->name, current->phone_number);
    } else {
        search_entry(current->next, name);
    }
}

// Function to display all entries in the phone book
void display_entries(struct phone_book_entry *current) {
    if (current == NULL) {
        printf("Phone book is empty.\n");
    } else {
        printf("Name: %s\nPhone Number: %s\n", current->name, current->phone_number);
        display_entries(current->next);
    }
}

// Main function
int main() {
    printf("Welcome to the Recursive Phone Book!\n");

    struct phone_book_entry *phone_book = malloc(sizeof(struct phone_book_entry));
    strcpy(phone_book->name, "John Smith");
    strcpy(phone_book->phone_number, "555-1234");
    phone_book->next = NULL;

    printf("\nAdded first entry to phone book:\n");
    printf("Name: %s\nPhone Number: %s\n", phone_book->name, phone_book->phone_number);

    printf("\nAdding second entry to phone book...\n");
    add_entry(phone_book, "Jane Doe", "555-5678");

    printf("\nAdding third entry to phone book...\n");
    add_entry(phone_book, "Bob Johnson", "555-9876");

    printf("\nDisplaying all entries in phone book...\n");
    display_entries(phone_book);

    printf("\nSearching for entry with name 'Jane Doe'...\n");
    search_entry(phone_book, "Jane Doe");

    printf("\nSearching for entry with name 'Bill Smith'...\n");
    search_entry(phone_book, "Bill Smith");

    return 0;
}