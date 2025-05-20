//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a phone book entry
typedef struct {
    char name[50];
    char number[20];
} phone_book_entry;

// Function to print the phone book
void print_phone_book(phone_book_entry *phone_book, int count) {
    if (count > 0) {
        printf("Phone Book:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
            print_phone_book(phone_book[i].number, count - i);
        }
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_book_entry **phone_book, int *count, char *name, char *number) {
    // Check if the phone book is full
    if (*count >= 50) {
        printf("Phone book is full, cannot add new entry\n");
        return;
    }

    // Allocate memory for the new entry
    phone_book_entry *new_entry = (phone_book_entry *)malloc(sizeof(phone_book_entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);

    // Add the new entry to the phone book
    *phone_book = realloc(*phone_book, (*count + 1) * sizeof(phone_book_entry));
    (*phone_book)[*count] = *new_entry;
    (*count)++;

    // Print the updated phone book
    print_phone_book(*phone_book, *count);
}

int main() {
    // Create an empty phone book
    phone_book_entry *phone_book = NULL;
    int count = 0;

    // Add some entries to the phone book
    add_entry(&phone_book, &count, "John Doe", "555-1234");
    add_entry(&phone_book, &count, "Jane Doe", "555-5678");
    add_entry(&phone_book, &count, "Bob Smith", "555-9012");

    // Print the phone book
    print_phone_book(phone_book, count);

    return 0;
}