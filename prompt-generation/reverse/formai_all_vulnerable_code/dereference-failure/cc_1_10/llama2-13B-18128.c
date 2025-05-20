//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define PHONE_NUMBER_LENGTH 10

// Structure to store phone book entries
typedef struct phone_entry {
    char name[50];
    char phone_number[PHONE_NUMBER_LENGTH];
} phone_entry;

// Function to insert a new phone book entry
void insert_entry(phone_entry **phone_book, int *size, const char *name, const char *phone_number) {
    int i;

    // Check if the phone book is full
    if (*size == PHONE_BOOK_SIZE) {
        printf("Phone book is full! Cannot insert new entry.\n");
        return;
    }

    // Find an empty slot in the phone book
    for (i = 0; i < *size; i++) {
        if (phone_book[i] == NULL) {
            break;
        }
    }

    // If no empty slot found, reallocate the phone book
    if (i == *size) {
        phone_book = realloc(phone_book, (i + 1) * sizeof(phone_entry *));
        if (phone_book == NULL) {
            printf("Failed to reallocate phone book!\n");
            return;
        }
        *size = i + 1;
    }

    // Insert the new entry
    phone_book[i] = malloc(sizeof(phone_entry));
    if (phone_book[i] == NULL) {
        printf("Failed to allocate memory for new entry!\n");
        return;
    }
    strcpy(phone_book[i]->name, name);
    strcpy(phone_book[i]->phone_number, phone_number);

    // Print the new entry
    printf("Inserted new entry: %s (%s)\n", phone_book[i]->name, phone_book[i]->phone_number);
}

// Function to search for a phone number in the phone book
int search_phone_number(phone_entry **phone_book, int size, const char *phone_number) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(phone_book[i]->phone_number, phone_number) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to print all phone book entries
void print_phone_book(phone_entry **phone_book, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d: %s (%s)\n", i, phone_book[i]->name, phone_book[i]->phone_number);
    }
}

int main() {
    // Create a phone book with 100 slots
    phone_entry *phone_book = malloc(PHONE_BOOK_SIZE * sizeof(phone_entry *));
    int size = PHONE_BOOK_SIZE;

    // Insert some entries
    insert_entry(&phone_book, &size, "John Doe", "555-1234");
    insert_entry(&phone_book, &size, "Jane Doe", "555-5678");
    insert_entry(&phone_book, &size, "Bob Smith", "555-9012");

    // Search for a phone number
    int index = search_phone_number(&phone_book, size, "555-5678");
    if (index != -1) {
        printf("Found entry: %d\n", index);
    } else {
        printf("Entry not found\n");
    }

    // Print the entire phone book
    print_phone_book(&phone_book, size);

    return 0;
}