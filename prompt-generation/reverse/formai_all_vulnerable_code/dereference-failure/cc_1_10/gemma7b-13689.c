//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry {
  char *message;
  struct LogEntry *next;
} LogEntry;

void log_add(LogEntry **head, char *message) {
  LogEntry *new_entry = malloc(sizeof(LogEntry));
  new_entry->message = strdup(message);
  new_entry->next = NULL;

  if (*head == NULL) {
    *head = new_entry;
  } else {
    (*head)->next = new_entry;
  }
}

int log_size(LogEntry *head) {
  int size = 0;
  LogEntry *current = head;

  while (current) {
    size++;
    current = current->next;
  }

  return size;
}

void log_clear(LogEntry **head) {
  LogEntry *current = *head;
  LogEntry *next = NULL;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }

  *head = NULL;
}

int main() {
  LogEntry *log = NULL;

  // Log some messages
  log_add(&log, "Hello, world!");
  log_add(&log, "This is a log entry.");
  log_add(&log, "The sky is blue.");

  // Print the log size
  printf("Log size: %d\n", log_size(log));

  // Clear the log
  log_clear(&log);

  // Print the log size after clearing
  printf("Log size: %d\n", log_size(log));

  return 0;
}