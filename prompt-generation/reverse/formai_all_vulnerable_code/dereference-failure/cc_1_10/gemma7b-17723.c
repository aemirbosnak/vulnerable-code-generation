//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char *html_code) {
  char *buffer = malloc(MAX_BUFFER_SIZE);
  int buffer_size = 0;
  int i = 0;
  int in_tag = 0;

  for (i = 0; html_code[i] != '\0'; i++) {
    if (in_tag) {
      if (html_code[i] == '>' && buffer_size > 0) {
        buffer[buffer_size++] = '\n';
        buffer[buffer_size++] = ' ';
      } else if (html_code[i] == '/' && buffer_size > 0) {
        buffer[buffer_size++] = '\n';
      } else {
        buffer[buffer_size++] = html_code[i];
      }
    } else {
      if (html_code[i] == '<' && buffer_size > 0) {
        buffer[buffer_size++] = '\n';
      }
      buffer[buffer_size++] = html_code[i];
    }

    if (html_code[i] == '>' && !in_tag) {
      in_tag = 1;
    }
  }

  if (buffer_size > 0) {
    buffer[buffer_size] = '\0';
    printf("%s", buffer);
  } else {
    printf("No HTML code to beautify.");
  }

  free(buffer);
}

int main() {
  char *html_code = "<p>This is a <b>bold</b> sentence.</p>\n";
  beautify_html(html_code);

  return 0;
}