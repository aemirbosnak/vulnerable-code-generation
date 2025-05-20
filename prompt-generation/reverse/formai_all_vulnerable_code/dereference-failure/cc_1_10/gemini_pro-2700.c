//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the database
#define MAX_ENTRIES 10

// Define the structure of a database entry
typedef struct {
  char *name;
  int age;
  char *occupation;
} entry_t;

// Define the structure of the database index
typedef struct {
  char *name;
  int offset;
} index_t;

// Create a new database entry
entry_t *create_entry(char *name, int age, char *occupation) {
  entry_t *entry = malloc(sizeof(entry_t));
  entry->name = strdup(name);
  entry->age = age;
  entry->occupation = strdup(occupation);
  return entry;
}

// Create a new database index
index_t *create_index(char *name, int offset) {
  index_t *index = malloc(sizeof(index_t));
  index->name = strdup(name);
  index->offset = offset;
  return index;
}

// Add an entry to the database
void add_entry(entry_t *entry, index_t *index) {
  // Add the entry to the database
  FILE *fp = fopen("database.bin", "ab");
  fwrite(entry, sizeof(entry_t), 1, fp);
  fclose(fp);

  // Add the index to the index file
  fp = fopen("index.bin", "ab");
  fwrite(index, sizeof(index_t), 1, fp);
  fclose(fp);
}

// Search for an entry in the database using the index
entry_t *search_entry(char *name, index_t *index) {
  // Find the index entry for the name
  int i;
  for (i = 0; i < MAX_ENTRIES; i++) {
    if (strcmp(index[i].name, name) == 0) {
      break;
    }
  }

  // If the index entry was found, read the entry from the database
  if (i < MAX_ENTRIES) {
    FILE *fp = fopen("database.bin", "rb");
    fseek(fp, index[i].offset, SEEK_SET);
    entry_t *entry = malloc(sizeof(entry_t));
    fread(entry, sizeof(entry_t), 1, fp);
    fclose(fp);
    return entry;
  }

  // If the index entry was not found, return NULL
  return NULL;
}

// Print the database
void print_database(entry_t *entries, index_t *index) {
  int i;
  for (i = 0; i < MAX_ENTRIES; i++) {
    printf("%s (%d, %s)\n", entries[i].name, entries[i].age, entries[i].occupation);
  }
}

// Main function
int main() {
  // Create some sample data
  entry_t *entries[] = {
    create_entry("John Doe", 30, "Software Engineer"),
    create_entry("Jane Doe", 25, "Teacher"),
    create_entry("Bob Smith", 40, "Doctor"),
    create_entry("Alice Smith", 35, "Lawyer"),
    create_entry("Tom Jones", 28, "Accountant"),
  };

  // Create the database index
  index_t *index[] = {
    create_index("John Doe", 0),
    create_index("Jane Doe", sizeof(entry_t)),
    create_index("Bob Smith", 2 * sizeof(entry_t)),
    create_index("Alice Smith", 3 * sizeof(entry_t)),
    create_index("Tom Jones", 4 * sizeof(entry_t)),
  };

  // Add the entries to the database
  int i;
  for (i = 0; i < MAX_ENTRIES; i++) {
    add_entry(entries[i], index[i]);
  }

  // Search for an entry in the database
  entry_t *entry = search_entry("John Doe", index);

  // Print the entry
  printf("Found entry: %s (%d, %s)\n", entry->name, entry->age, entry->occupation);

  // Print the database
  print_database(entries, index);

  // Free the allocated memory
  for (i = 0; i < MAX_ENTRIES; i++) {
    free(entries[i]->name);
    free(entries[i]->occupation);
    free(entries[i]);
    free(index[i]->name);
    free(index[i]);
  }

  return 0;
}