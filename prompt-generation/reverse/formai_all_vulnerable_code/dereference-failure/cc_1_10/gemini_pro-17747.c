//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct diary_entry {
  char date[11];
  char time[9];
  char entry[MAX_ENTRY_LENGTH];
} diary_entry;

// Define the structure of the digital diary
typedef struct digital_diary {
  diary_entry entries[MAX_ENTRIES];
  int num_entries;
} digital_diary;

// Create a new digital diary
digital_diary* create_digital_diary() {
  digital_diary* diary = malloc(sizeof(digital_diary));
  diary->num_entries = 0;
  return diary;
}

// Add a new entry to the digital diary
void add_entry(digital_diary* diary, char* date, char* time, char* entry) {
  if (diary->num_entries >= MAX_ENTRIES) {
    printf("Error: cannot add more entries to the diary.\n");
    return;
  }

  strcpy(diary->entries[diary->num_entries].date, date);
  strcpy(diary->entries[diary->num_entries].time, time);
  strcpy(diary->entries[diary->num_entries].entry, entry);
  diary->num_entries++;
}

// Print the digital diary
void print_diary(digital_diary* diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    printf("Entry %d:\n", i + 1);
    printf("Date: %s\n", diary->entries[i].date);
    printf("Time: %s\n", diary->entries[i].time);
    printf("Entry: %s\n\n", diary->entries[i].entry);
  }
}

// Delete the digital diary
void delete_diary(digital_diary* diary) {
  free(diary);
}

// Main function
int main() {
  // Create a new digital diary
  digital_diary* diary = create_digital_diary();

  // Add some entries to the diary
  add_entry(diary, "2023-01-01", "09:00", "Dear diary, today is a new year. I'm so excited about what the future holds.");
  add_entry(diary, "2023-01-02", "12:00", "Dear diary, I had a great lunch with my friends today. We laughed and talked for hours.");
  add_entry(diary, "2023-01-03", "17:00", "Dear diary, I'm feeling really stressed about my upcoming exams. I'm not sure if I'm going to be able to pass.");
  add_entry(diary, "2023-01-04", "21:00", "Dear diary, I'm so happy! I got a promotion at work today. I'm so grateful for this opportunity.");

  // Print the digital diary
  print_diary(diary);

  // Delete the digital diary
  delete_diary(diary);

  return 0;
}