//Falcon-180B DATASET v1.0 Category: Database querying ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float salary;
} Record;

typedef struct {
    Record records[MAX_ROWS];
    int num_rows;
    int num_cols;
} Database;

Database* create_database(int num_rows, int num_cols) {
    Database* db = (Database*)malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    return db;
}

void destroy_database(Database* db) {
    free(db);
}

void add_record(Database* db, char* name, int age, float salary) {
    Record* record = &db->records[db->num_rows - 1];
    strcpy(record->name, name);
    record->age = age;
    record->salary = salary;
    db->num_rows++;
}

void print_database(Database* db) {
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < db->num_rows; i++) {
        Record* record = &db->records[i];
        printf("%s\t%d\t%.2f\n", record->name, record->age, record->salary);
    }
}

int main() {
    Database* db = create_database(3, 3);
    add_record(db, "Alice", 25, 30000);
    add_record(db, "Bob", 30, 40000);
    add_record(db, "Charlie", 35, 50000);
    print_database(db);
    destroy_database(db);
    return 0;
}