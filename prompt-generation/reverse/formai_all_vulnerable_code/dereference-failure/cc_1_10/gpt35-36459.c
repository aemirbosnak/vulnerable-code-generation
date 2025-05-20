//FormAI DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int numContacts;
} MailingList;

void addContact(MailingList *myList) {
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    printf("Enter email: ");
    fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);
    if (myList->contacts == NULL) {
        myList->contacts = (Contact*) malloc(sizeof(Contact));
    } else {
        myList->contacts = (Contact*) realloc(myList->contacts, (myList->numContacts + 1) * sizeof(Contact));
    }
    myList->contacts[myList->numContacts++] = newContact;
    printf("Contact added!\n");
}

void removeContact(MailingList *myList) {
    if (myList->numContacts == 0) {
        printf("No contacts to remove.\n");
    } else {
        int indexToRemove;
        printf("Enter index of contact to remove (0-%d): ", myList->numContacts - 1);
        scanf("%d", &indexToRemove);
        getchar(); // Consumes newline character in input buffer
        if (indexToRemove < 0 || indexToRemove >= myList->numContacts) {
            printf("Invalid index.\n");
        } else {
            for (int i = indexToRemove; i < myList->numContacts - 1; i++) {
                myList->contacts[i] = myList->contacts[i+1];
            }
            myList->contacts = (Contact*) realloc(myList->contacts, (myList->numContacts - 1) * sizeof(Contact));
            myList->numContacts--;
            printf("Contact removed!\n");
        }
    }
}

void displayContacts(MailingList *myList) {
    if (myList->numContacts == 0) {
        printf("No contacts to display.\n");
    } else {
        for (int i = 0; i < myList->numContacts; i++) {
            printf("%d. %s - %s", i, myList->contacts[i].name, myList->contacts[i].email);
        }
    }
}

int main() {
    MailingList myList = {NULL, 0};
    int choice = 0;
    do {
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Consumes newline character in input buffer
        switch (choice) {
            case 1:
                addContact(&myList);
                break;
            case 2:
                removeContact(&myList);
                break;
            case 3:
                displayContacts(&myList);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    free(myList.contacts);
    printf("Goodbye!\n");
    return 0;
}