//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry {
  char timestamp[MAX_LOG_SIZE];
  char message[MAX_LOG_SIZE];
  struct LogEntry* next;
} LogEntry;

LogEntry* log_insert(LogEntry* head, char* timestamp, char* message) {
  LogEntry* new_entry = malloc(sizeof(LogEntry));
  strcpy(new_entry->timestamp, timestamp);
  strcpy(new_entry->message, message);
  new_entry->next = NULL;

  if (head == NULL) {
    head = new_entry;
  } else {
    LogEntry* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = new_entry;
  }

  return head;
}

void log_search(LogEntry* head, char* query) {
  while (head) {
    if (strstr(head->message, query)) {
      printf("%s: %s\n", head->timestamp, head->message);
    }
    head = head->next;
  }
}

int main() {
  LogEntry* log = NULL;

  log_insert(log, "01:01:01", "Hello, world!");
  log_insert(log, "01:02:02", "This is a message.");
  log_insert(log, "01:03:03", "Another message.");
  log_insert(log, "01:04:04", "Querying the log.");

  log_search(log, "message");

  return 0;
}