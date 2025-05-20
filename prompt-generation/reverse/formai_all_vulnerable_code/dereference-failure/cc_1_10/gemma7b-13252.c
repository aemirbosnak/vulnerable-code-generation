//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

int main() {
  char **lines = NULL;
  int numLines = 0;

  // Allocate memory for the lines
  lines = malloc(MAX_LINES * sizeof(char *));
  if (lines == NULL) {
    return EXIT_FAILURE;
  }

  // Get the number of lines from the user
  printf("Enter the number of lines: ");
  scanf("%d", &numLines);

  // Allocate memory for each line
  for (int i = 0; i < numLines; i++) {
    lines[i] = malloc(MAX_LINES * sizeof(char));
    if (lines[i] == NULL) {
      return EXIT_FAILURE;
    }
  }

  // Get the lines from the user
  for (int i = 0; i < numLines; i++) {
    printf("Enter line %d: ", i + 1);
    scanf("%s", lines[i]);
  }

  // Beautify the lines
  for (int i = 0; i < numLines; i++) {
    lines[i] = realloc(lines[i], strlen(lines[i]) * 2 + 1);
    lines[i][0] = ' ';
  }

  // Print the beautified lines
  for (int i = 0; i < numLines; i++) {
    printf("%s\n", lines[i]);
  }

  // Free the memory
  for (int i = 0; i < numLines; i++) {
    free(lines[i]);
  }
  free(lines);

  return EXIT_SUCCESS;
}