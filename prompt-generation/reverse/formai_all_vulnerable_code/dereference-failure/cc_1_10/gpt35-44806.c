//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to represent a database entry
struct Contact {
    char name[50];
    char phone[20];
};

// Define a struct to represent a database table
struct Table {
    char name[50];
    int num_records;
    struct Contact* records;
};

// Function to create a new table with no records
struct Table* create_table(char* name) {
    struct Table* table = (struct Table*)malloc(sizeof(struct Table));
    strcpy(table->name, name);
    table->num_records = 0;
    table->records = NULL;
    return table;
}

// Function to add a record to a table
void add_record(struct Table* table, char* name, char* phone) {
    // Allocate memory for a new record
    struct Contact* record = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(record->name, name);
    strcpy(record->phone, phone);
    
    // Increase the size of the records array by one and add the new record
    table->num_records++;
    table->records = (struct Contact*)realloc(table->records, table->num_records * sizeof(struct Contact));
    table->records[table->num_records - 1] = *record;
}

// Function to print all of the records in a table
void print_records(struct Table* table) {
    printf("Table: %s\n", table->name);
    printf("%-20s %-20s\n", "Name", "Phone");
    for (int i = 0; i < table->num_records; i++) {
        printf("%-20s %-20s\n", table->records[i].name, table->records[i].phone);
    }
    printf("\n");
}

int main() {
    // Create a new table
    struct Table* contacts = create_table("Contacts");

    // Add some records to the table
    add_record(contacts, "John Smith", "555-1234");
    add_record(contacts, "Jane Doe", "555-5678");

    // Print all of the records in the table
    print_records(contacts);

    // Free memory used by the table and records
    free(contacts->records);
    free(contacts);

    return 0;
}