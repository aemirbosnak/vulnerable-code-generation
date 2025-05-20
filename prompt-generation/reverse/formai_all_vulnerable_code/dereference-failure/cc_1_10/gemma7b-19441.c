//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void xml_parser_init(char **buffer, int *buffer_size) {
  *buffer = malloc(MAX_BUFFER_SIZE);
  *buffer_size = MAX_BUFFER_SIZE;
}

void xml_parser_append(char **buffer, int *buffer_size, char data) {
  if (*buffer_size - 1 < 0) {
    *buffer = realloc(*buffer, (*buffer_size) * 2);
    *buffer_size *= 2;
  }
  (*buffer)[*buffer_size - 1] = data;
  (*buffer_size)++;
}

int xml_parser_parse(char *buffer, int buffer_size) {
  int i = 0;
  for (i = 0; i < buffer_size; i++) {
    if (buffer[i] == '<' && buffer[i + 1] == '>' && buffer[i + 2] == ' ') {
      return 1;
    }
  }
  return 0;
}

int main() {
  char *buffer = NULL;
  int buffer_size = 0;

  xml_parser_init(&buffer, &buffer_size);

  xml_parser_append(&buffer, &buffer_size, '<');
  xml_parser_append(&buffer, &buffer_size, 'a');
  xml_parser_append(&buffer, &buffer_size, '>');

  xml_parser_append(&buffer, &buffer_size, 'b');
  xml_parser_append(&buffer, &buffer_size, '>');

  if (xml_parser_parse(buffer, buffer_size)) {
    printf("XML element found.\n");
  } else {
    printf("No XML element found.\n");
  }

  free(buffer);

  return 0;
}