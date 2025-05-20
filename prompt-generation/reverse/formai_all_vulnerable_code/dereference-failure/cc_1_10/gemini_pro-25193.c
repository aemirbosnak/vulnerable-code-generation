//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100

typedef struct {
    int id;
    char name[50];
    int age;
    char city[50];
} Person;

typedef struct {
    int num_columns;
    int num_rows;
    Person data[MAX_ROWS][MAX_COLUMNS];
} Database;

Database* create_database(int num_columns, int num_rows) {
    Database* db = (Database*)malloc(sizeof(Database));
    db->num_columns = num_columns;
    db->num_rows = num_rows;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            db->data[i][j].id = 0;
            strcpy(db->data[i][j].name, "");
            db->data[i][j].age = 0;
            strcpy(db->data[i][j].city, "");
        }
    }
    return db;
}

void insert_person(Database* db, int id, char* name, int age, char* city) {
    for (int i = 0; i < db->num_rows; i++) {
        if (db->data[i][0].id == 0) {
            db->data[i][0].id = id;
            strcpy(db->data[i][0].name, name);
            db->data[i][0].age = age;
            strcpy(db->data[i][0].city, city);
            break;
        }
    }
}

Person* find_person_by_id(Database* db, int id) {
    for (int i = 0; i < db->num_rows; i++) {
        if (db->data[i][0].id == id) {
            return &db->data[i][0];
        }
    }
    return NULL;
}

void print_database(Database* db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_columns; j++) {
            printf("%d %s %d %s\n", db->data[i][j].id, db->data[i][j].name, db->data[i][j].age, db->data[i][j].city);
        }
    }
}

int main() {
    Database* db = create_database(4, 10);

    insert_person(db, 1, "John", 20, "New York");
    insert_person(db, 2, "Jane", 25, "Los Angeles");
    insert_person(db, 3, "Bob", 30, "Chicago");
    insert_person(db, 4, "Alice", 35, "San Francisco");

    Person* person = find_person_by_id(db, 2);
    if (person != NULL) {
        printf("Found person: %d %s %d %s\n", person->id, person->name, person->age, person->city);
    } else {
        printf("Person not found.\n");
    }

    print_database(db);

    return 0;
}