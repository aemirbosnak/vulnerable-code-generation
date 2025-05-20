//FormAI DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Function to clear the input buffer
void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a new contact
void addContact(char names[MAX_CONTACTS][50], char numbers[MAX_CONTACTS][20], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Error: Maximum number of contacts reached!\n");
        return;
    }

    printf("Enter the name of the contact: ");
    fgets(names[*numContacts], 50, stdin);
    names[*numContacts][strlen(names[*numContacts])-1] = '\0'; // Removing the newline character

    printf("Enter the phone number of the contact: ");
    fgets(numbers[*numContacts], 20, stdin);
    numbers[*numContacts][strlen(numbers[*numContacts])-1] = '\0'; // Removing the newline character

    *numContacts += 1;
    printf("Contact added successfully.\n");
}

// Function to display all contacts
void displayContacts(char names[MAX_CONTACTS][50], char numbers[MAX_CONTACTS][20], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found!\n");
        return;
    }

    printf("Name\t\t\tPhone Number\n");
    printf("----\t\t\t------------\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s\t\t\t%s\n", names[i], numbers[i]);
    }
}

// Function to search for a contact by name
void searchContact(char names[MAX_CONTACTS][50], char numbers[MAX_CONTACTS][20], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts found!\n");
        return;
    }

    char searchName[50];
    printf("Enter the name of the contact to search for: ");
    fgets(searchName, 50, stdin);
    searchName[strlen(searchName)-1] = '\0'; // Removing the newline character

    int found = 0; // Flag to keep track of whether the contact was found or not
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("Name\t\t\tPhone Number\n");
            printf("----\t\t\t------------\n");
            printf("%s\t\t\t%s\n", names[i], numbers[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

// Function to delete a contact by name
void deleteContact(char names[MAX_CONTACTS][50], char numbers[MAX_CONTACTS][20], int *numContacts) {
    if (*numContacts == 0) {
        printf("No contacts found!\n");
        return;
    }

    char deleteName[50];
    printf("Enter the name of the contact to delete: ");
    fgets(deleteName, 50, stdin);
    deleteName[strlen(deleteName)-1] = '\0'; // Removing the newline character

    int found = 0; // Flag to keep track of whether the contact was found or not
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(names[i], deleteName) == 0) {
            // Shift all the contacts after this one by one position to the left
            for (int j = i; j < *numContacts - 1; j++) {
                strcpy(names[j], names[j+1]);
                strcpy(numbers[j], numbers[j+1]);
            }

            *numContacts -= 1;
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

int main() {
    printf("Paranoid Phone Book\n");
    printf("===================\n");

    char contacts[MAX_CONTACTS][50]; // Array to store names of all contacts
    char numbers[MAX_CONTACTS][20]; // Array to store phone numbers of all contacts
    int numContacts = 0; // Variable to keep track of the number of contacts

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact by name\n");
        printf("4. Delete a contact by name\n");
        printf("5. Exit the program\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clearing the input buffer

        switch (choice) {
            case 1:
                addContact(contacts, numbers, &numContacts);
                break;

            case 2:
                displayContacts(contacts, numbers, numContacts);
                break;

            case 3:
                searchContact(contacts, numbers, numContacts);
                break;

            case 4:
                deleteContact(contacts, numbers, &numContacts);
                break;

            case 5:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}