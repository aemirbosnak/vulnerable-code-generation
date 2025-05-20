//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a person's information
typedef struct {
    char name[50];
    char number[20];
} person;

// Function to print the phone book
void printPhoneBook(person *phoneBook, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, phoneBook[i].name);
    }
}

// Function to add a new person to the phone book
void addPerson(person *phoneBook, int size, char *name, char *number) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            // Person already exists, update their number
            strcpy(phoneBook[i].number, number);
            break;
        }
    }
    if (i == size) {
        // Person does not exist, add them to the end
        person newPerson = { name, number };
        memcpy(phoneBook + size, &newPerson, sizeof(person));
        size++;
    }
}

int main() {
    // Initialize the phone book with 5 empty slots
    person phoneBook[5] = { };

    // Add some people to the phone book
    addPerson(phoneBook, 5, "John", "555-1234");
    addPerson(phoneBook, 5, "Jane", "555-5678");
    addPerson(phoneBook, 5, "Bob", "555-9012");

    // Print the phone book
    printPhoneBook(phoneBook, 5);

    // Add a new person to the phone book
    addPerson(phoneBook, 5, "Alice", "555-1111");

    // Print the phone book again
    printPhoneBook(phoneBook, 5);

    return 0;
}