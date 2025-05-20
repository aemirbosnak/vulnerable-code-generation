//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold database data
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// function to initialize database and populate it with sample data
void initDatabase(Person *db, int size) {
    for (int i = 0; i < size; i++) {
        db[i].id = i+1;
        strcpy(db[i].name, "John Doe");
        db[i].age = 25+i;
    }
}

// function to print a single person's data
void printPerson(Person p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("---------------------------\n");
}

// function to print all people in the database
void printDatabase(Person *db, int size) {
    for (int i = 0; i < size; i++)
        printPerson(db[i]);
}

// function to search the database by ID and return a Person struct
Person searchById(Person *db, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (db[i].id == id)
            return db[i];
    }
    // return an empty Person if no match is found
    Person empty;
    empty.id = -1;
    return empty;
}

// main function
int main() {
    // initialize database
    int dbSize = 5;
    Person *database = malloc(dbSize * sizeof(Person));
    initDatabase(database, dbSize);

    // print all people in database
    printDatabase(database, dbSize);

    // search for a person by ID
    int searchId = 3;
    Person searchResult = searchById(database, dbSize, searchId);

    // print search result
    if (searchResult.id == -1)
        printf("No person found with ID %d.\n", searchId);
    else
        printPerson(searchResult);

    // free memory and exit
    free(database);
    return 0;
}