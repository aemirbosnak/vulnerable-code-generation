//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry
typedef struct diary_entry {
  time_t timestamp;
  char *entry;
} diary_entry;

// Define the structure of a digital diary
typedef struct digital_diary {
  char *name;
  int num_entries;
  diary_entry *entries;
} digital_diary;

// Create a new digital diary
digital_diary *create_digital_diary(char *name) {
  digital_diary *diary = malloc(sizeof(digital_diary));
  diary->name = strdup(name);
  diary->num_entries = 0;
  diary->entries = NULL;
  return diary;
}

// Add a new entry to a digital diary
void add_entry(digital_diary *diary, char *entry) {
  diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(diary_entry));
  diary->entries[diary->num_entries].timestamp = time(NULL);
  diary->entries[diary->num_entries].entry = strdup(entry);
  diary->num_entries++;
}

// Print a digital diary
void print_diary(digital_diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    printf("%s: %s\n", ctime(&diary->entries[i].timestamp), diary->entries[i].entry);
  }
}

// Free the memory allocated for a digital diary
void free_diary(digital_diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    free(diary->entries[i].entry);
  }
  free(diary->entries);
  free(diary->name);
  free(diary);
}

// Main function
int main() {
  // Create a new digital diary
  digital_diary *diary = create_digital_diary("My Diary");

  // Add some entries to the digital diary
  add_entry(diary, "Today was a great day!");
  add_entry(diary, "I went for a walk in the park and saw a beautiful sunset.");
  add_entry(diary, "I met a new friend and we had a great conversation.");

  // Print the digital diary
  print_diary(diary);

  // Free the memory allocated for the digital diary
  free_diary(diary);

  return 0;
}