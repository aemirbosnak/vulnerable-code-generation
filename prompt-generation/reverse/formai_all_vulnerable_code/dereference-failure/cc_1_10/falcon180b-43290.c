//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

// Define the structure of a row in the database
typedef struct {
    int id;
    char name[50];
    char address[100];
    float salary;
} Row;

// Define the structure of the database
typedef struct {
    int numRows;
    int numCols;
    Row **rows;
} Database;

// Function to initialize the database
void initDatabase(Database *db) {
    db->numRows = 0;
    db->numCols = 0;
    db->rows = NULL;
}

// Function to destroy the database
void destroyDatabase(Database *db) {
    for (int i = 0; i < db->numRows; i++) {
        free(db->rows[i]);
    }
    free(db->rows);
    db->numRows = 0;
}

// Function to add a row to the database
void addRow(Database *db, int id, char *name, char *address, float salary) {
    Row *newRow = (Row *)malloc(sizeof(Row));
    newRow->id = id;
    strcpy(newRow->name, name);
    strcpy(newRow->address, address);
    newRow->salary = salary;
    db->rows[db->numRows++] = newRow;
}

// Function to find the row with the given ID
Row *findRow(Database *db, int id) {
    for (int i = 0; i < db->numRows; i++) {
        if (db->rows[i]->id == id) {
            return db->rows[i];
        }
    }
    return NULL;
}

// Function to print the database
void printDatabase(Database *db) {
    printf("ID\tName\tAddress\tSalary\n");
    for (int i = 0; i < db->numRows; i++) {
        printf("%d\t%s\t%s\t%.2f\n", db->rows[i]->id, db->rows[i]->name, db->rows[i]->address, db->rows[i]->salary);
    }
}

// Main function
int main() {
    Database db;
    initDatabase(&db);
    addRow(&db, 1, "John Doe", "123 Main St.", 50000);
    addRow(&db, 2, "Jane Smith", "456 Elm St.", 60000);
    addRow(&db, 3, "Bob Johnson", "789 Maple St.", 55000);
    printDatabase(&db);
    Row *row = findRow(&db, 2);
    if (row!= NULL) {
        printf("Found row with ID %d\n", row->id);
    } else {
        printf("Row not found\n");
    }
    destroyDatabase(&db);
    return 0;
}