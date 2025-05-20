//FormAI DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

void createDatabase(Person **db) {
    *db = (Person *) malloc(sizeof(Person) * 5);

    // Populate database with sample data
    (*db)[0].id = 1;
    strcpy((*db)[0].name, "Alice");
    (*db)[0].age = 25;

    (*db)[1].id = 2;
    strcpy((*db)[1].name, "Bob");
    (*db)[1].age = 30;

    (*db)[2].id = 3;
    strcpy((*db)[2].name, "Charlie");
    (*db)[2].age = 28;

    (*db)[3].id = 4;
    strcpy((*db)[3].name, "David");
    (*db)[3].age = 35;

    (*db)[4].id = 5;
    strcpy((*db)[4].name, "Eve");
    (*db)[4].age = 22;
}

void printDatabase(Person *db) {
    printf("|%-5s|%-20s|%-5s|\n", "ID", "NAME", "AGE");
    printf("|-----|--------------------|-----|\n");
    for (int i = 0; i < 5; i++) {
        printf("|%-5d|%-20s|%-5d|\n", db[i].id, db[i].name, db[i].age);
    }
}

void queryByName(Person *db, char *name) {
    printf("Results matching name '%s':\n", name);
    printf("|%-5s|%-20s|%-5s|\n", "ID", "NAME", "AGE");
    printf("|-----|--------------------|-----|\n");
    for (int i = 0; i < 5; i++) {
        if (strcmp(db[i].name, name) == 0) {
            printf("|%-5d|%-20s|%-5d|\n", db[i].id, db[i].name, db[i].age);
        }
    }
}

int main() {
    Person *database;
    createDatabase(&database);
    printDatabase(database);

    queryByName(database, "Alice");

    free(database);
    return 0;
}