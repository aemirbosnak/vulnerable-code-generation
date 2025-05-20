//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 25
#define MAX_AGE 100

// Structure to store student records
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} student_record_t;

// Function to create a new student record
student_record_t* create_record(char* name, int age) {
    student_record_t* record = (student_record_t*)malloc(sizeof(student_record_t));
    strcpy(record->name, name);
    record->age = age;
    return record;
}

// Function to display all student records
void display_records(student_record_t** records) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i] != NULL) {
            printf("%s %d\n", records[i]->name, records[i]->age);
        }
    }
}

// Function to add a new student record
void add_record(student_record_t** records, char* name, int age) {
    student_record_t* new_record = create_record(name, age);
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i] == NULL) {
            records[i] = new_record;
            break;
        }
    }
    if (i == MAX_RECORDS) {
        printf("Sorry, the database is full. Please delete some records first.\n");
    }
}

// Function to delete a student record
void delete_record(student_record_t** records, int index) {
    if (index < MAX_RECORDS && records[index] != NULL) {
        free(records[index]);
        records[index] = NULL;
    }
}

int main() {
    srand(time(NULL));

    // Create an empty database
    student_record_t** records = (student_record_t**)malloc(MAX_RECORDS * sizeof(student_record_t*));
    for (int i = 0; i < MAX_RECORDS; i++) {
        records[i] = NULL;
    }

    // Add some records
    add_record(records, "Alice", 25);
    add_record(records, "Bob", 30);
    add_record(records, "Charlie", 20);

    // Display all records
    display_records(records);

    // Delete a record
    delete_record(records, 1);

    // Display all records again
    display_records(records);

    return 0;
}