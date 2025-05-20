//Gemma-7B DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog {
  char timestamp[26];
  char event_name[256];
  char event_details[MAX_LOG_SIZE];
  int event_severity;
} EventLog;

EventLog event_log[100];
int event_log_index = 0;

void log_event(char *event_name, char *event_details, int event_severity) {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  event_log[event_log_index].timestamp[0] = tm->tm_hour;
  event_log[event_log_index].timestamp[1] = tm->tm_min;
  event_log[event_log_index].timestamp[2] = tm->tm_sec;

  event_log[event_log_index].event_name[0] = '\0';
  strcpy(event_log[event_log_index].event_name, event_name);

  event_log[event_log_index].event_details[0] = '\0';
  strcpy(event_log[event_log_index].event_details, event_details);

  event_log[event_log_index].event_severity = event_severity;

  event_log_index++;

  if (event_log_index >= 100) {
    event_log_index = 0;
  }
}

int main() {
  log_event("System Boot", "System started successfully.", 0);
  log_event("User Login", "John Doe logged in.", 1);
  log_event("File Download", "Download of file.txt completed.", 2);

  for (int i = 0; i < event_log_index; i++) {
    printf("Timestamp: %s, Event Name: %s, Event Details: %s, Event Severity: %d\n", event_log[i].timestamp, event_log[i].event_name, event_log[i].event_details, event_log[i].event_severity);
  }

  return 0;
}