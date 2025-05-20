//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the struct for the mailing list entry
typedef struct {
  char *name;
  char *email;
} mailing_list_entry;

// Declare the struct for the mailing list
typedef struct {
  mailing_list_entry *entries;
  int num_entries;
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list() {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->entries = NULL;
  list->num_entries = 0;
  return list;
}

// Free a mailing list
void free_mailing_list(mailing_list *list) {
  for (int i = 0; i < list->num_entries; i++) {
    free(list->entries[i].name);
    free(list->entries[i].email);
  }
  free(list->entries);
  free(list);
}

// Add an entry to a mailing list
void add_entry_to_mailing_list(mailing_list *list, char *name, char *email) {
  list->entries = realloc(list->entries, (list->num_entries + 1) * sizeof(mailing_list_entry));
  list->entries[list->num_entries].name = strdup(name);
  list->entries[list->num_entries].email = strdup(email);
  list->num_entries++;
}

// Remove an entry from a mailing list
void remove_entry_from_mailing_list(mailing_list *list, int index) {
  if (index < 0 || index >= list->num_entries) {
    return;
  }
  // Shift the entries after the one we're removing to the left
  for (int i = index + 1; i < list->num_entries; i++) {
    list->entries[i - 1] = list->entries[i];
  }
  // Free the memory for the entry we're removing
  free(list->entries[index].name);
  free(list->entries[index].email);
  // Decrement the number of entries in the list
  list->num_entries--;
}

// Print a mailing list
void print_mailing_list(mailing_list *list) {
  for (int i = 0; i < list->num_entries; i++) {
    printf("%s: %s\n", list->entries[i].name, list->entries[i].email);
  }
}

// Get the index of an entry in a mailing list by name
int get_entry_index_by_name(mailing_list *list, char *name) {
  for (int i = 0; i < list->num_entries; i++) {
    if (strcmp(list->entries[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Get the index of an entry in a mailing list by email
int get_entry_index_by_email(mailing_list *list, char *email) {
  for (int i = 0; i < list->num_entries; i++) {
    if (strcmp(list->entries[i].email, email) == 0) {
      return i;
    }
  }
  return -1;
}

// Main function
int main() {
  // Create a new mailing list
  mailing_list *list = create_mailing_list();

  // Add some entries to the mailing list
  add_entry_to_mailing_list(list, "John Doe", "johndoe@example.com");
  add_entry_to_mailing_list(list, "Jane Doe", "janedoe@example.com");

  // Print the mailing list
  print_mailing_list(list);

  // Get the index of an entry in the mailing list by name
  int index = get_entry_index_by_name(list, "John Doe");
  printf("The index of John Doe in the mailing list is %d\n", index);

  // Get the index of an entry in the mailing list by email
  index = get_entry_index_by_email(list, "janedoe@example.com");
  printf("The index of Jane Doe in the mailing list is %d\n", index);

  // Remove an entry from the mailing list
  remove_entry_from_mailing_list(list, 1);

  // Print the mailing list again
  print_mailing_list(list);

  // Free the mailing list
  free_mailing_list(list);

  return 0;
}