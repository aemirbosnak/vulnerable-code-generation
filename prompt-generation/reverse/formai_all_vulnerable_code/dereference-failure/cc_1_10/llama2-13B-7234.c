//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the database structure
typedef struct {
    char name[50];
    int age;
} person;

// Define the database array
person database[10];

// Function to add a person to the database
void add_person(person *person) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, person->name) == 0) {
            printf("Person already exists in the database!\n");
            return;
        }
    }
    strcpy(database[i].name, person->name);
    database[i].age = person->age;
    i++;
}

// Function to remove a person from the database
void remove_person(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, name) == 0) {
            break;
        }
    }
    if (i < 10) {
        memset(database[i].name, 0, 50);
        database[i].age = 0;
    } else {
        printf("Person not found in the database!\n");
    }
}

// Function to search for a person in the database
int search_person(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print all persons in the database
void print_database() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d: %s %d\n", i, database[i].name, database[i].age);
    }
}

int main() {
    srand(time(NULL));

    // Add some persons to the database
    person p1 = {"Alice", 25};
    person p2 = {"Bob", 30};
    person p3 = {"Charlie", 20};
    add_person(&p1);
    add_person(&p2);
    add_person(&p3);

    // Remove a person from the database
    remove_person("Bob");

    // Search for a person in the database
    int found = search_person("Charlie");
    if (found != -1) {
        printf("Found Charlie at index %d\n", found);
    } else {
        printf("Not found\n");
    }

    // Print all persons in the database
    print_database();

    return 0;
}