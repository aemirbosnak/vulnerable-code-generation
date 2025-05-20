//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Database structure
typedef struct {
    char *name;
    char *email;
    int age;
} Person;

// Create a new database
Person *create_database() {
    // Allocate memory for the database
    Person *database = malloc(sizeof(Person) * 10);

    // Initialize the database
    for (int i = 0; i < 10; i++) {
        database[i].name = NULL;
        database[i].email = NULL;
        database[i].age = 0;
    }

    // Return the database
    return database;
}

// Add a new person to the database
void add_person(Person *database, char *name, char *email, int age) {
    // Find the first empty slot in the database
    int i = 0;
    while (database[i].name != NULL) {
        i++;
    }

    // Add the new person to the database
    database[i].name = name;
    database[i].email = email;
    database[i].age = age;
}

// Print the database
void print_database(Person *database) {
    // Print the header
    printf("Name\tEmail\tAge\n");

    // Print the data
    for (int i = 0; i < 10; i++) {
        printf("%s\t%s\t%d\n", database[i].name, database[i].email, database[i].age);
    }
}

// Free the database
void free_database(Person *database) {
    // Free the memory allocated for each person
    for (int i = 0; i < 10; i++) {
        free(database[i].name);
        free(database[i].email);
    }

    // Free the memory allocated for the database
    free(database);
}

// Main function
int main() {
    // Create a new database
    Person *database = create_database();

    // Add some people to the database
    add_person(database, "John", "john@example.com", 30);
    add_person(database, "Jane", "jane@example.com", 25);
    add_person(database, "Bob", "bob@example.com", 40);

    // Print the database
    print_database(database);

    // Free the database
    free_database(database);

    return 0;
}