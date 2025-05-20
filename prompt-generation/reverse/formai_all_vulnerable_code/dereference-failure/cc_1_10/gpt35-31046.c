//FormAI DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a mailing list contact
typedef struct {
    char name[50];
    char email[100];
} Contact;

// Define a struct for the mailing list itself
typedef struct {
    char name[50];
    Contact* contacts;
    int numContacts;
} MailingList;

// Function to add a new contact to a mailing list
void addContact(MailingList* list, Contact contact) {
    list->numContacts++;
    list->contacts = realloc(list->contacts, sizeof(Contact) * list->numContacts);
    list->contacts[list->numContacts-1] = contact;
}

// Function to display all contacts in a mailing list
void displayContacts(MailingList list) {
    printf("Contacts for %s:\n", list.name);
    for(int i=0; i<list.numContacts; i++) {
        printf("%s: %s\n", list.contacts[i].name, list.contacts[i].email);
    }
}

int main() {
    // Create a new mailing list
    MailingList list;
    strcpy(list.name, "My List");
    list.numContacts = 0;
    list.contacts = NULL;

    // Add some example contacts to the mailing list
    Contact contact1 = {"John Smith", "johnsmith@gmail.com"};
    addContact(&list, contact1);

    Contact contact2 = {"Jane Doe", "janedoe@yahoo.com"};
    addContact(&list, contact2);

    // Display all contacts in the mailing list
    displayContacts(list);

    // Clean up memory
    free(list.contacts);

    return 0;
}