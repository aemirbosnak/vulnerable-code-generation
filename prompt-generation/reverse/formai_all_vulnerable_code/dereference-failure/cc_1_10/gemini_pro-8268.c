//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the database structure
typedef struct {
    int id;
    char *name;
    char *email;
} person;

// Create a new database
person *create_database(int size) {
    person *db = malloc(sizeof(person) * size);
    return db;
}

// Insert a new person into the database
void insert_person(person *db, int id, char *name, char *email) {
    db[id].id = id;
    db[id].name = name;
    db[id].email = email;
}

// Print the database
void print_database(person *db, int size) {
    for (int i = 0; i < size; i++) {
        printf("id: %d, name: %s, email: %s\n", db[i].id, db[i].name, db[i].email);
    }
}

// Delete a person from the database
void delete_person(person *db, int id) {
    free(db[id].name);
    free(db[id].email);
}

// Close the database
void close_database(person *db) {
    free(db);
}

// Main function
int main() {
    // Create a new database
    person *db = create_database(10);

    // Insert some people into the database
    insert_person(db, 0, "John Doe", "john.doe@example.com");
    insert_person(db, 1, "Jane Doe", "jane.doe@example.com");
    insert_person(db, 2, "John Smith", "john.smith@example.com");

    // Print the database
    print_database(db, 10);

    // Delete a person from the database
    delete_person(db, 1);

    // Close the database
    close_database(db);

    return 0;
}