//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *value;
} Field;

typedef struct {
  char *table_name;
  Field *fields;
  int num_fields;
} Table;

typedef struct {
  Table *tables;
  int num_tables;
} Database;

Database *create_database() {
  Database *db = malloc(sizeof(Database));
  db->tables = NULL;
  db->num_tables = 0;
  return db;
}

void destroy_database(Database *db) {
  for (int i = 0; i < db->num_tables; i++) {
    free(db->tables[i].table_name);
    for (int j = 0; j < db->tables[i].num_fields; j++) {
      free(db->tables[i].fields[j].name);
      free(db->tables[i].fields[j].value);
    }
    free(db->tables[i].fields);
  }
  free(db->tables);
  free(db);
}

Table *create_table(const char *table_name) {
  Table *table = malloc(sizeof(Table));
  table->table_name = strdup(table_name);
  table->fields = NULL;
  table->num_fields = 0;
  return table;
}

void destroy_table(Table *table) {
  free(table->table_name);
  for (int i = 0; i < table->num_fields; i++) {
    free(table->fields[i].name);
    free(table->fields[i].value);
  }
  free(table->fields);
  free(table);
}

void add_field_to_table(Table *table, const char *field_name, const char *field_value) {
  table->fields = realloc(table->fields, (table->num_fields + 1) * sizeof(Field));
  table->fields[table->num_fields].name = strdup(field_name);
  table->fields[table->num_fields].value = strdup(field_value);
  table->num_fields++;
}

void add_table_to_database(Database *db, Table *table) {
  db->tables = realloc(db->tables, (db->num_tables + 1) * sizeof(Table));
  db->tables[db->num_tables] = *table;
  db->num_tables++;
}

Table *get_table_from_database(Database *db, const char *table_name) {
  for (int i = 0; i < db->num_tables; i++) {
    if (strcmp(db->tables[i].table_name, table_name) == 0) {
      return &db->tables[i];
    }
  }
  return NULL;
}

void print_table(Table *table) {
  printf("Table: %s\n", table->table_name);
  for (int i = 0; i < table->num_fields; i++) {
    printf("  %s: %s\n", table->fields[i].name, table->fields[i].value);
  }
}

int main() {
  Database *db = create_database();

  Table *users = create_table("users");
  add_field_to_table(users, "name", "John Doe");
  add_field_to_table(users, "email", "john.doe@example.com");
  add_table_to_database(db, users);

  Table *posts = create_table("posts");
  add_field_to_table(posts, "title", "My First Post");
  add_field_to_table(posts, "body", "This is my first post on the blog.");
  add_table_to_database(db, posts);

  Table *comments = create_table("comments");
  add_field_to_table(comments, "post_id", "1");
  add_field_to_table(comments, "user_id", "1");
  add_field_to_table(comments, "body", "This is my first comment on the post.");
  add_table_to_database(db, comments);

  print_table(users);
  print_table(posts);
  print_table(comments);

  destroy_table(users);
  destroy_table(posts);
  destroy_table(comments);
  destroy_database(db);

  return 0;
}