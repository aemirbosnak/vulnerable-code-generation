//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 1000
#define AVG_PHONE_NUMBER_LENGTH 10

// Structure to store phone book entries
typedef struct {
    char name[50];
    char number[AVG_PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Function to generate random phone book entries
phone_book_entry generate_entry(void) {
    // Generate a random name
    char name[50];
    snprintf(name, sizeof(name), "Person %d", rand() % 100);

    // Generate a random phone number
    char number[AVG_PHONE_NUMBER_LENGTH];
    snprintf(number, sizeof(number), "%d%d%d", rand() % 10, rand() % 10, rand() % 10);

    // Return the phone book entry
    return (phone_book_entry) {
        .name = name,
        .number = number
    };
}

// Function to print the phone book
void print_phone_book(phone_book_entry *book, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s %s\n", i + 1, book[i].name, book[i].number);
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_book_entry **book, int *size, phone_book_entry new_entry) {
    // Check if the phone book is full
    if (*size == PHONE_BOOK_SIZE) {
        printf("Phone book is full! (%d entries)\n", *size);
        return;
    }

    // Add the new entry to the phone book
    (*book)[*size] = new_entry;
    (*size)++;

    // Print the updated phone book
    print_phone_book(book, *size);
}

int main(void) {
    // Initialize the phone book
    phone_book_entry *book = calloc(PHONE_BOOK_SIZE, sizeof(phone_book_entry));
    int size = 0;

    // Generate and add some entries to the phone book
    for (int i = 0; i < 10; i++) {
        phone_book_entry new_entry = generate_entry();
        add_entry(&book, &size, new_entry);
    }

    // Print the phone book
    print_phone_book(book, size);

    // Free the phone book memory
    free(book);

    return 0;
}