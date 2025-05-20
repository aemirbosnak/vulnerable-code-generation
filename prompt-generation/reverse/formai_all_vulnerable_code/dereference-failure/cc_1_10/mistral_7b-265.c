//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE 1024
#define KEYWORDS_COUNT 5
#define KEYWORDS_LENGTHS_ARRAY_LENGTH 10

char *keywords[KEYWORDS_COUNT] = { "neon", "hack", "cyber", "data", "matrix" };
int keywords_lengths[KEYWORDS_COUNT][KEYWORDS_LENGTHS_ARRAY_LENGTH] = {
  {3, 4, 5, 4, 6, 5, 6, 5, 5, 6},
  {4, 4, 5, 4, 5, 5, 5, 5, 6, 6},
  {5, 4, 5, 5, 5, 6, 6, 5, 6, 6},
  {4, 4, 4, 5, 5, 5, 5, 6, 6, 6},
  {5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
};

void process_line(char *line) {
  int line_length = strlen(line);
  int i, j;
  for (i = 0; i < KEYWORDS_COUNT; i++) {
    int keyword_length = keywords_lengths_array_length(keywords[i]);
    for (j = 0; j <= line_length - keyword_length; j++) {
      int k;
      int match = 1;
      for (k = 0; k < keyword_length; k++) {
        if (line[j + k] != keywords[i][k]) {
          match = 0;
          break;
        }
      }
      if (match) {
        printf("%s%s%s ", "\033[1;31m", keywords[i], "\033[0m");
        int pos = j;
        while (line[pos] != ' ' && line[pos] != '\0') {
          printf("%c", line[pos++]);
        }
        printf(" %s\n", "\033[1;34m>>\033[0m");
        return;
      }
    }
  }
  printf("%s\n", line);
}

int keywords_lengths_array_length(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

int main(int argc, char **argv) {
  int file_descriptor;
  char file_name[MAX_LINE];
  char line[MAX_LINE];
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  strcpy(file_name, argv[1]);
  file_descriptor = open(file_name, O_RDONLY);
  if (file_descriptor < 0) {
    perror("Error opening file");
    return 1;
  }
  while (read(file_descriptor, line, MAX_LINE) > 0) {
    process_line(line);
  }
  close(file_descriptor);
  return 0;
}