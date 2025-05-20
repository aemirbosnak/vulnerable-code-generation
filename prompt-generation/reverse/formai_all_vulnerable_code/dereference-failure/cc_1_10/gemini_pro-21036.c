//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 256

typedef struct {
    char name[STR_LEN];
    int age;
    char *address;
} person_t;

typedef struct {
    person_t **persons;
    int size;
} database_t;

database_t *create_database() {
    database_t *db = malloc(sizeof(database_t));
    if (!db) {
        return NULL;
    }

    db->persons = malloc(sizeof(person_t *) * 10);
    if (!db->persons) {
        free(db);
        return NULL;
    }

    db->size = 0;

    return db;
}

void free_database(database_t *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->persons[i]->address);
        free(db->persons[i]);
    }

    free(db->persons);
    free(db);
}

person_t *create_person(char *name, int age, char *address) {
    person_t *person = malloc(sizeof(person_t));
    if (!person) {
        return NULL;
    }

    strcpy(person->name, name);
    person->age = age;
    person->address = strdup(address);

    return person;
}

void add_person(database_t *db, person_t *person) {
    if (db->size >= 10) {
        return;
    }

    db->persons[db->size++] = person;
}

person_t *find_person_by_name(database_t *db, char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->persons[i]->name, name) == 0) {
            return db->persons[i];
        }
    }

    return NULL;
}

void print_database(database_t *db) {
    printf("Database:\n");
    for (int i = 0; i < db->size; i++) {
        printf("%s, %d, %s\n", db->persons[i]->name, db->persons[i]->age, db->persons[i]->address);
    }
}

int main() {
    database_t *db = create_database();

    person_t *john = create_person("John", 30, "123 Main Street");
    person_t *mary = create_person("Mary", 25, "456 Elm Street");

    add_person(db, john);
    add_person(db, mary);

    print_database(db);

    person_t *found = find_person_by_name(db, "John");
    if (found) {
        printf("Found person: %s\n", found->name);
    } else {
        printf("Person not found\n");
    }

    free_database(db);

    return 0;
}