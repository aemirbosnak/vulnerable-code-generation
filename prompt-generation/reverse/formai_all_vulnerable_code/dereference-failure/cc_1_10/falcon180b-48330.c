//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char address[MAX_NAME_LEN];
} Person;

typedef struct {
    int num_rows;
    int num_cols;
    Person **data;
} Database;

void init_database(Database *db) {
    db->num_rows = 0;
    db->num_cols = 3;
    db->data = (Person **)malloc(MAX_ROWS * sizeof(Person *));
    for (int i = 0; i < MAX_ROWS; i++) {
        db->data[i] = (Person *)malloc(MAX_COLS * sizeof(Person));
    }
}

void add_person(Database *db, char *name, int age, char *address) {
    int row = db->num_rows;
    db->num_rows++;
    strcpy(db->data[row]->name, name);
    db->data[row]->age = age;
    strcpy(db->data[row]->address, address);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("Name: %s\n", db->data[i]->name);
        printf("Age: %d\n", db->data[i]->age);
        printf("Address: %s\n\n", db->data[i]->address);
    }
}

int main() {
    Database db;
    init_database(&db);

    add_person(&db, "John", 25, "New York");
    add_person(&db, "Jane", 30, "Los Angeles");

    print_database(&db);

    return 0;
}