//Falcon-180B DATASET v1.0 Category: Database querying ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_ROWS_IN_MEMORY 100
#define MAX_COLS_IN_MEMORY 100

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person **rows;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->rows = (Person **)malloc(MAX_ROWS_IN_MEMORY * sizeof(Person *));
    db->num_rows = 0;
    db->num_cols = 0;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->rows[i]);
    }
    free(db->rows);
}

int read_csv_file(const char *filename, Database *db) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char line[MAX_COLS];
    while (fgets(line, MAX_COLS, fp)) {
        char *token = strtok(line, ",");
        if (db->num_cols == 0) {
            while (token!= NULL) {
                db->num_cols++;
                token = strtok(NULL, ",");
            }
        } else {
            while (token!= NULL) {
                Person *person = (Person *)malloc(sizeof(Person));
                person->name = strdup(token);
                person->age = atoi(strtok(NULL, ","));
                db->rows[db->num_rows] = person;
                db->num_rows++;
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(fp);
    return 0;
}

int write_csv_file(const char *filename, Database *db) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    for (int i = 0; i < db->num_cols; i++) {
        fprintf(fp, "%s", db->rows[0]->name);
        for (int j = 1; j < db->num_rows; j++) {
            fprintf(fp, ",");
            fprintf(fp, "%s", db->rows[j]->name);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

int main() {
    Database db;
    init_database(&db);

    if (read_csv_file("data.csv", &db)!= 0) {
        destroy_database(&db);
        return 1;
    }

    printf("Number of rows: %d\n", db.num_rows);
    printf("Number of columns: %d\n", db.num_cols);

    write_csv_file("output.csv", &db);

    destroy_database(&db);

    return 0;
}