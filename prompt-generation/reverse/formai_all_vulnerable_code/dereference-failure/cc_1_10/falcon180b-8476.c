//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 100

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = malloc(MAX_ROWS * sizeof(char*));
    db->num_rows = 0;
    db->num_cols = 0;
}

void add_row(Database *db, char **data) {
    db->data[db->num_rows++] = data;
    int i;
    for (i = 0; i < MAX_COLS; i++) {
        if (data[i]!= NULL) {
            db->num_cols = i + 1;
            break;
        }
    }
}

void print_database(Database *db) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_cols; j++) {
            printf("%s ", db->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    init_database(&db);
    char *data1[] = {"John", "25", "Male"};
    char *data2[] = {"Jane", "30", "Female"};
    char *data3[] = {"Bob", "20", "Male"};
    add_row(&db, data1);
    add_row(&db, data2);
    add_row(&db, data3);
    print_database(&db);
    return 0;
}