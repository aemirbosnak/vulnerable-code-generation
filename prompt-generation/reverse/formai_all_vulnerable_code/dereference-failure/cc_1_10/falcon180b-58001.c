//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a record
typedef struct Record {
    int id;
    char name[50];
    float salary;
} Record;

// Define a structure for a table
typedef struct Table {
    Record *records;
    int num_records;
    int max_records;
} Table;

// Function to create a new table
Table* create_table(int max_records) {
    Table *table = (Table*) malloc(sizeof(Table));
    table->records = (Record*) malloc(max_records * sizeof(Record));
    table->num_records = 0;
    table->max_records = max_records;
    return table;
}

// Function to add a record to a table
void add_record(Table *table, int id, char *name, float salary) {
    if (table->num_records >= table->max_records) {
        printf("Error: Table is full.\n");
        return;
    }
    Record *record = &table->records[table->num_records];
    record->id = id;
    strcpy(record->name, name);
    record->salary = salary;
    table->num_records++;
}

// Function to search for a record in a table
Record* search_record(Table *table, int id) {
    for (int i = 0; i < table->num_records; i++) {
        if (table->records[i].id == id) {
            return &table->records[i];
        }
    }
    return NULL;
}

// Function to print all records in a table
void print_records(Table *table) {
    for (int i = 0; i < table->num_records; i++) {
        printf("%d: %s - $%.2f\n", table->records[i].id, table->records[i].name, table->records[i].salary);
    }
}

int main() {
    Table *employees = create_table(100);

    add_record(employees, 1, "John Doe", 50000);
    add_record(employees, 2, "Jane Smith", 60000);
    add_record(employees, 3, "Bob Johnson", 70000);

    print_records(employees);

    Record *record = search_record(employees, 2);
    if (record!= NULL) {
        printf("Found record: %s - $%.2f\n", record->name, record->salary);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}