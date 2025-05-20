//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

// Define the structure of a row in the database
typedef struct {
    int id;
    char name[MAX_DATA_SIZE];
    char address[MAX_DATA_SIZE];
} Row;

// Define the structure of the database
typedef struct {
    int numRows;
    int numCols;
    Row *data;
} Database;

// Function to initialize the database with default values
void initDatabase(Database *db) {
    db->numRows = 0;
    db->numCols = 2; // Assuming two columns for id and name
    db->data = NULL;
}

// Function to add a row to the database
void addRow(Database *db, int id, char *name, char *address) {
    Row *newRow = (Row *)malloc(sizeof(Row));
    newRow->id = id;
    strcpy(newRow->name, name);
    strcpy(newRow->address, address);
    db->data = (Row *)realloc(db->data, sizeof(Row) * (db->numRows + 1));
    db->data[db->numRows] = *newRow;
    db->numRows++;
}

// Function to delete a row from the database
void deleteRow(Database *db, int id) {
    int i;
    for (i = 0; i < db->numRows; i++) {
        if (db->data[i].id == id) {
            db->data = (Row *)realloc(db->data, sizeof(Row) * (db->numRows - 1));
            db->numRows--;
            break;
        }
    }
}

// Function to search for a row in the database
int searchRow(Database *db, int id) {
    int i;
    for (i = 0; i < db->numRows; i++) {
        if (db->data[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Function to print the database
void printDatabase(Database *db) {
    int i, j;
    printf("ID\tName\tAddress\n");
    for (i = 0; i < db->numRows; i++) {
        printf("%d\t%s\t%s\n", db->data[i].id, db->data[i].name, db->data[i].address);
    }
}

int main() {
    Database db;
    initDatabase(&db);
    addRow(&db, 1, "John Doe", "123 Main St.");
    addRow(&db, 2, "Jane Doe", "456 Elm St.");
    printDatabase(&db);
    deleteRow(&db, 1);
    printDatabase(&db);
    return 0;
}