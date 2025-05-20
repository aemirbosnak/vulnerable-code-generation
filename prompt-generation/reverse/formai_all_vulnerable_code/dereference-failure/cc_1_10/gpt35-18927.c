//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_LENGTH 20
#define PHONE_LENGTH 12

// define the structure of the person containing the name and phone number
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Person;

// define the structure of the database containing an array of persons and the size of the array
typedef struct {
    Person *persons;
    int size;
} Database;

// function to print a single person's information
void printPerson(Person *p) {
    printf("Name: %s\nPhone: %s\n", p->name, p->phone);
}

// function to initialize a single person's information
void initPerson(Person *p, char name[], char phone[]) {
    strcpy(p->name, name);
    strcpy(p->phone, phone);
}

// function to initialize the entire database
void initDatabase(Database *db, int size) {
    db->persons = (Person *) malloc(size * sizeof(Person));
    db->size = size;

    // initialize each person in the database to default values
    int i;
    for(i = 0; i < size; i++) {
        initPerson(&db->persons[i], "Unknown", "000-000-0000");
    }
}

// function to add a new person to the database
void addPerson(Database *db, char name[], char phone[]) {
    // find the first person with default values and replace their information with the new person's information
    int i;
    for(i = 0; i < db->size; i++) {
        if(strcmp(db->persons[i].name, "Unknown") == 0 && strcmp(db->persons[i].phone, "000-000-0000") == 0) {
            initPerson(&db->persons[i], name, phone);
            printf("Added person %s with phone number %s to database.\n", name, phone);
            return;
        }
    }

    // if all persons have been initialized with values, print an error message
    printf("Database is full, cannot add person %s with phone number %s.\n", name, phone);
}

// function to delete a person from the database
void deletePerson(Database *db, char name[]) {
    // find the person with the given name and replace their information with default values
    int i;
    for(i = 0; i < db->size; i++) {
        if(strcmp(db->persons[i].name, name) == 0) {
            initPerson(&db->persons[i], "Unknown", "000-000-0000");
            printf("Deleted person %s from database.\n", name);
            return;
        }
    }

    // if no person was found with the given name, print an error message
    printf("Person %s not found in database, cannot delete.\n", name);
}

// function to print the entire database
void printDatabase(Database *db) {
    // iterate through each person in the database and print their information
    int i;
    for(i = 0; i < db->size; i++) {
        printf("Person %d:\n", i+1);
        printPerson(&db->persons[i]);
        printf("\n");
    }
}

int main() {
    int size = 5;
    Database db;
    initDatabase(&db, size);

    addPerson(&db, "John Doe", "111-111-1111");
    addPerson(&db, "Jane Smith", "222-222-2222");
    addPerson(&db, "Mike Johnson", "333-333-3333");
    addPerson(&db, "Emily Brown", "444-444-4444");
    addPerson(&db, "David Lee", "555-555-5555");
    addPerson(&db, "Sarah Kim", "666-666-6666");

    deletePerson(&db, "Mike Johnson");

    printDatabase(&db);

    return 0;
}