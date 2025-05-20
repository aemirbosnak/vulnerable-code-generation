//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void beautify(char *html) {
  char *p, *q;
  int indent = 0;

  for (p = html; *p; p++) {
    if (*p == '<') {
      // Start of a tag
      if (p[1] == '/') {
        // Closing tag
        indent--;
        printf("%*s%s\n", indent * 2, "", p);
      } else {
        // Opening tag
        printf("%*s%s", indent * 2, "", p);
        indent++;
      }
    } else if (*p == '>') {
      // End of a tag
      printf("\n");
    } else {
      // Text
      q = p;
      while (*q && *q != '<') {
        q++;
      }
      *q = '\0';
      printf("%*s%s", indent * 2, "", p);
      p = q;
      q--;
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char *html = malloc(MAX_LINE_LENGTH);
  if (html == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  size_t n;
  while ((n = fread(html, 1, MAX_LINE_LENGTH, fp)) > 0) {
    beautify(html);
  }

  free(html);
  fclose(fp);

  return EXIT_SUCCESS;
}