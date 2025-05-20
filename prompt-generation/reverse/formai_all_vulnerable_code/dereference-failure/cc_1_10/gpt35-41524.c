//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    char gender;
} Person;

typedef struct {
    Person* data;
    int capacity;
    int size;
} PersonDB;

PersonDB* createPersonDB(int capacity) {
    PersonDB* db = (PersonDB*) malloc(sizeof(PersonDB));
    db->data = (Person*) malloc(sizeof(Person) * capacity);
    db->capacity = capacity;
    db->size = 0;
    return db;
}

void insertPerson(PersonDB* db, Person p) {
    if(db->size >= db->capacity) {
        db->data = (Person*) realloc(db->data, sizeof(Person) * (db->capacity * 2));
        db->capacity *= 2;
    }

    db->data[db->size++] = p;
}

void printPersonInfo(Person p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %c\n", p.gender);
    printf("\n");
}

void printPersonDB(PersonDB* db) {
    for(int i = 0; i < db->size; i++) {
        printPersonInfo(db->data[i]);
    }
}

int main() {
    PersonDB* db = createPersonDB(2);

    Person p1 = {1, "John", 25, 'M'};
    Person p2 = {2, "Jane", 30, 'F'};
    Person p3 = {3, "Bob", 45, 'M'};

    insertPerson(db, p1);
    insertPerson(db, p2);
    insertPerson(db, p3);

    printf("PersonDB:\n");
    printPersonDB(db);

    free(db->data);
    free(db);

    return 0;
}