//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    char *name;
    char *email;
    char *phone;
} Person;

// Create a new database
Person *create_database(int size) {
    Person *database = malloc(sizeof(Person) * size);
    return database;
}

// Insert a new person into the database
void insert_person(Person *database, int index, char *name, char *email, char *phone) {
    database[index].name = strdup(name);
    database[index].email = strdup(email);
    database[index].phone = strdup(phone);
}

// Print the database
void print_database(Person *database, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Email: %s\n", database[i].email);
        printf("Phone: %s\n\n", database[i].phone);
    }
}

// Free the database
void free_database(Person *database, int size) {
    for (int i = 0; i < size; i++) {
        free(database[i].name);
        free(database[i].email);
        free(database[i].phone);
    }
    free(database);
}

// Main function
int main() {
    // Create a new database
    Person *database = create_database(10);

    // Insert some people into the database
    insert_person(database, 0, "John Smith", "john.smith@example.com", "555-1212");
    insert_person(database, 1, "Jane Doe", "jane.doe@example.com", "555-1213");
    insert_person(database, 2, "Bill Johnson", "bill.johnson@example.com", "555-1214");

    // Print the database
    print_database(database, 3);

    // Free the database
    free_database(database, 3);

    return 0;
}