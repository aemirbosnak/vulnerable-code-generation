//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *data;
  int length;
} String;

String *new_string(int length) {
  String *string = malloc(sizeof(String));
  string->data = malloc(length + 1);
  string->data[length] = '\0';
  string->length = length;
  return string;
}

void free_string(String *string) {
  free(string->data);
  free(string);
}

String *read_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  String *string = new_string(0);

  char buffer[MAX_LINE_LENGTH];
  while (fgets(buffer, MAX_LINE_LENGTH, file)) {
    int length = strlen(buffer);
    string->data = realloc(string->data, string->length + length + 1);
    memcpy(string->data + string->length, buffer, length);
    string->length += length;
  }

  fclose(file);

  return string;
}

void write_file(const char *filename, String *string) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  fwrite(string->data, string->length, 1, file);

  fclose(file);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  String *string = read_file(argv[1]);

  // Beautify the HTML.

  // Replace all whitespace characters with a single space character.
  for (int i = 0; i < string->length; i++) {
    if (isspace(string->data[i])) {
      string->data[i] = ' ';
    }
  }

  // Remove all empty lines.
  int j = 0;
  for (int i = 0; i < string->length; i++) {
    if (string->data[i] != '\n') {
      string->data[j++] = string->data[i];
    }
  }
  string->length = j;

  // Add a newline character at the end of the string.
  string->data[string->length++] = '\n';

  // Write the beautified HTML to the output file.
  write_file(argv[2], string);

  free_string(string);

  return EXIT_SUCCESS;
}