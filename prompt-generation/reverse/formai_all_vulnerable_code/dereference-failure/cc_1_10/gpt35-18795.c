//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of records that can be stored
#define MAX_RECORDS 100

// Define the structure of a record
struct record {
    int id;
    char name[50];
    int age;
};

// Declare the array of records
struct record records[MAX_RECORDS];

// Keep track of the number of records currently stored
int num_records = 0;

// Function to add a new record to the array
void add_record(int id, char name[50], int age) {
    // Check if the array is full
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached\n");
        return;
    }

    // Create a new record with the given values
    struct record new_record;
    new_record.id = id;
    for (int i=0; i<50; i++) {
        new_record.name[i] = name[i];
    }
    new_record.age = age;

    // Add the new record to the end of the array
    records[num_records++] = new_record;
}

// Function to delete a record from the array
void delete_record(int id) {
    // Find the index of the record with the given ID
    int index = -1;
    for (int i=0; i<num_records; i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }

    // If the record was not found, print an error message and return
    if (index == -1) {
        printf("Error: Record with ID %d not found\n", id);
        return;
    }

    // If the record was found, shift all subsequent records one position to the left
    for (int i=index; i<num_records-1; i++) {
        records[i] = records[i+1];
    }

    // Update the number of records
    num_records--;
}

// Function to print all records in the array
void print_records() {
    printf("ID\tName\tAge\n");
    for (int i=0; i<num_records; i++) {
        printf("%d\t%s\t%d\n", records[i].id, records[i].name, records[i].age);
    }
}

// Main function to simulate database operations
int main() {
    // Add some initial records to the array
    add_record(1, "John Doe", 25);
    add_record(2, "Jane Smith", 30);
    add_record(3, "Bob Johnson", 45);

    // Print the initial records
    printf("Initial records:\n");
    print_records();

    // Add a new record
    add_record(4, "Alice Brown", 20);

    // Print all records again
    printf("All records after adding a new one:\n");
    print_records();

    // Delete a record
    delete_record(2);

    // Print all records again
    printf("All records after deleting record with ID 2:\n");
    print_records();

    return 0;
}