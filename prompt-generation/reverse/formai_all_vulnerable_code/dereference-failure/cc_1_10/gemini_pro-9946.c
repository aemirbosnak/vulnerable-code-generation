//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// A custom data structure to store the result of a query
typedef struct {
    int id;
    char *name;
    int age;
} Person;

// A function to print the result of a query
void print_person(Person *person) {
    printf("ID: %d, Name: %s, Age: %d\n", person->id, person->name, person->age);
}

// A function to query the database and print the result
void query_database(sqlite3 *db) {
    // Prepare the query statement
    sqlite3_stmt *stmt;
    const char *query = "SELECT * FROM people WHERE age > 21";
    int rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

    // Check for errors
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing query: %s\n", sqlite3_errmsg(db));
        return;
    }

    // Step through the results
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // Create a new Person struct to store the result
        Person *person = malloc(sizeof(Person));

        // Get the column values
        person->id = sqlite3_column_int(stmt, 0);
        person->name = (char *)sqlite3_column_text(stmt, 1);
        person->age = sqlite3_column_int(stmt, 2);

        // Print the result
        print_person(person);

        // Free the memory allocated for the person's name
        free(person->name);
        free(person);
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}

int main() {
    // Open the database
    sqlite3 *db;
    int rc = sqlite3_open("people.db", &db);

    // Check for errors
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }

    // Query the database
    query_database(db);

    // Close the database
    sqlite3_close(db);

    return EXIT_SUCCESS;
}