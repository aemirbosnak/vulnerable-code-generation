//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
  // Check if file argument was passed
  if (argc < 2) {
    printf("Error: no file argument passed.\n");
    return 1;
  }

  // Open file
  FILE* logfile;
  if ((logfile = fopen(argv[1], "r")) == NULL) {
    printf("Error: could not open file %s.\n", argv[1]);
    return 1;
  }

  // Initialize variables
  int num_requests = 0;
  int num_failed_requests = 0;
  char buffer[BUFFER_SIZE];

  // Loop through file line by line
  while (fgets(buffer, BUFFER_SIZE, logfile) != NULL) {
    // Find request status
    int status_start = strstr(buffer, "\"") - buffer + 1;
    int status_end = strstr(buffer + status_start, "\"") - buffer;
    char status[4];
    strncpy(status, buffer + status_start, status_end - status_start);
    status[status_end - status_start] = '\0';

    // Increment total number of requests
    num_requests++;

    // Check if request was successful
    if (strcmp(status, "200") == 0) {
      continue;
    }
    else {
      num_failed_requests++;
    }
  }

  // Print results
  printf("Total number of requests: %d\n", num_requests);
  printf("Number of failed requests: %d\n", num_failed_requests);
  printf("Percentage of failed requests: %.2f%%\n", (float)num_failed_requests / (float)num_requests * 100.0);

  // Close file
  fclose(logfile);

  return 0;
}