//FormAI DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct for the database
typedef struct Database {
    char name[50];
    int age;
    float salary;
} database;

// Function to add a record to the database
void add_record(database **db, int *size) {
    // Get user input for new record information
    printf("Enter name: ");
    char temp_name[50];
    fgets(temp_name, 50, stdin);
    // Remove newline character from input
    temp_name[strcspn(temp_name, "\n")] = 0;
    printf("Enter age: ");
    int temp_age;
    scanf("%d", &temp_age);
    printf("Enter salary: ");
    float temp_salary;
    scanf("%f", &temp_salary);

    // Create new record and add to database
    database *new_record = malloc(sizeof(database));
    strcpy(new_record->name, temp_name);
    new_record->age = temp_age;
    new_record->salary = temp_salary;

    *size += 1;
    *db = realloc(*db, *size * sizeof(database));
    (*db)[*size - 1] = *new_record;

    free(new_record);
}

// Function to search for a record in the database
void search_record(database *db, int size) {
    // Get user input for name to search for
    printf("Enter name to search for: ");
    char search_name[50];
    fgets(search_name, 50, stdin);
    // Remove newline character from input
    search_name[strcspn(search_name, "\n")] = 0;

    // Loop through database and print matching records
    for (int i = 0; i < size; i++) {
        if (strcmp(db[i].name, search_name) == 0) {
            printf("Record found:\n");
            printf("Name: %s\nAge: %d\nSalary: %.2f\n", db[i].name, db[i].age, db[i].salary);
            return;
        }
    }
    printf("Record not found.\n");
}

int main() {
    database *db = NULL;
    int size = 0;
    int choice = 0;

    while (choice != 3) {
        // Print menu options and get user choice
        printf("\nDatabase Menu\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input stream

        switch (choice) {
            case 1:
                add_record(&db, &size);
                break;
            case 2:
                search_record(db, size);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    free(db);  // Free dynamically allocated memory
    return 0;
}