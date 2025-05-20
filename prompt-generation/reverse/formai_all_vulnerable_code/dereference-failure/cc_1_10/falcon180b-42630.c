//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of each record in the database
typedef struct {
    char name[50];
    char house[50];
    int age;
} Person;

// Define the structure of the database
typedef struct {
    Person *records;
    int num_records;
    int max_records;
} Database;

// Function to initialize a new database with a given maximum capacity
Database *new_database(int max_records) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->records = (Person *)malloc(max_records * sizeof(Person));
    db->num_records = 0;
    db->max_records = max_records;
    return db;
}

// Function to add a new record to the database
void add_record(Database *db, char *name, char *house, int age) {
    if (db->num_records >= db->max_records) {
        printf("Error: Database is full!\n");
        return;
    }
    strcpy(db->records[db->num_records].name, name);
    strcpy(db->records[db->num_records].house, house);
    db->records[db->num_records].age = age;
    db->num_records++;
}

// Function to query the database for records matching a given name and/or house
void query_records(Database *db, char *name, char *house) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if ((strcmp(db->records[i].name, name) == 0 || name == NULL) &&
            (strcmp(db->records[i].house, house) == 0 || house == NULL)) {
            printf("Name: %s\nHouse: %s\nAge: %d\n", db->records[i].name, db->records[i].house, db->records[i].age);
        }
    }
}

int main() {
    Database *db = new_database(100);
    add_record(db, "Romeo", "Montague", 18);
    add_record(db, "Juliet", "Capulet", 16);
    add_record(db, "Tybalt", "Capulet", 20);
    add_record(db, "Mercutio", "Prince's Kinsman", 25);
    add_record(db, "Benvolio", "Montague", 22);
    query_records(db, "Capulet", NULL);
    query_records(db, NULL, "Verona");
    return 0;
}