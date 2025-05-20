//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// File to store diary entries
#define DIARY_FILE "apocalypse_diary.txt"

// Max length of a diary entry
#define MAX_ENTRY_LEN 1024

// Get current date as a string
char *get_current_date() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *date_str = malloc(sizeof(char) * 11);
  strftime(date_str, 11, "%Y-%m-%d", tm);
  return date_str;
}

// Write a diary entry to file
void write_diary_entry(char *date, char *entry) {
  FILE *fp = fopen(DIARY_FILE, "a");
  if (fp == NULL) {
    perror("Error opening diary file");
    exit(1);
  }
  fprintf(fp, "[%s]\n%s\n\n", date, entry);
  fclose(fp);
}

// Read diary entries from file
char **read_diary_entries() {
  FILE *fp = fopen(DIARY_FILE, "r");
  if (fp == NULL) {
    perror("Error opening diary file");
    exit(1);
  }

  // Count the number of lines in the file
  int num_lines = 0;
  char c;
  while ((c = fgetc(fp)) != EOF) {
    if (c == '\n') {
      num_lines++;
    }
  }
  rewind(fp);

  // Allocate memory for the diary entries
  char **entries = malloc(sizeof(char *) * num_lines);
  for (int i = 0; i < num_lines; i++) {
    entries[i] = malloc(sizeof(char) * MAX_ENTRY_LEN);
  }

  // Read the diary entries into the array
  int i = 0;
  while (fgets(entries[i], MAX_ENTRY_LEN, fp) != NULL) {
    i++;
  }

  fclose(fp);

  return entries;
}

// Print diary entries to console
void print_diary_entries(char **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("%s\n", entries[i]);
  }
}

// Free memory allocated for diary entries
void free_diary_entries(char **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    free(entries[i]);
  }
  free(entries);
}

int main() {
  // Get the current date
  char *date = get_current_date();

  // Get the diary entry from the user
  char entry[MAX_ENTRY_LEN];
  printf("Enter your diary entry for %s:\n", date);
  fgets(entry, MAX_ENTRY_LEN, stdin);

  // Write the diary entry to file
  write_diary_entry(date, entry);

  // Read the diary entries from file
  char **entries = read_diary_entries();

  // Print the diary entries to console
  print_diary_entries(entries, 10);

  // Free the memory allocated for diary entries
  free_diary_entries(entries, 10);

  return 0;
}