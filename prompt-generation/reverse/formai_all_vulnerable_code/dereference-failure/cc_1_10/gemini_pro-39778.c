//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <unistd.h>

// Define the facility and level for our log messages.
#define FACILITY LOG_LOCAL0
#define LEVEL LOG_INFO

// Define a custom log message format.
#define LOG_FORMAT "%s: %s (%d)"

// Define a function to log a message to syslog.
void log_message(const char *component, const char *message) {
  // Check if the component and message are valid.
  if (!component || !message) {
    fprintf(stderr, "Error: Invalid component or message.\n");
    return;
  }

  // Format the log message.
  char log_message[strlen(component) + strlen(message) + 10];
  sprintf(log_message, LOG_FORMAT, component, message, getpid());

  // Log the message to syslog.
  syslog(LEVEL, "%s", log_message);
}

// Define the main function.
int main(int argc, char *argv[]) {
  // Check if the user provided a message to log.
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Log the message to syslog.
  log_message("main", argv[1]);

  // Open the syslog facility.
  openlog("my_app", LOG_PID, FACILITY);

  // Log a message to syslog using the openlog facility.
  syslog(LEVEL, "This is a message logged using the openlog facility.");

  // Close the syslog facility.
  closelog();

  return EXIT_SUCCESS;
}