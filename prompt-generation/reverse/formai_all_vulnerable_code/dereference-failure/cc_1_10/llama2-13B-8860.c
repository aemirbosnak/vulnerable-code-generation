//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Structure to store contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
} contact;

// Function to print the contact book
void printContactBook(contact *contacts, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("Name: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phoneNumber);
    }
}

// Function to add a new contact
void addContact(contact *contacts, int *count, char *name, char *phoneNumber) {
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact already exists, update the phone number
            strcpy(contacts[i].phoneNumber, phoneNumber);
            return;
        }
    }
    // Contact does not exist, add a new one
    contacts[*count] = (contact) { name, phoneNumber };
    (*count)++;
}

// Function to remove a contact
void removeContact(contact *contacts, int *count, char *name) {
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Remove the contact
            memset(&contacts[i], 0, sizeof(contact));
            (*count)--;
            return;
        }
    }
    // Contact does not exist, do nothing
}

int main() {
    int count = 0;
    contact *contacts = malloc(sizeof(contact) * 10);
    srand(time(NULL));

    // Add some contacts
    addContact(contacts, &count, "Alice", "555-1234");
    addContact(contacts, &count, "Bob", "555-5678");
    addContact(contacts, &count, "Charlie", "555-9012");

    // Remove a contact
    removeContact(contacts, &count, "Bob");

    // Print the contact book
    printContactBook(contacts, count);

    // Free memory
    free(contacts);

    return 0;
}