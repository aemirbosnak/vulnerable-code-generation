//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry
typedef struct diary_entry {
  char *date;
  char *entry;
} diary_entry_t;

// Define the structure of a digital diary
typedef struct digital_diary {
  char *name;
  int num_entries;
  diary_entry_t *entries;
} digital_diary_t;

// Create a new digital diary
digital_diary_t *create_digital_diary(char *name) {
  digital_diary_t *diary = malloc(sizeof(digital_diary_t));
  diary->name = strdup(name);
  diary->num_entries = 0;
  diary->entries = NULL;
  return diary;
}

// Add a new entry to a digital diary
void add_entry(digital_diary_t *diary, char *date, char *entry) {
  // Allocate memory for the new entry
  diary_entry_t *new_entry = malloc(sizeof(diary_entry_t));

  // Copy the date and entry into the new entry
  new_entry->date = strdup(date);
  new_entry->entry = strdup(entry);

  // Add the new entry to the diary
  diary->entries = realloc(diary->entries, (diary->num_entries + 1) * sizeof(diary_entry_t));
  diary->entries[diary->num_entries++] = *new_entry;
}

// Print a digital diary
void print_digital_diary(digital_diary_t *diary) {
  printf("Digital Diary: %s\n", diary->name);
  for (int i = 0; i < diary->num_entries; i++) {
    printf("Entry %d:\n", i + 1);
    printf("Date: %s\n", diary->entries[i].date);
    printf("Entry: %s\n", diary->entries[i].entry);
  }
}

// Free the memory allocated for a digital diary
void free_digital_diary(digital_diary_t *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    free(diary->entries[i].date);
    free(diary->entries[i].entry);
  }
  free(diary->entries);
  free(diary->name);
  free(diary);
}

// Main function
int main() {
  // Create a new digital diary
  digital_diary_t *diary = create_digital_diary("Romeo and Juliet");

  // Add some entries to the diary
  add_entry(diary, "1597-07-13", "My dearest Juliet, I have heard from my cousin, Benvolio, that you are to be wed to Paris. I am heartbroken, my love. I cannot bear the thought of living without you.");
  add_entry(diary, "1597-07-14", "Oh, Romeo, my love, I know not what to do. I do not love Paris, but I fear my father's wrath if I disobey him.");
  add_entry(diary, "1597-07-15", "My love, we must elope. We cannot bear to be parted. I will send my servant, Friar Laurence, to you with a plan.");

  // Print the digital diary
  print_digital_diary(diary);

  // Free the memory allocated for the digital diary
  free_digital_diary(diary);

  return 0;
}