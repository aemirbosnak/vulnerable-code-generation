//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definition of a Person struct
typedef struct {
    char name[50];
    int age;
    int address[3];
} Person;

// Definition of a Database struct
typedef struct {
    int numPeople;
    Person **people;
} Database;

// Function to create a new database
Database *createDatabase(int size) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->numPeople = size;
    db->people = (Person **)malloc(size * sizeof(Person *));
    for (int i = 0; i < size; i++) {
        Person *p = (Person *)malloc(sizeof(Person));
        srand(time(NULL));
        p->name[0] = 'A' + (rand() % 26);
        p->age = rand() % 100;
        p->address[0] = rand() % 100;
        p->address[1] = rand() % 100;
        p->address[2] = rand() % 100;
        db->people[i] = p;
    }
    return db;
}

// Function to add a person to the database
void addPerson(Database *db, char *name, int age, int address0, int address1, int address2) {
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, name);
    p->age = age;
    p->address[0] = address0;
    p->address[1] = address1;
    p->address[2] = address2;
    db->numPeople++;
    db->people = (Person **)realloc(db->people, db->numPeople * sizeof(Person *));
    db->people[db->numPeople - 1] = p;
}

// Function to search for a person in the database
Person *searchPerson(Database *db, char *name) {
    for (int i = 0; i < db->numPeople; i++) {
        if (strcmp(db->people[i]->name, name) == 0) {
            return db->people[i];
        }
    }
    return NULL;
}

// Function to remove a person from the database
void removePerson(Database *db, char *name) {
    for (int i = 0; i < db->numPeople; i++) {
        if (strcmp(db->people[i]->name, name) == 0) {
            free(db->people[i]);
            db->numPeople--;
            break;
        }
    }
}

// Function to print all the people in the database
void printDatabase(Database *db) {
    for (int i = 0; i < db->numPeople; i++) {
        printf("%s %d %d %d %d\n", db->people[i]->name, db->people[i]->age, db->people[i]->address[0], db->people[i]->address[1], db->people[i]->address[2]);
    }
}

int main() {
    Database *db = createDatabase(10);
    addPerson(db, "Alice", 25, 10, 20, 30);
    addPerson(db, "Bob", 35, 40, 50, 60);
    addPerson(db, "Charlie", 18, 20, 30, 40);
    removePerson(db, "Bob");
    printDatabase(db);
    return 0;
}