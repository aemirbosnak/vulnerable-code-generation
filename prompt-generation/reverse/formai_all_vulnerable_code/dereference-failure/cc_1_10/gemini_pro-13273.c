//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the phone book.
#define MAX_ENTRIES 100

// Define the structure of a phone book entry.
typedef struct {
    char name[32];
    char number[16];
} phone_book_entry;

// Define the phone book.
phone_book_entry phone_book[MAX_ENTRIES];

// Define the current number of entries in the phone book.
int num_entries = 0;

// Function to add an entry to the phone book.
void add_entry(char *name, char *number) {
    // Check if the phone book is full.
    if (num_entries == MAX_ENTRIES) {
        printf("The phone book is full!\n");
        return;
    }

    // Add the entry to the phone book.
    strcpy(phone_book[num_entries].name, name);
    strcpy(phone_book[num_entries].number, number);

    // Increment the number of entries in the phone book.
    num_entries++;
}

// Function to delete an entry from the phone book.
void delete_entry(char *name) {
    // Find the entry in the phone book.
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            break;
        }
    }

    // Check if the entry was found.
    if (i == num_entries) {
        printf("The entry was not found!\n");
        return;
    }

    // Delete the entry from the phone book.
    for (i = i + 1; i < num_entries; i++) {
        phone_book[i - 1] = phone_book[i];
    }

    // Decrement the number of entries in the phone book.
    num_entries--;
}

// Function to find an entry in the phone book.
void find_entry(char *name) {
    // Find the entry in the phone book.
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            break;
        }
    }

    // Check if the entry was found.
    if (i == num_entries) {
        printf("The entry was not found!\n");
        return;
    }

    // Print the entry.
    printf("Name: %s\n", phone_book[i].name);
    printf("Number: %s\n", phone_book[i].number);
}

// Function to print the phone book.
void print_phone_book() {
    // Print the phone book.
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\n", phone_book[i].name);
        printf("Number: %s\n", phone_book[i].number);
    }
}

// Main function.
int main() {
    // Welcome the user.
    printf("Welcome to the phone book!\n");

    // Get the user's input.
    char input[100];
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);

        // Parse the input.
        char *command = strtok(input, " ");
        char *name = strtok(NULL, " ");
        char *number = strtok(NULL, " ");

        // Execute the command.
        if (strcmp(command, "add") == 0) {
            add_entry(name, number);
        } else if (strcmp(command, "delete") == 0) {
            delete_entry(name);
        } else if (strcmp(command, "find") == 0) {
            find_entry(name);
        } else if (strcmp(command, "print") == 0) {
            print_phone_book();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    // Thank the user.
    printf("Thank you for using the phone book!\n");

    return 0;
}