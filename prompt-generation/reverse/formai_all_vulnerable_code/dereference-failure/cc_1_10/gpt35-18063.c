//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the database record
typedef struct {
    int id;
    char name[30];
    int age;
} Record;

// Define a struct for the database table
typedef struct {
    Record *records;
    int numRecords;
} Table;

// Initialize the table with a given number of records
void initTable(Table *table, int numRecords) {
    table->records = (Record *) malloc(numRecords * sizeof(Record));
    table->numRecords = numRecords;
    // Initialize each record with default values
    for (int i = 0; i < numRecords; i++) {
        table->records[i].id = i + 1;
        strcpy(table->records[i].name, "John Doe");
        table->records[i].age = 35;
    }
}

// Print all the records in the table
void printTable(Table *table) {
    printf("ID\tName\t\tAge\n");
    for (int i = 0; i < table->numRecords; i++) {
        printf("%d\t%s\t\t%d\n", table->records[i].id, table->records[i].name, table->records[i].age);
    }
}

// Update a record in the table with new values
void updateRecord(Table *table, int id, char *name, int age) {
    if (id > 0 && id <= table->numRecords) {
        // Subtract 1 from the ID to get the index of the record in the array
        int index = id - 1;
        strcpy(table->records[index].name, name);
        table->records[index].age = age;
    } else {
        printf("Invalid ID!\n");
    }
}

int main() {
    Table table;
    int numRecords = 5;
    initTable(&table, numRecords);
    printTable(&table);
    updateRecord(&table, 3, "Jane Smith", 28);
    printTable(&table);
    return 0;
}