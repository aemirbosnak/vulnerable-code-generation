//FormAI DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_DATA 100

// Struct to define a row
typedef struct {
    int id;
    char name[MAX_DATA];
    char age[MAX_DATA];
    char gender[MAX_DATA];
} Row;

// Struct to define a database
typedef struct {
    Row rows[MAX_ROWS];
    int size;
} Database;

// Function to print a row
void print_row(Row *row) {
    printf("%d, %s, %s, %s\n", row->id, row->name, row->age, row->gender);
}

// Function to print the database
void print_database(Database *database) {
    for (int i = 0; i < database->size; i++) {
        print_row(&database->rows[i]);
    }
}

int main() {
    Database *database = malloc(sizeof(Database));
    database->size = 0;

    // Insert some rows
    Row row1 = {1, "John", "28", "Male"};
    database->rows[database->size] = row1;
    database->size++;

    Row row2 = {2, "Jane", "23", "Female"};
    database->rows[database->size] = row2;
    database->size++;

    Row row3 = {3, "Mike", "35", "Male"};
    database->rows[database->size] = row3;
    database->size++;

    Row row4 = {4, "Sally", "41", "Female"};
    database->rows[database->size] = row4;
    database->size++;

    Row row5 = {5, "Steve", "57", "Male"};
    database->rows[database->size] = row5;
    database->size++;

    printf("Initial database:\n");
    print_database(database);

    // Query the database to find all females over the age of 30
    printf("Query result:\n");
    for (int i = 0; i < database->size; i++) {
        if (strcmp(database->rows[i].gender, "Female") == 0 && atoi(database->rows[i].age) > 30) {
            print_row(&database->rows[i]);
        }
    }

    free(database);
    return 0;
}