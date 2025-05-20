//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>  // This is the standard input/output library in C language
#include <stdlib.h>  // This library is used for dynamic memory allocation
#include <string.h>  // This library is used for manipulating strings

// Constants
#define MAX_NAME_LENGTH 50 // maximum length of a name
#define MAX_ID_LENGTH 10 // maximum length of an ID
#define MAX_ENTRIES 1000 // maximum number of entries in the database

// Structure to store an entry in the database
typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
} Entry;

// Function prototypes
void addEntry(Entry *db, int *numEntries);
void deleteEntry(Entry *db, int *numEntries);
void printEntries(Entry *db, int numEntries);

int main() {
    Entry *db = (Entry*)malloc(MAX_ENTRIES * sizeof(Entry)); 
    // Allocate memory for the database

    int numEntries = 0; // variable to store the number of entries in the database

    printf("Welcome to the Database Simulation Program!\n");

    while (1) { // Loop until the user chooses to exit
        printf("What would you like to do?\n\n");
        printf("1. Add entry\n2. Delete entry\n3. Print entries\n4. Exit\n");

        char choice[2];
        fgets(choice, 2, stdin);
        getchar(); // Consume the newline character

        switch (choice[0]) {
            case '1':
                addEntry(db, &numEntries);
                break;
            case '2':
                deleteEntry(db, &numEntries);
                break;
            case '3':
                printEntries(db, numEntries);
                break;
            case '4':
                printf("Thank you for using the Database Simulation Program!\n");
                free(db);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add an entry to the database
void addEntry(Entry *db, int *numEntries) {
    if (*numEntries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    printf("Please enter the ID: ");
    char id[MAX_ID_LENGTH];
    fgets(id, MAX_ID_LENGTH, stdin);
    getchar(); // Consume the newline character

    printf("Please enter the name: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    getchar(); // Consume the newline character

    // Remove the newline character from the end of the strings
    id[strcspn(id, "\n")] = '\0';
    name[strcspn(name, "\n")] = '\0';

    // Check if ID already exists
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(db[i].id, id) == 0) {
            printf("Error: ID already exists in the database.\n");
            return;
        }
    }

    // Add the entry to the database
    strcpy(db[*numEntries].id, id);
    strcpy(db[*numEntries].name, name);
    (*numEntries)++;

    printf("Entry added to the database.\n");
}

// Function to delete an entry from the database
void deleteEntry(Entry *db, int *numEntries) {
    if (*numEntries == 0) {
        printf("Error: database is empty.\n");
        return;
    }

    printf("Please enter the ID of the entry to delete: ");
    char id[MAX_ID_LENGTH];
    fgets(id, MAX_ID_LENGTH, stdin);
    getchar(); // Consume the newline character

    // Remove the newline character from the end of the string
    id[strcspn(id, "\n")] = '\0';

    int indexToDelete = -1; // variable to store the index of the entry to delete

    // Find the index of the entry to delete
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(db[i].id, id) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("Error: entry not found in the database.\n");
        return;
    }

    // Shift all the entries after the deleted entry one position to the left
    for (int i = indexToDelete; i < *numEntries - 1; i++) {
        db[i] = db[i+1];
    }

    (*numEntries)--;

    printf("Entry deleted from the database.\n");
}

// Function to print all the entries in the database
void printEntries(Entry *db, int numEntries) {
    if (numEntries == 0) {
        printf("The database is empty.\n");
        return;
    }

    printf("ID\tName\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", db[i].id, db[i].name);
    }
}