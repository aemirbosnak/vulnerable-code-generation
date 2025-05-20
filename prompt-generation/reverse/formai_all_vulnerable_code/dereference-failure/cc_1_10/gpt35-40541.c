//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the person
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Define a struct for the database table
typedef struct {
    Person* records;
    int num_records;
} DatabaseTable;

// Main function
int main() {
    // Declare the database table
    DatabaseTable my_table;
    my_table.num_records = 0;
    my_table.records = (Person*) malloc(sizeof(Person));

    // Insert some random records
    Person p1 = { 1, "John Doe", 28 };
    my_table.records[0] = p1;
    my_table.num_records++;

    Person p2 = { 2, "Jane Smith", 35 };
    my_table.records = (Person*) realloc(my_table.records, sizeof(Person) * (my_table.num_records+1));
    my_table.records[1] = p2;
    my_table.num_records++;

    Person p3 = { 3, "Bob Johnson", 42 };
    my_table.records = (Person*) realloc(my_table.records, sizeof(Person) * (my_table.num_records+1));
    my_table.records[2] = p3;
    my_table.num_records++;

    // Display the records
    printf("ID    Name                 Age\n");
    printf("---------------------------------\n");
    for (int i=0; i<my_table.num_records; i++) {
        printf("%-5d %-20s %3d\n", my_table.records[i].id, my_table.records[i].name, my_table.records[i].age);
    }

    // Update the age of Jane Smith
    for (int i=0; i<my_table.num_records; i++) {
        if (strcmp(my_table.records[i].name, "Jane Smith") == 0) {
            my_table.records[i].age = 36;
            break;
        }
    }

    // Display the updated record
    printf("\nUpdated record for Jane Smith:\n");
    printf("ID    Name                 Age\n");
    printf("---------------------------------\n");
    for (int i=0; i<my_table.num_records; i++) {
        printf("%-5d %-20s %3d\n", my_table.records[i].id, my_table.records[i].name, my_table.records[i].age);
    }

    // Delete the record for Bob Johnson
    for (int i=0; i<my_table.num_records; i++) {
        if (strcmp(my_table.records[i].name, "Bob Johnson") == 0) {
            for (int j=i; j<my_table.num_records-1; j++) {
                my_table.records[j] = my_table.records[j+1];
            }
            my_table.num_records--;
            my_table.records = (Person*) realloc(my_table.records, sizeof(Person) * my_table.num_records);
            break;
        }
    }

    // Display the updated table
    printf("\nTable after deleting Bob Johnson:\n");
    printf("ID    Name                 Age\n");
    printf("---------------------------------\n");
    for (int i=0; i<my_table.num_records; i++) {
        printf("%-5d %-20s %3d\n", my_table.records[i].id, my_table.records[i].name, my_table.records[i].age);
    }

    // Free the memory allocated for the records
    free(my_table.records);

    return 0;
}