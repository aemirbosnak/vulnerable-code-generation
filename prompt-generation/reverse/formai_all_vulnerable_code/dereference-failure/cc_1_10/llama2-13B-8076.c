//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: shocked
// SHOCKING DATABASE SIMULATION PROGRAM
// DO NOT ATTEMPT TO RUN THIS CODE, IT MAY CAUSE SYSTEM INSTABILITY!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GLOBAL VARIABLES
const int DATABASE_SIZE = 1000;
const int MAX_RECORD_SIZE = 100;
const char* DATABASE_NAME = "shocking_database.db";

// FUNCTION PROTOTYPES
void insert_record(int, char**, int);
void retrieve_record(int, char**, int);
void update_record(int, char**, int);
void delete_record(int, char**, int);

// FUNCTION DEFINITIONS
void insert_record(int id, char** record, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Inserting record %d: %s\n", id, record[i]);
    // SIMULATE INSERTION BY WAITING FOR 1 SECOND
    sleep(1);
  }
}

void retrieve_record(int id, char** record, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Retrieving record %d: %s\n", id, record[i]);
    // SIMULATE RETRIEVAL BY WAITING FOR 2 SECONDS
    sleep(2);
  }
}

void update_record(int id, char** record, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Updating record %d: %s\n", id, record[i]);
    // SIMULATE UPDATING BY WAITING FOR 3 SECONDS
    sleep(3);
  }
}

void delete_record(int id, char** record, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Deleting record %d: %s\n", id, record[i]);
    // SIMULATE DELETION BY WAITING FOR 4 SECONDS
    sleep(4);
  }
}

int main() {
  // CREATE THE DATABASE
  char* database = (char*)calloc(1, DATABASE_SIZE);
  for (int i = 0; i < DATABASE_SIZE; i++) {
    database[i] = ' ';
  }

  // INSERT RECORDS
  for (int i = 0; i < 10; i++) {
    insert_record(i, (char**)calloc(1, MAX_RECORD_SIZE), MAX_RECORD_SIZE);
  }

  // RETRIEVE RECORDS
  for (int i = 0; i < 10; i++) {
    retrieve_record(i, (char**)calloc(1, MAX_RECORD_SIZE), MAX_RECORD_SIZE);
  }

  // UPDATE RECORDS
  for (int i = 0; i < 10; i++) {
    update_record(i, (char**)calloc(1, MAX_RECORD_SIZE), MAX_RECORD_SIZE);
  }

  // DELETE RECORDS
  for (int i = 0; i < 10; i++) {
    delete_record(i, (char**)calloc(1, MAX_RECORD_SIZE), MAX_RECORD_SIZE);
  }

  // CLEAN UP
  free(database);

  return 0;
}