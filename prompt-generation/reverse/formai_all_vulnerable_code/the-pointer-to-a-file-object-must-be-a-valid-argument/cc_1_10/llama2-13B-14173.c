//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_LEN 1024
#define MAX_LINE_LEN 256

void log_analysis(const char* log_file_path) {
  FILE* log_file = fopen(log_file_path, "r");
  char line[MAX_LINE_LEN];
  char word[MAX_LINE_LEN];
  int count[MAX_LINE_LEN];
  int i = 0;

  // Count the frequency of each word in the log
  while (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
    // Split the line into words
    char* words = strtok(line, " ");
    while (words != NULL && i < MAX_LINE_LEN) {
      word[i] = words;
      count[i] = 1;
      words = strtok(NULL, " ");
      i++;
    }
  }

  // Print the top 5 most common words
  int top_five[5];
  for (int i = 0; i < 5; i++) {
    top_five[i] = 0;
  }
  for (int i = 0; i < MAX_LINE_LEN; i++) {
    if (count[i] > top_five[4]) {
      top_five[4] = count[i];
      top_five[3] = top_five[3];
      top_five[2] = top_five[2];
      top_five[1] = top_five[1];
      top_five[0] = word[i];
    }
  }
  for (int i = 0; i < 5; i++) {
    printf("%d. %s\n", i + 1, top_five[i]);
  }

  fclose(log_file);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <log_file_path>\n", argv[0]);
    return 1;
  }
  log_analysis(argv[1]);
  return 0;
}