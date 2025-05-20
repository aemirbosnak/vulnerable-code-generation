//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The diary entry struct
typedef struct diary_entry {
  char *date;
  char *entry;
} diary_entry;

// The diary struct
typedef struct diary {
  int num_entries;
  diary_entry *entries;
} diary;

// Create a new diary
diary *create_diary() {
  diary *d = malloc(sizeof(diary));
  d->num_entries = 0;
  d->entries = NULL;
  return d;
}

// Add an entry to the diary
void add_entry(diary *d, char *date, char *entry) {
  // Reallocate the entries array if necessary
  if (d->num_entries == 0) {
    d->entries = malloc(sizeof(diary_entry));
  } else {
    d->entries = realloc(d->entries, (d->num_entries + 1) * sizeof(diary_entry));
  }

  // Copy the date and entry into the new entry
  d->entries[d->num_entries].date = strdup(date);
  d->entries[d->num_entries].entry = strdup(entry);

  // Increment the number of entries
  d->num_entries++;
}

// Print the diary
void print_diary(diary *d) {
  for (int i = 0; i < d->num_entries; i++) {
    printf("%s\n", d->entries[i].date);
    printf("%s\n\n", d->entries[i].entry);
  }
}

// Free the diary
void free_diary(diary *d) {
  for (int i = 0; i < d->num_entries; i++) {
    free(d->entries[i].date);
    free(d->entries[i].entry);
  }
  free(d->entries);
  free(d);
}

// Main function
int main() {
  // Create a new diary
  diary *d = create_diary();

  // Add some entries to the diary
  add_entry(d, "2102-01-01", "The end of the world came today. I don't know how it happened, but everything is gone. The cities are in ruins, the people are dead, and the animals are gone. I am all alone.");
  add_entry(d, "2102-01-02", "I've been wandering for days, looking for food and water. I'm starting to lose hope. I don't know how much longer I can go on like this.");
  add_entry(d, "2102-01-03", "I found a small group of survivors today. They're just as lost and scared as I am. But together, we might have a chance of making it through this.");

  // Print the diary
  print_diary(d);

  // Free the diary
  free_diary(d);

  return 0;
}