//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct Contact {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function to create a new contact
Contact* createContact(char* name, char* phone, char* email) {
    Contact* contact = malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->phone, phone);
    strcpy(contact->email, email);
    return contact;
}

// Function to print a contact
void printContact(Contact* contact) {
    printf("Name: %s\n", contact->name);
    printf("Phone: %s\n", contact->phone);
    printf("Email: %s\n", contact->email);
}

// Function to add a contact to a phone book
void addContact(Contact** phoneBook, int* numContacts, Contact* contact) {
    phoneBook[*numContacts] = contact;
    (*numContacts)++;
}

// Function to search for a contact in a phone book by name
Contact* searchContactByName(Contact** phoneBook, int numContacts, char* name) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i]->name, name) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Function to search for a contact in a phone book by phone number
Contact* searchContactByPhone(Contact** phoneBook, int numContacts, char* phone) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i]->phone, phone) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Function to search for a contact in a phone book by email
Contact* searchContactByEmail(Contact** phoneBook, int numContacts, char* email) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i]->email, email) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Function to delete a contact from a phone book
void deleteContact(Contact** phoneBook, int* numContacts, Contact* contact) {
    for (int i = 0; i < *numContacts; i++) {
        if (phoneBook[i] == contact) {
            for (int j = i; j < *numContacts - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            (*numContacts)--;
            free(contact);
            return;
        }
    }
}

// Function to print all contacts in a phone book
void printPhoneBook(Contact** phoneBook, int numContacts) {
    for (int i = 0; i < numContacts; i++) {
        printContact(phoneBook[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a phone book
    Contact** phoneBook = malloc(sizeof(Contact*) * 100);
    int numContacts = 0;

    // Add some contacts to the phone book
    addContact(phoneBook, &numContacts, createContact("Alice", "555-123-4567", "alice@example.com"));
    addContact(phoneBook, &numContacts, createContact("Bob", "555-234-5678", "bob@example.com"));
    addContact(phoneBook, &numContacts, createContact("Carol", "555-345-6789", "carol@example.com"));

    // Print the phone book
    printf("Phone Book:\n");
    printPhoneBook(phoneBook, numContacts);

    // Search for a contact by name
    Contact* contact = searchContactByName(phoneBook, numContacts, "Bob");
    if (contact != NULL) {
        printf("Found contact by name:\n");
        printContact(contact);
    } else {
        printf("Contact not found by name.\n");
    }

    // Search for a contact by phone number
    contact = searchContactByPhone(phoneBook, numContacts, "555-234-5678");
    if (contact != NULL) {
        printf("Found contact by phone number:\n");
        printContact(contact);
    } else {
        printf("Contact not found by phone number.\n");
    }

    // Search for a contact by email
    contact = searchContactByEmail(phoneBook, numContacts, "bob@example.com");
    if (contact != NULL) {
        printf("Found contact by email:\n");
        printContact(contact);
    } else {
        printf("Contact not found by email.\n");
    }

    // Delete a contact from the phone book
    deleteContact(phoneBook, &numContacts, contact);

    // Print the phone book again
    printf("\nPhone Book after deleting contact:\n");
    printPhoneBook(phoneBook, numContacts);

    // Free the memory allocated for the phone book
    for (int i = 0; i < numContacts; i++) {
        free(phoneBook[i]);
    }
    free(phoneBook);

    return 0;
}