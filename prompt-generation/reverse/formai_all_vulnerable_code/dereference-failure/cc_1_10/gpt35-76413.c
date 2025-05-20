//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each contact
typedef struct contact {
    char name[50];
    char number[20];
    struct contact* next;
} Contact;

// Function to add a new contact to the phone book
void addContact(Contact** phonebook, char name[], char number[]) {
    Contact* newContact = (Contact*) malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    newContact->next = (*phonebook);
    (*phonebook) = newContact;
}

// Function to search for a contact by name
void searchContact(Contact* phonebook, char name[]) {
    Contact* current = phonebook;
    int found = 0;
    
    printf("\nSearch Results:\n");
    printf("-----------------\n");

    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->number);
            found = 1;
        }
        current = current->next;
    }

    if(found == 0){
        printf("No matching contacts found.\n");
    }
}

// Function to display all contacts in the phone book
void displayContacts(Contact* phonebook) {
    Contact* current = phonebook;
    
    printf("\nPhonebook:\n");
    printf("-----------\n");

    while(current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

// Main function to test out the phone book program
int main() {
    Contact* phonebook = NULL;
    char name[50], number[20];
    int choice;

    while(1) {
        // Display the menu
        printf("\nPhone Book Menu:\n");
        printf("-----------------\n");
        printf("1. Add New Contact\n");
        printf("2. Search for Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4):");
        scanf("%d", &choice);

        // Perform the appropriate action based on the user's choice
        switch(choice) {
            case 1:
                printf("\nEnter Contact Name:");
                scanf("%s", name);
                printf("Enter Contact Number:");
                scanf("%s", number);
                addContact(&phonebook, name, number);
                printf("\nContact added successfully!\n");
                break;

            case 2:
                printf("\nEnter Name to Search For:");
                scanf("%s", name);
                searchContact(phonebook, name);
                break;

            case 3:
                displayContacts(phonebook);
                break;

            case 4:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid Choice, Please Try Again.\n");
        }
    }
    
    return 0;
}