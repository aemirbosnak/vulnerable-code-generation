//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a phone book entry
typedef struct phone_book_entry {
  char *name;
  char *number;
} phone_book_entry;

// Define the maximum number of entries in the phone book
#define MAX_ENTRIES 100

// Create a new phone book entry
phone_book_entry *new_phone_book_entry(char *name, char *number) {
  phone_book_entry *entry = malloc(sizeof(phone_book_entry));
  entry->name = strdup(name);
  entry->number = strdup(number);
  return entry;
}

// Free a phone book entry
void free_phone_book_entry(phone_book_entry *entry) {
  free(entry->name);
  free(entry->number);
  free(entry);
}

// Add an entry to the phone book
void add_phone_book_entry(phone_book_entry **entries, int *num_entries, phone_book_entry *entry) {
  entries[*num_entries] = entry;
  (*num_entries)++;
}

// Find an entry in the phone book by name
phone_book_entry *find_phone_book_entry_by_name(phone_book_entry **entries, int num_entries, char *name) {
  for (int i = 0; i < num_entries; i++) {
    if (strcmp(entries[i]->name, name) == 0) {
      return entries[i];
    }
  }
  return NULL;
}

// Find an entry in the phone book by number
phone_book_entry *find_phone_book_entry_by_number(phone_book_entry **entries, int num_entries, char *number) {
  for (int i = 0; i < num_entries; i++) {
    if (strcmp(entries[i]->number, number) == 0) {
      return entries[i];
    }
  }
  return NULL;
}

// Print the phone book
void print_phone_book(phone_book_entry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("%s: %s\n", entries[i]->name, entries[i]->number);
  }
}

// Free the phone book
void free_phone_book(phone_book_entry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    free_phone_book_entry(entries[i]);
  }
  free(entries);
}

// Main function
int main() {
  // Create a new phone book
  phone_book_entry **entries = malloc(sizeof(phone_book_entry *) * MAX_ENTRIES);
  int num_entries = 0;

  // Add some entries to the phone book
  add_phone_book_entry(entries, &num_entries, new_phone_book_entry("Alice", "555-1212"));
  add_phone_book_entry(entries, &num_entries, new_phone_book_entry("Bob", "555-1213"));
  add_phone_book_entry(entries, &num_entries, new_phone_book_entry("Carol", "555-1214"));

  // Print the phone book
  printf("Phone book:\n");
  print_phone_book(entries, num_entries);

  // Find an entry in the phone book by name
  phone_book_entry *entry = find_phone_book_entry_by_name(entries, num_entries, "Bob");
  if (entry != NULL) {
    printf("Found entry: %s: %s\n", entry->name, entry->number);
  } else {
    printf("Entry not found.\n");
  }

  // Free the phone book
  free_phone_book(entries, num_entries);

  return 0;
}