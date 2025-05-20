//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define database structure
typedef struct {
    char *name;
    int age;
} person;

// Define database
person *db[10];
int db_size = 0;

// Function to insert a person into the database
void insert_person(char *name, int age) {
    person *new_person = malloc(sizeof(person));
    new_person->name = name;
    new_person->age = age;
    db[db_size] = new_person;
    db_size++;
}

// Function to search for a person in the database
person *search_person(char *name) {
    int i;
    for (i = 0; i < db_size; i++) {
        if (strcmp(db[i]->name, name) == 0) {
            return db[i];
        }
    }
    return NULL;
}

// Function to delete a person from the database
void delete_person(char *name) {
    int i;
    for (i = 0; i < db_size; i++) {
        if (strcmp(db[i]->name, name) == 0) {
            free(db[i]);
            db[i] = NULL;
            break;
        }
    }
}

// Function to display all persons in the database
void display_all() {
    int i;
    for (i = 0; i < db_size; i++) {
        printf("%s is %d years old.\n", db[i]->name, db[i]->age);
    }
}

int main() {
    insert_person("Alice", 25);
    insert_person("Bob", 30);
    insert_person("Charlie", 20);
    insert_person("David", 35);

    // Search for a person
    person *alice = search_person("Alice");
    if (alice != NULL) {
        printf("Alice is %d years old.\n", alice->age);
    } else {
        printf("Alice is not found.\n");
    }

    // Delete a person
    delete_person("Bob");

    // Display all persons
    display_all();

    return 0;
}