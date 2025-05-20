//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The case of the unindented HTML
int main(int argc, char *argv[]) {
  // The initial investigation
  if (argc != 2) {
    printf("Elementary, my dear Watson! You must provide a filename.\n");
    return 1;
  }

  // Open the case file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("The file could not be opened, my dear Watson.\n");
    return 1;
  }

  // Read the contents of the file
  char *html = NULL;
  size_t len = 0;
  getline(&html, &len, fp);
  fclose(fp);

  // Examine the evidence
  char *indented = malloc(strlen(html) * 4);
  int indent_level = 0;
  int i, j;
  for (i = 0, j = 0; html[i] != '\0'; i++) {
    switch (html[i]) {
      case '<':
        if (html[i + 1] == '/') {
          indent_level--;
        } else {
          indent_level++;
        }
        for (int k = 0; k < indent_level; k++) {
          indented[j++] = ' ';
        }
        indented[j++] = html[i++];
        indented[j++] = html[i];
        break;
      case '>':
        indented[j++] = html[i];
        break;
      default:
        indented[j++] = html[i];
        break;
    }
  }
  indented[j] = '\0';

  // Present the findings
  printf("The indented HTML, my dear Watson:\n%s\n", indented);

  // Clean up the crime scene
  free(html);
  free(indented);

  return 0;
}