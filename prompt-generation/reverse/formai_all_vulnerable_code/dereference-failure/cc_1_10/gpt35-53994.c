//FormAI DATASET v1.0 Category: Database querying ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs for database
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

typedef struct {
    Person* people;
    int count;
} Database;

// function to initialize database
void init_db(Database* db) {
    db->count = 0;
    db->people = NULL;
}

// function to add person to database
void add_person(Database* db, int id, char* name, int age) {
    Person* new_person = realloc(db->people, (db->count + 1) * sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Failed to allocate memory");
        exit(1);
    }
    db->people = new_person;
    db->people[db->count].id = id;
    strcpy(db->people[db->count].name, name);
    db->people[db->count].age = age;
    db->count++;
}

// function to query database by name
void query_by_name(Database* db, char* name) {
    int count = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->people[i].name, name) == 0) {
            printf("Name: %s, Age: %d, ID: %d\n", db->people[i].name, db->people[i].age, db->people[i].id);
            count++;
        }
    }
    if (count == 0) {
        printf("No person with name '%s' found in database\n", name);
    }
}

int main() {
    // initialize database
    Database database;
    init_db(&database);

    // add some people to database
    add_person(&database, 1, "John", 32);
    add_person(&database, 2, "Jane", 28);
    add_person(&database, 3, "Bob", 44);
    add_person(&database, 4, "Alice", 21);
    
    // query database by name
    query_by_name(&database, "Bob");
    
    // free memory and exit program
    free(database.people);
    return 0;
}