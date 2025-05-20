//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define a macro for checking memory allocation
#define MALLOC_CHECK(ptr) \
  if (ptr == NULL) { \
    fprintf(stderr, "Memory allocation failed!\n"); \
    exit(1); \
  }

// Define a structure to represent a metadata item
typedef struct metadata_item {
  char *key;
  char *value;
} metadata_item;

// Define a structure to represent a metadata collection
typedef struct metadata_collection {
  metadata_item *items;
  int count;
  int capacity;
} metadata_collection;

// Create a new metadata collection
metadata_collection *metadata_collection_new() {
  metadata_collection *collection = malloc(sizeof(metadata_collection));
  MALLOC_CHECK(collection);

  collection->items = NULL;
  collection->count = 0;
  collection->capacity = 0;

  return collection;
}

// Free a metadata collection
void metadata_collection_free(metadata_collection *collection) {
  if (collection != NULL) {
    for (int i = 0; i < collection->count; i++) {
      free(collection->items[i].key);
      free(collection->items[i].value);
    }
    free(collection->items);
    free(collection);
  }
}

// Add a new item to a metadata collection
void metadata_collection_add(metadata_collection *collection, char *key, char *value) {
  if (collection == NULL) {
    return;
  }

  // Check if the collection needs to be resized
  if (collection->count == collection->capacity) {
    int new_capacity = collection->capacity == 0 ? 4 : collection->capacity * 2;
    metadata_item *new_items = realloc(collection->items, new_capacity * sizeof(metadata_item));
    MALLOC_CHECK(new_items);

    collection->items = new_items;
    collection->capacity = new_capacity;
  }

  // Add the new item to the collection
  collection->items[collection->count].key = strdup(key);
  collection->items[collection->count].value = strdup(value);
  collection->count++;
}

// Get the value of a metadata item by key
char *metadata_collection_get(metadata_collection *collection, char *key) {
  if (collection == NULL) {
    return NULL;
  }

  for (int i = 0; i < collection->count; i++) {
    if (strcmp(collection->items[i].key, key) == 0) {
      return collection->items[i].value;
    }
  }

  return NULL;
}

// Print a metadata collection
void metadata_collection_print(metadata_collection *collection) {
  if (collection == NULL) {
    return;
  }

  for (int i = 0; i < collection->count; i++) {
    printf("%s: %s\n", collection->items[i].key, collection->items[i].value);
  }
}

// Main function
int main() {
  // Create a new metadata collection
  metadata_collection *collection = metadata_collection_new();

  // Add some items to the collection
  metadata_collection_add(collection, "Title", "My Awesome File");
  metadata_collection_add(collection, "Author", "John Doe");
  metadata_collection_add(collection, "Description", "This is a description of my awesome file.");

  // Print the collection
  metadata_collection_print(collection);

  // Get the value of the "Author" item
  char *author = metadata_collection_get(collection, "Author");
  printf("The author of the file is: %s\n", author);

  // Free the collection
  metadata_collection_free(collection);

  return 0;
}