//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

//Define the structure of the database
typedef struct {
    int id;
    char name[50];
    char address[100];
    int age;
} Record;

//Define the structure of the table
typedef struct {
    Record **records;
    int num_records;
    int max_records;
} Table;

//Function to initialize an empty table
Table* create_table(int max_records) {
    Table *table = (Table*) malloc(sizeof(Table));
    table->records = (Record**) malloc(max_records * sizeof(Record*));
    table->num_records = 0;
    table->max_records = max_records;
    return table;
}

//Function to add a record to the table
void add_record(Table *table, Record *record) {
    if (table->num_records == table->max_records) {
        printf("Table is full!\n");
        return;
    }
    table->records[table->num_records] = record;
    table->num_records++;
}

//Function to search for a record in the table
Record* search_record(Table *table, int id) {
    int i;
    for (i = 0; i < table->num_records; i++) {
        if (table->records[i]->id == id) {
            return table->records[i];
        }
    }
    return NULL;
}

//Function to delete a record from the table
void delete_record(Table *table, int id) {
    Record *record = search_record(table, id);
    if (record == NULL) {
        printf("Record not found!\n");
        return;
    }
    free(record);
    table->num_records--;
}

//Function to display all records in the table
void display_records(Table *table) {
    int i;
    for (i = 0; i < table->num_records; i++) {
        printf("ID: %d\nName: %s\nAddress: %s\nAge: %d\n", table->records[i]->id, table->records[i]->name, table->records[i]->address, table->records[i]->age);
    }
}

int main() {
    Table *table = create_table(10);
    Record record1 = {1, "John Doe", "123 Main St.", 25};
    Record record2 = {2, "Jane Doe", "456 Elm St.", 30};
    add_record(table, &record1);
    add_record(table, &record2);
    display_records(table);
    Record *record3 = search_record(table, 1);
    if (record3!= NULL) {
        delete_record(table, 1);
    }
    display_records(table);
    return 0;
}