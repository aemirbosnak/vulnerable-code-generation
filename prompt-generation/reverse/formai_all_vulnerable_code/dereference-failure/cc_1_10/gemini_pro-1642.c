//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the structure of a diary entry
typedef struct diary_entry {
  time_t timestamp;
  char *text;
} diary_entry;

// Create a new diary entry
diary_entry *create_entry(time_t timestamp, char *text) {
  diary_entry *entry = malloc(sizeof(diary_entry));
  entry->timestamp = timestamp;
  entry->text = strdup(text);
  return entry;
}

// Free the memory allocated for a diary entry
void free_entry(diary_entry *entry) {
  free(entry->text);
  free(entry);
}

// Print a diary entry
void print_entry(diary_entry *entry) {
  printf("%s\n", ctime(&entry->timestamp));
  printf("%s\n", entry->text);
}

// Add a new entry to the diary
void add_entry(diary_entry **entries, int *num_entries, diary_entry *entry) {
  *entries = realloc(*entries, (*num_entries + 1) * sizeof(diary_entry));
  (*entries)[*num_entries] = *entry;
  (*num_entries)++;
}

// Load the diary entries from a file
int load_entries(diary_entry **entries, int *num_entries, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  char line[MAX_ENTRY_LENGTH];
  while (fgets(line, MAX_ENTRY_LENGTH, fp)) {
    time_t timestamp = atoi(strtok(line, ","));
    char *text = strtok(NULL, ",");

    diary_entry *entry = create_entry(timestamp, text);
    add_entry(entries, num_entries, entry);
  }

  fclose(fp);

  return 0;
}

// Save the diary entries to a file
int save_entries(diary_entry *entries, int num_entries, char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    return -1;
  }

  for (int i = 0; i < num_entries; i++) {
    fprintf(fp, "%ld,%s\n", entries[i].timestamp, entries[i].text);
  }

  fclose(fp);

  return 0;
}

// Get the current date and time
time_t get_current_time() {
  time_t now = time(NULL);
  return now;
}

// Main function
int main() {
  // Define the diary entries array
  diary_entry *entries = NULL;

  // Define the number of diary entries
  int num_entries = 0;

  // Load the diary entries from a file
  int result = load_entries(&entries, &num_entries, "diary.txt");
  if (result != 0) {
    printf("Error loading diary entries from file\n");
    return 1;
  }

  // Get the current date and time
  time_t now = get_current_time();

  // Create a new diary entry
  diary_entry *entry = create_entry(now, "This is a new diary entry");

  // Add the new entry to the diary
  add_entry(&entries, &num_entries, entry);

  // Print the diary entries
  for (int i = 0; i < num_entries; i++) {
    print_entry(&entries[i]);
  }

  // Save the diary entries to a file
  result = save_entries(entries, num_entries, "diary.txt");
  if (result != 0) {
    printf("Error saving diary entries to file\n");
    return 1;
  }

  // Free the memory allocated for the diary entries
  for (int i = 0; i < num_entries; i++) {
    free_entry(&entries[i]);
  }
  free(entries);

  return 0;
}