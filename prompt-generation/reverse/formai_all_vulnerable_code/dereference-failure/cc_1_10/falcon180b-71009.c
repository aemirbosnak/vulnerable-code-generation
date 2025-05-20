//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

typedef struct {
    Person *data;
    int num_rows;
    int num_cols;
} Database;

void create_table(Database *db, int num_rows, int num_cols) {
    db->data = (Person *)malloc(num_rows * num_cols * sizeof(Person));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
}

void insert_row(Database *db, int row, const char *name, int age, const char *email) {
    Person *p = &db->data[row];
    p->name = strdup(name);
    p->age = age;
    p->email = strdup(email);
}

void print_table(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        Person *p = &db->data[i];
        printf("%s %d %s\n", p->name, p->age, p->email);
    }
}

int main() {
    Database db;
    create_table(&db, 3, 3);

    insert_row(&db, 0, "Alice", 25, "alice@example.com");
    insert_row(&db, 1, "Bob", 30, "bob@example.com");
    insert_row(&db, 2, "Charlie", 35, "charlie@example.com");

    print_table(&db);

    return 0;
}