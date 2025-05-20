//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the log levels
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_ERROR 3

// Define the log file name
#define LOG_FILE_NAME "log.txt"

// Define the maximum log file size
#define LOG_FILE_MAX_SIZE 1024 * 1024

// Define the log file rotation period
#define LOG_FILE_ROTATION_PERIOD 24 * 60 * 60

// Define the log file rotation count
#define LOG_FILE_ROTATION_COUNT 7

// Create a new log file
FILE *log_file = NULL;

// Open the log file
void open_log_file()
{
  // Open the log file for writing
  log_file = fopen(LOG_FILE_NAME, "a");

  // Check if the log file was opened successfully
  if (log_file == NULL)
  {
    // Print an error message
    fprintf(stderr, "Error opening log file: %s\n", LOG_FILE_NAME);

    // Exit the program
    exit(EXIT_FAILURE);
  }
}

// Close the log file
void close_log_file()
{
  // Close the log file
  fclose(log_file);
}

// Write a log message to the log file
void log_message(int level, const char *message)
{
  // Get the current time
  time_t now = time(NULL);

  // Convert the current time to a string
  char *time_string = ctime(&now);

  // Remove the newline character from the time string
  time_string[strlen(time_string) - 1] = '\0';

  // Write the log message to the log file
  fprintf(log_file, "%s [%d] %s\n", time_string, level, message);
}

// Rotate the log file
void rotate_log_file()
{
  // Close the current log file
  close_log_file();

  // Rename the current log file to the next log file
  char old_log_file_name[256];
  snprintf(old_log_file_name, sizeof(old_log_file_name), "%s.%d", LOG_FILE_NAME, LOG_FILE_ROTATION_COUNT);
  rename(LOG_FILE_NAME, old_log_file_name);

  // Delete the oldest log file
  char oldest_log_file_name[256];
  snprintf(oldest_log_file_name, sizeof(oldest_log_file_name), "%s.%d", LOG_FILE_NAME, 0);
  remove(oldest_log_file_name);

  // Open the new log file
  open_log_file();
}

// Check if the log file is too large
void check_log_file_size()
{
  // Get the size of the log file
  long log_file_size = ftell(log_file);

  // Check if the log file is too large
  if (log_file_size > LOG_FILE_MAX_SIZE)
  {
    // Rotate the log file
    rotate_log_file();
  }
}

// Main function
int main()
{
  // Open the log file
  open_log_file();

  // Write some log messages to the log file
  log_message(LOG_LEVEL_DEBUG, "Debug message");
  log_message(LOG_LEVEL_INFO, "Info message");
  log_message(LOG_LEVEL_WARNING, "Warning message");
  log_message(LOG_LEVEL_ERROR, "Error message");

  // Check if the log file is too large
  check_log_file_size();

  // Close the log file
  close_log_file();

  return 0;
}