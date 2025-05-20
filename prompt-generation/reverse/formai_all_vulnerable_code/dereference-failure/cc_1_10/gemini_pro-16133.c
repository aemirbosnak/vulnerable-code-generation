//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: Donald Knuth
/* A C System Event Logger Example Program in a Donald Knuth Style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

/* Define the maximum length of a log entry. */
#define MAX_LOG_ENTRY_LENGTH 1000

/* Define the location of the log file. */
#define LOG_FILE "/var/log/my_log.txt"

/* Define the types of log entries. */
typedef enum {
  LOG_INFO,
  LOG_WARNING,
  LOG_ERROR,
  LOG_DEBUG
} log_type;

/* Define the structure of a log entry. */
typedef struct {
  log_type type;
  time_t timestamp;
  char message[MAX_LOG_ENTRY_LENGTH];
} log_entry;

/* Function to write a log entry to the log file. */
void write_log_entry(log_entry *entry) {
  /* Open the log file. */
  FILE *log_file = fopen(LOG_FILE, "a");
  if (log_file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  /* Write the log entry to the log file. */
  fprintf(log_file, "%s\n", entry->message);

  /* Close the log file. */
  fclose(log_file);
}

/* Function to create a log entry. */
log_entry *create_log_entry(log_type type, const char *message) {
  /* Allocate memory for the log entry. */
  log_entry *entry = malloc(sizeof(log_entry));
  if (entry == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  /* Set the log entry's type, timestamp, and message. */
  entry->type = type;
  entry->timestamp = time(NULL);
  strcpy(entry->message, message);

  /* Return the log entry. */
  return entry;
}

/* Function to free the memory allocated for a log entry. */
void free_log_entry(log_entry *entry) {
  /* Free the memory allocated for the log entry's message. */
  free(entry->message);

  /* Free the memory allocated for the log entry. */
  free(entry);
}

/* Main function. */
int main(void) {
  /* Create a log entry. */
  log_entry *entry = create_log_entry(LOG_INFO, "This is an informational message.");

  /* Write the log entry to the log file. */
  write_log_entry(entry);

  /* Free the memory allocated for the log entry. */
  free_log_entry(entry);

  return EXIT_SUCCESS;
}