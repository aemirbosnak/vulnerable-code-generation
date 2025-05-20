//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the database
struct database {
    char **names;
    int *ages;
    bool *taken;
    int size;
};

// Function to create a new database
struct database *create_database() {
    struct database *db = malloc(sizeof(struct database));
    db->names = malloc(sizeof(char *) * 100);
    db->ages = malloc(sizeof(int) * 100);
    db->taken = malloc(sizeof(bool) * 100);
    db->size = 0;
    return db;
}

// Function to add a person to the database
void add_person(struct database *db, char *name, int age, bool taken) {
    db->names[db->size] = malloc(strlen(name) + 1);
    strcpy(db->names[db->size], name);
    db->ages[db->size] = age;
    db->taken[db->size] = taken;
    db->size++;
}

// Function to find a person in the database
int find_person(struct database *db, char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print the database
void print_database(struct database *db) {
    for (int i = 0; i < db->size; i++) {
        printf("%s, %d, %s\n", db->names[i], db->ages[i], db->taken[i] ? "Taken" : "Single");
    }
}

// Function to free the database
void free_database(struct database *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->names[i]);
    }
    free(db->names);
    free(db->ages);
    free(db->taken);
    free(db);
}

int main() {
    // Create a new database
    struct database *db = create_database();

    // Add some people to the database
    add_person(db, "Alice", 20, false);
    add_person(db, "Bob", 25, true);
    add_person(db, "Carol", 30, false);
    add_person(db, "Dave", 35, true);
    add_person(db, "Eve", 40, false);

    // Print the database
    print_database(db);

    // Find a person in the database
    int index = find_person(db, "Alice");
    if (index != -1) {
        printf("Found Alice at index %d\n", index);
    } else {
        printf("Alice not found\n");
    }

    // Free the database
    free_database(db);

    return 0;
}