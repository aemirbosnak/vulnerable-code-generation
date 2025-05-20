//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 32

// Structure to store a person's name and phone number
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} person_t;

// Function to create a new person
person_t* create_person(char* name, char* phone_number) {
    person_t* new_person = malloc(sizeof(person_t));
    strcpy(new_person->name, name);
    strcpy(new_person->phone_number, phone_number);
    return new_person;
}

// Function to print all people in the phone book
void print_phone_book(person_t** phone_book) {
    for (int i = 0; i < sizeof(phone_book) / sizeof(person_t*); i++) {
        printf("%d: %s %s\n", i, phone_book[i]->name, phone_book[i]->phone_number);
    }
}

// Function to add a new person to the phone book
void add_person(person_t** phone_book, char* name, char* phone_number) {
    person_t* new_person = create_person(name, phone_number);
    int index = sizeof(phone_book) / sizeof(person_t*);
    phone_book[index] = new_person;
    print_phone_book(phone_book);
}

// Function to remove a person from the phone book
void remove_person(person_t** phone_book, int index) {
    if (index < sizeof(phone_book) / sizeof(person_t*)) {
        free(phone_book[index]);
        memmove(phone_book + index, phone_book + index + 1, (sizeof(phone_book) / sizeof(person_t*)) - index);
        print_phone_book(phone_book);
    }
}

int main() {
    person_t** phone_book = malloc(sizeof(person_t*) * 10);
    for (int i = 0; i < 10; i++) {
        char name[MAX_NAME_LENGTH];
        char phone_number[MAX_PHONE_NUMBER_LENGTH];
        printf("Enter name: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        printf("Enter phone number: ");
        fgets(phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);
        add_person(phone_book, name, phone_number);
    }

    // Remove some people from the phone book
    remove_person(phone_book, 3);
    remove_person(phone_book, 6);

    // Print the updated phone book
    print_phone_book(phone_book);

    return 0;
}