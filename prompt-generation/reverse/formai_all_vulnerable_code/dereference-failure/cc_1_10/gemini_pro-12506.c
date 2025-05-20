//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the log levels
#define LOG_INFO 0
#define LOG_WARNING 1
#define LOG_ERROR 2

// Define the log file path
#define LOG_FILE_PATH "log.txt"

// Define the maximum log message length
#define LOG_MESSAGE_MAX_LENGTH 1024

// Log a message
void log_message(int level, const char *message) {
  // Get the current time
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);

  // Open the log file
  FILE *fp = fopen(LOG_FILE_PATH, "a+");
  if (fp == NULL) {
    fprintf(stderr, "Error opening log file: %s\n", LOG_FILE_PATH);
    return;
  }

  // Write the log message to the file
  fprintf(fp, "[%02d:%02d:%02d] ", tm->tm_hour, tm->tm_min, tm->tm_sec);
  switch (level) {
    case LOG_INFO:
      fprintf(fp, "INFO: ");
      break;
    case LOG_WARNING:
      fprintf(fp, "WARNING: ");
      break;
    case LOG_ERROR:
      fprintf(fp, "ERROR: ");
      break;
  }
  fprintf(fp, "%s\n", message);

  // Close the log file
  fclose(fp);
}

// Main function
int main(int argc, char **argv) {
  // Log an info message
  log_message(LOG_INFO, "This is an info message.");

  // Log a warning message
  log_message(LOG_WARNING, "This is a warning message.");

  // Log an error message
  log_message(LOG_ERROR, "This is an error message.");

  return 0;
}