//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A cheerful phonebook entry
struct entry {
  char name[32];
  char number[16];
  char mood[16];
};

// A list of phonebook entries
struct phonebook {
  struct entry *entries;
  int num_entries;
};

// Create a new phonebook
struct phonebook *create_phonebook() {
  struct phonebook *pb = malloc(sizeof(struct phonebook));
  pb->entries = NULL;
  pb->num_entries = 0;
  return pb;
}

// Add an entry to the phonebook
void add_entry(struct phonebook *pb, char *name, char *number, char *mood) {
  pb->entries = realloc(pb->entries, (pb->num_entries + 1) * sizeof(struct entry));
  strcpy(pb->entries[pb->num_entries].name, name);
  strcpy(pb->entries[pb->num_entries].number, number);
  strcpy(pb->entries[pb->num_entries].mood, mood);
  pb->num_entries++;
}

// Find an entry in the phonebook by name
struct entry *find_entry(struct phonebook *pb, char *name) {
  for (int i = 0; i < pb->num_entries; i++) {
    if (strcmp(pb->entries[i].name, name) == 0) {
      return &pb->entries[i];
    }
  }
  return NULL;
}

// Print the phonebook
void print_phonebook(struct phonebook *pb) {
  for (int i = 0; i < pb->num_entries; i++) {
    printf("%s: %s (%s)\n", pb->entries[i].name, pb->entries[i].number, pb->entries[i].mood);
  }
}

// Free the phonebook
void free_phonebook(struct phonebook *pb) {
  free(pb->entries);
  free(pb);
}

// Main function
int main() {
  // Create a new phonebook
  struct phonebook *pb = create_phonebook();

  // Add some entries to the phonebook
  add_entry(pb, "Alice", "555-1212", "Happy");
  add_entry(pb, "Bob", "555-1213", "Grumpy");
  add_entry(pb, "Carol", "555-1214", "Excited");

  // Find an entry in the phonebook
  struct entry *entry = find_entry(pb, "Bob");

  // Print the entry
  printf("Found entry: %s: %s (%s)\n", entry->name, entry->number, entry->mood);

  // Print the phonebook
  print_phonebook(pb);

  // Free the phonebook
  free_phonebook(pb);

  return 0;
}