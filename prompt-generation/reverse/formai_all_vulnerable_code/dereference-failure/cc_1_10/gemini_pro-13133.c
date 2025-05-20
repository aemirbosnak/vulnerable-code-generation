//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 1024
#define MAX_EVENT_LEVEL 7
#define EVENT_LEVEL_DEBUG 0
#define EVENT_LEVEL_INFO 1
#define EVENT_LEVEL_WARNING 2
#define EVENT_LEVEL_ERROR 3
#define EVENT_LEVEL_CRITICAL 4
#define EVENT_LEVEL_FATAL 5
#define EVENT_LEVEL_NONE 6

typedef struct {
  time_t timestamp;
  int level;
  char message[MAX_EVENT_SIZE];
} event_t;

event_t *event_logger;
int event_logger_size;
int event_logger_index;

void event_logger_init(int size) {
  event_logger = malloc(sizeof(event_t) * size);
  event_logger_size = size;
  event_logger_index = 0;
}

void event_logger_log(int level, const char *format, ...) {
  if (level < EVENT_LEVEL_DEBUG || level > EVENT_LEVEL_FATAL) {
    return;
  }

  va_list args;
  va_start(args, format);
  vsnprintf(event_logger[event_logger_index].message, MAX_EVENT_SIZE, format, args);
  va_end(args);

  event_logger[event_logger_index].timestamp = time(NULL);
  event_logger[event_logger_index].level = level;

  event_logger_index++;
  if (event_logger_index >= event_logger_size) {
    event_logger_index = 0;
  }
}

void event_logger_print() {
  for (int i = 0; i < event_logger_size; i++) {
    printf("%s\t", ctime(&event_logger[i].timestamp));
    switch (event_logger[i].level) {
    case EVENT_LEVEL_DEBUG:
      printf("DEBUG\t");
      break;
    case EVENT_LEVEL_INFO:
      printf("INFO\t");
      break;
    case EVENT_LEVEL_WARNING:
      printf("WARNING\t");
      break;
    case EVENT_LEVEL_ERROR:
      printf("ERROR\t");
      break;
    case EVENT_LEVEL_CRITICAL:
      printf("CRITICAL\t");
      break;
    case EVENT_LEVEL_FATAL:
      printf("FATAL\t");
      break;
    }
    printf("%s\n", event_logger[i].message);
  }
}

int main() {
  event_logger_init(10);

  event_logger_log(EVENT_LEVEL_DEBUG, "This is a debug message");
  event_logger_log(EVENT_LEVEL_INFO, "This is an info message");
  event_logger_log(EVENT_LEVEL_WARNING, "This is a warning message");
  event_logger_log(EVENT_LEVEL_ERROR, "This is an error message");
  event_logger_log(EVENT_LEVEL_CRITICAL, "This is a critical message");
  event_logger_log(EVENT_LEVEL_FATAL, "This is a fatal message");

  event_logger_print();

  return 0;
}