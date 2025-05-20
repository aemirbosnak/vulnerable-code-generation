//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
typedef struct {
    char *name;
    int age;
} person;

// Define database array
person database[10];

// Function to add person to database
void add_person(person *p) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, p->name) == 0) {
            printf("Person already exists in the database.\n");
            return;
        }
    }
    database[i] = *p;
    printf("Person added to the database successfully.\n");
}

// Function to retrieve all persons in the database
void print_database() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%s (%d)\n", database[i].name, database[i].age);
    }
}

// Function to retrieve a specific person from the database
void print_person(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("%s (%d)\n", database[i].name, database[i].age);
            break;
        }
    }
}

// Function to update a person's information in the database
void update_person(person *p) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, p->name) == 0) {
            database[i].age = p->age;
            printf("Person updated successfully.\n");
            return;
        }
    }
    printf("Person not found in the database.\n");
}

// Function to delete a person from the database
void delete_person(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, name) == 0) {
            memset(&database[i], 0, sizeof(person));
            printf("Person deleted successfully.\n");
            return;
        }
    }
    printf("Person not found in the database.\n");
}

int main() {
    // Add some people to the database
    person p1 = {"Alice", 25};
    add_person(&p1);
    person p2 = {"Bob", 30};
    add_person(&p2);
    person p3 = {"Charlie", 35};
    add_person(&p3);

    // Retrieve all persons in the database
    print_database();

    // Retrieve a specific person from the database
    print_person("Alice");

    // Update a person's information in the database
    person p4 = {"Alice", 30};
    update_person(&p4);

    // Delete a person from the database
    delete_person("Bob");

    return 0;
}