//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
typedef struct {
    char *name;
    int age;
} person;

// Define database
person db[5] = {
    {"Alice", 25},
    {"Bob", 30},
    {"Charlie", 35},
    {"David", 20},
    {"Eve", 40}
};

// Define function to add person to database
void add_person(person *db, char *name, int age) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(db[i].name, name) == 0) {
            db[i].age = age;
            return;
        }
    }
    printf("Person already exists in the database.\n");
}

// Define function to retrieve person from database
person *get_person(person *db, char *name) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(db[i].name, name) == 0) {
            return &db[i];
        }
    }
    return NULL;
}

// Define function to delete person from database
void delete_person(person *db, char *name) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(db[i].name, name) == 0) {
            memset(db[i].name, 0, sizeof(db[i].name));
            db[i].age = 0;
            return;
        }
    }
    printf("Person not found in the database.\n");
}

// Define function to display all persons in the database
void display_all(person *db) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%s %d\n", db[i].name, db[i].age);
    }
}

int main() {
    srand(time(NULL));

    // Add some persons to the database
    add_person(db, "Alice", 25);
    add_person(db, "Bob", 30);
    add_person(db, "Charlie", 35);

    // Display all persons in the database
    display_all(db);

    // Delete a person from the database
    delete_person(db, "Bob");

    // Display all persons in the database again
    display_all(db);

    return 0;
}