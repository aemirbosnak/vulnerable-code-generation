//FormAI DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50              // maximum number of records in database
#define MAX_NAME_LENGTH 30          // maximum length of name string
#define MAX_PHONE_NUMBER_LENGTH 10  // maximum length of phone number string

// structure to hold a single record in the database
struct Record {
  char name[MAX_NAME_LENGTH];             // name of person
  char phone_number[MAX_PHONE_NUMBER_LENGTH]; // phone number of person
  struct Record *next;                    // pointer to next record in database
};

// function to add a new record to the database
void addRecord(struct Record *database, char *name, char *phone_number) {
  struct Record *new_record = malloc(sizeof(struct Record));
  strncpy(new_record->name, name, MAX_NAME_LENGTH-1);
  strncpy(new_record->phone_number, phone_number, MAX_PHONE_NUMBER_LENGTH-1);
  new_record->next = NULL;

  // find last record in database
  struct Record *last_record = database;
  while (last_record->next) {
    last_record = last_record->next;
  }

  // add new record to end of database
  last_record->next = new_record;
}

// function to print all records in the database
void printDatabase(struct Record *database) {
  printf("\nPrinting database...\n");
  struct Record *record = database->next;
  int record_count = 0;
  while (record) {
    printf("Record %d:\n", ++record_count);
    printf("  Name: %s\n", record->name);
    printf("  Phone number: %s\n", record->phone_number);
    record = record->next;
  }
}

int main() {
  // create empty database
  struct Record *database = malloc(sizeof(struct Record));
  database->name[0] = '\0';
  database->phone_number[0] = '\0';
  database->next = NULL;

  // add some records to the database
  addRecord(database, "Alice", "1234567890");
  addRecord(database, "Bob", "0987654321");
  addRecord(database, "Charlie", "5555555555");

  // print out all records in the database
  printDatabase(database);

  // free memory used by database
  struct Record *record = database;
  struct Record *next_record;
  while (record) {
    next_record = record->next;
    free(record);
    record = next_record;
  }

  return 0;
}