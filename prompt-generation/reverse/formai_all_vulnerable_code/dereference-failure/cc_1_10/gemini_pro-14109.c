//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *input;
  int length;
  int capacity;
} InputBuffer;

InputBuffer *new_input_buffer() {
  InputBuffer *buffer = malloc(sizeof(InputBuffer));
  buffer->input = NULL;
  buffer->length = 0;
  buffer->capacity = 0;
  return buffer;
}

void free_input_buffer(InputBuffer *buffer) {
  free(buffer->input);
  free(buffer);
}

void append_to_input_buffer(InputBuffer *buffer, const char *s, int len) {
  if (buffer->length + len + 1 > buffer->capacity) {
    buffer->capacity = buffer->capacity * 2 + 1;
    buffer->input = realloc(buffer->input, buffer->capacity);
  }
  memcpy(buffer->input + buffer->length, s, len);
  buffer->length += len;
  buffer->input[buffer->length] = '\0';
}

void sanitize_input_buffer(InputBuffer *buffer) {
  for (int i = 0; i < buffer->length; i++) {
    if (buffer->input[i] == '<') {
      buffer->input[i] = '&';
    } else if (buffer->input[i] == '>') {
      buffer->input[i] = '&';
    }
  }
}

int main() {
  InputBuffer *input_buffer = new_input_buffer();
  char buffer[1024];
  while (1) {
    printf("Enter your input: ");
    fgets(buffer, sizeof(buffer), stdin);
  
    append_to_input_buffer(input_buffer, buffer, strlen(buffer));
    sanitize_input_buffer(input_buffer);
    printf("Sanitized input: %s", input_buffer->input);
  }
  free_input_buffer(input_buffer);
  return 0;
}