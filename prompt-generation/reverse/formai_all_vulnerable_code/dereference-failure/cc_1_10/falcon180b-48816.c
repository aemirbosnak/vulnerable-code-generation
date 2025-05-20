//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

//Struct to define the database
typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    char **data;
} Database;

//Function to create a new database
Database *create_database(char *name, int num_rows, int num_cols) {
    Database *db = malloc(sizeof(Database));
    db->name = name;
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = malloc(num_cols * sizeof(char));
    }
    return db;
}

//Function to insert data into the database
void insert_data(Database *db, int row, int col, char *data) {
    strcpy(db->data[row - 1] + col - 1, data);
}

//Function to print the database
void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%c", db->data[i][j]);
        }
        printf("\n");
    }
}

//Main function to test the database
int main() {
    Database *db = create_database("test_db", 3, 3);
    insert_data(db, 1, 1, "Hello");
    insert_data(db, 1, 2, "World");
    insert_data(db, 2, 1, "Testing");
    insert_data(db, 2, 2, "123");
    insert_data(db, 3, 1, "Artistic");
    insert_data(db, 3, 2, "Programming");
    print_database(db);
    return 0;
}