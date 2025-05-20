//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int i = 0;
  int line_number = 1;
  FILE *fp = fopen("source.c", "r");

  // Read file line by line
  while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
    // Remove unnecessary characters
    char *p = buffer;
    while (*p) {
      if (*p == '/' && p[1] == '/') {
        p++;
      } else if (*p == '#') {
        p++;
      } else if (*p == '{' && p[1] != '/') {
        p++;
      } else if (*p == '}' && p[1] != '/') {
        p++;
      } else if (*p == ' ' && p[0] == ' ' && p[1] == ' ') {
        *p = '\0';
      } else {
        p++;
      }
    }

    // Indent lines appropriately
    int num_tabs = 0;
    if (buffer[0] == '{' || buffer[0] == '}') {
      num_tabs = 2;
    } else if (buffer[0] == '}') {
      num_tabs = -2;
    } else {
      num_tabs = 1;
    }

    // Print the line with beautified formatting
    printf("%d: %s\n", line_number, buffer);

    line_number++;
  }

  fclose(fp);

  return 0;
}