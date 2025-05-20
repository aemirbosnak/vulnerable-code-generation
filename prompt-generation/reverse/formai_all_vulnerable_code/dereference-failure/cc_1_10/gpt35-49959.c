//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 30
#define MAX_AGE 120
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} PersonDatabase;

// function prototypes
void addPerson(PersonDatabase *db, Person person);
void displayPerson(Person person);
void displayDatabase(PersonDatabase db);
void queryByName(PersonDatabase db, char *name);

int main() {
    PersonDatabase db;
    db.size = 0;
    db.capacity = 10;
    db.data = malloc(db.capacity * sizeof(Person));

    addPerson(&db, (Person){"John Smith", 35, "123 Main St", "555-555-5555"});
    addPerson(&db, (Person){"Jane Doe", 28, "456 Oak Ave", "555-123-4567"});
    addPerson(&db, (Person){"Bob Johnson", 45, "789 Elm St", "555-777-8888"});
    addPerson(&db, (Person){"Sally Anderson", 22, "321 Maple Blvd", "555-444-3333"});

    printf("--- All Persons ---\n");
    displayDatabase(db);

    printf("\n--- Query by Name: \"John Smith\" ---\n");
    queryByName(db, "John Smith");

    printf("\n--- Query by Name: \"Bob Johnson\" ---\n");
    queryByName(db, "Bob Johnson");

    printf("\n--- Query by Name: \"Alice Johnson\" ---\n");
    queryByName(db, "Alice Johnson");

    free(db.data);

    return 0;
}

void addPerson(PersonDatabase *db, Person person) {
    if (db->size == db->capacity) {
        db->capacity *= 2;
        db->data = realloc(db->data, db->capacity * sizeof(Person));
    }

    db->data[db->size++] = person;
}

void displayPerson(Person person) {
    printf("Name: %s\nAge: %d\nAddress: %s\nPhone: %s\n",
           person.name, person.age, person.address, person.phone);
}

void displayDatabase(PersonDatabase db) {
    for (int i = 0; i < db.size; i++) {
        printf("Person %d\n", i + 1);
        displayPerson(db.data[i]);
        printf("\n");
    }
}

void queryByName(PersonDatabase db, char *name) {
    bool found = false;

    for (int i = 0; i < db.size; i++) {
        if (strcmp(db.data[i].name, name) == 0) {
            found = true;
            printf("Person %d\n", i + 1);
            displayPerson(db.data[i]);
            printf("\n");
        }
    }

    if (!found) {
        printf("No person found with name \"%s\"\n", name);
    }
}