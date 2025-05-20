//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Database;

void createDatabase(Database *db) {
    db->data = (Person *) malloc(MAX_SIZE * sizeof(Person));
    db->size = 0;
    db->capacity = MAX_SIZE;
}

void destroyDatabase(Database *db) {
    free(db->data);
    db->size = 0;
    db->capacity = 0;
}

void addPerson(Database *db, char *name, int age) {
    if (db->size >= db->capacity) {
        printf("Database is full!\n");
        return;
    }

    strcpy(db->data[db->size].name, name);
    db->data[db->size].age = age;
    db->size++;
}

void removePerson(Database *db, char *name) {
    int i;

    for (i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            db->size--;
            break;
        }
    }
}

void printDatabase(Database *db) {
    int i;

    for (i = 0; i < db->size; i++) {
        printf("Name: %s, Age: %d\n", db->data[i].name, db->data[i].age);
    }
}

int main() {
    Database db;

    createDatabase(&db);

    addPerson(&db, "John", 25);
    addPerson(&db, "Jane", 30);
    addPerson(&db, "Bob", 40);
    addPerson(&db, "Alice", 20);

    printDatabase(&db);

    removePerson(&db, "Bob");

    printDatabase(&db);

    destroyDatabase(&db);

    return 0;
}