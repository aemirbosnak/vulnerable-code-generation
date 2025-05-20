//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet style digital diary

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1000

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
  char *entry;
  int length;
} diary_entry;

// Define the structure of a digital diary
typedef struct {
  diary_entry entries[MAX_ENTRIES];
  int num_entries;
} digital_diary;

// Create a new digital diary
digital_diary *create_digital_diary() {
  digital_diary *diary = malloc(sizeof(digital_diary));
  if (diary == NULL) {
    return NULL;
  }

  diary->num_entries = 0;

  return diary;
}

// Add a new entry to a digital diary
int add_entry(digital_diary *diary, char *entry, int length) {
  if (diary->num_entries >= MAX_ENTRIES) {
    return -1;
  }

  diary->entries[diary->num_entries].entry = malloc(length + 1);
  if (diary->entries[diary->num_entries].entry == NULL) {
    return -1;
  }

  strcpy(diary->entries[diary->num_entries].entry, entry);
  diary->entries[diary->num_entries].length = length;

  diary->num_entries++;

  return 0;
}

// Print a digital diary
void print_diary(digital_diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    printf("%s\n", diary->entries[i].entry);
  }
}

// Free the memory allocated for a digital diary
void free_diary(digital_diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    free(diary->entries[i].entry);
  }

  free(diary);
}

// Main function
int main() {
  // Create a new digital diary
  digital_diary *diary = create_digital_diary();

  // Add some entries to the diary
  char *entry1 = "My dearest Juliet, I have heard of thy beauty and thy wit, and I am smitten with love for thee.";
  add_entry(diary, entry1, strlen(entry1));

  char *entry2 = "O Romeo, my Romeo! Wherefore art thou Romeo? Deny thy father and refuse thy name; or, if thou wilt not, be but sworn my love, and I'll no longer be a Capulet.";
  add_entry(diary, entry2, strlen(entry2));

  // Print the diary
  print_diary(diary);

  // Free the memory allocated for the diary
  free_diary(diary);

  return 0;
}