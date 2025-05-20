//FormAI DATASET v1.0 Category: System event logger ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure for a log entry
typedef struct {
  time_t timestamp;      // The time the event occurred
  char *source;          // The source of the event
  char *message;         // The message associated with the event
} LogEntry;

// Define a function that creates and returns a new LogEntry
LogEntry *create_log_entry(char *source, char *message) {
  LogEntry *entry = malloc(sizeof(LogEntry));
  entry->timestamp = time(NULL);
  entry->source = strdup(source);
  entry->message = strdup(message);
  return entry;
}

// Define a function that prints a log entry to stdout
void print_log_entry(LogEntry *entry) {
  printf("[%ld] %s: %s\n", entry->timestamp, entry->source, entry->message);
}

// Define the structure for the node in the decentralized log
typedef struct node Node;
struct node {
  LogEntry *entry;
  Node *next;
};

// Define the structure for a decentralized log
typedef struct {
  Node *head;
  int size;
} DecentralizedLog;

// Define a function that initializes a DecentralizedLog
void init_decentralized_log(DecentralizedLog *log) {
  log->head = NULL;
  log->size = 0;
}

// Define a function that adds a LogEntry to a DecentralizedLog
void add_log_entry(DecentralizedLog *log, LogEntry *entry) {
  Node *new_node = malloc(sizeof(Node));
  new_node->entry = entry;
  new_node->next = log->head;
  log->head = new_node;
  log->size++;
}

// Define a function that prints a DecentralizedLog to stdout
void print_decentralized_log(DecentralizedLog *log) {
  Node *current = log->head;
  while (current != NULL) {
    print_log_entry(current->entry);
    current = current->next;
  }
}

int main() {
  // Initialize a DecentralizedLog
  DecentralizedLog log;
  init_decentralized_log(&log);

  // Create and add some LogEntries
  LogEntry *entry1 = create_log_entry("System", "Program started");
  LogEntry *entry2 = create_log_entry("Network", "Connection established");
  LogEntry *entry3 = create_log_entry("System", "Program exiting");
  add_log_entry(&log, entry1);
  add_log_entry(&log, entry2);
  add_log_entry(&log, entry3);

  // Print the DecentralizedLog
  print_decentralized_log(&log);

  return 0;
}