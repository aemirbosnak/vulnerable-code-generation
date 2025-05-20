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
  char *entry;
} diary_entry;

// Create a new diary entry
diary_entry *new_diary_entry(char *entry) {
  diary_entry *new_entry = malloc(sizeof(diary_entry));
  new_entry->timestamp = time(NULL);
  new_entry->entry = strdup(entry);
  return new_entry;
}

// Free a diary entry
void free_diary_entry(diary_entry *entry) {
  free(entry->entry);
  free(entry);
}

// Add a new diary entry to a file
void add_diary_entry(char *filename, diary_entry *entry) {
  FILE *fp = fopen(filename, "a");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }
  fprintf(fp, "%ld:%s\n", entry->timestamp, entry->entry);
  fclose(fp);
}

// Print the contents of a diary file
void print_diary(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }
  char line[MAX_ENTRY_LENGTH];
  while (fgets(line, MAX_ENTRY_LENGTH, fp) != NULL) {
    // Parse the line
    char *timestamp_str = strtok(line, ":");
    char *entry = strtok(NULL, "\n");
    // Convert the timestamp to a time_t
    time_t timestamp = atol(timestamp_str);
    // Print the entry
    printf("%s: %s\n", ctime(&timestamp), entry);
  }
  fclose(fp);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user provided a filename
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the filename
  char *filename = argv[1];

  // Create a new diary entry
  char *entry = "Dear Diary,\n\nToday was a great day! I woke up feeling refreshed and went for a walk in the park. The birds were singing and the sun was shining. I felt so happy and at peace.\n\nAfter my walk, I came home and wrote some poetry. I'm really enjoying writing poetry and I think I'm getting better at it. I'm so grateful for my life and all the wonderful things in it.\n\nLove,\nMe";
  diary_entry *new_entry = new_diary_entry(entry);

  // Add the new entry to the file
  add_diary_entry(filename, new_entry);

  // Print the contents of the diary
  print_diary(filename);

  // Free the diary entry
  free_diary_entry(new_entry);

  return EXIT_SUCCESS;
}