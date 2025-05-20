//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
    int id;
    char* name;
    int age;
    char* job;
} person;

// Create a new database
person* create_database(int size) {
    person* database = malloc(sizeof(person) * size);
    for (int i = 0; i < size; i++) {
        database[i].id = i;
        database[i].name = NULL;
        database[i].age = 0;
        database[i].job = NULL;
    }
    return database;
}

// Insert a new person into the database
void insert_person(person* database, int id, char* name, int age, char* job) {
    database[id].id = id;
    database[id].name = strdup(name);
    database[id].age = age;
    database[id].job = strdup(job);
}

// Print the database
void print_database(person* database, int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d\n", database[i].id);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Job: %s\n", database[i].job);
        printf("\n");
    }
}

// Free the database
void free_database(person* database, int size) {
    for (int i = 0; i < size; i++) {
        free(database[i].name);
        free(database[i].job);
    }
    free(database);
}

// Main function
int main() {
    // Create a new database
    person* database = create_database(10);

    // Insert some people into the database
    insert_person(database, 0, "John Doe", 30, "Software Engineer");
    insert_person(database, 1, "Jane Doe", 25, "Doctor");
    insert_person(database, 2, "Bill Smith", 40, "Lawyer");
    insert_person(database, 3, "Alice Smith", 35, "Teacher");
    insert_person(database, 4, "Bob Jones", 28, "Police Officer");

    // Print the database
    print_database(database, 5);

    // Free the database
    free_database(database, 5);

    return 0;
}