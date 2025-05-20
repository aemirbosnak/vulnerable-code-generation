//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data structure to represent a person with name and age
typedef struct Person {
    char name[30];
    int age;
} Person;

// Declare global variables for the database
Person *database;
int num_records = 0;
int max_records = 10;

// Function to add a new person record to the database
void add_record(char *name, int age) {
    // Check if the database is full and resize if needed
    if (num_records == max_records) {
        max_records *= 2;
        database = realloc(database, max_records * sizeof(Person));
    }
    
    // Create a new person record and add to the database
    Person new_person;
    strcpy(new_person.name, name);
    new_person.age = age;
    database[num_records] = new_person;
    num_records++;
}

// Function to print all records in the database
void print_database() {
    printf("------------\n");
    printf("DATABASE (%d records)\n", num_records);
    printf("------------\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d. Name: %s, Age: %d\n", i+1, database[i].name, database[i].age);
    }
}

// Main function
int main() {
    // Initialize the database with 10 records
    database = malloc(max_records * sizeof(Person));
    
    // Add some sample records to the database
    add_record("John Smith", 25);
    add_record("Jane Doe", 30);
    add_record("Bob Johnson", 45);
    
    // Print the initial database
    print_database();
    
    // Add a new record and print the updated database
    add_record("Alice Smith", 27);
    print_database();
    
    // Free memory and exit
    free(database);
    return 0;
}