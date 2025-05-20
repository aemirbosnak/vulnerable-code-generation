//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a phone book entry
struct phone_book_entry {
    char name[50];  // Name of the person
    char number[20]; // Phone number
};

// Define a function to insert a new entry into the phone book
void insert_entry(struct phone_book_entry **phone_book, int *num_entries, const char *name, const char *number) {
    // Check if the name already exists in the phone book
    int i;
    for (i = 0; i < *num_entries; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            printf("Error: %s already exists in the phone book!\n", name);
            return;
        }
    }

    // Allocate memory for a new entry
    struct phone_book_entry *new_entry = (struct phone_book_entry *) malloc(sizeof(struct phone_book_entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);

    // Add the new entry to the phone book
    *num_entries += 1;
    phone_book = realloc(phone_book, (*num_entries) * sizeof(struct phone_book_entry));
    phone_book[*num_entries - 1] = new_entry;
}

// Define a function to search for a specific entry in the phone book
struct phone_book_entry *search_entry(struct phone_book_entry **phone_book, int num_entries, const char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

int main() {
    // Define the phone book
    struct phone_book_entry *phone_book = NULL;
    int num_entries = 0;

    // Insert some entries into the phone book
    insert_entry(&phone_book, &num_entries, "John Doe", "555-1234");
    insert_entry(&phone_book, &num_entries, "Jane Doe", "555-5678");
    insert_entry(&phone_book, &num_entries, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    struct phone_book_entry *entry = search_entry(&phone_book, num_entries, "Jane Doe");
    if (entry != NULL) {
        printf("Found Jane Doe's number: %s\n", entry->number);
    } else {
        printf("No such entry in the phone book... boo hoo!\n");
    }

    // Clean up
    free(phone_book);
    return 0;
}