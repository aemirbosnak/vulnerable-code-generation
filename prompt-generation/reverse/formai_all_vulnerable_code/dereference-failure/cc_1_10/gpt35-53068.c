//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50 // Maximum length of name and address fields

typedef struct person {
    int id; 
    char name[MAX_LENGTH];
    char address[MAX_LENGTH];
    int age;
} person;

typedef struct database {
    int num_records;
    person *records;
} database;

void add_person(person p, database *db) {
    db->records = realloc(db->records, (db->num_records + 1) * sizeof(person)); // Increase size of records array in db
    db->records[db->num_records] = p; // Add person p to database
    db->num_records++;
    printf("Person added!\n");
}

void delete_person(int id, database *db) {
    int index = -1;
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Person not found.\n");
        return;
    }
    // Move all records after index back by one
    for (int i = index+1; i < db->num_records; i++) {
        db->records[i-1] = db->records[i];
    }
    db->num_records--;
    db->records = realloc(db->records, db->num_records * sizeof(person)); // Reduce size of records array in db
    printf("Person deleted!\n");
}

void display_database(database db) {
    printf("Number of records: %d\n", db.num_records);
    for (int i = 0; i < db.num_records; i++) {
        printf("ID: %d\nName: %s\nAddress: %s\nAge: %d\n", db.records[i].id, db.records[i].name, db.records[i].address, db.records[i].age);
    }
}

int main() {
    database db = {0, NULL}; // Initialize database with 0 records and null records array
    int option = 0;
    while (1) {
        printf("\n---MENU---\n");
        printf("1. Add person\n");
        printf("2. Delete person\n");
        printf("3. Display database\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        if (option == 1) {
            person p;
            printf("\nEnter ID: ");
            scanf("%d", &p.id);
            printf("Enter name: ");
            scanf("%s", p.name);
            printf("Enter address: ");
            scanf("%s", p.address);
            printf("Enter age: ");
            scanf("%d", &p.age);
            add_person(p, &db);
        }
        else if (option == 2) {
            int id;
            printf("\nEnter ID of person to delete: ");
            scanf("%d", &id);
            delete_person(id, &db);
        }
        else if (option == 3) {
            display_database(db);
        }
        else if (option == 4) {
            break;
        }
        else {
            printf("Invalid option.\n");
        }
    }
    free(db.records); // Free heap memory used by records array
    return 0;
}