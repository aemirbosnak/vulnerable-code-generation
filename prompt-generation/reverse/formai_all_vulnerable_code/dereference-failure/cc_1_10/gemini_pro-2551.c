//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to represent a diary entry
typedef struct diary_entry {
  char *title;
  char *body;
  time_t timestamp;
} diary_entry;

// Create a new diary entry
diary_entry* new_diary_entry(char *title, char *body) {
  diary_entry *entry = malloc(sizeof(diary_entry));
  entry->title = strdup(title);
  entry->body = strdup(body);
  entry->timestamp = time(NULL);
  return entry;
}

// Print a diary entry
void print_diary_entry(diary_entry *entry) {
  printf("Title: %s\n", entry->title);
  printf("Body: %s\n", entry->body);
  printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

// Add a new diary entry to a file
void add_diary_entry(char *filename, diary_entry *entry) {
  FILE *fp = fopen(filename, "a");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }
  fprintf(fp, "%s\n%s\n%ld\n", entry->title, entry->body, entry->timestamp);
  fclose(fp);
}

// Load all diary entries from a file
diary_entry** load_diary_entries(char *filename, int *num_entries) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Count the number of lines in the file
  int num_lines = 0;
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    num_lines++;
  }
  fclose(fp);

  // Allocate memory for the diary entries
  diary_entry **entries = malloc(sizeof(diary_entry*) * num_lines / 3);
  *num_entries = num_lines / 3;

  // Load the diary entries from the file
  fp = fopen(filename, "r");
  int i = 0;
  while (fgets(line, sizeof(line), fp)) {
    char *title = strdup(line);
    fgets(line, sizeof(line), fp);
    char *body = strdup(line);
    long timestamp = atol(line);
    entries[i++] = new_diary_entry(title, body);
  }
  fclose(fp);

  return entries;
}

// Print all diary entries
void print_diary_entries(diary_entry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    print_diary_entry(entries[i]);
    printf("\n");
  }
}

// Free all diary entries
void free_diary_entries(diary_entry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    free(entries[i]->title);
    free(entries[i]->body);
    free(entries[i]);
  }
  free(entries);
}

// Main function
int main() {
  // Create a new diary entry
  diary_entry *entry = new_diary_entry("My first diary entry", "This is my first diary entry. I'm going to write about my day.");

  // Add the diary entry to a file
  add_diary_entry("diary.txt", entry);

  // Load all diary entries from the file
  int num_entries;
  diary_entry **entries = load_diary_entries("diary.txt", &num_entries);

  // Print all diary entries
  print_diary_entries(entries, num_entries);

  // Free all diary entries
  free_diary_entries(entries, num_entries);

  return 0;
}