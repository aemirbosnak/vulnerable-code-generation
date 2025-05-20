//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the database structure
typedef struct {
    char *name;
    int age;
    char gender;
    int address[3];
} person;

// Define the database functions
person *create_person(char *name, int age, char gender, int address[3]);
void insert_person(person *person);
person *search_person(char *name);
void delete_person(person *person);
void display_all_persons();

// Define the database
person *db[5];
int num_persons = 0;

// Function to create a new person
person *create_person(char *name, int age, char gender, int address[3]) {
    person *new_person = (person *)malloc(sizeof(person));
    new_person->name = name;
    new_person->age = age;
    new_person->gender = gender;
    for (int i = 0; i < 3; i++) {
        new_person->address[i] = address[i];
    }
    num_persons++;
    return new_person;
}

// Function to insert a new person into the database
void insert_person(person *person) {
    db[num_persons] = person;
    num_persons++;
}

// Function to search for a person in the database
person *search_person(char *name) {
    for (int i = 0; i < num_persons; i++) {
        if (strcmp(db[i]->name, name) == 0) {
            return db[i];
        }
    }
    return NULL;
}

// Function to delete a person from the database
void delete_person(person *person) {
    for (int i = 0; i < num_persons; i++) {
        if (db[i] == person) {
            memcpy(db[i], db[num_persons - 1], sizeof(person));
            num_persons--;
            break;
        }
    }
}

// Function to display all persons in the database
void display_all_persons() {
    for (int i = 0; i < num_persons; i++) {
        printf("%s %d %c %d %d %d\n", db[i]->name, db[i]->age, db[i]->gender, db[i]->address[0], db[i]->address[1], db[i]->address[2]);
    }
}

int main() {
    srand(time(NULL));

    // Create some sample data
    person *p1 = create_person("Alice", 25, 'F', (int[]){1234, 5678, 9012});
    person *p2 = create_person("Bob", 30, 'M', (int[]){2345, 6789, 0123});
    person *p3 = create_person("Charlie", 35, 'M', (int[]){3456, 7890, 1234});

    // Insert the sample data into the database
    insert_person(p1);
    insert_person(p2);
    insert_person(p3);

    // Search for a person in the database
    person *found_person = search_person("Alice");
    if (found_person != NULL) {
        printf("Found Alice at address %d %d %d\n", found_person->address[0], found_person->address[1], found_person->address[2]);
    } else {
        printf("Alice not found\n");
    }

    // Delete a person from the database
    delete_person(p2);

    // Display all persons in the database
    display_all_persons();

    return 0;
}