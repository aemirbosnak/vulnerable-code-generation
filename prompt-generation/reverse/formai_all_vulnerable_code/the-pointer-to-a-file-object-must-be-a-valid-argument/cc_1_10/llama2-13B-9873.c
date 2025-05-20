//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: thoughtful
// A Phone Book Program for the Creatively Inclined

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store phone book entries
struct phone_entry {
    char name[50];
    char number[20];
};

// Function to read phone book entries from file
void read_phone_book(struct phone_entry *phone_book, int max_entries) {
    int i = 0;
    FILE *file = fopen("phone_book.txt", "r");

    // Read each line of the file and store in phone book
    while (i < max_entries && fgets(phone_book[i].name, 50, file) != NULL) {
        // Skip any leading or trailing white space
        char *token = strtok(phone_book[i].name, " ");
        strcpy(phone_book[i].number, token);
        i++;
    }

    fclose(file);
}

// Function to search for a phone number in the phone book
int search_phone_book(struct phone_entry *phone_book, int max_entries, char *number) {
    int i = 0;

    // Search through the phone book for the given number
    while (i < max_entries && strcmp(phone_book[i].number, number) != 0)
        i++;

    // If the number is found, return the corresponding name
    if (i < max_entries)
        return phone_book[i].name;
    else
        return NULL;
}

// Function to add a new phone book entry
void add_phone_book_entry(struct phone_entry *phone_book, int max_entries, char *name, char *number) {
    int i = 0;

    // Find an empty slot in the phone book
    while (i < max_entries && phone_book[i].name != NULL)
        i++;

    // If an empty slot is found, store the new entry
    if (i < max_entries) {
        strcpy(phone_book[i].name, name);
        strcpy(phone_book[i].number, number);
    }
}

int main() {
    struct phone_entry phone_book[10];
    int max_entries = 10;

    // Read phone book entries from file
    read_phone_book(phone_book, max_entries);

    // Search for a phone number in the phone book
    char *number = "555-1234";
    char *name = search_phone_book(phone_book, max_entries, number);

    // Add a new phone book entry
    char *new_name = "John Doe";
    char *new_number = "555-5678";
    add_phone_book_entry(phone_book, max_entries, new_name, new_number);

    // Print the phone book
    for (int i = 0; i < max_entries; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
    }

    return 0;
}