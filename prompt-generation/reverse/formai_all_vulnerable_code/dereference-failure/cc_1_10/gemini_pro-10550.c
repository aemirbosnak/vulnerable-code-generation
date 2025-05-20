//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char name[50];
    int age;
    char gender;
} Person;

typedef struct {
    Person people[MAX_ROWS][MAX_COLS];
    int num_rows;
    int num_cols;
} Database;

Database* create_database() {
    Database* db = malloc(sizeof(Database));
    db->num_rows = 0;
    db->num_cols = 0;
    return db;
}

void destroy_database(Database* db) {
    free(db);
}

int add_person(Database* db, Person person) {
    if (db->num_rows >= MAX_ROWS) {
        return -1;
    }
    if (db->num_cols >= MAX_COLS) {
        return -1;
    }
    db->people[db->num_rows][db->num_cols] = person;
    db->num_rows++;
    db->num_cols++;
    return 0;
}

Person* find_person(Database* db, char* name) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            if (strcmp(db->people[i][j].name, name) == 0) {
                return &db->people[i][j];
            }
        }
    }
    return NULL;
}

void print_database(Database* db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s %d %c\n", db->people[i][j].name, db->people[i][j].age, db->people[i][j].gender);
        }
    }
}

int main() {
    Database* db = create_database();
    Person p1 = {"John", 20, 'M'};
    Person p2 = {"Mary", 25, 'F'};
    add_person(db, p1);
    add_person(db, p2);
    Person* p3 = find_person(db, "John");
    printf("%s %d %c\n", p3->name, p3->age, p3->gender);
    print_database(db);
    destroy_database(db);
    return 0;
}