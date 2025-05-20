//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20

int main(int argc, char *argv[]) {
  char *filename = argv[1];
  char *delim = argv[2];
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    printf("Could not open file %s\n", filename);
    exit(1);
  }
  
  char line[1024];
  char *token;
  char *cols[MAX_COLS];
  int num_cols = 0;

  fgets(line, 1024, fp);

  // Parse the column headers
  for (token = strtok(line, delim); token && num_cols < MAX_COLS; token = strtok(NULL, delim)) {
    cols[num_cols++] = strdup(token);
  }

  // Print out the column headers
  for (int i = 0; i < num_cols; i++) {
    printf("%s\t", cols[i]);
  }
  printf("\n");

  // Parse and print out each row
  while (fgets(line, 1024, fp)) {
    num_cols = 0;
    for (token = strtok(line, delim); token && num_cols < MAX_COLS; token = strtok(NULL, delim)) {
      cols[num_cols++] = strdup(token);
    }
    for (int i = 0; i < num_cols; i++) {
      printf("%s\t", cols[i]);
    }
    printf("\n");
  }

  // Free memory
  for (int i = 0; i < num_cols; i++) {
    free(cols[i]);
  }

  fclose(fp);
  return 0;
}