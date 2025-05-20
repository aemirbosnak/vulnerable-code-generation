//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    char *name;
    char *email;
    char *phone;
} person;

// Create a new database
person *create_database() {
    person *db = malloc(sizeof(person) * 100);
    return db;
}

// Add a new person to the database
void add_person(person *db, char *name, char *email, char *phone) {
    int i;
    for (i = 0; i < 100; i++) {
        if (db[i].name == NULL) {
            db[i].name = strdup(name);
            db[i].email = strdup(email);
            db[i].phone = strdup(phone);
            break;
        }
    }
}

// Print the database
void print_database(person *db) {
    int i;
    for (i = 0; i < 100; i++) {
        if (db[i].name != NULL) {
            printf("%s %s %s\n", db[i].name, db[i].email, db[i].phone);
        }
    }
}

// Free the database
void free_database(person *db) {
    int i;
    for (i = 0; i < 100; i++) {
        if (db[i].name != NULL) {
            free(db[i].name);
            free(db[i].email);
            free(db[i].phone);
        }
    }
    free(db);
}

// Main function
int main() {
    // Create a new database
    person *db = create_database();

    // Add some people to the database
    add_person(db, "John Doe", "johndoe@example.com", "123-456-7890");
    add_person(db, "Jane Doe", "janedoe@example.com", "123-456-7891");
    add_person(db, "John Smith", "johnsmith@example.com", "123-456-7892");

    // Print the database
    print_database(db);

    // Free the database
    free_database(db);

    return 0;
}