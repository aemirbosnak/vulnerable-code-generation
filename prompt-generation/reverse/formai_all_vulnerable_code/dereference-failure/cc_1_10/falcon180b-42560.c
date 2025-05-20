//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Row;

typedef struct {
    int num_rows;
    int num_cols;
    Row **data;
} Database;

void init_database(Database *db) {
    db->num_rows = 0;
    db->num_cols = 0;
    db->data = NULL;
}

void free_database(Database *db) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    db->num_rows = 0;
    db->num_cols = 0;
}

int read_csv(const char *filename, Database *db) {
    FILE *fp;
    char line[MAX_VALUE_LEN];
    char delimiter = ',';
    int i = 0;
    Row **new_data = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return -1;
    }

    while (fgets(line, MAX_VALUE_LEN, fp)!= NULL) {
        if (i >= db->num_rows) {
            new_data = realloc(db->data, sizeof(Row *) * (i + 1));
            if (new_data == NULL) {
                printf("Error: could not allocate memory\n");
                free_database(db);
                fclose(fp);
                return -1;
            }
            db->data = new_data;
        }

        char *row_data = strdup(line);
        char *token = strtok(row_data, &delimiter);
        db->data[i] = malloc(sizeof(Row));
        strncpy(db->data[i]->name, token, MAX_NAME_LEN);
        token = strtok(NULL, &delimiter);
        strncpy(db->data[i]->value, token, MAX_VALUE_LEN);

        i++;
    }

    fclose(fp);
    db->num_rows = i;
    db->num_cols = 2;

    return 0;
}

int main() {
    Database db;
    init_database(&db);

    int ret = read_csv("example.csv", &db);
    if (ret!= 0) {
        return ret;
    }

    printf("Number of rows: %d\n", db.num_rows);
    printf("Number of columns: %d\n", db.num_cols);

    return 0;
}