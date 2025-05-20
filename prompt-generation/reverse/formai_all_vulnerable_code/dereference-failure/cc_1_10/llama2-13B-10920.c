//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the phone book structure
struct phone_book {
    char name[50];   // Name of the person
    char number[20];  // Phone number
};

// Function to insert a new phone number into the phone book
void insert_phone(struct phone_book *phone_book, char *name, char *number) {
    // Check if the name already exists in the phone book
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            break;
        }
    }
    if (i == 10) {
        // If the name doesn't exist, allocate a new entry and copy the name and number
        struct phone_book *new_entry = (struct phone_book *)malloc(sizeof(struct phone_book));
        strcpy(new_entry->name, name);
        strcpy(new_entry->number, number);
        // Insert the new entry at the end of the phone book
        if (i == 10) {
            phone_book[i] = *new_entry;
        } else {
            memmove(&phone_book[i], &phone_book[i+1], (10 - i) * sizeof(struct phone_book));
            phone_book[i] = *new_entry;
        }
        i++;
    }
}

// Function to search for a phone number in the phone book
int search_phone(struct phone_book *phone_book, char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display the phone book
void display_phone_book(struct phone_book *phone_book) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d: %s %s\n", i, phone_book[i].name, phone_book[i].number);
    }
}

int main() {
    struct phone_book phone_book;
    char name[50];
    char number[20];

    // Insert some phone numbers
    insert_phone(&phone_book, "John Doe", "555-1234");
    insert_phone(&phone_book, "Jane Doe", "555-5678");
    insert_phone(&phone_book, "Bob Smith", "555-9012");

    // Search for a phone number
    int result = search_phone(&phone_book, "Jane Doe");
    if (result != -1) {
        printf("Jane Doe's phone number is %d\n", result);
    } else {
        printf("Jane Doe's phone number is not found\n");
    }

    // Display the phone book
    display_phone_book(&phone_book);

    return 0;
}