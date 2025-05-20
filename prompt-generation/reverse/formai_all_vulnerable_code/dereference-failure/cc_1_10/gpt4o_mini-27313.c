//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold contact information
typedef struct {
    char name[50];
    char email[50];
    char phone[15];
} Contact;

// Function prototypes
Contact* createContact(const char* name, const char* email, const char* phone);
void displayContact(const Contact* contact);
void freeContact(Contact* contact);
void addContact(Contact*** contacts, int* size, const char* name, const char* email, const char* phone);
void displayAllContacts(Contact** contacts, int size);
void freeAllContacts(Contact** contacts, int size);

int main() {
    Contact** contacts = NULL; // Array of pointers to Contact
    int size = 0; // Number of contacts

    // Adding contacts
    addContact(&contacts, &size, "Alice Johnson", "alice@example.com", "123-456-7890");
    addContact(&contacts, &size, "Bob Smith", "bob@example.com", "987-654-3210");
    addContact(&contacts, &size, "Charlie Brown", "charlie@example.com", "555-555-5555");

    // Display all contacts
    printf("Contact List:\n");
    displayAllContacts(contacts, size);

    // Free all allocated memory
    freeAllContacts(contacts, size);
    
    return 0;
}

// Function to create and initialize a new Contact
Contact* createContact(const char* name, const char* email, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact == NULL) {
        fprintf(stderr, "Memory allocation failed for contact.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newContact->name, name, sizeof(newContact->name));
    strncpy(newContact->email, email, sizeof(newContact->email));
    strncpy(newContact->phone, phone, sizeof(newContact->phone));
    
    return newContact;
}

// Function to display a single contact's information
void displayContact(const Contact* contact) {
    printf("Name: %s\n", contact->name);
    printf("Email: %s\n", contact->email);
    printf("Phone: %s\n", contact->phone);
}

// Function to free the memory allocated for a single contact
void freeContact(Contact* contact) {
    free(contact);
}

// Function to add a new contact to the list
void addContact(Contact*** contacts, int* size, const char* name, const char* email, const char* phone) {
    // Resize the array of contacts
    *contacts = (Contact**)realloc(*contacts, (*size + 1) * sizeof(Contact*));
    if (*contacts == NULL) {
        fprintf(stderr, "Memory reallocation failed while adding a contact.\n");
        exit(EXIT_FAILURE);
    }

    // Create a new contact and add it to the list
    (*contacts)[*size] = createContact(name, email, phone);
    (*size)++;
}

// Function to display all contacts
void displayAllContacts(Contact** contacts, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nContact %d:\n", i + 1);
        displayContact(contacts[i]);
    }
}

// Function to free the memory allocated for all contacts
void freeAllContacts(Contact** contacts, int size) {
    for (int i = 0; i < size; i++) {
        freeContact(contacts[i]);
    }
    free(contacts);
    printf("\nAll contacts have been freed from memory.\n");
}