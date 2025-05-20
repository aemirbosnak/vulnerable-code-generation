//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char **argv) {

  char *log_file_path = argv[1];

  if (!log_file_path) {
    printf("usage: %s <log_file_path>\n", argv[0]);
    exit(1);
  }

  FILE *log_file = fopen(log_file_path, "r");

  if (!log_file) {
    printf("could not open log file: %s\n", log_file_path);
    exit(1);
  }

  char line[MAX_LINE_SIZE];
  int total_requests = 0;
  int total_successes = 0;
  int total_failures = 0;
  int total_bytes_sent = 0;
  int total_bytes_received = 0;
  double total_response_time = 0.0;

  while (fgets(line, MAX_LINE_SIZE, log_file)) {
    char *token = strtok(line, " ");
    if (strcmp(token, "request") == 0) {
      total_requests++;
      token = strtok(NULL, " ");
      if (strcmp(token, "success") == 0) {
        total_successes++;
        token = strtok(NULL, " ");
        total_bytes_sent += atoi(token);
        token = strtok(NULL, " ");
        total_bytes_received += atoi(token);
        token = strtok(NULL, " ");
        total_response_time += atof(token);
      } else {
        total_failures++;
      }
    } 
  }

  printf("Total requests: %d\n", total_requests);
  printf("Total successes: %d\n", total_successes);
  printf("Total failures: %d\n", total_failures);
  printf("Total bytes sent: %d\n", total_bytes_sent);
  printf("Total bytes received: %d\n", total_bytes_received);
  printf("Average response time: %.2f\n", total_response_time / total_successes);

  fclose(log_file);

  return 0;
}