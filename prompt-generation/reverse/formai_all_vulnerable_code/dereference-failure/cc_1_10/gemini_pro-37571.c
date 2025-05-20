//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A super serious and important database index record
struct IndexRecord {
  char *key;              // The key of the record
  int value;             // The value of the record
  struct IndexRecord *next; // The next record in the index
};

// A super serious and important database index
struct Index {
  struct IndexRecord *head; // The head of the index
};

// Create a new index record
struct IndexRecord *create_index_record(char *key, int value) {
  // Allocate memory for the new record
  struct IndexRecord *record = malloc(sizeof(struct IndexRecord));
  if (record == NULL) {
    // Oh no! We ran out of memory!
    printf("Error: Out of memory!\n");
    exit(1);
  }

  // Set the key and value of the record
  record->key = strdup(key);
  record->value = value;

  // Set the next record to NULL
  record->next = NULL;

  // Return the new record
  return record;
}

// Create a new index
struct Index *create_index() {
  // Allocate memory for the new index
  struct Index *index = malloc(sizeof(struct Index));
  if (index == NULL) {
    // Oh no! We ran out of memory!
    printf("Error: Out of memory!\n");
    exit(1);
  }

  // Set the head of the index to NULL
  index->head = NULL;

  // Return the new index
  return index;
}

// Insert a new record into the index
void insert_index_record(struct Index *index, char *key, int value) {
  // Create a new record
  struct IndexRecord *record = create_index_record(key, value);

  // Insert the record into the index
  record->next = index->head;
  index->head = record;
}

// Search for a record in the index
struct IndexRecord *search_index_record(struct Index *index, char *key) {
  // Set the current record to the head of the index
  struct IndexRecord *current = index->head;

  // Search for the record
  while (current != NULL) {
    // Check if the current record is the one we're looking for
    if (strcmp(current->key, key) == 0) {
      // Return the current record
      return current;
    }

    // Move to the next record
    current = current->next;
  }

  // The record was not found
  return NULL;
}

// Print the index
void print_index(struct Index *index) {
  // Set the current record to the head of the index
  struct IndexRecord *current = index->head;

  // Print the records
  while (current != NULL) {
    // Print the key and value of the record
    printf("%s: %d\n", current->key, current->value);

    // Move to the next record
    current = current->next;
  }
}

// Free the index
void free_index(struct Index *index) {
  // Set the current record to the head of the index
  struct IndexRecord *current = index->head;

  // Free the records
  while (current != NULL) {
    // Free the key and the record
    free(current->key);
    free(current);

    // Move to the next record
    current = current->next;
  }

  // Free the index
  free(index);
}

int main() {
  // Create a new index
  struct Index *index = create_index();

  // Insert some records into the index
  insert_index_record(index, "Bob", 42);
  insert_index_record(index, "Alice", 24);
  insert_index_record(index, "John", 30);

  // Search for a record in the index
  struct IndexRecord *record = search_index_record(index, "Bob");

  // Check if the record was found
  if (record != NULL) {
    // Print the key and value of the record
    printf("Found record: %s: %d\n", record->key, record->value);
  } else {
    // The record was not found
    printf("Record not found!\n");
  }

  // Print the index
  print_index(index);

  // Free the index
  free_index(index);

  return 0;
}