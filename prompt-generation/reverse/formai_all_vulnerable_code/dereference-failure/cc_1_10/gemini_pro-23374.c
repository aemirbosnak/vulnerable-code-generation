//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>  // For the printf() function
#include <stdlib.h> // For the exit() function
#include <string.h> // For the strlen() function
#include <time.h>   // For the time() function

// A structure to store the log entry
typedef struct log_entry {
  time_t timestamp;        // The timestamp of the log entry
  char *source;             // The source of the log entry
  char *message;            // The message of the log entry
  struct log_entry *next;  // A pointer to the next log entry
} log_entry;

// A function to create a new log entry
log_entry *create_log_entry(char *source, char *message) {
  // Allocate memory for the new log entry
  log_entry *new_entry = (log_entry *)malloc(sizeof(log_entry));

  // Check if the memory allocation was successful
  if (new_entry == NULL) {
    // If the memory allocation failed, print an error message and exit the program
    fprintf(stderr, "Error: Could not allocate memory for new log entry.\n");
    exit(1);
  }

  // Initialize the new log entry
  new_entry->timestamp = time(NULL);
  new_entry->source = source;
  new_entry->message = message;
  new_entry->next = NULL;

  // Return the new log entry
  return new_entry;
}

// A function to add a log entry to the end of a log
void add_log_entry(log_entry **head, log_entry *new_entry) {
  // If the log is empty, set the head of the log to the new entry
  if (*head == NULL) {
    *head = new_entry;
    return;
  }

  // Otherwise, iterate through the log until we find the last entry
  log_entry *current_entry = *head;
  while (current_entry->next != NULL) {
    current_entry = current_entry->next;
  }

  // Set the next pointer of the last entry to the new entry
  current_entry->next = new_entry;
}

// A function to print a log entry
void print_log_entry(log_entry *entry) {
  // Print the timestamp of the log entry
  printf("%s", ctime(&entry->timestamp));

  // Print the source of the log entry
  printf("Source: %s\n", entry->source);

  // Print the message of the log entry
  printf("Message: %s\n\n", entry->message);
}

// A function to print a log
void print_log(log_entry *head) {
  // Iterate through the log and print each entry
  log_entry *current_entry = head;
  while (current_entry != NULL) {
    print_log_entry(current_entry);
    current_entry = current_entry->next;
  }
}

// A function to free the memory allocated for a log
void free_log(log_entry *head) {
  // Iterate through the log and free the memory for each entry
  log_entry *current_entry = head;
  while (current_entry != NULL) {
    log_entry *next_entry = current_entry->next;
    free(current_entry->source);
    free(current_entry->message);
    free(current_entry);
    current_entry = next_entry;
  }
}

int main() {
  // Create a new log
  log_entry *head = NULL;

  // Add some log entries to the log
  add_log_entry(&head, create_log_entry("Romeo", "My heart is full of love for thee."));
  add_log_entry(&head, create_log_entry("Juliet", "And mine for thee."));
  add_log_entry(&head, create_log_entry("Romeo", "I wouldst that I could hold thee in my arms."));
  add_log_entry(&head, create_log_entry("Juliet", "And I wouldst that I could kiss thee on thy lips."));

  // Print the log
  print_log(head);

  // Free the memory allocated for the log
  free_log(head);

  return 0;
}