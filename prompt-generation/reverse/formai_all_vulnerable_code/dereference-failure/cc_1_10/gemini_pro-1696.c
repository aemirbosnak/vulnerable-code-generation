//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
  char *key;
  char *value;
  struct Record *next;
};

struct Database {
  struct Record *head;
};

struct Database *new_database() {
  struct Database *db = malloc(sizeof(struct Database));
  db->head = NULL;
  return db;
}

void insert_record(struct Database *db, char *key, char *value) {
  struct Record *new_record = malloc(sizeof(struct Record));
  new_record->key = strdup(key);
  new_record->value = strdup(value);
  new_record->next = db->head;
  db->head = new_record;
}

char *get_record(struct Database *db, char *key) {
  struct Record *current = db->head;
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }
  return NULL;
}

void delete_record(struct Database *db, char *key) {
  struct Record *current = db->head;
  struct Record *previous = NULL;
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      if (previous == NULL) {
        db->head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->key);
      free(current->value);
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void print_database(struct Database *db) {
  struct Record *current = db->head;
  while (current != NULL) {
    printf("%s: %s\n", current->key, current->value);
    current = current->next;
  }
}

void free_database(struct Database *db) {
  struct Record *current = db->head;
  while (current != NULL) {
    struct Record *next = current->next;
    free(current->key);
    free(current->value);
    free(current);
    current = next;
  }
  free(db);
}

int main() {
  struct Database *db = new_database();
  insert_record(db, "name", "John Doe");
  insert_record(db, "age", "30");
  insert_record(db, "city", "New York");
  printf("Name: %s\n", get_record(db, "name"));
  printf("Age: %s\n", get_record(db, "age"));
  printf("City: %s\n", get_record(db, "city"));
  delete_record(db, "age");
  printf("Age after deletion: %s\n", get_record(db, "age"));
  print_database(db);
  free_database(db);
  return 0;
}