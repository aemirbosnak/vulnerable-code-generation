//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *address;
} person;

person *create_person(char *name, int age, char *address) {
    person *p = malloc(sizeof(person));
    p->name = strdup(name);
    p->age = age;
    p->address = strdup(address);
    return p;
}

void free_person(person *p) {
    free(p->name);
    free(p->address);
    free(p);
}

typedef struct {
    person **people;
    int count;
} database;

database *create_database() {
    database *db = malloc(sizeof(database));
    db->people = malloc(sizeof(person *) * 100);
    db->count = 0;
    return db;
}

void free_database(database *db) {
    for (int i = 0; i < db->count; i++) {
        free_person(db->people[i]);
    }
    free(db->people);
    free(db);
}

void add_person(database *db, person *p) {
    db->people[db->count++] = p;
}

person *find_person(database *db, char *name) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->people[i]->name, name) == 0) {
            return db->people[i];
        }
    }
    return NULL;
}

void print_database(database *db) {
    for (int i = 0; i < db->count; i++) {
        printf("%s, %d, %s\n", db->people[i]->name, db->people[i]->age, db->people[i]->address);
    }
}

int main() {
    database *db = create_database();
    add_person(db, create_person("John Doe", 30, "123 Main Street"));
    add_person(db, create_person("Jane Doe", 25, "456 Elm Street"));
    add_person(db, create_person("Bob Smith", 40, "789 Oak Street"));
    print_database(db);
    person *p = find_person(db, "John Doe");
    printf("Found person: %s, %d, %s\n", p->name, p->age, p->address);
    free_database(db);
    return 0;
}