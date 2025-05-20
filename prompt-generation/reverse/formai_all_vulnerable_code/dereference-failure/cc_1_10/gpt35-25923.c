//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the database entry
typedef struct {
    int id;
    char name[50];
    float temperature;
    int age;
} Person;

// Define a struct for the database
typedef struct {
    Person **entries;
    int num_entries;
    int max_entries;
} Database;

// Function to initialize a new database
Database *init_database(int max_entries) {
    Database *db = malloc(sizeof(Database));
    db->entries = malloc(max_entries * sizeof(Person *));
    for (int i = 0; i < max_entries; i++) {
        db->entries[i] = NULL;
    }
    db->num_entries = 0;
    db->max_entries = max_entries;
    return db;
}

// Function to add a new entry to the database
void add_entry(Database *db, Person *new_entry) {
    if (db->num_entries < db->max_entries) {
        db->entries[db->num_entries++] = new_entry;
    } else {
        printf("Error: Database is full.\n");
    }
}

// Function to print out all entries in the database
void print_database(Database *db) {
    printf("%-10s%-20s%-15s%-10s\n", "ID", "Name", "Temperature", "Age");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < db->num_entries; i++) {
        Person *p = db->entries[i];
        printf("%-10d%-20s%-15.2f%-10d\n", p->id, p->name, p->temperature, p->age);
    }
}

int main() {
    // Initialize a new database
    Database *db = init_database(10);

    // Add some entries to the database
    Person *p1 = malloc(sizeof(Person));
    p1->id = 1;
    strcpy(p1->name, "John Doe");
    p1->temperature = 98.6;
    p1->age = 30;
    add_entry(db, p1);

    Person *p2 = malloc(sizeof(Person));
    p2->id = 2;
    strcpy(p2->name, "Jane Smith");
    p2->temperature = 99.2;
    p2->age = 25;
    add_entry(db, p2);

    // Print out all entries in the database
    print_database(db);

    // Free the memory used by the database and its entries
    for (int i = 0; i < db->num_entries; i++) {
        free(db->entries[i]);
    }
    free(db->entries);
    free(db);

    return 0;
}