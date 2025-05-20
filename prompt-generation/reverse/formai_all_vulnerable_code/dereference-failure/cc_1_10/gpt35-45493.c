//FormAI DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
// This C program analyzes a log file and outputs various statistics
// Written by [Your name], inspired by Donald Knuth's literate programming style

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Define constants for array sizes and log entry properties
#define MAX_LINE_LENGTH 1000
#define MAX_TIMESTAMP_LENGTH 25
#define MAX_METHOD_LENGTH 10
#define MAX_URI_LENGTH 500
#define MAX_STATUS_CODE_LENGTH 5

// Define struct for log entries
struct LogEntry {
  char timestamp[MAX_TIMESTAMP_LENGTH];
  char method[MAX_METHOD_LENGTH];
  char uri[MAX_URI_LENGTH];
  char status_code[MAX_STATUS_CODE_LENGTH];
};

// Define function to parse log entry string into struct
void parse_log_entry(char* line, struct LogEntry* entry) {
  // Use string tokenization to split line by spaces
  char* token = strtok(line, " ");
  
  // Parse timestamp, method, uri, and status code from tokens
  strcpy(entry->timestamp, token);
  token = strtok(NULL, " ");
  strcpy(entry->method, token);
  token = strtok(NULL, " ");
  strcpy(entry->uri, token);
  token = strtok(NULL, " ");
  strcpy(entry->status_code, token);
}

int main() {
  // Define variables for file handling and log analysis
  char log_filename[] = "access.log";
  char line[MAX_LINE_LENGTH];
  struct LogEntry entry;
  int total_entries = 0;
  int get_requests = 0;
  int post_requests = 0;
  int successful_requests = 0;
  int redirects = 0;
  int client_errors = 0;
  int server_errors = 0;
  
  // Open log file for reading
  FILE* log_file = fopen(log_filename, "r");
  
  // Check for errors opening file
  if (log_file == NULL) {
    printf("Error opening log file\n");
    return 1;
  }
  
  // Loop through each line in file, parsing log entries and updating stats
  while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
    // Parse log entry from line
    parse_log_entry(line, &entry);
    
    // Update total entry count
    total_entries++;
    
    // Check if request method is GET or POST and update count
    if (strcmp(entry.method, "GET") == 0) {
      get_requests++;
    } else if (strcmp(entry.method, "POST") == 0) {
      post_requests++;
    }
    
    // Check if request was successful or a redirect and update count
    if (strncmp(entry.status_code, "2", 1) == 0) {
      successful_requests++;
    } else if (strncmp(entry.status_code, "3", 1) == 0) {
      redirects++;
    }
    
    // Check if request resulted in client or server error and update count
    if (strncmp(entry.status_code, "4", 1) == 0) {
      client_errors++;
    } else if (strncmp(entry.status_code, "5", 1) == 0) {
      server_errors++;
    }
  }
  
  // Close log file
  fclose(log_file);
  
  // Output log analysis results
  printf("Log analysis results for file %s\n", log_filename);
  printf("Total entries: %d\n", total_entries);
  printf("Get requests: %d\n", get_requests);
  printf("Post requests: %d\n", post_requests);
  printf("Successful requests: %d\n", successful_requests);
  printf("Redirects: %d\n", redirects);
  printf("Client errors: %d\n", client_errors);
  printf("Server errors: %d\n", server_errors);
  
  // Return success
  return 0;
}