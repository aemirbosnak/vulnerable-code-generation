//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a database record
typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[20];
} Record;

// Define the structure of a database table
typedef struct {
    Record *records;
    int count;
    int capacity;
} Table;

// Create a new database table
Table *create_table(int capacity) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->records = (Record *)malloc(capacity * sizeof(Record));
    table->count = 0;
    table->capacity = capacity;
    return table;
}

// Add a record to the table
void add_record(Table *table, int id, char *name, char *address, char *phone) {
    if (table->count >= table->capacity) {
        printf("Table is full.\n");
        return;
    }
    table->records[table->count].id = id;
    strcpy(table->records[table->count].name, name);
    strcpy(table->records[table->count].address, address);
    strcpy(table->records[table->count].phone, phone);
    table->count++;
}

// Search for a record in the table
Record *search_record(Table *table, int id) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (table->records[i].id == id) {
            return &table->records[i];
        }
    }
    return NULL;
}

// Print the contents of the table
void print_table(Table *table) {
    int i;
    for (i = 0; i < table->count; i++) {
        printf("ID: %d\nName: %s\nAddress: %s\nPhone: %s\n", table->records[i].id, table->records[i].name, table->records[i].address, table->records[i].phone);
    }
}

// Main function
int main() {
    Table *table = create_table(10);
    add_record(table, 1, "John Doe", "123 Main St.", "555-1234");
    add_record(table, 2, "Jane Smith", "456 Maple Ave.", "555-5678");
    add_record(table, 3, "Bob Johnson", "789 Oak St.", "555-9012");
    print_table(table);
    Record *record = search_record(table, 2);
    if (record!= NULL) {
        printf("Found record with ID %d:\n", record->id);
        printf("Name: %s\n", record->name);
        printf("Address: %s\n", record->address);
        printf("Phone: %s\n", record->phone);
    } else {
        printf("Record not found.\n");
    }
    return 0;
}