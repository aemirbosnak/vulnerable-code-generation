//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a database record
typedef struct {
    int id;
    char name[50];
    char address[100];
    int phone;
} Record;

// Define a structure for a database table
typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Table;

// Function to create a new table
Table *CreateTable(int max_records) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->records = (Record *)malloc(max_records * sizeof(Record));
    table->num_records = 0;
    table->max_records = max_records;
    return table;
}

// Function to add a record to a table
void AddRecord(Table *table, int id, char *name, char *address, int phone) {
    if (table->num_records >= table->max_records) {
        printf("Error: Table is full.\n");
        return;
    }
    table->records[table->num_records].id = id;
    strcpy(table->records[table->num_records].name, name);
    strcpy(table->records[table->num_records].address, address);
    table->records[table->num_records].phone = phone;
    table->num_records++;
}

// Function to search for a record in a table
Record *SearchRecord(Table *table, int id) {
    for (int i = 0; i < table->num_records; i++) {
        if (table->records[i].id == id) {
            return &table->records[i];
        }
    }
    return NULL;
}

// Function to print a record
void PrintRecord(Record *record) {
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Address: %s\n", record->address);
    printf("Phone: %d\n", record->phone);
}

// Function to print all records in a table
void PrintTable(Table *table) {
    for (int i = 0; i < table->num_records; i++) {
        PrintRecord(&table->records[i]);
    }
}

int main() {
    Table *table = CreateTable(100);
    AddRecord(table, 1, "John Doe", "123 Main St.", 5551234);
    AddRecord(table, 2, "Jane Smith", "456 Elm St.", 5555678);
    PrintTable(table);
    Record *record = SearchRecord(table, 1);
    if (record!= NULL) {
        PrintRecord(record);
    }
    return 0;
}