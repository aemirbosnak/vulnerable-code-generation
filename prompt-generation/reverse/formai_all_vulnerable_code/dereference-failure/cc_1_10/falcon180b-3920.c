//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a single record
typedef struct {
    char name[50];
    int age;
    float salary;
} record;

// Define the structure for the database
typedef struct {
    int num_records;
    record* records;
} database;

// Function to create a new database with the given number of records
database* create_database(int num_records) {
    database* db = (database*)malloc(sizeof(database));
    db->num_records = num_records;
    db->records = (record*)malloc(sizeof(record) * num_records);
    for (int i = 0; i < num_records; i++) {
        strcpy(db->records[i].name, "N/A");
        db->records[i].age = 0;
        db->records[i].salary = 0;
    }
    return db;
}

// Function to add a new record to the database
void add_record(database* db, char* name, int age, float salary) {
    strcpy(db->records[db->num_records-1].name, name);
    db->records[db->num_records-1].age = age;
    db->records[db->num_records-1].salary = salary;
    db->num_records++;
}

// Function to delete a record from the database by name
void delete_record(database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            for (int j = i; j < db->num_records-1; j++) {
                strcpy(db->records[j].name, db->records[j+1].name);
                db->records[j].age = db->records[j+1].age;
                db->records[j].salary = db->records[j+1].salary;
            }
            db->num_records--;
            break;
        }
    }
}

// Function to update a record in the database by name
void update_record(database* db, char* name, int age, float salary) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            db->records[i].age = age;
            db->records[i].salary = salary;
            break;
        }
    }
}

// Function to display all records in the database
void display_records(database* db) {
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%s\t%d\t%.2f\n", db->records[i].name, db->records[i].age, db->records[i].salary);
    }
}

int main() {
    database* db = create_database(5);
    add_record(db, "John", 25, 50000);
    add_record(db, "Jane", 30, 60000);
    add_record(db, "Bob", 40, 70000);
    display_records(db);
    delete_record(db, "Jane");
    display_records(db);
    update_record(db, "John", 26, 55000);
    display_records(db);
    return 0;
}