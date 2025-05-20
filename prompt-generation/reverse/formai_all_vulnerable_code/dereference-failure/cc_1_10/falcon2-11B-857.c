//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold database record
struct Record
{
    char name[50];
    int age;
    double salary;
};

// Structure to hold database table
struct Table
{
    int rows;
    int columns;
    struct Record *records;
};

// Function to initialize a table
void initializeTable(struct Table *table)
{
    table->rows = 0;
    table->columns = 3;
    table->records = malloc(sizeof(struct Record) * table->rows);
}

// Function to add a record to the table
void addRecord(struct Table *table, char *name, int age, double salary)
{
    if (table->rows >= table->columns)
    {
        printf("Table is full. Cannot add more records.\n");
        return;
    }

    strcpy(table->records[table->rows].name, name);
    table->records[table->rows].age = age;
    table->records[table->rows].salary = salary;

    table->rows++;
}

// Function to print all records in the table
void printRecords(struct Table *table)
{
    if (table->rows == 0)
    {
        printf("Table is empty.\n");
        return;
    }

    for (int i = 0; i < table->rows; i++)
    {
        printf("%s, %d, %.2f\n", table->records[i].name, table->records[i].age, table->records[i].salary);
    }
}

int main()
{
    struct Table table;
    initializeTable(&table);

    // Add records to the table
    addRecord(&table, "John Doe", 30, 5000);
    addRecord(&table, "Jane Smith", 25, 4000);
    addRecord(&table, "Bob Johnson", 35, 6000);

    printf("Records in the table:\n");
    printRecords(&table);

    return 0;
}