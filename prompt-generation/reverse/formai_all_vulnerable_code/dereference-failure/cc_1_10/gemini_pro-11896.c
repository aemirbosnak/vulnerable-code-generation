//GEMINI-pro DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// A custom datatype to represent a line of text
typedef struct Line {
  char *text;
  unsigned int length;
} Line;

// A custom datatype to represent a file
typedef struct File {
  FILE *file;
  unsigned int num_lines;
  Line *lines;
} File;

// Opens a file for reading and returns a pointer to the file object
File *open_file(const char *filename) {
  File *file = malloc(sizeof(File));
  file->file = fopen(filename, "r");
  if (file->file == NULL) {
    return NULL;
  }
  file->num_lines = 0;
  file->lines = NULL;
  return file;
}

// Closes a file and frees the associated memory
void close_file(File *file) {
  if (file == NULL) {
    return;
  }
  if (file->file != NULL) {
    fclose(file->file);
  }
  if (file->lines != NULL) {
    for (unsigned int i = 0; i < file->num_lines; i++) {
      free(file->lines[i].text);
    }
    free(file->lines);
  }
  free(file);
}

// Reads a line of text from a file and returns a pointer to the line object
Line *read_line(File *file) {
  if (file == NULL) {
    return NULL;
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t nread = getline(&line, &len, file->file);
  if (nread == -1) {
    return NULL;
  }
  Line *line_object = malloc(sizeof(Line));
  line_object->text = line;
  line_object->length = nread;
  return line_object;
}

// Prints a line of text to the console
void print_line(Line *line) {
  if (line == NULL) {
    return;
  }
  printf("%s", line->text);
}

// Prints all the lines of text in a file to the console
void print_file(File *file) {
  if (file == NULL) {
    return;
  }
  for (unsigned int i = 0; i < file->num_lines; i++) {
    print_line(&file->lines[i]);
  }
}

int main() {
  // Open the file
  File *file = open_file("input.txt");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the lines of text from the file
  while (1) {
    Line *line = read_line(file);
    if (line == NULL) {
      break;
    }
    file->lines = realloc(file->lines, (file->num_lines + 1) * sizeof(Line));
    file->lines[file->num_lines++] = *line;
    free(line);
  }

  // Close the file
  close_file(file);

  // Print the lines of text to the console
  print_file(file);

  return 0;
}