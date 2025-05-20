//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
} Contact;

Contact *phoneBook = NULL;
int numContacts = 0;

void addContact(char *name, char *number) {
    phoneBook = realloc(phoneBook, (numContacts + 1) * sizeof(Contact));
    strcpy(phoneBook[numContacts].name, name);
    strcpy(phoneBook[numContacts].number, number);
    numContacts++;
}

void printPhoneBook() {
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

void searchContact(char *name) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found contact: %s (%s)\n", phoneBook[i].name, phoneBook[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    // Add some contacts to the phone book
    addContact("John Doe", "555-1234");
    addContact("Jane Doe", "555-1235");
    addContact("Bill Smith", "555-1236");
    addContact("Mary Johnson", "555-1237");

    // Print the phone book
    printf("Phone Book:\n");
    printPhoneBook();

    // Search for a contact
    printf("\nSearch for a contact (enter name): ");
    char name[50];
    gets(name);
    searchContact(name);

    // Free the memory allocated for the phone book
    free(phoneBook);

    return 0;
}