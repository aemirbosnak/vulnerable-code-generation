//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100000

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char **lines = malloc(sizeof(char *) * MAX_NUM_LINES);
  if (lines == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  int num_lines = 0;
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    if (num_lines == MAX_NUM_LINES) {
      lines = realloc(lines, sizeof(char *) * (MAX_NUM_LINES + 10000));
      if (lines == NULL) {
        perror("realloc");
        return EXIT_FAILURE;
      }
    }
    lines[num_lines] = strdup(line);
    if (lines[num_lines] == NULL) {
      perror("strdup");
      return EXIT_FAILURE;
    }
    num_lines++;
  }

  fclose(fp);

  struct timeval start, end;
  gettimeofday(&start, NULL);

  // Do something with the lines here.

  gettimeofday(&end, NULL);

  double elapsed_seconds = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
  printf("Elapsed time: %f seconds\n", elapsed_seconds);

  // Free the allocated memory.

  for (int i = 0; i < num_lines; i++) {
    free(lines[i]);
  }
  free(lines);

  return EXIT_SUCCESS;
}