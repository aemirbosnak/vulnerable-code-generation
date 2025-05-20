//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define the phone book structure
typedef struct {
    char *name;
    char *phone;
    struct phone_book *next;
} phone_book;

// Define the phone book list
phone_book *phone_book_list = NULL;

// Function to add a new phone number to the list
void add_phone(char *name, char *phone) {
    phone_book *new_entry = malloc(sizeof(phone_book));
    new_entry->name = name;
    new_entry->phone = phone;
    new_entry->next = phone_book_list;
    phone_book_list = new_entry;
}

// Function to search for a phone number in the list
phone_book *search_phone(char *name) {
    phone_book *current = phone_book_list;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to remove a phone number from the list
void remove_phone(char *name) {
    phone_book *current = phone_book_list;
    phone_book *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                phone_book_list = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    // Add some phone numbers to the list
    add_phone("John Doe", "555-1234");
    add_phone("Jane Doe", "555-5678");
    add_phone("Bob Smith", "555-9012");

    // Search for a phone number in the list
    phone_book *john = search_phone("John Doe");
    if (john != NULL) {
        printf("Found John Doe's phone number: %s\n", john->phone);
    } else {
        printf("Could not find John Doe's phone number\n");
    }

    // Remove a phone number from the list
    remove_phone("Jane Doe");

    // Print the updated list
    phone_book *current = phone_book_list;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }

    return 0;
}