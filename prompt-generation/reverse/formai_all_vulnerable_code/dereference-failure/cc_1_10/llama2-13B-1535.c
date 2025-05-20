//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100

void process_line(char *line) {
  char *word1, *word2, *word3;
  int i, j, k;

  // Split the line into words
  word1 = strtok(line, " ");
  word2 = strtok(NULL, " ");
  word3 = strtok(NULL, " ");

  // Check if the line is a date
  if (strcmp(word1, "Date:") == 0) {
    // Get the date in YYYY-MM-DD format
    char date[20];
    strcpy(date, word2);
    strcat(date, "-");
    strcat(date, word3);

    // Print the date in YYYY-MM-DD format
    printf("%s\n", date);
  }

  // Check if the line is a time
  else if (strcmp(word1, "Time:") == 0) {
    // Get the time in HH:MM:SS format
    char time[10];
    strcpy(time, word2);
    strcat(time, ":");
    strcat(time, word3);

    // Print the time in HH:MM:SS format
    printf("%s\n", time);
  }

  // Check if the line is a comment
  else if (strcmp(word1, "#") == 0) {
    // Skip the line
    return;
  }

  // Check if the line is a blank line
  else if (strcmp(word1, "") == 0) {
    // Skip the line
    return;
  }

  // Print the line as is
  printf("%s\n", line);
}

int main() {
  char line[MAX_LINE_LENGTH];
  int i;

  // Read lines from the standard input
  while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
    process_line(line);
  }

  return 0;
}