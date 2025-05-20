//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct {
  char buffer[MAX_BUFFER_SIZE];
  int head, tail;
} Buffer;

void initialize_buffer(Buffer *b) {
  b->head = 0;
  b->tail = MAX_BUFFER_SIZE - 1;
}

int insert_into_buffer(Buffer *b, char data) {
  if ((b->tail - b->head) >= MAX_BUFFER_SIZE - 1) {
    return -1;
  }
  b->buffer[b->head++] = data;
  return 0;
}

void beautify_html(char *html) {
  Buffer *in_buffer = malloc(sizeof(Buffer));
  initialize_buffer(in_buffer);

  Buffer *out_buffer = malloc(sizeof(Buffer));
  initialize_buffer(out_buffer);

  char current_tag = '\0';
  int i = 0;

  for (; html[i] != '\0'; i++) {
    switch (html[i]) {
      case '<':
        current_tag = html[i + 1];
        insert_into_buffer(out_buffer, '\n');
        insert_into_buffer(out_buffer, ' ');
        break;
      case '>':
        insert_into_buffer(out_buffer, ' ');
        insert_into_buffer(out_buffer, '\n');
        break;
      default:
        if (current_tag != '\0') {
          insert_into_buffer(out_buffer, ' ');
        }
        insert_into_buffer(out_buffer, html[i]);
    }
  }

  insert_into_buffer(out_buffer, '\n');

  free(in_buffer);
  free(out_buffer);

  return;
}

int main() {
  char html[] = "<p><b>This is a sample HTML string.</b></p>";
  beautify_html(html);

  printf("%s", html);

  return 0;
}