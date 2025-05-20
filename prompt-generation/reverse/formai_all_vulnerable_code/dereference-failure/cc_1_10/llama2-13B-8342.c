//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to store a person's name and age
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person_t;

// Function to read and write to a database file
void read_db(person_t** database, int* num_records) {
    // Open the database file in read mode
    FILE* file = fopen("database.dat", "r");
    if (file == NULL) {
        printf("Error: Unable to open database file\n");
        return;
    }

    // Read the database contents into memory
    char line[1024];
    int i = 0;
    while (fgets(line, 1024, file)) {
        // Ignore empty lines and comments
        if (line[0] == '\0' || strchr(line, '#') != NULL) {
            continue;
        }

        // Extract the name and age from the line
        char* name = strtok(line, " ");
        int age = atoi(strtok(NULL, " "));

        // Add the record to the database
        person_t* new_record = (person_t*) malloc(sizeof(person_t));
        strcpy(new_record->name, name);
        new_record->age = age;
        database[i++] = new_record;
    }

    // Close the database file
    fclose(file);

    // Return the number of records in the database
    *num_records = i;
}

// Function to write the database to a file
void write_db(person_t** database, int num_records) {
    // Open the database file in write mode
    FILE* file = fopen("database.dat", "w");
    if (file == NULL) {
        printf("Error: Unable to open database file\n");
        return;
    }

    // Write each record in the database to the file
    for (int i = 0; i < num_records; i++) {
        person_t* record = database[i];
        fprintf(file, "%s %d\n", record->name, record->age);
    }

    // Close the database file
    fclose(file);
}

int main() {
    // Initialize the database with some sample records
    person_t* database[MAX_RECORDS];
    int num_records = 0;

    // Read the database from the file
    read_db(database, &num_records);

    // Add some new records to the database
    person_t* new_record1 = (person_t*) malloc(sizeof(person_t));
    strcpy(new_record1->name, "Alice");
    new_record1->age = 25;
    person_t* new_record2 = (person_t*) malloc(sizeof(person_t));
    strcpy(new_record2->name, "Bob");
    new_record2->age = 30;

    // Write the updated database to the file
    write_db(database, num_records + 2);

    // Close the database
    for (int i = 0; i < num_records; i++) {
        free(database[i]);
    }
    free(database);

    return 0;
}