//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LINES 1000

typedef struct {
  char *text;
  int length;
} Line;

typedef struct {
  Line *lines;
  int num_lines;
} Ebook;

Ebook *ebook_create(FILE *file) {
  Ebook *ebook = malloc(sizeof(Ebook));
  ebook->lines = malloc(sizeof(Line) * MAX_LINES);
  ebook->num_lines = 0;

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file)) {
    ebook->lines[ebook->num_lines].text = strdup(line);
    ebook->lines[ebook->num_lines].length = strlen(line);
    ebook->num_lines++;
  }

  return ebook;
}

void ebook_destroy(Ebook *ebook) {
  for (int i = 0; i < ebook->num_lines; i++) {
    free(ebook->lines[i].text);
  }
  free(ebook->lines);
  free(ebook);
}

void ebook_print(Ebook *ebook) {
  for (int i = 0; i < ebook->num_lines; i++) {
    printf("%s", ebook->lines[i].text);
  }
}

int main() {
  FILE *file = fopen("ebook.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  Ebook *ebook = ebook_create(file);
  ebook_print(ebook);
  ebook_destroy(ebook);

  fclose(file);
  return EXIT_SUCCESS;
}