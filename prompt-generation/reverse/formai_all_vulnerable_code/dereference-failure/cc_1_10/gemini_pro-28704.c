//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

/*
 * The event logger is a simple program that logs events to a file.
 * Each event is written to the file in the following format:
 *
 *     <timestamp> <event type> <event description>
 *
 * The timestamp is the current time in seconds since the epoch. The event type is a short string that describes the type of event. The event description is a longer string that provides more details about the event.
 *
 * The event logger can be used to log a variety of events, such as system events, application events, and user events. The logged events can be used to help troubleshoot problems, track system activity, and audit security events.
 */

#define EVENT_LOGGER_VERSION "1.0"

/*
 * The event types that are supported by the event logger.
 */
typedef enum {
  EVENT_TYPE_SYSTEM,
  EVENT_TYPE_APPLICATION,
  EVENT_TYPE_USER
} event_type_t;

/*
 * The event logger configuration.
 */
typedef struct {
  FILE *logfile;
} event_logger_config_t;

/*
 * The event logger data structure.
 */
typedef struct {
  event_logger_config_t config;
  char *buffer;
  size_t buffer_size;
} event_logger_t;

/*
 * Create a new event logger.
 */
event_logger_t *event_logger_new(const char *logfile_path) {
  event_logger_t *logger = malloc(sizeof(event_logger_t));
  if (logger == NULL) {
    return NULL;
  }

  logger->config.logfile = fopen(logfile_path, "a");
  if (logger->config.logfile == NULL) {
    free(logger);
    return NULL;
  }

  logger->buffer = NULL;
  logger->buffer_size = 0;

  return logger;
}

/*
 * Destroy an event logger.
 */
void event_logger_destroy(event_logger_t *logger) {
  if (logger == NULL) {
    return;
  }

  if (logger->config.logfile != NULL) {
    fclose(logger->config.logfile);
  }

  if (logger->buffer != NULL) {
    free(logger->buffer);
  }

  free(logger);
}

/*
 * Log an event.
 */
void event_logger_log(event_logger_t *logger, event_type_t event_type, const char *event_description) {
  if (logger == NULL) {
    return;
  }

  time_t timestamp = time(NULL);
  const char *event_type_string;
  switch (event_type) {
    case EVENT_TYPE_SYSTEM:
      event_type_string = "SYSTEM";
      break;
    case EVENT_TYPE_APPLICATION:
      event_type_string = "APPLICATION";
      break;
    case EVENT_TYPE_USER:
      event_type_string = "USER";
      break;
    default:
      event_type_string = "UNKNOWN";
      break;
  }

  // Determine the size of the buffer needed to hold the event message.
  size_t buffer_size = strlen(event_type_string) + strlen(event_description) + 32;

  // Ensure the buffer is large enough to hold the event message.
  if (buffer_size > logger->buffer_size) {
    logger->buffer = realloc(logger->buffer, buffer_size);
    logger->buffer_size = buffer_size;
  }

  // Format the event message.
  snprintf(logger->buffer, buffer_size, "%ld %s %s", timestamp, event_type_string, event_description);

  // Write the event message to the log file.
  fprintf(logger->config.logfile, "%s\n", logger->buffer);
}

/*
 * Print the usage information for the event logger.
 */
void event_logger_usage(const char *program_name) {
  printf("Usage: %s <logfile_path>\n", program_name);
  printf("Logs events to the specified logfile.\n");
}

/*
 * The main function.
 */
int main(int argc, char **argv) {
  if (argc != 2) {
    event_logger_usage(argv[0]);
    return EXIT_FAILURE;
  }

  const char *logfile_path = argv[1];

  // Create a new event logger.
  event_logger_t *logger = event_logger_new(logfile_path);
  if (logger == NULL) {
    fprintf(stderr, "Error: Could not create event logger.\n");
    return EXIT_FAILURE;
  }

  // Log some events.
  event_logger_log(logger, EVENT_TYPE_SYSTEM, "System started.");
  event_logger_log(logger, EVENT_TYPE_APPLICATION, "Application started.");
  event_logger_log(logger, EVENT_TYPE_USER, "User logged in.");

  // Destroy the event logger.
  event_logger_destroy(logger);

  return EXIT_SUCCESS;
}