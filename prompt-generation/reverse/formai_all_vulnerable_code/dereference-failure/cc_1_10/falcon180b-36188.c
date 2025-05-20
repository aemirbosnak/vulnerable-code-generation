//Falcon-180B DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 100

typedef struct {
    char *data;
    int row_count;
    int col_count;
} Database;

void init_database(Database *db) {
    db->data = malloc(MAX_ROWS * MAX_COLS * MAX_DATA_LEN);
    db->row_count = 0;
    db->col_count = 0;
}

void free_database(Database *db) {
    free(db->data);
    db->row_count = 0;
    db->col_count = 0;
}

int get_row_count(Database *db) {
    return db->row_count;
}

int get_col_count(Database *db) {
    return db->col_count;
}

void add_row(Database *db, char *data) {
    int len = strlen(data);
    if (len > MAX_DATA_LEN) {
        printf("Error: Data exceeds maximum length.\n");
        return;
    }
    if (db->row_count >= MAX_ROWS) {
        printf("Error: Maximum number of rows reached.\n");
        return;
    }
    if (db->col_count == 0) {
        db->col_count = strlen(data);
    } else if (db->col_count!= strlen(data)) {
        printf("Error: Column count does not match.\n");
        return;
    }
    strcpy(db->data + db->row_count * MAX_DATA_LEN, data);
    db->row_count++;
}

void print_database(Database *db) {
    int i, j;
    for (i = 0; i < db->row_count; i++) {
        for (j = 0; j < db->col_count; j++) {
            printf("%c", db->data[i * MAX_DATA_LEN + j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    init_database(&db);
    add_row(&db, "Name");
    add_row(&db, "Age");
    add_row(&db, "Gender");
    print_database(&db);
    free_database(&db);
    return 0;
}