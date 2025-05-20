//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: retro
// RetroPhoneBook.c - A vintage-inspired phone book application

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the phone book structure
typedef struct {
    char name[20];  // Name of the person
    char phone[10]; // Phone number
} phone_book_entry;

// Define a function to read the phone book from a file
phone_book_entry read_phone_book(const char* file_name) {
    // Open the file in read mode
    FILE* file = fopen(file_name, "r");

    // Read the phone book entry from the file
    char line[100];
    fgets(line, 100, file);

    // Tokenize the line into name and phone number
    char* name = strtok(line, " ");
    char* phone = strtok(NULL, "\n");

    // Create a phone book entry and return it
    phone_book_entry entry = {
        .name = name,
        .phone = phone
    };
    return entry;
}

// Define a function to write the phone book to a file
void write_phone_book(const char* file_name, phone_book_entry entry) {
    // Open the file in write mode
    FILE* file = fopen(file_name, "w");

    // Write the phone book entry to the file
    fprintf(file, "%s %s\n", entry.name, entry.phone);

    // Close the file
    fclose(file);
}

int main() {
    // Create a phone book with some entries
    phone_book_entry phone_book[] = {
        { "John Doe", "555-1234" },
        { "Jane Smith", "555-5678" },
        { "Bob Johnson", "555-9012" }
    };

    // Print the phone book entries
    for (int i = 0; i < sizeof(phone_book) / sizeof(phone_book_entry); i++) {
        printf("%d: %s %s\n", i, phone_book[i].name, phone_book[i].phone);
    }

    // Ask the user for a file name to write the phone book to
    printf("Enter a file name to write the phone book to (e.g. 'my_phone_book.txt'): ");
    char file_name[50];
    scanf("%49s", file_name);

    // Write the phone book to the file
    for (int i = 0; i < sizeof(phone_book) / sizeof(phone_book_entry); i++) {
        write_phone_book(file_name, phone_book[i]);
    }

    // Ask the user for a file name to read the phone book from
    printf("Enter a file name to read the phone book from (e.g. 'my_phone_book.txt'): ");
    char read_file_name[50];
    scanf("%49s", read_file_name);

    // Read the phone book from the file
    phone_book_entry entry = read_phone_book(read_file_name);

    // Print the read phone book entry
    printf("Read phone book entry: %s %s\n", entry.name, entry.phone);

    return 0;
}