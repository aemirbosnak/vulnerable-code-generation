//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]) {
  FILE *log_file;
  char line[1024];
  char *token;
  int total_requests = 0, total_errors = 0;

  if (argc != 2) {
    printf("Usage: %s <log_file.csv>\n", argv[0]);
    exit(1);
  }

  log_file = fopen(argv[1], "r");

  if (!log_file) {
    perror("Error opening log file");
    exit(1);
  }

  puts("**** Welcome to the Crazy Log Analyzer! ****");
  puts("*******************************************");
  puts("");

  while (fgets(line, sizeof(line), log_file)) {
    if (strstr(line, "ERROR") != NULL) {
      total_errors++;
      puts("*************************************");
      puts("Error found in log!");
      puts("*************************************");
      puts(line);
      puts("");
    } else {
      token = strtok(line, ",");
      if (strcmp(token, "REQUEST") == 0) {
        total_requests++;
      }
    }
  }

  fclose(log_file);

  printf("Total number of requests: %d\n", total_requests);
  printf("Total number of errors: %d\n", total_errors);

  if (total_errors == 0) {
    puts("No errors found in log file.");
  } else {
    puts("Errors found in log file.");
  }

  if (total_requests > 0) {
    puts("Requests found in log file.");
  } else {
    puts("No requests found in log file.");
  }
}