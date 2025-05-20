//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_RECORDS 10
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 12

// Define a struct to hold a single record
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

// Define an array to hold records
Record db[MAX_RECORDS];

// Define variables to hold the number of records and the file name
int num_records = 0;
char file_name[] = "database.txt";

// Function to add a record to the database
int add_record(char *name, char *phone) {
    // Check if there is room in the database
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database full\n");
        return 0;
    }
    // Add the record to the database
    strcpy(db[num_records].name, name);
    strcpy(db[num_records].phone, phone);
    num_records++;
    // Save the database to a file
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return 0;
    }
    for (int i = 0; i < num_records; i++) {
        fprintf(fp, "%s,%s\n", db[i].name, db[i].phone);
    }
    fclose(fp);
    // Return success
    return 1;
}

// Function to search for a record in the database by name
void search_record(char *name) {
    // Search for the record in the database
    int found = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(db[i].name, name) == 0) {
            printf("Record found: %s,%s\n", db[i].name, db[i].phone);
            found = 1;
        }
    }
    // If the record was not found, print an error message
    if (!found) {
        printf("Record not found\n");
    }
}

int main() {
    // Load the database from the file
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        if (add_record(name, phone) == 0) {
            printf("Error loading database\n");
            return 1;
        }
    }
    fclose(fp);
    // Add some records to the database
    add_record("Alice", "1234567890");
    add_record("Bob", "9876543210");
    add_record("Charlie", "5555555555");
    // Search for a record in the database
    search_record("Bob");
    // Return success
    return 0;
}