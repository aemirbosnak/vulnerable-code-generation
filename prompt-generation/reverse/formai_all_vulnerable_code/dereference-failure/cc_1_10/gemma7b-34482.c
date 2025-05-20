//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry {
  char timestamp[MAX_LOG_SIZE];
  char message[MAX_LOG_SIZE];
  struct LogEntry* next;
} LogEntry;

LogEntry* createLogEntry(char* timestamp, char* message) {
  LogEntry* newLogEntry = (LogEntry*)malloc(sizeof(LogEntry));
  strcpy(newLogEntry->timestamp, timestamp);
  strcpy(newLogEntry->message, message);
  newLogEntry->next = NULL;
  return newLogEntry;
}

void appendLog(LogEntry* log, char* timestamp, char* message) {
  LogEntry* newLogEntry = createLogEntry(timestamp, message);
  if (log) {
    log->next = newLogEntry;
  } else {
    log = newLogEntry;
  }
  log = log->next;
}

int analyzeLog(LogEntry* log) {
  int count = 0;
  while (log) {
    if (strstr(log->message, "error")) {
      count++;
    }
    log = log->next;
  }
  return count;
}

int main() {
  LogEntry* log = NULL;
  appendLog(log, "12:00:01", "System started.");
  appendLog(log, "12:00:02", "User logged in.");
  appendLog(log, "12:00:03", "Error occurred.");
  appendLog(log, "12:00:04", "User logged out.");
  appendLog(log, "12:00:05", "System stopped.");

  int numErrors = analyzeLog(log);
  printf("Number of errors: %d", numErrors);

  return 0;
}