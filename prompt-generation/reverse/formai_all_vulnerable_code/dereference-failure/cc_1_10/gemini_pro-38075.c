//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
  char *name;
  int age;
  char *occupation;
} record;

typedef struct database {
  record *records;
  int num_records;
} database;

database *create_database() {
  database *db = malloc(sizeof(database));
  db->records = NULL;
  db->num_records = 0;
  return db;
}

void add_record(database *db, char *name, int age, char *occupation) {
  db->records = realloc(db->records, (db->num_records + 1) * sizeof(record));
  record *new_record = &db->records[db->num_records];
  new_record->name = malloc(strlen(name) + 1);
  strcpy(new_record->name, name);
  new_record->age = age;
  new_record->occupation = malloc(strlen(occupation) + 1);
  strcpy(new_record->occupation, occupation);
  db->num_records++;
}

void print_database(database *db) {
  for (int i = 0; i < db->num_records; i++) {
    record *r = &db->records[i];
    printf("Name: %s\n", r->name);
    printf("Age: %d\n", r->age);
    printf("Occupation: %s\n\n", r->occupation);
  }
}

int main() {
  database *db = create_database();

  add_record(db, "Alice", 25, "Software Engineer");
  add_record(db, "Bob", 30, "Doctor");
  add_record(db, "Carol", 35, "Teacher");

  print_database(db);

  return 0;
}