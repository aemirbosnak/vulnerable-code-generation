//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHONE_BOOK_SIZE 100
#define PHONE_NUMBER_SIZE 10

// Structure to store phone book entries
typedef struct {
    char name[50];
    char phone_number[PHONE_NUMBER_SIZE];
} phone_book_entry;

// Function to initialize phone book
void init_phone_book(phone_book_entry **phone_book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, 50);
        memset(phone_book[i]->phone_number, 0, PHONE_NUMBER_SIZE);
    }
}

// Function to search phone book
int search_phone_book(phone_book_entry **phone_book, int size, char *name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add phone book entry
void add_phone_book_entry(phone_book_entry **phone_book, int size, char *name, char *phone_number) {
    int i;
    for (i = 0; i < size; i++) {
        if (phone_book[i]->name[0] == 0) {
            strcpy(phone_book[i]->name, name);
            strcpy(phone_book[i]->phone_number, phone_number);
            return;
        }
    }
    printf("Phone book is full, cannot add more entries\n");
}

// Function to print phone book
void print_phone_book(phone_book_entry **phone_book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d: %s %s\n", i, phone_book[i]->name, phone_book[i]->phone_number);
    }
}

int main() {
    phone_book_entry *phone_book;
    int size = PHONE_BOOK_SIZE;

    // Initialize phone book
    init_phone_book(&phone_book, size);

    // Add some phone book entries
    add_phone_book_entry(&phone_book, size, "John Doe", "555-1234");
    add_phone_book_entry(&phone_book, size, "Jane Doe", "555-5678");
    add_phone_book_entry(&phone_book, size, "Bob Smith", "555-9012");

    // Search phone book
    int index = search_phone_book(&phone_book, size, "Jane Doe");
    if (index != -1) {
        printf("Jane Doe's phone number is %s\n", phone_book[index].phone_number);
    } else {
        printf("Jane Doe is not in the phone book\n");
    }

    // Print phone book
    print_phone_book(&phone_book, size);

    return 0;
}