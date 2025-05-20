//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_NUMBER_LENGTH 10

// Structure to store a person's name and phone number
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} person;

// Function to initialize a phone book
void init_phone_book(person** phone_book, int capacity) {
    int i;

    for (i = 0; i < capacity; i++) {
        person* current = phone_book[i];
        current->name[0] = '\0';
        current->phone_number[0] = '\0';
    }
}

// Function to add a person to the phone book
void add_person(person** phone_book, int capacity, const char* name, const char* phone_number) {
    int i;

    for (i = 0; i < capacity; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Person already exists, update their phone number
            strcpy(phone_book[i]->phone_number, phone_number);
            return;
        }
    }

    // Person does not exist, allocate a new slot in the phone book
    if (i == capacity) {
        // Increase the capacity of the phone book
        person** new_phone_book = realloc(phone_book, (capacity + 1) * sizeof(person*));
        if (new_phone_book == NULL) {
            printf("Error: Unable to allocate memory for phone book expansion\n");
            return;
        }
        phone_book = new_phone_book;
        capacity++;
    }

    // Add the new person to the phone book
    person* new_person = malloc(sizeof(person));
    strcpy(new_person->name, name);
    strcpy(new_person->phone_number, phone_number);
    phone_book[i] = new_person;
}

// Function to search the phone book for a person's name
int search_phone_book(const char* name, person** phone_book, int capacity) {
    int i;

    for (i = 0; i < capacity; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to print the phone book
void print_phone_book(person** phone_book, int capacity) {
    int i;

    for (i = 0; i < capacity; i++) {
        printf("%d: %s %s\n", i, phone_book[i]->name, phone_book[i]->phone_number);
    }
}

int main() {
    // Initialize the phone book with a capacity of 10
    person* phone_book[10];
    init_phone_book(phone_book, 10);

    // Add some people to the phone book
    add_person(phone_book, 10, "John Doe", "555-1234");
    add_person(phone_book, 10, "Jane Doe", "555-5678");
    add_person(phone_book, 10, "Bob Smith", "555-9012");

    // Search the phone book for a person's name
    int index = search_phone_book("Jane Doe", phone_book, 10);
    if (index != -1) {
        printf("Jane Doe's phone number is %s\n", phone_book[index]->phone_number);
    } else {
        printf("Jane Doe is not in the phone book\n");
    }

    // Print the phone book
    print_phone_book(phone_book, 10);

    return 0;
}