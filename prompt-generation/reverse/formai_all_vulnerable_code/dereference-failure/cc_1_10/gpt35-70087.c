//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000 // Maximum number of lines in the log file
#define MAX_LEN  100 // Maximum length of each line

int main() {
  char line[MAX_LEN]; // Current line of log file
  int n_lines = 0; // Current number of lines in log file
  int found_attack = 0; // Current status of attack detection

  // Array of suspicious keywords
  char* keywords[] = {"password", "root", "sudo", "exec", "wget", "curl", "python"};

  // Allocate space for log file
  char** log_file = (char**) calloc(MAX_LINES, sizeof(char*));
  for(int i = 0; i < MAX_LINES; i++) {
    log_file[i] = (char*) calloc(MAX_LEN, sizeof(char));
  }

  // Open log file
  FILE* fp = fopen("log.txt", "r");
  if(fp == NULL) {
    printf("Error: Could not open log file\n");
    return 1;
  }

  // Read log file into memory
  while(fgets(line, MAX_LEN, fp) != NULL) {
    if(n_lines >= MAX_LINES) {
      printf("Warning: Log file has exceeded maximum number of lines\n");
      break;
    }
    strcpy(log_file[n_lines], line);
    n_lines++;
  }

  // Close log file
  fclose(fp);

  // Check log file for suspicious keywords
  for(int i = 0; i < n_lines; i++) {
    for(int j = 0; j < sizeof(keywords)/sizeof(*keywords); j++) {
      if(strstr(log_file[i], keywords[j]) != NULL) {
        printf("Warning: Suspicious keyword '%s' found in line %d\n", keywords[j], i+1);
        found_attack = 1;
      }
    }
  }

  // Alert user if an attack was detected
  if(found_attack) {
    printf("Attention: Possible intrusion detected\n");
  } else {
    printf("No signs of intrusion were detected\n");
  }

  // Free memory used by log file
  for(int i = 0; i < MAX_LINES; i++) {
    free(log_file[i]);
  }
  free(log_file);

  return 0;
}