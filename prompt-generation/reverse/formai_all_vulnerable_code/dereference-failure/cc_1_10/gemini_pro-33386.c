//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int age;
  char *occupation;
} person_t;

typedef struct {
  char *name;
  int num_people;
  person_t *people;
} table_t;

table_t *create_table(char *name) {
  table_t *table = malloc(sizeof(table_t));
  table->name = strdup(name);
  table->num_people = 0;
  table->people = NULL;
  return table;
}

void add_person(table_t *table, char *name, int age, char *occupation) {
  table->num_people++;
  table->people = realloc(table->people, sizeof(person_t) * table->num_people);
  person_t *person = &table->people[table->num_people - 1];
  person->name = strdup(name);
  person->age = age;
  person->occupation = strdup(occupation);
}

void print_table(table_t *table) {
  printf("Table %s:\n", table->name);
  for (int i = 0; i < table->num_people; i++) {
    person_t *person = &table->people[i];
    printf("  %s, %d, %s\n", person->name, person->age, person->occupation);
  }
}

void free_table(table_t *table) {
  for (int i = 0; i < table->num_people; i++) {
    person_t *person = &table->people[i];
    free(person->name);
    free(person->occupation);
  }
  free(table->people);
  free(table->name);
  free(table);
}

int main() {
  table_t *table = create_table("people");
  add_person(table, "Alice", 25, "software engineer");
  add_person(table, "Bob", 30, "doctor");
  add_person(table, "Charlie", 35, "lawyer");
  print_table(table);
  free_table(table);
  return 0;
}