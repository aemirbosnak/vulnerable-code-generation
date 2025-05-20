//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the database structure
struct database {
    char *name;
    int age;
    char *city;
};

// Create a new database
struct database *create_database() {
    struct database *db = malloc(sizeof(struct database));
    db->name = NULL;
    db->age = 0;
    db->city = NULL;
    return db;
}

// Insert a new record into the database
void insert_record(struct database *db, char *name, int age, char *city) {
    db->name = malloc(strlen(name) + 1);
    strcpy(db->name, name);
    db->age = age;
    db->city = malloc(strlen(city) + 1);
    strcpy(db->city, city);
}

// Print the database
void print_database(struct database *db) {
    printf("Name: %s\n", db->name);
    printf("Age: %d\n", db->age);
    printf("City: %s\n", db->city);
}

// Free the database
void free_database(struct database *db) {
    free(db->name);
    free(db->city);
    free(db);
}

// Main function
int main() {
    // Create a new database
    struct database *db = create_database();

    // Insert some records into the database
    insert_record(db, "John", 30, "New York");
    insert_record(db, "Jane", 25, "Los Angeles");
    insert_record(db, "Bob", 40, "Chicago");

    // Print the database
    print_database(db);

    // Free the database
    free_database(db);

    return 0;
}