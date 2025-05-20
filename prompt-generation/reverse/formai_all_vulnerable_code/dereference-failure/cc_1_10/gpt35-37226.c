//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a database record structure
struct record {
    char name[30];
    int age;
    char occupation[50];
};

// Define the database structure
struct database {
    int num_records;
    struct record* records;
};

int main() {
    // Initialize the database with 10 empty records
    struct database my_db;
    my_db.num_records = 10;
    my_db.records = (struct record*) malloc(sizeof(struct record) * my_db.num_records);
    memset(my_db.records, 0, sizeof(struct record) * my_db.num_records);

    // Insert a record into the database
    struct record new_record;
    strcpy(new_record.name, "John Smith");
    new_record.age = 35;
    strcpy(new_record.occupation, "Software Engineer");
    my_db.records[0] = new_record;

    // Update a record in the database
    struct record updated_record;
    strcpy(updated_record.name, "Jane Doe");
    updated_record.age = 28;
    strcpy(updated_record.occupation, "Data Analyst");
    my_db.records[0] = updated_record;

    // Delete a record from the database
    memset(&my_db.records[0], 0, sizeof(struct record));

    // Search for a record in the database
    char search_name[30];
    printf("Enter name to search for: ");
    fgets(search_name, 30, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // remove newline character from input
    for(int i = 0; i < my_db.num_records; i++) {
        if(strcmp(my_db.records[i].name, search_name) == 0) {
            printf("Record Found:\n");
            printf("Name: %s\n", my_db.records[i].name);
            printf("Age: %d\n", my_db.records[i].age);
            printf("Occupation: %s\n", my_db.records[i].occupation);
            break;
        }
    }

    // Clean up memory
    free(my_db.records);

    return 0;
}