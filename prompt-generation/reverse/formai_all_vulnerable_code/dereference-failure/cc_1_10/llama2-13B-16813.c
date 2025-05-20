//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PHONE_BOOK_SIZE 1000
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Structure to store a phone book entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Function to initialize the phone book
void init_phone_book(phone_book_entry** phone_book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, MAX_NAME_LENGTH);
        memset(phone_book[i]->phone_number, 0, MAX_PHONE_NUMBER_LENGTH);
    }
}

// Function to search for a name in the phone book
phone_book_entry* search_phone_book(phone_book_entry** phone_book, int size, char* name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to add a new entry to the phone book
void add_to_phone_book(phone_book_entry** phone_book, int size, char* name, char* phone_number) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Update existing entry
            strcpy(phone_book[i]->phone_number, phone_number);
            return;
        }
    }
    // Add new entry
    phone_book[size] = malloc(sizeof(phone_book_entry));
    strcpy(phone_book[size]->name, name);
    strcpy(phone_book[size]->phone_number, phone_number);
    size++;
}

// Function to print the phone book
void print_phone_book(phone_book_entry** phone_book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i]->name, phone_book[i]->phone_number);
    }
}

int main() {
    int i, j;
    phone_book_entry** phone_book = malloc(PHONE_BOOK_SIZE * sizeof(phone_book_entry*));
    init_phone_book(phone_book, PHONE_BOOK_SIZE);

    // Add some entries to the phone book
    add_to_phone_book(phone_book, PHONE_BOOK_SIZE, "John Doe", "555-1234");
    add_to_phone_book(phone_book, PHONE_BOOK_SIZE, "Jane Doe", "555-5678");
    add_to_phone_book(phone_book, PHONE_BOOK_SIZE, "Bob Smith", "555-9012");

    // Search for some names in the phone book
    printf("Searching for 'John Doe': ");
    phone_book_entry* john_doe = search_phone_book(phone_book, PHONE_BOOK_SIZE, "John Doe");
    if (john_doe != NULL) {
        printf("Found! %s %s\n", john_doe->name, john_doe->phone_number);
    } else {
        printf("Not found.\n");
    }

    printf("Searching for 'Jane Doe': ");
    phone_book_entry* jane_doe = search_phone_book(phone_book, PHONE_BOOK_SIZE, "Jane Doe");
    if (jane_doe != NULL) {
        printf("Found! %s %s\n", jane_doe->name, jane_doe->phone_number);
    } else {
        printf("Not found.\n");
    }

    // Print the phone book
    printf("Phone book: \n");
    print_phone_book(phone_book, PHONE_BOOK_SIZE);

    return 0;
}