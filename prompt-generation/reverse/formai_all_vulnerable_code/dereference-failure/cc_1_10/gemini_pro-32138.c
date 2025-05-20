//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *type;
  int size;
} Field;

typedef struct {
  char *name;
  Field *fields;
  int numFields;
} Table;

typedef struct {
  Table *tables;
  int numTables;
} Database;

Database *createDatabase() {
  Database *db = malloc(sizeof(Database));
  db->tables = NULL;
  db->numTables = 0;
  return db;
}

void destroyDatabase(Database *db) {
  for (int i = 0; i < db->numTables; i++) {
    free(db->tables[i].name);
    for (int j = 0; j < db->tables[i].numFields; j++) {
      free(db->tables[i].fields[j].name);
      free(db->tables[i].fields[j].type);
    }
    free(db->tables[i].fields);
  }
  free(db->tables);
  free(db);
}

Table *createTable(Database *db, char *name) {
  Table *table = malloc(sizeof(Table));
  table->name = malloc(strlen(name) + 1);
  strcpy(table->name, name);
  table->fields = NULL;
  table->numFields = 0;
  db->tables = realloc(db->tables, (db->numTables + 1) * sizeof(Table));
  db->tables[db->numTables++] = *table;
  return table;
}

void destroyTable(Table *table) {
  free(table->name);
  for (int i = 0; i < table->numFields; i++) {
    free(table->fields[i].name);
    free(table->fields[i].type);
  }
  free(table->fields);
  free(table);
}

Field *addField(Table *table, char *name, char *type, int size) {
  Field *field = malloc(sizeof(Field));
  field->name = malloc(strlen(name) + 1);
  strcpy(field->name, name);
  field->type = malloc(strlen(type) + 1);
  strcpy(field->type, type);
  field->size = size;
  table->fields = realloc(table->fields, (table->numFields + 1) * sizeof(Field));
  table->fields[table->numFields++] = *field;
  return field;
}

void destroyField(Field *field) {
  free(field->name);
  free(field->type);
  free(field);
}

int main() {
  Database *db = createDatabase();
  Table *table = createTable(db, "users");
  addField(table, "id", "int", 4);
  addField(table, "name", "char", 255);
  addField(table, "email", "char", 255);
  addField(table, "password", "char", 255);
  addField(table, "created_at", "datetime", 0);
  addField(table, "updated_at", "datetime", 0);
  destroyTable(table);
  destroyDatabase(db);
  return 0;
}