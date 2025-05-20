//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = (char **)malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = (char *)malloc(sizeof(char) * num_cols);
        memset(db->data[i], '\0', num_cols);
    }
    return db;
}

void delete_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%c", db->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(5, 5);
    strcpy(db->data[0], "Name");
    strcpy(db->data[1], "Age");
    strcpy(db->data[2], "Gender");
    strcpy(db->data[3], "Email");
    strcpy(db->data[4], "Phone");

    strcpy(db->data[0][1], "John");
    strcpy(db->data[0][2], "Doe");
    strcpy(db->data[1][1], "25");
    strcpy(db->data[2][1], "Male");
    strcpy(db->data[3][1], "johndoe@example.com");
    strcpy(db->data[4][1], "123-456-7890");

    strcpy(db->data[2][2], "Jane");
    strcpy(db->data[3][2], "jane@example.com");
    strcpy(db->data[4][2], "987-654-3210");

    print_database(db);

    delete_database(db);

    return 0;
}