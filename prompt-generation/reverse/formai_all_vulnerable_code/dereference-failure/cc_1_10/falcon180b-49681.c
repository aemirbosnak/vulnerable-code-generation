//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    char **headers;
    Record *records;
    int num_rows;
    int num_columns;
} Database;

void create_database(Database *db) {
    db->headers = (char **)malloc(MAX_COLUMNS * sizeof(char *));
    db->records = (Record *)malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_columns = 0;
}

void add_column(Database *db, char *header) {
    db->headers[db->num_columns] = strdup(header);
    db->num_columns++;
}

void add_record(Database *db, Record record) {
    db->records[db->num_rows] = record;
    db->num_rows++;
}

void print_database(Database db) {
    printf("+----+------------------+------------------+------------------+\n");
    for (int i = 0; i < db.num_columns; i++) {
        printf("| %s |", db.headers[i]);
    }
    printf("|\n");
    printf("+----+------------------+------------------+------------------+\n");

    for (int i = 0; i < db.num_rows; i++) {
        printf("| %d | %s | %.2f |\n", db.records[i].age, db.records[i].name, db.records[i].salary);
    }
}

int main() {
    Database db;
    create_database(&db);

    add_column(&db, "ID");
    add_column(&db, "Name");
    add_column(&db, "Age");
    add_column(&db, "Salary");

    Record record1 = {"John Doe", 25, 50000};
    Record record2 = {"Jane Smith", 30, 60000};
    Record record3 = {"Bob Johnson", 40, 70000};

    add_record(&db, record1);
    add_record(&db, record2);
    add_record(&db, record3);

    print_database(db);

    return 0;
}