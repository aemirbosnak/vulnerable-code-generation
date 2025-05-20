//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char *html_beautify(char *html) {
  char *beautified_html = malloc(strlen(html) * 2);
  int level = 0;
  char *p = html;
  char *q = beautified_html;
  while (*p) {
    if (*p == '<') {
      *q++ = *p++;
      if (*p == '/') {
        *q++ = *p++;
      }
      while (*p && *p != '>') {
        *q++ = *p++;
      }
      *q++ = *p++;
      if (*p == '>') {
        *q++ = *p++;
        level++;
      }
    } else if (*p == '&') {
      *q++ = *p++;
      while (*p && *p != ';') {
        *q++ = *p++;
      }
      *q++ = *p++;
    } else if (*p == '\n') {
      *q++ = *p++;
      while (*p && *p == '\n') {
        *q++ = *p++;
      }
      for (int i = 0; i < level; i++) {
        *q++ = ' ';
      }
    } else {
      *q++ = *p++;
    }
  }
  *q = '\0';
  return beautified_html;
}

int main() {
  char *html = "<html><body><h1>Hello, world!</h1></body></html>";
  char *beautified_html = html_beautify(html);
  printf("%s", beautified_html);
  free(beautified_html);
  return 0;
}