//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the file name for the diary
#define DIARY_FILE "diary.txt"

// Define the structure of a diary entry
typedef struct {
  char *date;
  char *entry;
} diary_entry;

// Create a new diary entry
diary_entry *new_diary_entry(char *date, char *entry) {
  diary_entry *new_entry = malloc(sizeof(diary_entry));
  new_entry->date = strdup(date);
  new_entry->entry = strdup(entry);
  return new_entry;
}

// Free a diary entry
void free_diary_entry(diary_entry *entry) {
  free(entry->date);
  free(entry->entry);
  free(entry);
}

// Add a diary entry to the diary
void add_diary_entry(diary_entry *entry) {
  FILE *fp = fopen(DIARY_FILE, "a");
  fprintf(fp, "%s: %s\n", entry->date, entry->entry);
  fclose(fp);
}

// Read the diary entries from the file
diary_entry **read_diary_entries(int *num_entries) {
  FILE *fp = fopen(DIARY_FILE, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_ENTRY_LENGTH];
  int num_lines = 0;
  while (fgets(line, MAX_ENTRY_LENGTH, fp) != NULL) {
    num_lines++;
  }
  fclose(fp);

  *num_entries = num_lines;
  diary_entry **entries = malloc(sizeof(diary_entry *) * num_lines);

  fp = fopen(DIARY_FILE, "r");
  int i = 0;
  while (fgets(line, MAX_ENTRY_LENGTH, fp) != NULL) {
    char *date = strtok(line, ":");
    char *entry = strtok(NULL, "\n");
    entries[i] = new_diary_entry(date, entry);
    i++;
  }
  fclose(fp);

  return entries;
}

// Free the diary entries
void free_diary_entries(diary_entry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    free_diary_entry(entries[i]);
  }
  free(entries);
}

// Print the diary entries
void print_diary_entries(diary_entry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("%s: %s\n", entries[i]->date, entries[i]->entry);
  }
}

// Main function
int main() {
  // Get the current date and time
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  char date[20];
  strftime(date, 20, "%Y-%m-%d %H:%M:%S", t);

  // Create a new diary entry
  diary_entry *entry = new_diary_entry(date, "I survived another day in this wasteland.");

  // Add the diary entry to the diary
  add_diary_entry(entry);

  // Read the diary entries from the file
  int num_entries;
  diary_entry **entries = read_diary_entries(&num_entries);

  // Print the diary entries
  print_diary_entries(entries, num_entries);

  // Free the diary entries
  free_diary_entries(entries, num_entries);

  return 0;
}