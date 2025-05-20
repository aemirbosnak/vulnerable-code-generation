//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

typedef struct {
    Person *data;
    int rows;
    int cols;
} Database;

void init_database(Database *db) {
    db->data = (Person *)malloc(MAX_ROWS * MAX_COLS * sizeof(Person));
    db->rows = 0;
    db->cols = 0;
}

void destroy_database(Database *db) {
    free(db->data);
}

int add_person(Database *db, char *name, int age, char *gender) {
    Person *row = (Person *)malloc(sizeof(Person));
    row->name = strdup(name);
    row->age = age;
    row->gender = strdup(gender);

    if (db->rows == MAX_ROWS || db->cols == MAX_COLS) {
        printf("Error: Database is full.\n");
        free(row->name);
        free(row->gender);
        free(row);
        return -1;
    }

    db->data[db->rows * MAX_COLS + db->cols] = *row;
    db->rows++;
    db->cols++;

    return 0;
}

int search_person(Database *db, char *name) {
    int i, j;

    for (i = 0; i < db->rows; i++) {
        for (j = 0; j < db->cols; j++) {
            if (strcmp(db->data[i * MAX_COLS + j].name, name) == 0) {
                printf("Name: %s\n", db->data[i * MAX_COLS + j].name);
                printf("Age: %d\n", db->data[i * MAX_COLS + j].age);
                printf("Gender: %s\n\n", db->data[i * MAX_COLS + j].gender);
                return 0;
            }
        }
    }

    printf("Person not found.\n");
    return -1;
}

int main() {
    Database db;
    init_database(&db);

    add_person(&db, "John", 25, "Male");
    add_person(&db, "Jane", 30, "Female");
    add_person(&db, "Bob", 40, "Male");

    search_person(&db, "John");
    search_person(&db, "Jane");
    search_person(&db, "Bob");

    destroy_database(&db);

    return 0;
}