//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to add a person to the phone book
void add_person(char **phonebook, int capacity, char *name, char *phone_number) {
    if (capacity == 0) {
        fprintf(stderr, "Phone book is full\n");
        return;
    }

    int len = strlen(name);
    if (len > 0) {
        char *ptr = (char*)malloc(sizeof(char) * (len + 1));
        strcpy(ptr, name);
        phonebook[capacity++] = ptr;
    }

    len = strlen(phone_number);
    if (len > 0) {
        char *ptr = (char*)malloc(sizeof(char) * (len + 1));
        strcpy(ptr, phone_number);
        phonebook[capacity++] = ptr;
    }
}

// Function to search for a person in the phone book
void search_person(char **phonebook, int capacity, char *name) {
    int i;
    for (i = 0; i < capacity; i++) {
        if (strcmp(phonebook[i], name) == 0) {
            printf("Phone number for %s: %s\n", phonebook[i], phonebook[i+1]);
            return;
        }
    }

    printf("Person not found in phone book\n");
}

// Function to print the phone book
void print_phone_book(char **phonebook, int capacity) {
    int i;
    for (i = 0; i < capacity; i++) {
        printf("Name: %s, Phone number: %s\n", phonebook[i], phonebook[i+1]);
    }
}

int main() {
    char *phonebook[10];
    int capacity = 10;

    add_person(phonebook, capacity, "Alice", "123456789");
    add_person(phonebook, capacity, "Bob", "098765432");
    add_person(phonebook, capacity, "Charlie", "123456789");

    search_person(phonebook, capacity, "Alice");
    search_person(phonebook, capacity, "Charlie");
    search_person(phonebook, capacity, "Bob");

    print_phone_book(phonebook, capacity);

    return 0;
}