//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

// Define a struct for the contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Define a struct for the mailing list
typedef struct {
    Contact* contacts;  // a pointer to an array of Contact structs
    int size;           // size of the array
    int count;          // number of contacts currently in the array
} MailingList;

// Function prototypes
void addContact(MailingList* list, char* name, char* email);
void printContacts(MailingList* list);
void freeList(MailingList* list);

int main() {
    // Initialize an empty mailing list
    MailingList list;
    list.contacts = NULL;
    list.size = 0;
    list.count = 0;

    // Add some contacts to the list
    addContact(&list, "John Smith", "john.smith@example.com");
    addContact(&list, "Jane Doe", "jane.doe@example.com");
    addContact(&list, "Bob Johnson", "bob.johnson@example.com");

    // Print out the contacts in the list
    printContacts(&list);

    // Free the memory used by the mailing list
    freeList(&list);

    return 0;
}

// This function adds a contact to the mailing list
void addContact(MailingList* list, char* name, char* email) {
    // If the list is currently empty, allocate space for one contact
    if (list->contacts == NULL) {
        list->contacts = (Contact*) malloc(sizeof(Contact));
        list->size = 1;
    }

    // If the list is full, double its size and realloc the memory
    if (list->count >= list->size) {
        list->size *= 2;
        list->contacts = (Contact*) realloc(list->contacts, sizeof(Contact) * list->size);
    }

    // Add the new contact to the list
    strcpy(list->contacts[list->count].name, name);
    strcpy(list->contacts[list->count].email, email);
    list->count++;
}

// This function prints out all of the contacts in the mailing list
void printContacts(MailingList* list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s, Email: %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

// This function frees the memory used by the mailing list
void freeList(MailingList* list) {
    free(list->contacts);
    list->contacts = NULL;
    list->size = 0;
    list->count = 0;
}