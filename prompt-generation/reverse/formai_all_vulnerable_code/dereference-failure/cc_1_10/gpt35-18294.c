//FormAI DATASET v1.0 Category: Mailing list manager ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char firstName[20];
    char lastName[20];
    char email[50];
} Contact; 

typedef struct{
    Contact *contacts;
    int numContacts;
} MailingList;

void addContact(MailingList *list, char *firstName, char *lastName, char *email){
    list->numContacts++;
    list->contacts = realloc(list->contacts, list->numContacts * sizeof(Contact));
    Contact newContact = {
        .firstName = firstName,
        .lastName = lastName,
        .email = email
    };
    list->contacts[list->numContacts - 1] = newContact;
}

void printContacts(MailingList *list){
    for(int i = 0; i < list->numContacts; i++){
        printf("Name: %s %s\nEmail: %s\n\n", list->contacts[i].firstName, list->contacts[i].lastName, list->contacts[i].email);
    }
}

void deleteContact(MailingList *list, int index){
    if(index >= list->numContacts || index < 0){
        printf("Invalid index\n");
        return;
    }
    for(int i = index; i < list->numContacts - 1; i++){
        list->contacts[i] = list->contacts[i+1];
    }
    list->numContacts--;
}

int main(void){
    MailingList myList = {
        .contacts = NULL,
        .numContacts = 0
    };

    // Add contacts to the list
    addContact(&myList, "Bob", "Johnson", "bjohnson@gmail.com");
    addContact(&myList, "Sarah", "Lee", "slee@yahoo.com");
    addContact(&myList, "Mark", "Kim", "mkim@hotmail.com");

    // Print the list of contacts
    printf("List of contacts:\n");
    printContacts(&myList);

    // Delete a contact from the list
    printf("Deleting index 1...\n");
    deleteContact(&myList, 1);

    // Print the updated list of contacts
    printf("List of contacts after deleting index 1:\n");
    printContacts(&myList);

    // Add a new contact to the list
    printf("Adding new contact...\n");
    addContact(&myList, "Michelle", "Park", "mpark@gmail.com");

    // Print the updated list of contacts
    printf("List of contacts after adding new contact:\n");
    printContacts(&myList);

    return 0;
}