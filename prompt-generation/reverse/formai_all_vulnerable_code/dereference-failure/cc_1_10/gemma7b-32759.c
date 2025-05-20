//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 20
#define MAX_CHAR 30

typedef struct Line {
  char **data;
  int lines;
  int max_chars;
} Line;

Line **create_line(int lines, int max_chars) {
  Line **line = malloc(sizeof(Line) * lines);
  for (int i = 0; i < lines; i++) {
    line[i] = malloc(sizeof(char *) * max_chars);
    line[i]->data = malloc(sizeof(char) * max_chars);
    line[i]->lines = lines;
    line[i]->max_chars = max_chars;
  }
  return line;
}

void print_line(Line *line) {
  for (int i = 0; i < line->lines; i++) {
    for (int j = 0; j < line->max_chars; j++) {
      printf("%c ", line->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  Line **lines = create_line(MAX_LINES, MAX_CHAR);

  // Write some ASCII art
  lines[0]->data[0] = "@";
  lines[0]->data[1] = "@";
  lines[0]->data[2] = "@";

  lines[1]->data[0] = "/";
  lines[1]->data[1] = "/";
  lines[1]->data[2] = "/";

  lines[2]->data[0] = "\\";
  lines[2]->data[1] = "\\";
  lines[2]->data[2] = "\\";

  print_line(lines);

  return 0;
}