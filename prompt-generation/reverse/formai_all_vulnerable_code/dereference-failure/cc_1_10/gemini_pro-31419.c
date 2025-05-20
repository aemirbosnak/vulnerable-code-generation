//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the location of the diary file
#define DIARY_FILE "/tmp/diary.txt"

// Create a new diary entry
void create_entry(char *entry) {
  // Get the current time
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  // Open the diary file
  FILE *fp = fopen(DIARY_FILE, "a");
  if (fp == NULL) {
    perror("Error opening diary file");
    exit(1);
  }

  // Write the entry to the file
  fprintf(fp, "%s %02d/%02d/%04d %02d:%02d:%02d\n", entry, tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);

  // Close the file
  fclose(fp);
}

// Read the diary entries
void read_entries() {
  // Open the diary file
  FILE *fp = fopen(DIARY_FILE, "r");
  if (fp == NULL) {
    perror("Error opening diary file");
    exit(1);
  }

  // Read the entries from the file
  char line[MAX_ENTRY_LENGTH];
  while (fgets(line, MAX_ENTRY_LENGTH, fp)) {
    // Print the entry
    printf("%s", line);
  }

  // Close the file
  fclose(fp);
}

// Delete the diary entries
void delete_entries() {
  // Open the diary file
  FILE *fp = fopen(DIARY_FILE, "w");
  if (fp == NULL) {
    perror("Error opening diary file");
    exit(1);
  }

  // Close the file
  fclose(fp);
}

// Main function
int main() {
  // Create a new entry
  create_entry("Hello, world!");

  // Read the entries
  read_entries();

  // Delete the entries
  delete_entries();

  return 0;
}