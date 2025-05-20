//Falcon-180B DATASET v1.0 Category: Database querying ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for a record
typedef struct Record
{
    int id;
    char name[50];
    char address[100];
    int phone;
}Record;

//Defining structure for a table
typedef struct Table
{
    Record *records;
    int num_records;
    int max_records;
}Table;

//Function to create a new table
Table *CreateTable(int max_records)
{
    Table *table = (Table*)malloc(sizeof(Table));
    table->records = (Record*)malloc(max_records*sizeof(Record));
    table->num_records = 0;
    table->max_records = max_records;
    return table;
}

//Function to add a record to the table
void AddRecord(Table *table, int id, char *name, char *address, int phone)
{
    if(table->num_records >= table->max_records)
    {
        printf("Table is full. Cannot add record.\n");
        return;
    }
    Record *record = &table->records[table->num_records];
    record->id = id;
    strcpy(record->name, name);
    strcpy(record->address, address);
    record->phone = phone;
    table->num_records++;
}

//Function to display all records in the table
void DisplayRecords(Table *table)
{
    if(table->num_records == 0)
    {
        printf("Table is empty.\n");
        return;
    }
    printf("ID\tName\tAddress\tPhone\n");
    for(int i=0; i<table->num_records; i++)
    {
        printf("%d\t%s\t%s\t%d\n", table->records[i].id, table->records[i].name, table->records[i].address, table->records[i].phone);
    }
}

//Function to search for a record by ID
Record *SearchRecordByID(Table *table, int id)
{
    for(int i=0; i<table->num_records; i++)
    {
        if(table->records[i].id == id)
        {
            return &table->records[i];
        }
    }
    return NULL;
}

//Main function
int main()
{
    Table *table = CreateTable(10);
    AddRecord(table, 1, "John Doe", "123 Main St.", 5551234);
    AddRecord(table, 2, "Jane Smith", "456 Elm St.", 5555678);
    AddRecord(table, 3, "Bob Johnson", "789 Oak St.", 5559012);
    DisplayRecords(table);
    Record *record = SearchRecordByID(table, 2);
    if(record!= NULL)
    {
        printf("Found record with ID %d:\n", record->id);
        printf("Name: %s\n", record->name);
        printf("Address: %s\n", record->address);
        printf("Phone: %d\n", record->phone);
    }
    else
    {
        printf("Record not found.\n");
    }
    return 0;
}