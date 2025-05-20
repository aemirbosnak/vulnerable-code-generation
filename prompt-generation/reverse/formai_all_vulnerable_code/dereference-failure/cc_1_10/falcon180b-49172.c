//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

typedef struct {
    Person **data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = NULL;
    db->num_rows = 0;
    db->num_cols = 0;
}

void add_person(Database *db, char *name, int age, char *email) {
    Person *new_person = malloc(sizeof(Person));
    new_person->name = strdup(name);
    new_person->age = age;
    new_person->email = strdup(email);

    if (db->data == NULL) {
        db->data = malloc(sizeof(Person *));
        db->num_rows = 1;
        db->num_cols = 3;
    } else {
        db->num_rows++;
        Person **temp_data = realloc(db->data, sizeof(Person *) * db->num_rows);
        if (temp_data == NULL) {
            printf("Error: Unable to reallocate memory.\n");
            exit(1);
        }
        db->data = temp_data;
    }

    db->data[db->num_rows - 1] = new_person;
}

void print_database(Database *db) {
    printf("+----+----------------+-----------------\n");
    printf("| %10s | %20s | %30s |\n", "Name", "Age", "Email");
    printf("+----+----------------+-----------------\n");

    for (int i = 0; i < db->num_rows; i++) {
        Person *person = db->data[i];
        printf("| %10s | %20d | %30s |\n", person->name, person->age, person->email);
    }

    printf("+----+----------------+-----------------\n");
}

int main() {
    Database db;
    init_database(&db);

    add_person(&db, "John Doe", 30, "john.doe@example.com");
    add_person(&db, "Jane Smith", 25, "jane.smith@example.com");
    add_person(&db, "Bob Johnson", 40, "bob.johnson@example.com");

    print_database(&db);

    return 0;
}