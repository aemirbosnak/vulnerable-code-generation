//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//Struct for each record
typedef struct {
    char name[50];
    int age;
    float salary;
} Record;

//Struct for the database
typedef struct {
    Record records[MAX_SIZE];
    int num_records;
} Database;

//Function prototypes
Database* create_database();
void add_record(Database* db, char* name, int age, float salary);
void display_records(Database* db);
void search_record(Database* db, char* name);

int main() {
    Database* db = create_database();

    add_record(db, "John Doe", 30, 50000);
    add_record(db, "Jane Smith", 25, 40000);
    add_record(db, "Bob Johnson", 35, 60000);

    display_records(db);

    search_record(db, "Jane Smith");

    return 0;
}

//Create an empty database with 0 records
Database* create_database() {
    Database* db = (Database*)malloc(sizeof(Database));
    db->num_records = 0;
    return db;
}

//Add a record to the database
void add_record(Database* db, char* name, int age, float salary) {
    if (db->num_records == MAX_SIZE) {
        printf("Database is full!\n");
        return;
    }

    strcpy(db->records[db->num_records].name, name);
    db->records[db->num_records].age = age;
    db->records[db->num_records].salary = salary;

    db->num_records++;
}

//Display all records in the database
void display_records(Database* db) {
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%s\t%d\t%.2f\n", db->records[i].name, db->records[i].age, db->records[i].salary);
    }
}

//Search for a specific record in the database
void search_record(Database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            printf("Found record:\n");
            printf("Name: %s\n", db->records[i].name);
            printf("Age: %d\n", db->records[i].age);
            printf("Salary: $.2f\n");
        }
    }
}