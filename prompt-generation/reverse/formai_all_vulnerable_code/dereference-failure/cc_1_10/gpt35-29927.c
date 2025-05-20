//FormAI DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 1000

typedef struct {
    char name[50];
    int age;
    char address[100];
} Person;

typedef struct {
    FILE *file;
    int num_records;
} Database;

void initialize_database(Database *database, char *filename) {
    database->file = fopen(filename, "r+");
    if (!database->file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Count the number of records in the file
    fseek(database->file, 0, SEEK_END);
    database->num_records = ftell(database->file) / sizeof(Person);
    fseek(database->file, 0, SEEK_SET);
}

void close_database(Database *database) {
    fclose(database->file);
}

Person *get_person_by_name(Database *database, char *name) {
    Person *person = malloc(sizeof(Person));

    // Query the database for the person with the given name
    char query[MAX_QUERY_LENGTH];
    snprintf(query, MAX_QUERY_LENGTH, "SELECT * FROM people WHERE name='%s'", name);
    fseek(database->file, 0, SEEK_SET);
    int found = 0;
    while (!feof(database->file)) {
        fread(person, sizeof(Person), 1, database->file);
        if (feof(database->file)) {
            break;
        }

        if (strcmp(person->name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        free(person);
        person = NULL;
    }

    return person;
}

int main(void) {
    Database database;
    initialize_database(&database, "people.db");

    // Query the database for a person by name
    Person *person = get_person_by_name(&database, "Alice");
    if (person) {
        printf("Name: %s\n", person->name);
        printf("Age: %d\n", person->age);
        printf("Address: %s\n", person->address);
        free(person);
    }
    else {
        printf("Person not found.\n");
    }

    close_database(&database);

    return 0;
}