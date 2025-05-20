//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// A custom data structure to represent a row in the database
typedef struct {
    int id;
    char *name;
    int age;
} Person;

// A custom function to print a person
void print_person(Person *person) {
    printf("%d %s %d\n", person->id, person->name, person->age);
}

// A custom function to compare two persons by their IDs
int compare_persons(const void *a, const void *b) {
    const Person *person1 = (const Person *)a;
    const Person *person2 = (const Person *)b;
    return person1->id - person2->id;
}

int main() {
    // Open the database
    sqlite3 *db;
    int rc = sqlite3_open("database.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }

    // Prepare a statement to query the database
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM people ORDER BY id", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return EXIT_FAILURE;
    }

    // Allocate an array to store the results
    Person *people = malloc(sizeof(Person) * 100);
    int num_people = 0;

    // Bind the results to the array
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        Person person;
        person.id = sqlite3_column_int(stmt, 0);
        person.name = (char *)sqlite3_column_text(stmt, 1);
        person.age = sqlite3_column_int(stmt, 2);
        people[num_people] = person;
        num_people++;
    }

    // Sort the array by ID
    qsort(people, num_people, sizeof(Person), compare_persons);

    // Print the results
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    // Clean up
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    free(people);

    return EXIT_SUCCESS;
}