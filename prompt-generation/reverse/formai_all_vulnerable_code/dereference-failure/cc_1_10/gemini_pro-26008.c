//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: distributed
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_KEYS 10

typedef struct node {
  int num_keys;
  int keys[MAX_KEYS];
  struct node *children[MAX_KEYS + 1];
} node_t;

typedef struct database {
  node_t *root;
  int num_nodes;
} database_t;

node_t *create_node() {
  node_t *node = malloc(sizeof(node_t));
  node->num_keys = 0;
  for (int i = 0; i < MAX_KEYS + 1; i++) {
    node->children[i] = NULL;
  }
  return node;
}

database_t *create_database() {
  database_t *database = malloc(sizeof(database_t));
  database->root = create_node();
  database->num_nodes = 1;
  return database;
}

void insert_key(database_t *database, int key) {
  node_t *current_node = database->root;
  while (current_node != NULL) {
    if (current_node->num_keys < MAX_KEYS) {
      // Insert the key into the current node
      int i = current_node->num_keys;
      while (i > 0 && key < current_node->keys[i - 1]) {
        current_node->keys[i] = current_node->keys[i - 1];
        current_node->children[i + 1] = current_node->children[i];
        i--;
      }
      current_node->keys[i] = key;
      current_node->children[i + 1] = create_node();
      current_node->num_keys++;
      return;
    } else {
      // Split the current node
      node_t *new_node = create_node();
      int median_key = current_node->keys[MAX_KEYS / 2];
      for (int i = MAX_KEYS / 2 + 1; i < MAX_KEYS; i++) {
        new_node->keys[i - (MAX_KEYS / 2 + 1)] = current_node->keys[i];
        new_node->children[i - (MAX_KEYS / 2 + 1)] = current_node->children[i];
        current_node->num_keys--;
      }
      new_node->children[MAX_KEYS / 2 + 1] = current_node->children[MAX_KEYS];
      current_node->children[MAX_KEYS] = new_node;

      if (key < median_key) {
        current_node = current_node->children[key];
      } else {
        current_node = new_node->children[key - (MAX_KEYS / 2 + 1)];
      }
    }
  }
}

bool search_key(database_t *database, int key) {
  node_t *current_node = database->root;
  while (current_node != NULL) {
    int i = 0;
    while (i < current_node->num_keys && key >= current_node->keys[i]) {
      i++;
    }
    if (i < current_node->num_keys && key == current_node->keys[i]) {
      return true;
    } else {
      current_node = current_node->children[i];
    }
  }
  return false;
}

void print_database(database_t *database) {
  node_t *current_node = database->root;
  while (current_node != NULL) {
    for (int i = 0; i < current_node->num_keys; i++) {
      printf("%d ", current_node->keys[i]);
    }
    printf("\n");
    for (int i = 0; i < current_node->num_keys + 1; i++) {
      print_database(current_node->children[i]);
    }
    current_node = current_node->children[current_node->num_keys];
  }
}

void free_database(database_t *database) {
  node_t *current_node = database->root;
  while (current_node != NULL) {
    node_t *next_node = current_node->children[current_node->num_keys];
    for (int i = 0; i < current_node->num_keys + 1; i++) {
      free_database(current_node->children[i]);
    }
    free(current_node);
    current_node = next_node;
  }
}

int main() {
  database_t *database = create_database();

  insert_key(database, 10);
  insert_key(database, 20);
  insert_key(database, 30);
  insert_key(database, 40);
  insert_key(database, 50);

  printf("Database:\n");
  print_database(database);

  printf("Searching for key 30: %s\n", search_key(database, 30) ? "true" : "false");

  free_database(database);

  return 0;
}