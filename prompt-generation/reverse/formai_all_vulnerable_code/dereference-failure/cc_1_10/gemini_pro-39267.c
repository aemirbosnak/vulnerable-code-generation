//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAX_LINE_LEN 1024

// Function to read a line from a file
char *readLine(FILE *fp) {
  char *line = malloc(MAX_LINE_LEN);
  if (line == NULL) {
    perror("Error allocating memory for line");
    exit(1);
  }
  if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
    free(line);
    return NULL;
  }
  size_t len = strlen(line);
  if (len > 0 && line[len - 1] == '\n') {
    line[len - 1] = '\0';
  }
  return line;
}

// Function to find the longest line in a file
int findLongestLine(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }
  int max_len = 0;
  char *line;
  while ((line = readLine(fp)) != NULL) {
    int len = strlen(line);
    if (len > max_len) {
      max_len = len;
    }
    free(line);
  }
  fclose(fp);
  return max_len;
}

// Function to main
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }
  int max_len = findLongestLine(argv[1]);
  printf("The longest line in %s is %d characters long.\n", argv[1], max_len);
  return 0;
}