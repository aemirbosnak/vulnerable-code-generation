//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone_number[20];
} Contact;

void addContact(Contact *contacts, int *numContacts) {
    printf("Enter name: ");
    fgets(contacts[*numContacts].name, 50, stdin);
    printf("Enter phone number: ");
    fgets(contacts[*numContacts].phone_number, 20, stdin);
    (*numContacts)++;
    printf("Contact added!\n");
}

void displayContacts(Contact *contacts, int numContacts) {
    printf("\nContacts:\n");
    for(int i = 0; i < numContacts; i++) {
        printf("%d. %s: %s", i+1, contacts[i].name, contacts[i].phone_number);
    }
    printf("\n");
}

int main() {
    char choice;
    int numContacts = 0;
    Contact *contacts = (Contact*) malloc(sizeof(Contact));
    if(contacts == NULL) {
        printf("Unable to allocate memory!");
        return 1;
    }

    printf("Welcome to the Surreal Phone Book! Your directory for all your nonsensical communication needs.\n");

    do {
        printf("\nPlease select an option:\n1. Add Contact\n2. Display Contacts\n3. Exit\n");
        choice = getchar();
        while(getchar() != '\n'); // Clear input buffer
        switch(choice) {
            case '1':
                addContact(contacts, &numContacts);
                break;
            case '2':
                displayContacts(contacts, numContacts);
                break;
            case '3':
                printf("Thank you for using the Surreal Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != '3');

    free(contacts);
    return 0;
}