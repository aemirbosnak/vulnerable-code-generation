//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store a diary entry
typedef struct {
  char *date;
  char *time;
  char *entry;
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry *create_entry(char *date, char *time, char *entry) {
  DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
  new_entry->date = malloc(strlen(date) + 1);
  strcpy(new_entry->date, date);
  new_entry->time = malloc(strlen(time) + 1);
  strcpy(new_entry->time, time);
  new_entry->entry = malloc(strlen(entry) + 1);
  strcpy(new_entry->entry, entry);
  return new_entry;
}

// Function to free a diary entry
void free_entry(DiaryEntry *entry) {
  free(entry->date);
  free(entry->time);
  free(entry->entry);
  free(entry);
}

// Function to print a diary entry
void print_entry(DiaryEntry *entry) {
  printf("Date: %s\n", entry->date);
  printf("Time: %s\n", entry->time);
  printf("Entry: %s\n", entry->entry);
}

// Function to add a new diary entry to a file
void add_entry(char *filename, DiaryEntry *entry) {
  FILE *fp = fopen(filename, "a");
  fprintf(fp, "%s %s %s\n", entry->date, entry->time, entry->entry);
  fclose(fp);
}

// Function to read diary entries from a file
DiaryEntry **read_entries(char *filename, int *num_entries) {
  FILE *fp = fopen(filename, "r");

  // Count the number of entries in the file
  int count = 0;
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    count++;
  }

  // Allocate memory for the entries
  DiaryEntry **entries = malloc(sizeof(DiaryEntry *) * count);

  // Read the entries from the file
  rewind(fp);
  int i = 0;
  while (fgets(line, sizeof(line), fp)) {
    // Split the line into date, time, and entry
    char *date = strtok(line, " ");
    char *time = strtok(NULL, " ");
    char *entry = strtok(NULL, "\n");

    // Create a new entry
    entries[i] = create_entry(date, time, entry);

    // Increment the entry count
    i++;
  }

  // Close the file
  fclose(fp);

  // Set the number of entries
  *num_entries = count;

  // Return the entries
  return entries;
}

// Function to print all diary entries
void print_entries(DiaryEntry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    print_entry(entries[i]);
    printf("\n");
  }
}

// Function to free all diary entries
void free_entries(DiaryEntry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    free_entry(entries[i]);
  }
  free(entries);
}

// Main function
int main() {
  // Create a new diary entry
  DiaryEntry *entry = create_entry("2023-03-08", "10:30 PM", "Today was a great day! I went for a hike in the mountains and saw some amazing views. I also met some new people and had some great conversations. I'm feeling really grateful for all the good things in my life.");

  // Add the entry to a file
  add_entry("diary.txt", entry);

  // Read the entries from the file
  int num_entries;
  DiaryEntry **entries = read_entries("diary.txt", &num_entries);

  // Print the entries
  print_entries(entries, num_entries);

  // Free the entries
  free_entries(entries, num_entries);

  // Free the entry
  free_entry(entry);

  return 0;
}