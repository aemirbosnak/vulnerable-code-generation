//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a field
#define MAX_FIELD_LENGTH 255

// Define the number of fields in each record
#define NUM_FIELDS 3

// Define the types of fields in each record
typedef enum {
  FIELD_TYPE_INT,
  FIELD_TYPE_FLOAT,
  FIELD_TYPE_STRING
} field_type_t;

// Define the structure of a field
typedef struct {
  field_type_t type;
  char *value;
} field_t;

// Define the structure of a record
typedef struct {
  int id;
  field_t fields[NUM_FIELDS];
} record_t;

// Define the structure of the database
typedef struct {
  record_t records[MAX_RECORDS];
  int num_records;
} database_t;

// Create a new database
database_t *create_database() {
  database_t *db = malloc(sizeof(database_t));
  db->num_records = 0;
  return db;
}

// Add a new record to the database
void add_record(database_t *db, record_t *record) {
  db->records[db->num_records++] = *record;
}

// Find a record in the database by its id
record_t *find_record_by_id(database_t *db, int id) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      return &db->records[i];
    }
  }
  return NULL;
}

// Find records in the database by a field value
record_t **find_records_by_field_value(database_t *db, field_t *field, char *value) {
  record_t **records = malloc(sizeof(record_t *) * db->num_records);
  int num_records = 0;
  for (int i = 0; i < db->num_records; i++) {
    if (strcmp(db->records[i].fields[field->type].value, value) == 0) {
      records[num_records++] = &db->records[i];
    }
  }
  return records;
}

// Print the records in the database
void print_records(database_t *db) {
  for (int i = 0; i < db->num_records; i++) {
    printf("Record %d:\n", db->records[i].id);
    for (int j = 0; j < NUM_FIELDS; j++) {
      printf("  %s: %s\n", db->records[i].fields[j].type == FIELD_TYPE_INT ? "int" : db->records[i].fields[j].type == FIELD_TYPE_FLOAT ? "float" : "string", db->records[i].fields[j].value);
    }
  }
}

// Free the memory allocated for the database
void free_database(database_t *db) {
  for (int i = 0; i < db->num_records; i++) {
    free(db->records[i].fields);
  }
  free(db);
}

// Main function
int main() {
  // Create a new database
  database_t *db = create_database();

  // Add some records to the database
  record_t record1 = {
    .id = 1,
    .fields = {
      { .type = FIELD_TYPE_INT, .value = "1" },
      { .type = FIELD_TYPE_FLOAT, .value = "3.14" },
      { .type = FIELD_TYPE_STRING, .value = "Hello world!" }
    }
  };
  add_record(db, &record1);

  record_t record2 = {
    .id = 2,
    .fields = {
      { .type = FIELD_TYPE_INT, .value = "2" },
      { .type = FIELD_TYPE_FLOAT, .value = "2.71" },
      { .type = FIELD_TYPE_STRING, .value = "Goodbye world!" }
    }
  };
  add_record(db, &record2);

  // Find a record in the database by its id
  record_t *record = find_record_by_id(db, 1);
  if (record != NULL) {
    printf("Record found:\n");
    printf("  id: %d\n", record->id);
    printf("  int field: %s\n", record->fields[0].value);
    printf("  float field: %s\n", record->fields[1].value);
    printf("  string field: %s\n", record->fields[2].value);
  } else {
    printf("Record not found\n");
  }

  // Find records in the database by a field value
  record_t **records = find_records_by_field_value(db, &record1.fields[2], "Hello world!");
  if (records != NULL) {
    printf("Records found:\n");
    for (int i = 0; i < db->num_records; i++) {
      printf("  id: %d\n", records[i]->id);
      printf("  int field: %s\n", records[i]->fields[0].value);
      printf("  float field: %s\n", records[i]->fields[1].value);
      printf("  string field: %s\n", records[i]->fields[2].value);
    }
  } else {
    printf("Records not found\n");
  }

  // Print the records in the database
  print_records(db);

  // Free the memory allocated for the database
  free_database(db);

  return 0;
}