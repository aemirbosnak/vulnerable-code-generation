//FormAI DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 50
#define MAX_PHONE 20

// Struct to store contact information
typedef struct Contact {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
} Contact;

// Function to display the menu
void displayMenu() {
    printf("-----------------------------------------\n");
    printf("DATABASE INDEXING SYSTEM - CONTACT MANAGER\n");
    printf("-----------------------------------------\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Exit\n\n");
}

// Function to add a new contact to the database
void addContact(FILE *indexFile, FILE *dataFile) {
    Contact contact;
    int recordNumber;
    long int offset;

    // Prompt user for contact information
    printf("Enter Name: ");
    scanf("%s", contact.name);
    printf("Enter Email: ");
    scanf("%s", contact.email);
    printf("Enter Phone Number: ");
    scanf("%s", contact.phone);

    // Write contact information to data file
    fseek(dataFile, 0, SEEK_END);
    offset = ftell(dataFile);
    fprintf(dataFile, "%s|%s|%s\n", contact.name, contact.email, contact.phone);

    // Write contact information to index file
    recordNumber = (int)(offset / sizeof(Contact));
    fprintf(indexFile, "%d,%ld\n", recordNumber, offset);
}

// Function to search for a contact in the database
void searchContact(FILE *indexFile, FILE *dataFile) {
    char searchTerm[MAX_NAME];
    int resultFound = 0;
    int recordNumber;
    long int offset;

    // Prompt user for search term
    printf("Enter Name to search: ");
    scanf("%s", searchTerm);

    // Search for the search term in index file
    char line[MAX_NAME + sizeof(long int)];
    while (fgets(line, sizeof line, indexFile) != NULL) {
        char *token = strtok(line, ",");
        recordNumber = atoi(token);
        token = strtok(NULL, ",");
        offset = atol(token);

        // Read the record from the data file with the given offset
        fseek(dataFile, offset, SEEK_SET);
        Contact contact;
        fscanf(dataFile, "%[^|]|%[^|]|%[^\n]\n", contact.name, contact.email, contact.phone);

        // Check if the name matches the search term
        if (strcmp(searchTerm, contact.name) == 0) {
            printf("Record found at record number %d:\n", recordNumber);
            printf("Name: %s\n", contact.name);
            printf("Email: %s\n", contact.email);
            printf("Phone: %s\n", contact.phone);
            resultFound = 1;
        }
    }

    if (!resultFound) {
        printf("No record found for search term: %s\n", searchTerm);
    }
}

// Function to delete a contact from the database
void deleteContact(FILE *indexFile, FILE *dataFile) {
    char searchTerm[MAX_NAME];
    int recordNumber;
    long int offset;
    int resultFound = 0;

    // Prompt user for search term
    printf("Enter Name to delete: ");
    scanf("%s", searchTerm);

    // Search for the search term in index file
    char line[MAX_NAME + sizeof(long int)];
    FILE *tempIndexFile = fopen("tempIndexFile.txt", "w");
    while (fgets(line, sizeof line, indexFile) != NULL) {
        char *token = strtok(line, ",");
        recordNumber = atoi(token);
        token = strtok(NULL, ",");
        offset = atol(token);

        // Read the record from the data file with the given offset
        fseek(dataFile, offset, SEEK_SET);
        Contact contact;
        fscanf(dataFile, "%[^|]|%[^|]|%[^\n]\n", contact.name, contact.email, contact.phone);

        // Check if the name matches the search term and delete the record
        if (strcmp(searchTerm, contact.name) == 0) {
            printf("Record deleted at record number %d:\n", recordNumber);
            printf("Name: %s\n", contact.name);
            printf("Email: %s\n", contact.email);
            printf("Phone: %s\n", contact.phone);
            resultFound = 1;
        } else {
            fprintf(tempIndexFile, "%d,%ld\n", recordNumber, offset);
        }
    }

    fclose(tempIndexFile);
    fclose(indexFile);
    remove("indexFile.txt");
    rename("tempIndexFile.txt", "indexFile.txt");

    if (!resultFound) {
        printf("No record found for search term: %s\n", searchTerm);
    }
}

// Function to display all the contacts in the database
void displayAllContacts(FILE *dataFile) {
    fseek(dataFile, 0, SEEK_SET);
    Contact contact;

    // Loop through each record in data file and display the contacts
    printf("All Contacts:\n");
    while (fscanf(dataFile, "%[^|]|%[^|]|%[^\n]\n", contact.name, contact.email, contact.phone) != EOF) {
        printf("Name: %s\n", contact.name);
        printf("Email: %s\n", contact.email);
        printf("Phone: %s\n\n", contact.phone);
    }
}

int main() {
    FILE *indexFile = fopen("indexFile.txt", "a+"); // Open index file in append mode
    FILE *dataFile = fopen("dataFile.txt", "a+"); // Open data file in append mode

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(indexFile, dataFile);
                break;
            case 2:
                searchContact(indexFile, dataFile);
                break;
            case 3:
                deleteContact(indexFile, dataFile);
                break;
            case 4:
                displayAllContacts(dataFile);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 5);

    fclose(indexFile);
    fclose(dataFile);

    return 0;
}