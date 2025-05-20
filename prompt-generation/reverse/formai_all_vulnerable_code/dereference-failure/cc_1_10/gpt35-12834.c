//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Structure for the Database record
 */
typedef struct Record {
    int id; // unique identifier
    char name[20]; // name of person
    char address[50]; // address of person
    char phone_no[15]; // phone number of person
} record_t;

/*
 * Structure for Database
 */
typedef struct Database {
    record_t *records; // Array of records
    int n_records; // number of records
    int next_id; // id for next record
} database_t;

/*
 * Function to create new record
 * Allocate memory for record and initialize id
 */
record_t *new_record(int id) {
    record_t *record = malloc(sizeof(record_t));
    record->id = id;
    return record;
}

/*
 * Function to create new database
 * Allocate memory for the database, initialize new record array
 */
database_t *new_database() {
    database_t *database = malloc(sizeof(database_t));
    database->records = malloc(sizeof(record_t)*10);
    database->n_records = 0;
    database->next_id = 1;
    return database;
}

/*
 * Function to add new record to the database
 * Allocate memory for new record, add to array and increment n_records
 */
void add_record(database_t *database, char name[], char address[], char phone_no[]) {
    record_t *record = new_record(database->next_id);
    strcpy(record->name, name);
    strcpy(record->address, address);
    strcpy(record->phone_no, phone_no);
    database->records[database->n_records++] = *record;
    database->next_id++;
}

/*
 * Function to search for a record by name
 * Return pointer to first record found
 */
record_t *search_record(database_t *database, char name[]){
    for (int i = 0; i < database->n_records; ++i) {
        if (strcmp(database->records[i].name, name) == 0) {
            return &database->records[i];
        }
    }
    printf("No record found for %s\n", name);
    return NULL;
}

/*
 * Function to delete a record
 * Shift all records following the deleted record left by one
 */
void delete_record(database_t *database, int id) {
    int i;
    for (i = 0; i < database->n_records; ++i) {
        if (database->records[i].id == id) {
            break;
        }
    }
    if (i == database->n_records) {
        printf("No record found with id %d\n", id);
        return;
    }
    for (int j = i; j < database->n_records - 1; ++j) {
        database->records[j] = database->records[j+1];
    }
    database->n_records--;
}

/*
 * Function to print a record
 */
void print_record(record_t *record){
    printf("id: %d\n", record->id);
    printf("name: %s\n", record->name);
    printf("address: %s\n", record->address);
    printf("phone number: %s\n\n", record->phone_no);
}

/*
 * Function to print all records in database
 */
void print_database(database_t *database) {
    if (database->n_records == 0) {
        printf("No records in database\n");
        return;
    }
    for (int i = 0; i < database->n_records; ++i) {
        print_record(&database->records[i]);
    }
}

int main() {
    database_t *database = new_database();
    add_record(database, "John Smith", "123 Main Street", "555-1234");
    add_record(database, "Jane Doe", "456 Park Ave", "555-5678");
    add_record(database, "Bob Johnson", "789 Broadway", "555-9012");
    printf("Current Database:\n");
    print_database(database);
    printf("Searching for Bob Johnson...\n");
    record_t *record = search_record(database, "Bob Johnson");
    printf("Deleting Bob Johnson...\n");
    delete_record(database, record->id);
    printf("New Database:\n");
    print_database(database);
    return 0;
}