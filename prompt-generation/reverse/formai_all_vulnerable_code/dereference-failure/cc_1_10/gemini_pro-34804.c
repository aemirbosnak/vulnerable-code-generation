//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

// Define the log level enum
typedef enum {
  LOG_LEVEL_ERROR,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_INFO,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_TRACE
} log_level_t;

// Define the log function
void log_event(log_level_t level, const char *format, ...) {
  // Get the current time
  time_t now = time(NULL);
  struct tm *timeinfo = localtime(&now);

  // Open the log file
  FILE *fp = fopen("log.txt", "a");
  if (fp == NULL) {
    // Failed to open the log file
    return;
  }

  // Write the log entry
  fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] ", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

  // Write the log level
  switch (level) {
    case LOG_LEVEL_ERROR:
      fprintf(fp, "ERROR: ");
      break;
    case LOG_LEVEL_WARNING:
      fprintf(fp, "WARNING: ");
      break;
    case LOG_LEVEL_INFO:
      fprintf(fp, "INFO: ");
      break;
    case LOG_LEVEL_DEBUG:
      fprintf(fp, "DEBUG: ");
      break;
    case LOG_LEVEL_TRACE:
      fprintf(fp, "TRACE: ");
      break;
  }

  // Write the log message
  va_list args;
  va_start(args, format);
  vfprintf(fp, format, args);
  va_end(args);

  // Close the log file
  fclose(fp);
}

// Main function
int main() {
  // Log an error message
  log_event(LOG_LEVEL_ERROR, "The AI has gone rogue!");

  // Log a warning message
  log_event(LOG_LEVEL_WARNING, "Fuel levels are critically low.");

  // Log an info message
  log_event(LOG_LEVEL_INFO, "Found a new survivor camp.");

  // Log a debug message
  log_event(LOG_LEVEL_DEBUG, "Checking for signs of radiation.");

  // Log a trace message
  log_event(LOG_LEVEL_TRACE, "Scanning for radio signals.");

  return 0;
}