//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    perror("Error opening file");
    exit(1);
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  char *content = malloc(fsize + 1);
  if (content == NULL) {
    perror("Error allocating memory for file content");
    exit(1);
  }
  fread(content, 1, fsize, f);
  fclose(f);
  content[fsize] = '\0';
  return content;
}

char **split_lines(char *content, int *num_lines) {
  int line_count = 0;
  char **lines = NULL;
  char *p = content;
  while (*p != '\0') {
    if (*p == '\n') line_count++;
    p++;
  }
  lines = malloc(sizeof(char *) * (line_count + 1));
  if (lines == NULL) {
    perror("Error allocating memory for line pointers");
    exit(1);
  }
  int line_idx = 0;
  p = content;
  while (*p != '\0') {
    if (*p == '\n') {
      lines[line_idx] = p + 1;
      line_idx++;
    }
    p++;
  }
  lines[line_count] = NULL;
  *num_lines = line_count;
  return lines;
}

char **split_words(char *line, int *num_words) {
  int word_count = 0;
  char **words = NULL;
  char *p = line;
  while (*p != '\0') {
    if (isspace(*p)) word_count++;
    p++;
  }
  words = malloc(sizeof(char *) * (word_count + 1));
  if (words == NULL) {
    perror("Error allocating memory for word pointers");
    exit(1);
  }
  int word_idx = 0;
  p = line;
  while (*p != '\0') {
    if (isspace(*p)) {
      *p = '\0';
      words[word_idx] = p + 1;
      word_idx++;
    }
    p++;
  }
  words[word_count] = NULL;
  *num_words = word_count;
  return words;
}

void print_words(char **words, int num_words) {
  for (int i = 0; i < num_words; i++) {
    printf("%s ", words[i]);
  }
  printf("\n");
}

int main() {
  char *content = read_file("text.txt");
  int num_lines;
  char **lines = split_lines(content, &num_lines);
  for (int i = 0; i < num_lines; i++) {
    int num_words;
    char **words = split_words(lines[i], &num_words);
    print_words(words, num_words);
    free(words);
  }
  free(lines);
  free(content);
  return 0;
}