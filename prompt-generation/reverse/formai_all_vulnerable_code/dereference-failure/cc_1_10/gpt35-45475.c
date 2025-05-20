//FormAI DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    char last_name[20];
    int age;
} person_data;

typedef struct {
    int size;
    person_data* data;
} database;

void init_db(database* db);
void add_person(database* db, person_data person);
void delete_person(database* db, int id);
void print_db(database* db);

int main() {
    database db;
    init_db(&db);

    person_data romeo = {1, "Romeo", "Montague", 18};
    add_person(&db, romeo);

    person_data juliet = {2, "Juliet", "Capulet", 13};
    add_person(&db, juliet);

    printf("\nInitial Database:\n");
    print_db(&db);

    delete_person(&db, 2); // Romeo deletes Juliet
    printf("\nAfter deletion:\n");
    print_db(&db);

    printf("\nA new person enters:\n");
    person_data new_person = {3, "Tybalt", "Capulet", 20};
    add_person(&db, new_person);
    print_db(&db);

    return 0;
}

void init_db(database* db) {
    db->size = 0;
    db->data = NULL;
}

void add_person(database* db, person_data person) {
    db->size++;
    db->data = (person_data*) realloc(db->data, sizeof(person_data) * db->size);
    db->data[db->size - 1] = person;
    printf("%s %s has been added to the database.\n", person.name, person.last_name);
}

void delete_person(database* db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->data[i].id == id) {
            printf("%s %s has been removed from the database.\n", db->data[i].name, db->data[i].last_name);
            for (int j = i; j < db->size - 1; j++) {
                db->data[j] = db->data[j + 1];
            }
            db->size--;
            db->data = (person_data*) realloc(db->data, sizeof(person_data) * db->size);
            break;
        }
    }
}

void print_db(database* db) {
    for (int i = 0; i < db->size; i++) {
        printf("%d. %s %s, %d years old\n", db->data[i].id, db->data[i].name, db->data[i].last_name, db->data[i].age);
    }
}