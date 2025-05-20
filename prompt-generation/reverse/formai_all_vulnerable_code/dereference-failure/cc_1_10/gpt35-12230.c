//FormAI DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a record in the database
typedef struct Record {
    char name[50];
    int age;
    float salary;
} Record;

// Function to create a new record
Record* create_record(char name[], int age, float salary) {
    Record* record = (Record*) malloc(sizeof(Record));
    strcpy(record->name, name);
    record->age = age;
    record->salary = salary;
    return record;
}

// Function to print a record
void print_record(Record* record) {
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Salary: $%.2f\n", record->salary);
}

// Main function to simulate the database
int main() {
    // Create an array of pointer to records
    Record* database[100];
    int num_records = 0;
    
    // Add some records to the database
    database[num_records++] = create_record("John Doe", 30, 50000);
    database[num_records++] = create_record("Jane Smith", 25, 60000);
    database[num_records++] = create_record("Bob Johnson", 35, 70000);
    
    // Print all records in the database
    printf("All records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record #%d:\n", i+1);
        print_record(database[i]);
        printf("\n");
    }
    
    // Update a record in the database
    strcpy(database[1]->name, "Jane Johnson");
    database[1]->salary = 65000;
    printf("Updated record:\n");
    print_record(database[1]);
    
    // Delete a record in the database
    free(database[2]);
    for (int i = 2; i < num_records; i++) {
        database[i-1] = database[i];
    }
    num_records--;
    printf("Deleted record, remaining records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record #%d:\n", i+1);
        print_record(database[i]);
        printf("\n");
    }
    
    // Free memory used by all records
    for (int i = 0; i < num_records; i++) {
        free(database[i]);
    }
    
    return 0;
}