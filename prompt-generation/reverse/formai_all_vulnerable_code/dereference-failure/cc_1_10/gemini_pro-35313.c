//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a name and phone number
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Define the structure of a phone book entry
typedef struct phone_book_entry {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Define the maximum number of entries in the phone book
#define MAX_PHONE_BOOK_ENTRIES 100

// Create an array of phone book entries
phone_book_entry phone_book[MAX_PHONE_BOOK_ENTRIES];

// Initialize the phone book with some sample data
void initialize_phone_book() {
    strcpy(phone_book[0].name, "John Doe");
    strcpy(phone_book[0].phone_number, "555-1212");
    strcpy(phone_book[1].name, "Jane Doe");
    strcpy(phone_book[1].phone_number, "555-1213");
    strcpy(phone_book[2].name, "Bob Smith");
    strcpy(phone_book[2].phone_number, "555-1214");
}

// Add a new entry to the phone book
void add_entry(char *name, char *phone_number) {
    // Find the first empty entry in the phone book
    int i;
    for (i = 0; i < MAX_PHONE_BOOK_ENTRIES; i++) {
        if (strlen(phone_book[i].name) == 0) {
            break;
        }
    }

    // If there is no empty entry, then the phone book is full
    if (i == MAX_PHONE_BOOK_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    // Copy the name and phone number into the new entry
    strcpy(phone_book[i].name, name);
    strcpy(phone_book[i].phone_number, phone_number);
}

// Delete an entry from the phone book
void delete_entry(char *name) {
    // Find the entry with the specified name
    int i;
    for (i = 0; i < MAX_PHONE_BOOK_ENTRIES; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            break;
        }
    }

    // If the entry was not found, then print an error message
    if (i == MAX_PHONE_BOOK_ENTRIES) {
        printf("Error: Entry not found.\n");
        return;
    }

    // Delete the entry
    strcpy(phone_book[i].name, "");
    strcpy(phone_book[i].phone_number, "");
}

// Find an entry in the phone book
phone_book_entry *find_entry(char *name) {
    // Find the entry with the specified name
    int i;
    for (i = 0; i < MAX_PHONE_BOOK_ENTRIES; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return &phone_book[i];
        }
    }

    // If the entry was not found, then return NULL
    return NULL;
}

// Print the phone book
void print_phone_book() {
    // Print the header
    printf("Name\t\tPhone Number\n");
    printf("-----------------------------------------\n");

    // Print each entry in the phone book
    int i;
    for (i = 0; i < MAX_PHONE_BOOK_ENTRIES; i++) {
        if (strlen(phone_book[i].name) > 0) {
            printf("%s\t\t%s\n", phone_book[i].name, phone_book[i].phone_number);
        }
    }
}

// Get a string from the user
char *get_string(char *prompt) {
    char *str = NULL;
    size_t len = 0;

    printf("%s", prompt);
    getline(&str, &len, stdin);

    // Remove the newline character from the end of the string
    str[strcspn(str, "\n")] = 0;

    return str;
}

// Main function
int main() {
    // Initialize the phone book
    initialize_phone_book();

    // Get the user's input
    char *name = get_string("Enter a name: ");
    char *phone_number = get_string("Enter a phone number: ");

    // Add the entry to the phone book
    add_entry(name, phone_number);

    // Print the phone book
    print_phone_book();

    return 0;
}