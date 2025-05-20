//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <syslog.h>
#include <time.h>
#include <string.h>

// Define a custom log facility
#define MY_FACILITY LOG_USER

// Define a custom log level
#define MY_LOG_LEVEL LOG_INFO

// Define a custom log tag
#define MY_LOG_TAG "My App"

// Define a custom log format
#define MY_LOG_FORMAT "%s: %s"

// Log a message to the system event log
void log_message(const char* message) {
  // Open the system event log
  openlog(MY_LOG_TAG, LOG_CONS | LOG_PID, MY_FACILITY);

  // Set the log level
  setlogmask(LOG_UPTO(MY_LOG_LEVEL));

  // Log the message
  syslog(MY_LOG_LEVEL, MY_LOG_FORMAT, MY_LOG_TAG, message);

  // Close the system event log
  closelog();
}

// Get the current time as a string
char* get_current_time() {
  // Get the current time
  time_t current_time = time(NULL);

  // Convert the current time to a string
  char* current_time_string = ctime(&current_time);

  // Remove the newline character from the end of the string
  current_time_string[strlen(current_time_string) - 1] = '\0';

  return current_time_string;
}

int main() {
  // Log a message to the system event log
  log_message("Hello, world!");

  // Log a message with the current time
  log_message(get_current_time());

  return 0;
}