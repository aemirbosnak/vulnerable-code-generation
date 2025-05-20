//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
} Contact;

// Create a new contact
Contact* createContact(char* name, char* number) {
    Contact* contact = (Contact*)malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->number, number);
    return contact;
}

// Print a contact
void printContact(Contact* contact) {
    printf("Name: %s, Number: %s\n", contact->name, contact->number);
}

// Add a contact to the phone book
void addContact(Contact*** phoneBook, int* numContacts, Contact* contact) {
    // Reallocate the phone book if necessary
    if (*numContacts == 0) {
        *phoneBook = (Contact**)malloc(sizeof(Contact*));
    } else {
        *phoneBook = (Contact**)realloc(*phoneBook, (*numContacts + 1) * sizeof(Contact*));
    }
    // Add the contact to the phone book
    (*phoneBook)[*numContacts] = contact;
    (*numContacts)++;
}

// Find a contact by name
Contact* findContactByName(Contact** phoneBook, int numContacts, char* name) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i]->name, name) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Delete a contact by name
void deleteContactByName(Contact*** phoneBook, int* numContacts, char* name) {
    // Find the contact by name
    Contact* contact = findContactByName(*phoneBook, *numContacts, name);
    if (contact == NULL) {
        printf("Contact not found!\n");
        return;
    }
    // Remove the contact from the phone book
    int index = -1;
    for (int i = 0; i < *numContacts; i++) {
        if (phoneBook[i] == contact) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Contact not found!\n");
        return;
    }
    for (int i = index; i < *numContacts - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }
    (*numContacts)--;
    // Free the memory allocated for the contact
    free(contact);
}

// Print the phone book
void printPhoneBook(Contact** phoneBook, int numContacts) {
    printf("Phone book:\n");
    for (int i = 0; i < numContacts; i++) {
        printContact(phoneBook[i]);
    }
}

// Main function
int main() {
    // Create a phone book
    Contact** phoneBook = NULL;
    int numContacts = 0;
    
    // Add some contacts to the phone book
    addContact(&phoneBook, &numContacts, createContact("Alice", "555-1212"));
    addContact(&phoneBook, &numContacts, createContact("Bob", "555-1213"));
    addContact(&phoneBook, &numContacts, createContact("Carol", "555-1214"));
    addContact(&phoneBook, &numContacts, createContact("Dave", "555-1215"));
    addContact(&phoneBook, &numContacts, createContact("Eve", "555-1216"));

    // Print the phone book
    printPhoneBook(phoneBook, numContacts);

    // Find a contact by name
    Contact* contact = findContactByName(phoneBook, numContacts, "Carol");
    if (contact != NULL) {
        printf("Found contact: ");
        printContact(contact);
    } else {
        printf("Contact not found!\n");
    }

    // Delete a contact by name
    deleteContactByName(&phoneBook, &numContacts, "Dave");
    
    // Print the phone book again
    printPhoneBook(phoneBook, numContacts);

    // Free the memory allocated for the phone book
    for (int i = 0; i < numContacts; i++) {
        free(phoneBook[i]);
    }
    free(phoneBook);

    return 0;
}