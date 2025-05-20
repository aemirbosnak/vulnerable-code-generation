//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
} person_t;

typedef struct {
    person_t *people;
    int num_people;
} database_t;

database_t *create_database() {
    database_t *db = malloc(sizeof(database_t));
    db->people = NULL;
    db->num_people = 0;
    return db;
}

void add_person(database_t *db, char *name, int age, char *occupation) {
    db->people = realloc(db->people, (db->num_people + 1) * sizeof(person_t));
    db->people[db->num_people].name = strdup(name);
    db->people[db->num_people].age = age;
    db->people[db->num_people].occupation = strdup(occupation);
    db->num_people++;
}

void print_database(database_t *db) {
    for (int i = 0; i < db->num_people; i++) {
        printf("Name: %s\n", db->people[i].name);
        printf("Age: %d\n", db->people[i].age);
        printf("Occupation: %s\n", db->people[i].occupation);
        printf("\n");
    }
}

void free_database(database_t *db) {
    for (int i = 0; i < db->num_people; i++) {
        free(db->people[i].name);
        free(db->people[i].occupation);
    }
    free(db->people);
    free(db);
}

int main() {
    database_t *db = create_database();

    add_person(db, "John Doe", 30, "Software Engineer");
    add_person(db, "Jane Doe", 25, "Teacher");
    add_person(db, "Bob Smith", 40, "Doctor");

    print_database(db);

    free_database(db);

    return 0;
}