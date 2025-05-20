//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the phone book structure
struct phone_book {
    char name[50];
    char number[20];
};

// Define a function to add a new contact to the phone book
void add_contact(struct phone_book *phone_book, char *name, char *number) {
    // Check if the name already exists in the phone book
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Error: Contact already exists with name %s\n", name);
            return;
        }
    }

    // Add the new contact to the phone book
    strcpy(phone_book[i].name, name);
    strcpy(phone_book[i].number, number);
    i++;

    // Print the updated phone book
    printf("Phone Book:\n");
    for (int j = 0; j < i; j++) {
        printf("%d. %s (%s)\n", j + 1, phone_book[j].name, phone_book[j].number);
    }
}

// Define a function to search for a contact in the phone book
struct phone_book *search_contact(struct phone_book *phone_book, char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return &phone_book[i];
        }
    }

    return NULL;
}

int main() {
    // Initialize the phone book with 10 empty slots
    struct phone_book phone_book[10];

    // Add some contacts to the phone book
    add_contact(phone_book, "John Doe", "555-1234");
    add_contact(phone_book, "Jane Doe", "555-5678");
    add_contact(phone_book, "Bob Smith", "555-9012");

    // Search for a contact in the phone book
    struct phone_book *found_contact = search_contact(phone_book, "Jane Doe");
    if (found_contact != NULL) {
        printf("Found contact: %s (%s)\n", found_contact->name, found_contact->number);
    } else {
        printf("Contact not found\n");
    }

    return 0;
}