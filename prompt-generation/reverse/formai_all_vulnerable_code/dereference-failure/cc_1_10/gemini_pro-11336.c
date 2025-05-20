//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple data structure to hold a data item */
typedef struct data {
  char *key;
  char *value;
} data_t;

/* A simple hash table implementation */
typedef struct hash_table {
  data_t **table;
  size_t size;
} hash_table_t;

/* Create a new hash table */
hash_table_t *hash_table_new(size_t size) {
  hash_table_t *hash_table = malloc(sizeof(hash_table_t));
  hash_table->table = malloc(sizeof(data_t *) * size);
  hash_table->size = size;
  return hash_table;
}

/* Insert a new data item into the hash table */
void hash_table_insert(hash_table_t *hash_table, char *key, char *value) {
  int index = hash_function(key) % hash_table->size;
  data_t *data = malloc(sizeof(data_t));
  data->key = key;
  data->value = value;
  hash_table->table[index] = data;
}

/* Get a data item from the hash table */
data_t *hash_table_get(hash_table_t *hash_table, char *key) {
  int index = hash_function(key) % hash_table->size;
  return hash_table->table[index];
}

/* Free the hash table */
void hash_table_free(hash_table_t *hash_table) {
  for (int i = 0; i < hash_table->size; i++) {
    free(hash_table->table[i]->key);
    free(hash_table->table[i]->value);
    free(hash_table->table[i]);
  }
  free(hash_table->table);
  free(hash_table);
}

/* A simple hash function */
int hash_function(char *key) {
  int hash = 0;
  for (int i = 0; i < strlen(key); i++) {
    hash += key[i];
  }
  return hash;
}

/* Main function */
int main() {
  /* Create a new hash table */
  hash_table_t *hash_table = hash_table_new(100);

  /* Insert some data into the hash table */
  hash_table_insert(hash_table, "key1", "value1");
  hash_table_insert(hash_table, "key2", "value2");
  hash_table_insert(hash_table, "key3", "value3");

  /* Get some data from the hash table */
  data_t *data1 = hash_table_get(hash_table, "key1");
  data_t *data2 = hash_table_get(hash_table, "key2");
  data_t *data3 = hash_table_get(hash_table, "key3");

  /* Print the data */
  printf("%s = %s\n", data1->key, data1->value);
  printf("%s = %s\n", data2->key, data2->value);
  printf("%s = %s\n", data3->key, data3->value);

  /* Free the hash table */
  hash_table_free(hash_table);

  return 0;
}