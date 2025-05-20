//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Struct for a cell in the database
typedef struct {
    char *data;
    int row;
    int col;
} Cell;

// Struct for the database itself
typedef struct {
    int numRows;
    int numCols;
    Cell **data;
} Database;

// Function to initialize an empty database
Database *createDatabase(int numRows, int numCols) {
    Database *db = (Database *) malloc(sizeof(Database));
    db->numRows = numRows;
    db->numCols = numCols;
    db->data = (Cell **) malloc(numRows * sizeof(Cell *));
    for (int i = 0; i < numRows; i++) {
        db->data[i] = (Cell *) malloc(numCols * sizeof(Cell));
        for (int j = 0; j < numCols; j++) {
            db->data[i][j].data = NULL;
            db->data[i][j].row = i;
            db->data[i][j].col = j;
        }
    }
    return db;
}

// Function to insert data into the database
void insertData(Database *db, int row, int col, char *data) {
    if (row >= 0 && row < db->numRows && col >= 0 && col < db->numCols) {
        db->data[row][col].data = data;
    } else {
        printf("Invalid row or column\n");
    }
}

// Function to retrieve data from the database
char *getData(Database *db, int row, int col) {
    if (row >= 0 && row < db->numRows && col >= 0 && col < db->numCols) {
        return db->data[row][col].data;
    } else {
        return NULL;
    }
}

// Function to print the entire database
void printDatabase(Database *db) {
    for (int i = 0; i < db->numRows; i++) {
        for (int j = 0; j < db->numCols; j++) {
            printf("%s ", getData(db, i, j));
        }
        printf("\n");
    }
}

int main() {
    Database *db = createDatabase(5, 5);
    insertData(db, 0, 0, "Hello");
    insertData(db, 1, 1, "World");
    insertData(db, 2, 2, "This");
    insertData(db, 3, 3, "Is");
    insertData(db, 4, 4, "A");
    printDatabase(db);
    return 0;
}