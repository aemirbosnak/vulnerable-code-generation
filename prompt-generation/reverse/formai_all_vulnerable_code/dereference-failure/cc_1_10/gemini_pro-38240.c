//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database.
#define MAX_RECORDS 100

// Define the maximum length of a record.
#define MAX_RECORD_LENGTH 100

// Define the maximum number of fields in a record.
#define MAX_FIELDS 10

// Define the maximum length of a field.
#define MAX_FIELD_LENGTH 100

// Define the type of a field.
typedef enum {
  FIELD_TYPE_INTEGER,
  FIELD_TYPE_STRING
} field_type;

// Define the structure of a field.
typedef struct {
  field_type type;
  char *name;
  char *value;
} field;

// Define the structure of a record.
typedef struct {
  int id;
  field fields[MAX_FIELDS];
} record;

// Define the structure of the database.
typedef struct {
  record records[MAX_RECORDS];
  int num_records;
} database;

// Create a new database.
database *create_database() {
  database *db = malloc(sizeof(database));
  db->num_records = 0;
  return db;
}

// Destroy a database.
void destroy_database(database *db) {
  for (int i = 0; i < db->num_records; i++) {
    free(db->records[i].fields);
  }
  free(db);
}

// Add a record to the database.
void add_record(database *db, record *record) {
  db->records[db->num_records] = *record;
  db->num_records++;
}

// Get a record from the database by its ID.
record *get_record(database *db, int id) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      return &db->records[i];
    }
  }
  return NULL;
}

// Update a record in the database.
void update_record(database *db, record *record) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == record->id) {
      db->records[i] = *record;
      return;
    }
  }
}

// Delete a record from the database.
void delete_record(database *db, int id) {
  for (int i = 0; i < db->num_records; i++) {
    if (db->records[i].id == id) {
      for (int j = i + 1; j < db->num_records; j++) {
        db->records[j - 1] = db->records[j];
      }
      db->num_records--;
      return;
    }
  }
}

// Create a new field.
field *create_field(field_type type, char *name, char *value) {
  field *field = malloc(sizeof(field));
  field->type = type;
  field->name = strdup(name);
  field->value = strdup(value);
  return field;
}

// Destroy a field.
void destroy_field(field *field) {
  free(field->name);
  free(field->value);
  free(field);
}

// Get the value of a field as a string.
char *get_field_value_as_string(field *field) {
  if (field->type == FIELD_TYPE_INTEGER) {
    char *value = malloc(100);
    sprintf(value, "%d", *(int *) field->value);
    return value;
  } else {
    return field->value;
  }
}

// Set the value of a field from a string.
void set_field_value_from_string(field *field, char *value) {
  if (field->type == FIELD_TYPE_INTEGER) {
    *(int *) field->value = atoi(value);
  } else {
    free(field->value);
    field->value = strdup(value);
  }
}

// Create a new record.
record *create_record(int id) {
  record *record = malloc(sizeof(record));
  record->id = id;
  for (int i = 0; i < MAX_FIELDS; i++) {
    record->fields[i].type = FIELD_TYPE_INTEGER;
    record->fields[i].name = NULL;
    record->fields[i].value = NULL;
  }
  return record;
}

// Destroy a record.
void destroy_record(record *record) {
  for (int i = 0; i < MAX_FIELDS; i++) {
    destroy_field(&record->fields[i]);
  }
  free(record);
}

// Print a record to the console.
void print_record(record *record) {
  printf("ID: %d\n", record->id);
  for (int i = 0; i < MAX_FIELDS; i++) {
    if (record->fields[i].name != NULL) {
      printf("%s: %s\n", record->fields[i].name, get_field_value_as_string(&record->fields[i]));
    }
  }
}

// The main function.
int main() {
  // Create a new database.
  database *db = create_database();

  // Add some records to the database.
  record *record1 = create_record(1);
  set_field_value_from_string(&record1->fields[0], "name");
  set_field_value_from_string(&record1->fields[1], "age");
  add_record(db, record1);

  record *record2 = create_record(2);
  set_field_value_from_string(&record2->fields[0], "name");
  set_field_value_from_string(&record2->fields[1], "age");
  add_record(db, record2);

  // Get a record from the database.
  record *record3 = get_record(db, 1);

  // Update a record in the database.
  set_field_value_from_string(&record3->fields[1], "age");
  update_record(db, record3);

  // Delete a record from the database.
  delete_record(db, 2);

  // Print the records in the database.
  for (int i = 0; i < db->num_records; i++) {
    print_record(&db->records[i]);
  }

  // Destroy the database.
  destroy_database(db);

  return 0;
}