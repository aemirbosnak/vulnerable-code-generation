//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Database {   // define a struct for the database
    int id;
    char name[20];
    char address[50];
    int age;
} Database;

int main() {
    Database *db = NULL;   // pointer to database
    int num_records = 0;   // initialize number of records to 0

    // Option menu to insert and view records in the database
    while (1) {
        printf("\nWelcome to the Database Simulator!\n");
        printf("1. Insert a new record\n");
        printf("2. View all records\n");
        printf("3. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: ; // add a new record
                num_records++;
                db = realloc(db, sizeof(Database) * num_records);  // resize database to hold new record

                Database record;
                record.id = num_records;

                printf("Enter name, address, and age separated by spaces: ");
                scanf("%s%s%d", &record.name, &record.address, &record.age);

                db[num_records - 1] = record;   // add record to database

                printf("\nNew record added successfully!\n\n");
                break;

            case 2: ; // view all records
                if (num_records == 0) {   // check if there are any records in database
                    printf("\nThere are no records in the database.\n\n");
                    break;
                }

                printf("\n%-5s %-20s %-50s %-5s\n", "ID", "Name", "Address", "Age");
                for (int i = 0; i < num_records; i++) {   // print all records in database
                    printf("%-5d %-20s %-50s %-5d\n", db[i].id, db[i].name, db[i].address, db[i].age);
                }

                break;

            case 3: ;   // exit program
                printf("Goodbye!\n");
                exit(0);

            default:   // wrong input
                printf("Invalid input! Please enter numbers between 1 - 3.\n");
                break;
        }
    }

    free(db);   // free memory allocated to database
    return 0;
}