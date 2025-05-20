//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_SIZE 1000000

// Structure to hold a single log entry
typedef struct {
  char *timestamp;
  char *level;
  char *message;
} log_entry;

// Function to read a log file into an array of log entries
int read_log_file(char *filename, log_entry *log_entries) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening log file");
    return -1;
  }

  int i = 0;
  char line[MAX_LOG_SIZE];
  while (fgets(line, MAX_LOG_SIZE, fp) != NULL) {
    // Parse the timestamp, level, and message from the log line
    char *timestamp = strtok(line, "|");
    char *level = strtok(NULL, "|");
    char *message = strtok(NULL, "|");

    // Allocate memory for the timestamp, level, and message
    log_entries[i].timestamp = malloc(strlen(timestamp) + 1);
    log_entries[i].level = malloc(strlen(level) + 1);
    log_entries[i].message = malloc(strlen(message) + 1);

    // Copy the timestamp, level, and message into the log entry
    strcpy(log_entries[i].timestamp, timestamp);
    strcpy(log_entries[i].level, level);
    strcpy(log_entries[i].message, message);

    i++;
  }

  fclose(fp);
  return i;
}

// Function to free the memory allocated for an array of log entries
void free_log_entries(log_entry *log_entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    free(log_entries[i].timestamp);
    free(log_entries[i].level);
    free(log_entries[i].message);
  }
}

// Function to print an array of log entries
void print_log_entries(log_entry *log_entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("%s | %s | %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
  }
}

// Function to filter an array of log entries by level
int filter_log_entries(log_entry *log_entries, int num_entries, char *level) {
  int num_filtered_entries = 0;

  for (int i = 0; i < num_entries; i++) {
    if (strcmp(log_entries[i].level, level) == 0) {
      num_filtered_entries++;
    }
  }

  return num_filtered_entries;
}

// Function to sort an array of log entries by timestamp
void sort_log_entries(log_entry *log_entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    for (int j = 0; j < num_entries - 1; j++) {
      if (strcmp(log_entries[j].timestamp, log_entries[j + 1].timestamp) > 0) {
        log_entry temp = log_entries[j];
        log_entries[j] = log_entries[j + 1];
        log_entries[j + 1] = temp;
      }
    }
  }
}

int main() {
  // Allocate memory for an array of log entries
  log_entry *log_entries = malloc(MAX_LOG_SIZE * sizeof(log_entry));

  // Read the log file into the array of log entries
  int num_entries = read_log_file("log.txt", log_entries);

  // Print the log entries
  printf("All log entries:\n");
  print_log_entries(log_entries, num_entries);

  // Filter the log entries by level
  char *level = "ERROR";
  int num_filtered_entries = filter_log_entries(log_entries, num_entries, level);

  // Print the filtered log entries
  printf("\nFiltered log entries (level=%s):\n", level);
  print_log_entries(log_entries, num_filtered_entries);

  // Sort the log entries by timestamp
  sort_log_entries(log_entries, num_entries);

  // Print the sorted log entries
  printf("\nSorted log entries:\n");
  print_log_entries(log_entries, num_entries);

  // Free the memory allocated for the array of log entries
  free_log_entries(log_entries, num_entries);

  return 0;
}