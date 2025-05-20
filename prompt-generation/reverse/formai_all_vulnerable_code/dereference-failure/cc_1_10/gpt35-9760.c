//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  // Initialize variables
  char* log = "2022-03-22 14:30:00 INFO Server starting up...\n"
              "2022-03-22 14:31:00 ERROR Could not connect to database\n"
              "2022-03-22 14:32:00 INFO Server shutting down...\n"
              "2022-03-23 12:00:00 DEBUG User logged in: alice123\n"
              "2022-03-23 12:10:00 DEBUG User logged out: alice123\n"
              "2022-03-23 12:15:00 WARNING Low disk space: 10% remaining\n";

  char* token = strtok(log, "\n"); // Split log into separate lines

  int info_count = 0;
  int warn_count = 0;
  int err_count = 0;
  int debug_count = 0;
  int disk_space = 0;

  while(token != NULL){
    printf("%s\n", token); // Print each line

    // Categorize log by severity
    if(strstr(token, "INFO")){
      info_count++;
    }
    else if(strstr(token, "WARNING")){
      warn_count++;
      if(strstr(token, "disk space")){
        disk_space = 1;
      }
    }
    else if(strstr(token, "ERROR")){
      err_count++;
    }
    else if(strstr(token, "DEBUG")){
      debug_count++;
    }

    token = strtok(NULL, "\n"); // Continue to next line
  }

  printf("\n");
  printf("Log Summary\n");
  printf("---------------\n");
  printf("INFO: %d\n", info_count);
  printf("WARNINGS: %d\n", warn_count);
  printf("ERRORS: %d\n", err_count);
  printf("DEBUG: %d\n", debug_count);

  if(disk_space){
    printf("ALERT: Low disk space!\n");
  }

  return 0; // End program
}