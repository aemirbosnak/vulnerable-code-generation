//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store database record
typedef struct Record {
    int id;
    char name[50];
    char email[50];
} Record;

// Function to initialize database with sample records
void initializeDatabase(Record** database, int* numRecords) {
    // Allocate memory for 5 records
    *database = (Record*)malloc(5 * sizeof(Record));
    
    // Initialize records with sample data
    (*database)[0].id = 1;
    strcpy((*database)[0].name, "John Doe");
    strcpy((*database)[0].email, "john.doe@gmail.com");
    
    (*database)[1].id = 2;
    strcpy((*database)[1].name, "Jane Smith");
    strcpy((*database)[1].email, "jane.smith@yahoo.com");
    
    (*database)[2].id = 3;
    strcpy((*database)[2].name, "Bob Johnson");
    strcpy((*database)[2].email, "bob.johnson@hotmail.com");
    
    (*database)[3].id = 4;
    strcpy((*database)[3].name, "Alice Brown");
    strcpy((*database)[3].email, "alice.brown@gmail.com");
    
    (*database)[4].id = 5;
    strcpy((*database)[4].name, "Joe Black");
    strcpy((*database)[4].email, "joe.black@yahoo.com");
    
    // Set number of records to 5
    *numRecords = 5;
}

// Function to query database by email
void queryByEmail(Record* database, int numRecords, char* email) {
    int i;
    int found = 0;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(database[i].email, email) == 0) {
            printf("Record found: \n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Email: %s\n", database[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

int main() {
    // Initialize database with sample records
    Record* database;
    int numRecords;
    initializeDatabase(&database, &numRecords);
    
    // Query database by email
    queryByEmail(database, numRecords, "alice.brown@gmail.com");
    
    // Free memory allocated for database
    free(database);
    
    return 0;
}