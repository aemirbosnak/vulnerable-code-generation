//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "peace.log"

// A structure to hold a log entry
struct log_entry {
  char *message;
  time_t timestamp;
};

// A function to create a new log entry
struct log_entry *create_log_entry(char *message) {
  struct log_entry *entry = malloc(sizeof(struct log_entry));
  entry->message = strdup(message);
  entry->timestamp = time(NULL);
  return entry;
}

// A function to write a log entry to a file
void write_log_entry(struct log_entry *entry) {
  FILE *fp = fopen(LOG_FILE, "a");
  if (!fp) {
    perror("Error opening log file");
    return;
  }
  fprintf(fp, "%s\n", entry->message);
  fclose(fp);
}

// A function to read a log file and print its contents
void read_log_file() {
  FILE *fp = fopen(LOG_FILE, "r");
  if (!fp) {
    perror("Error opening log file");
    return;
  }
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
  }
  fclose(fp);
}

// A function to clear the log file
void clear_log_file() {
  FILE *fp = fopen(LOG_FILE, "w");
  if (!fp) {
    perror("Error opening log file");
    return;
  }
  fclose(fp);
}

// The main function
int main() {
  // Create a new log entry
  struct log_entry *entry = create_log_entry("Peace and love!");

  // Write the log entry to a file
  write_log_entry(entry);

  // Read the log file and print its contents
  read_log_file();

  // Clear the log file
  clear_log_file();

  return 0;
}