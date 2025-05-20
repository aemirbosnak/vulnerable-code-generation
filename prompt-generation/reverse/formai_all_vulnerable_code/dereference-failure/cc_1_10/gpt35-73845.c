//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MSG_LEN 256
#define MAX_LOG_ENTRIES 1000

// Struct to hold a log entry
typedef struct log_entry {
  char timestamp[20];
  char message[MAX_MSG_LEN];
} LogEntry;

// Array to hold all log entries
LogEntry log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

// Function to log a new message
void log_event(char *msg) {
  // Get current time
  time_t curr_time = time(NULL);
  struct tm * time_info = localtime(&curr_time);

  // Format timestamp
  char timestamp[20];
  strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", time_info);

  // Create log entry
  LogEntry entry;
  strcpy(entry.timestamp, timestamp);
  strcpy(entry.message, msg);

  // Add entry to log array
  log_entries[num_log_entries] = entry;

  // Increment number of log entries
  num_log_entries++;
}

// Function to print all log entries
void print_logs() {
  printf("Event Log:\n");
  for (int i = 0; i < num_log_entries; i++) {
    printf("%s - %s\n", log_entries[i].timestamp, log_entries[i].message);
  }
}

int main() {
  // Log some events
  log_event("System started");
  log_event("File system mounted");
  log_event("Network interface initialized");

  // Print logs
  print_logs();

  // Exit program
  printf("Exiting program...\n");
  return 0;
}