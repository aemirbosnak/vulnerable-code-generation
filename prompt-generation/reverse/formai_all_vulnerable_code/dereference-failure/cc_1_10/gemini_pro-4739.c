//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *next;
} node_t;

typedef struct index {
  char *key;
  node_t *list;
} index_t;

typedef struct database {
  index_t *indices;
  int num_indices;
} database_t;

database_t *create_database() {
  database_t *db = malloc(sizeof(database_t));
  db->indices = NULL;
  db->num_indices = 0;
  return db;
}

void destroy_database(database_t *db) {
  for (int i = 0; i < db->num_indices; i++) {
    index_t *index = &db->indices[i];
    free(index->key);
    node_t *node = index->list;
    while (node) {
      node_t *next = node->next;
      free(node->data);
      free(node);
      node = next;
    }
  }
  free(db->indices);
  free(db);
}

index_t *create_index(char *key) {
  index_t *index = malloc(sizeof(index_t));
  index->key = strdup(key);
  index->list = NULL;
  return index;
}

void destroy_index(index_t *index) {
  free(index->key);
  node_t *node = index->list;
  while (node) {
    node_t *next = node->next;
    free(node->data);
    free(node);
    node = next;
  }
  free(index);
}

void add_index_to_database(database_t *db, index_t *index) {
  db->indices = realloc(db->indices, sizeof(index_t) * (db->num_indices + 1));
  db->indices[db->num_indices++] = *index;
}

void add_data_to_index(index_t *index, char *data) {
  node_t *node = malloc(sizeof(node_t));
  node->data = strdup(data);
  node->next = index->list;
  index->list = node;
}

node_t *find_data_in_index(index_t *index, char *key) {
  node_t *node = index->list;
  while (node) {
    if (strcmp(node->data, key) == 0) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

void print_database(database_t *db) {
  for (int i = 0; i < db->num_indices; i++) {
    index_t *index = &db->indices[i];
    printf("%s:\n", index->key);
    node_t *node = index->list;
    while (node) {
      printf("  %s\n", node->data);
      node = node->next;
    }
  }
}

int main() {
  database_t *db = create_database();

  index_t *name_index = create_index("name");
  add_index_to_database(db, name_index);
  add_data_to_index(name_index, "John Doe");
  add_data_to_index(name_index, "Jane Doe");

  index_t *email_index = create_index("email");
  add_index_to_database(db, email_index);
  add_data_to_index(email_index, "john.doe@example.com");
  add_data_to_index(email_index, "jane.doe@example.com");

  printf("Database:\n");
  print_database(db);

  destroy_index(name_index);
  destroy_index(email_index);
  destroy_database(db);

  return 0;
}