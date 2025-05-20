//FormAI DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum data size for each record
#define MAX_DATA_SIZE 100

// Define struct for database record
typedef struct {
  int id;
  char data[MAX_DATA_SIZE];
} Record;

// Define struct for database table
typedef struct {
  int num_records;
  Record **records;
} Table;

// Function to create a new record with given id and data
Record *createRecord(int id, char *data) {
  Record *record = malloc(sizeof(Record));
  record->id = id;
  strncpy(record->data, data, MAX_DATA_SIZE);
  return record;
}

// Function to create a new table with given initial capacity
Table *createTable(int capacity) {
  Table *table = malloc(sizeof(Table));
  table->num_records = 0;
  table->records = malloc(sizeof(Record *) * capacity);
  return table;
}

// Function to add a record to the table
void addRecord(Table *table, Record *record) {
  if (table->num_records < sizeof(table->records)) {
    table->records[table->num_records] = record;
    table->num_records++;
    printf("Added record with id %d\n", record->id);
  } else {
    printf("Table is full, cannot add record\n");
  }
}

// Function to find a record by id in the table
Record *findRecord(Table *table, int id) {
  for (int i = 0; i < table->num_records; i++) {
    if (table->records[i]->id == id) {
      return table->records[i];
    }
  }
  return NULL;
}

// Function to delete a record by id from the table
void deleteRecord(Table *table, int id) {
  for (int i = 0; i < table->num_records; i++) {
    if (table->records[i]->id == id) {
      free(table->records[i]);
      for (int j = i; j < table->num_records - 1; j++) {
        table->records[j] = table->records[j + 1];
      }
      table->num_records--;
      printf("Deleted record with id %d\n", id);
      return;
    }
  }
  printf("Record with id %d not found\n", id);
}

// Function to print all records in the table
void printRecords(Table *table) {
  printf("Table contains %d record(s):\n", table->num_records);
  for (int i = 0; i < table->num_records; i++) {
    printf("id: %d, data: %s\n", table->records[i]->id, table->records[i]->data);
  }
}

int main() {
  Table *table = createTable(10);
  addRecord(table, createRecord(1, "John"));
  addRecord(table, createRecord(2, "Jane"));
  Record *record = findRecord(table, 1);
  if (record) {
    printf("Found record with id %d, data: %s\n", record->id, record->data);
  } else {
    printf("Record not found\n");
  }
  deleteRecord(table, 2);
  printRecords(table);
  return 0;
}