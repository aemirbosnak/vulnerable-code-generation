//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *log_file_path = "example.log"; // Replace with your log file path

  FILE *log_file = fopen(log_file_path, "r");

  if (log_file == NULL) {
    perror("Error opening log file!");
    exit(EXIT_FAILURE);
  }

  printf("LOG ANALYSIS REPORT:\n\n");

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  int total_requests = 0;
  int successful_requests = 0;
  int client_errors = 0;
  int server_errors = 0;

  while ((read = getline(&line, &len, log_file)) != -1) {
    total_requests++;

    // Check if the request was successful (status code 2xx)
    if (strstr(line, "2") == &line[9]) {
      successful_requests++;
    }

    // Check if the request resulted in a client error (status code 4xx)
    if (strstr(line, "4") == &line[9]) {
      client_errors++;
    }

    // Check if the request resulted in a server error (status code 5xx)
    if (strstr(line, "5") == &line[9]) {
      server_errors++;
    }
  }

  printf("Total Requests: %d\n", total_requests);
  printf("Successful Requests: %d\n", successful_requests);
  printf("Client Errors: %d\n", client_errors);
  printf("Server Errors: %d\n", server_errors);

  fclose(log_file);
  if (line) {
    free(line);
  }

  return 0;
}