//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a record in the database
typedef struct record {
    char name[50];
    char title[50];
    int age;
    int wealth;
} record;

// Function to create a new database
void create_database() {
    FILE *fp;
    fp = fopen("database.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file for writing\n");
        exit(1);
    }
    // Initialize the database with some sample records
    record r1 = {"King Arthur", "King", 50, 10000};
    record r2 = {"Sir Lancelot", "Knight", 30, 5000};
    record r3 = {"Queen Guinevere", "Queen", 25, 7500};
    fwrite(&r1, sizeof(record), 1, fp);
    fwrite(&r2, sizeof(record), 1, fp);
    fwrite(&r3, sizeof(record), 1, fp);
    fclose(fp);
}

// Function to add a new record to the database
void add_record() {
    FILE *fp;
    fp = fopen("database.txt", "a");
    if (fp == NULL) {
        printf("Error: could not open file for writing\n");
        exit(1);
    }
    // Get the new record from the user
    record r;
    printf("Enter the name of the person: ");
    scanf("%s", r.name);
    printf("Enter the title of the person: ");
    scanf("%s", r.title);
    printf("Enter the age of the person: ");
    scanf("%d", &r.age);
    printf("Enter the wealth of the person: ");
    scanf("%d", &r.wealth);
    // Write the new record to the file
    fwrite(&r, sizeof(record), 1, fp);
    fclose(fp);
}

// Function to delete a record from the database
void delete_record() {
    FILE *fp;
    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file for reading\n");
        exit(1);
    }
    // Get the name of the person to delete
    char name[50];
    printf("Enter the name of the person to delete: ");
    scanf("%s", name);
    // Create a temporary file to store the records that we want to keep
    FILE *fp_temp;
    fp_temp = fopen("database_temp.txt", "w");
    if (fp_temp == NULL) {
        printf("Error: could not open temporary file for writing\n");
        exit(1);
    }
    // Read each record from the original file and write it to the temporary file if it is not the record we want to delete
    record r;
    while (fread(&r, sizeof(record), 1, fp)) {
        if (strcmp(r.name, name) != 0) {
            fwrite(&r, sizeof(record), 1, fp_temp);
        }
    }
    fclose(fp);
    fclose(fp_temp);
    // Delete the original file and rename the temporary file to the original file name
    remove("database.txt");
    rename("database_temp.txt", "database.txt");
}

// Function to search for a record in the database
void search_record() {
    FILE *fp;
    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file for reading\n");
        exit(1);
    }
    // Get the name of the person to search for
    char name[50];
    printf("Enter the name of the person to search for: ");
    scanf("%s", name);
    // Read each record from the file and print it if it matches the search term
    record r;
    while (fread(&r, sizeof(record), 1, fp)) {
        if (strcmp(r.name, name) == 0) {
            printf("Name: %s\n", r.name);
            printf("Title: %s\n", r.title);
            printf("Age: %d\n", r.age);
            printf("Wealth: %d\n", r.wealth);
        }
    }
    fclose(fp);
}

// Function to print all the records in the database
void print_records() {
    FILE *fp;
    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file for reading\n");
        exit(1);
    }
    // Read each record from the file and print it
    record r;
    while (fread(&r, sizeof(record), 1, fp)) {
        printf("Name: %s\n", r.name);
        printf("Title: %s\n", r.title);
        printf("Age: %d\n", r.age);
        printf("Wealth: %d\n", r.wealth);
        printf("\n");
    }
    fclose(fp);
}

// Main function
int main() {
    // Create the database if it does not exist
    create_database();
    // Get the user's choice
    int choice;
    do {
        printf("1. Add a record\n");
        printf("2. Delete a record\n");
        printf("3. Search for a record\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Perform the selected action
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                search_record();
                break;
            case 4:
                print_records();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}