//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char age[10];
    char gender[5];
    char address[100];
} Person;

typedef struct {
    Person* people;
    int num_people;
} Database;

void add_person(Database* db, const char* name, const char* age, const char* gender, const char* address) {
    Person* new_person = (Person*)malloc(sizeof(Person));
    strcpy(new_person->name, name);
    strcpy(new_person->age, age);
    strcpy(new_person->gender, gender);
    strcpy(new_person->address, address);
    db->people = (Person*)realloc(db->people, (db->num_people + 1) * sizeof(Person));
    db->people[db->num_people++] = *new_person;
}

void search_person(Database* db, const char* name) {
    int i;
    for (i = 0; i < db->num_people; i++) {
        if (strcmp(db->people[i].name, name) == 0) {
            printf("Name: %s\n", db->people[i].name);
            printf("Age: %s\n", db->people[i].age);
            printf("Gender: %s\n", db->people[i].gender);
            printf("Address: %s\n", db->people[i].address);
            break;
        }
    }
}

void free_db(Database* db) {
    free(db->people);
    db->people = NULL;
    db->num_people = 0;
}

int main() {
    Database db;
    db.people = NULL;
    db.num_people = 0;

    add_person(&db, "John", "25", "Male", "123 Main St");
    add_person(&db, "Jane", "30", "Female", "456 Elm St");

    search_person(&db, "John");

    free_db(&db);

    return 0;
}