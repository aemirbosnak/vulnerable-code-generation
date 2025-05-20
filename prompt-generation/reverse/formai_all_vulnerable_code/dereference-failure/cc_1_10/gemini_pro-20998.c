//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <time.h>

typedef struct _logevent {
  uint64_t timestamp;
  char *level;
  char *message;
} logevent;

typedef struct _log {
  logevent *events;
  size_t size;
  size_t capacity;
} log;

typedef enum _loglevel {
  LOG_ERROR,
  LOG_WARN,
  LOG_INFO,
  LOG_DEBUG
} loglevel;

char *loglevel_to_string(loglevel level) {
  switch (level) {
    case LOG_ERROR:
      return "ERROR";
    case LOG_WARN:
      return "WARN";
    case LOG_INFO:
      return "INFO";
    case LOG_DEBUG:
      return "DEBUG";
    default:
      return "UNKNOWN";
  }
}

void log_event(log *l, loglevel level, char *format, ...) {
  logevent e;
  va_list args;

  e.timestamp = time(NULL);
  e.level = loglevel_to_string(level);

  va_start(args, format);
  vasprintf(&e.message, format, args);
  va_end(args);

  if (l->size >= l->capacity) {
    l->capacity *= 2;
    l->events = realloc(l->events, l->capacity * sizeof(logevent));
  }

  l->events[l->size++] = e;
}

void log_flush(log *l, FILE *f) {
  size_t i;

  for (i = 0; i < l->size; i++) {
    logevent e = l->events[i];
    fprintf(f, "[%s] [%s] %s\n", ctime(&e.timestamp), e.level, e.message);
    free(e.message);
  }

  free(l->events);
  l->size = 0;
  l->capacity = 10;
}

int main(void) {
  log error_log;
  log info_log;
  log debug_log;

  log_event(&error_log, LOG_ERROR, "Critical failure!");
  log_event(&info_log, LOG_INFO, "Starting up...");
  log_event(&debug_log, LOG_DEBUG, "Variable value: %d", 123);

  log_flush(&error_log, stderr);
  log_flush(&info_log, stdout);
  log_flush(&debug_log, stderr);

  return 0;
}