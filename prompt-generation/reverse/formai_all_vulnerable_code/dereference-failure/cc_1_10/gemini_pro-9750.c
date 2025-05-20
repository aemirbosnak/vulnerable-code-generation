//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_LENGTH 10000

typedef struct {
  char *line;
  int length;
} LogLine;

typedef struct {
  LogLine *lines;
  int num_lines;
} Log;

Log *read_log(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  Log *log = malloc(sizeof(Log));
  log->lines = malloc(MAX_LOG_LENGTH * sizeof(LogLine));
  log->num_lines = 0;

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    int length = strlen(line);
    if (length > 0) {
      line[length - 1] = '\0';  // Remove newline character
      log->lines[log->num_lines].line = strdup(line);
      log->lines[log->num_lines].length = length;
      log->num_lines++;
    }
  }

  fclose(file);
  return log;
}

void free_log(Log *log) {
  for (int i = 0; i < log->num_lines; i++) {
    free(log->lines[i].line);
  }
  free(log->lines);
  free(log);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  Log *log = read_log(argv[1]);

  // TODO: Analyze the log here

  free_log(log);
  return EXIT_SUCCESS;
}