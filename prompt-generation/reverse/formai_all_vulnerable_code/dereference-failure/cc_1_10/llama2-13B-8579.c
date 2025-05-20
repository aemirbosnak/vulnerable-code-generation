//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structures
typedef struct {
    char *name;
    int age;
} person;

typedef struct {
    person *data;
    int capacity;
    int size;
} database;

// Define database operations
database *create_database(int capacity) {
    database *db = (database *)malloc(sizeof(database));
    db->capacity = capacity;
    db->size = 0;
    db->data = (person *)malloc(capacity * sizeof(person));
    return db;
}

void insert_person(database *db, char *name, int age) {
    if (db->size == db->capacity) {
        printf("Database is full! Please increase capacity before inserting more data.\n");
        return;
    }
    db->data[db->size].name = name;
    db->data[db->size].age = age;
    db->size++;
}

void print_database(database *db) {
    printf("Database contains:\n");
    for (int i = 0; i < db->size; i++) {
        printf("%d. %s (%d years old)\n", i + 1, db->data[i].name, db->data[i].age);
    }
}

void delete_person(database *db, char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            memmove(&db->data[i], &db->data[i + 1], (db->size - i - 1) * sizeof(person));
            db->size--;
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    database *db = create_database(10);

    for (int i = 0; i < 10; i++) {
        char *name = (char *)malloc(20 * sizeof(char));
        int age = rand() % 100 + 1;
        insert_person(db, name, age);
    }

    print_database(db);

    char *name = "Alice";
    delete_person(db, name);

    print_database(db);

    return 0;
}