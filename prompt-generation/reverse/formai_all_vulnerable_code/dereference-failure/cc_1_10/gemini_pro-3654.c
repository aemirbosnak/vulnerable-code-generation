//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the maximum number of fields in a record
#define MAX_FIELDS 10

// Define the maximum length of a field
#define MAX_FIELD_LENGTH 100

// Define the type of a field
typedef enum {
  FIELD_TYPE_STRING,
  FIELD_TYPE_INTEGER,
  FIELD_TYPE_FLOAT
} field_type;

// Define the structure of a field
typedef struct {
  char *name;
  field_type type;
  int length;
} field;

// Define the structure of a record
typedef struct {
  char *data[MAX_FIELDS];
} record;

// Define the structure of the database
typedef struct {
  record records[MAX_RECORDS];
  int num_records;
  field fields[MAX_FIELDS];
  int num_fields;
} database;

// Create a new database
database *create_database() {
  database *db = malloc(sizeof(database));
  db->num_records = 0;
  db->num_fields = 0;
  return db;
}

// Add a field to the database
void add_field(database *db, char *name, field_type type, int length) {
  if (db->num_fields >= MAX_FIELDS) {
    fprintf(stderr, "Error: Too many fields\n");
    return;
  }

  field *field = &db->fields[db->num_fields++];
  field->name = strdup(name);
  field->type = type;
  field->length = length;
}

// Add a record to the database
void add_record(database *db, char **data) {
  if (db->num_records >= MAX_RECORDS) {
    fprintf(stderr, "Error: Too many records\n");
    return;
  }

  record *record = &db->records[db->num_records++];
  for (int i = 0; i < db->num_fields; i++) {
    record->data[i] = strdup(data[i]);
  }
}

// Find a record in the database by its primary key
record *find_record_by_primary_key(database *db, char *primary_key) {
  for (int i = 0; i < db->num_records; i++) {
    record *record = &db->records[i];
    if (strcmp(record->data[0], primary_key) == 0) {
      return record;
    }
  }

  return NULL;
}

// Print the database
void print_database(database *db) {
  for (int i = 0; i < db->num_records; i++) {
    record *record = &db->records[i];
    for (int j = 0; j < db->num_fields; j++) {
      printf("%s: %s\n", db->fields[j].name, record->data[j]);
    }
    printf("\n");
  }
}

// Free the memory allocated by the database
void free_database(database *db) {
  for (int i = 0; i < db->num_records; i++) {
    record *record = &db->records[i];
    for (int j = 0; j < db->num_fields; j++) {
      free(record->data[j]);
    }
  }

  for (int i = 0; i < db->num_fields; i++) {
    field *field = &db->fields[i];
    free(field->name);
  }

  free(db);
}

// Main function
int main() {
  // Create a new database
  database *db = create_database();

  // Add some fields to the database
  add_field(db, "id", FIELD_TYPE_STRING, 10);
  add_field(db, "name", FIELD_TYPE_STRING, 100);
  add_field(db, "age", FIELD_TYPE_INTEGER, 3);

  // Add some records to the database
  add_record(db, (char *[]) {"1", "John Doe", "30"});
  add_record(db, (char *[]) {"2", "Jane Doe", "25"});

  // Find a record in the database by its primary key
  record *record = find_record_by_primary_key(db, "1");

  // Print the record
  printf("Record:\n");
  for (int i = 0; i < db->num_fields; i++) {
    printf("%s: %s\n", db->fields[i].name, record->data[i]);
  }
  printf("\n");

  // Print the database
  printf("Database:\n");
  print_database(db);

  // Free the memory allocated by the database
  free_database(db);

  return 0;
}