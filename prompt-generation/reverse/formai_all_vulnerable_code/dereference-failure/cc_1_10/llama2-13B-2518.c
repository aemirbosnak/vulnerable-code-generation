//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store contact information
typedef struct {
    char name[50];
    char phoneNumber[20];
    char email[50];
} Contact;

// Function to print the phone book
void printPhoneBook(Contact *phoneBook, int numEntries) {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("%d. %s %s %s\n", i + 1, phoneBook[i].name, phoneBook[i].phoneNumber, phoneBook[i].email);
    }
}

// Function to add a new contact to the phone book
void addContact(Contact *phoneBook, int *numEntries, char *name, char *phoneNumber, char *email) {
    int i;
    for (i = 0; i < *numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            // Contact already exists, update the information
            strcpy(phoneBook[i].phoneNumber, phoneNumber);
            strcpy(phoneBook[i].email, email);
            return;
        }
    }
    // Contact does not exist, add a new entry
    if (*numEntries == *numEntries) {
        // Increase the size of the phone book
        Contact *newPhoneBook = realloc(phoneBook, (*numEntries + 1) * sizeof(Contact));
        if (newPhoneBook == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        phoneBook = newPhoneBook;
        *numEntries += 1;
    }
    // Add the new contact
    strcpy(phoneBook[*numEntries].name, name);
    strcpy(phoneBook[*numEntries].phoneNumber, phoneNumber);
    strcpy(phoneBook[*numEntries].email, email);
}

// Example usage
int main() {
    int numEntries = 0;
    Contact *phoneBook = NULL;

    // Add some contacts
    addContact(&phoneBook, &numEntries, "John Doe", "555-1234", "johndoe@example.com");
    addContact(&phoneBook, &numEntries, "Jane Doe", "555-5678", "janedoe@example.com");
    addContact(&phoneBook, &numEntries, "Bob Smith", "555-9012", "bobsmith@example.com");

    // Print the phone book
    printPhoneBook(phoneBook, numEntries);

    return 0;
}