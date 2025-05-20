//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log line
#define MAX_LINE_LENGTH 1024

// Define the maximum number of log lines to store in memory
#define MAX_LOG_LINES 1000

// Define the types of log messages
enum log_type {
  LOG_TYPE_INFO,
  LOG_TYPE_WARNING,
  LOG_TYPE_ERROR
};

// Define the structure of a log message
struct log_message {
  enum log_type type;
  char *text;
};

// Define the structure of a log file
struct log_file {
  FILE *file;
  struct log_message messages[MAX_LOG_LINES];
  int num_messages;
};

// Open a log file
struct log_file *log_file_open(const char *filename) {
  // Allocate memory for the log file
  struct log_file *log_file = malloc(sizeof(struct log_file));

  // Open the log file
  log_file->file = fopen(filename, "r");

  // Check if the log file was opened successfully
  if (log_file->file == NULL) {
    free(log_file);
    return NULL;
  }

  // Read the log file into memory
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, log_file->file) != NULL) {
    // Parse the log line
    struct log_message message;
    if (strncmp(line, "INFO:", 5) == 0) {
      message.type = LOG_TYPE_INFO;
      message.text = strdup(line + 5);
    } else if (strncmp(line, "WARNING:", 8) == 0) {
      message.type = LOG_TYPE_WARNING;
      message.text = strdup(line + 8);
    } else if (strncmp(line, "ERROR:", 6) == 0) {
      message.type = LOG_TYPE_ERROR;
      message.text = strdup(line + 6);
    } else {
      continue;
    }

    // Add the log message to the log file
    log_file->messages[log_file->num_messages++] = message;
  }

  // Close the log file
  fclose(log_file->file);

  // Return the log file
  return log_file;
}

// Close a log file
void log_file_close(struct log_file *log_file) {
  // Free the memory allocated for the log file
  for (int i = 0; i < log_file->num_messages; i++) {
    free(log_file->messages[i].text);
  }
  free(log_file);
}

// Print the log file
void log_file_print(struct log_file *log_file) {
  // Print the log file header
  printf("Log File: %s\n", log_file->file);
  printf("-----------------------------------------------------\n");

  // Print the log file messages
  for (int i = 0; i < log_file->num_messages; i++) {
    struct log_message message = log_file->messages[i];

    // Print the log message type
    switch (message.type) {
      case LOG_TYPE_INFO:
        printf("[INFO] ");
        break;
      case LOG_TYPE_WARNING:
        printf("[WARNING] ");
        break;
      case LOG_TYPE_ERROR:
        printf("[ERROR] ");
        break;
    }

    // Print the log message text
    printf("%s\n", message.text);
  }
}

// Main function
int main(int argc, char **argv) {
  // Check if the user specified a log file
  if (argc != 2) {
    printf("Usage: %s <log file>\n", argv[0]);
    return 1;
  }

  // Open the log file
  struct log_file *log_file = log_file_open(argv[1]);

  // Check if the log file was opened successfully
  if (log_file == NULL) {
    printf("Error opening log file: %s\n", argv[1]);
    return 1;
  }

  // Print the log file
  log_file_print(log_file);

  // Close the log file
  log_file_close(log_file);

  return 0;
}