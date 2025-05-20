//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
  // Ensure we were given the input file as a command-line arg
  if (argc != 2) {
    printf("Usage: %s <input file>\n", argv[0]);
    return 1;
  }

  // Attempt to open the input file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: input file could not be opened\n");
    return 1;
  }

  // Initialize a hash table to store the count for each log message
  const int NUM_BUCKETS = 1000;
  int *counts = calloc(NUM_BUCKETS, sizeof(int));

  // Read the input file line-by-line
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    // Remove the newline character at the end of the line (if it exists)
    int len = strlen(line);
    if (line[len-1] == '\n') {
      line[len-1] = '\0';
    }

    // Hash the log message and increment the count in the hash table
    int hash = 0;
    int i = 0;
    while (line[i]) {
      hash += line[i] * (i+1);
      i++;
    }
    counts[hash % NUM_BUCKETS]++;
  }

  // Print out the top 10 log messages by count
  printf("Top 10 log messages:\n");
  for (int i = 0; i < 10; i++) {
    int max_count = 0;
    int max_index = 0;
    for (int j = 0; j < NUM_BUCKETS; j++) {
      if (counts[j] > max_count) {
        max_count = counts[j];
        max_index = j;
      }
    }
    if (max_count == 0) {
      break;
    }
    printf("%s: %d\n", (char *)&max_index, max_count);
    counts[max_index] = 0;
  }

  // Clean up memory and close the input file
  free(counts);
  fclose(fp);

  return 0;
}