//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char address[100];
    char phone[20];
} Person;

typedef struct {
    Person *people;
    int size;
    int capacity;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->people = malloc(sizeof(Person) * 10);
    db->size = 0;
    db->capacity = 10;
    return db;
}

void destroy_database(Database *db) {
    free(db->people);
    free(db);
}

void add_person(Database *db, Person person) {
    if (db->size == db->capacity) {
        db->people = realloc(db->people, sizeof(Person) * db->capacity * 2);
        db->capacity *= 2;
    }

    db->people[db->size++] = person;
}

void print_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        printf("%s\n", db->people[i].name);
        printf("%d\n", db->people[i].age);
        printf("%s\n", db->people[i].address);
        printf("%s\n", db->people[i].phone);
        printf("\n");
    }
}

int main() {
    Database *db = create_database();

    Person person1 = {"John Doe", 30, "123 Main Street", "555-1212"};
    Person person2 = {"Jane Doe", 25, "456 Elm Street", "555-1213"};
    Person person3 = {"Bill Smith", 40, "789 Oak Street", "555-1214"};

    add_person(db, person1);
    add_person(db, person2);
    add_person(db, person3);

    print_database(db);

    destroy_database(db);

    return 0;
}