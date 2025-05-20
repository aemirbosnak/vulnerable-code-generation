//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUMMARY_LENGTH 256

char *summarize(char *text) {
  char *summary = malloc(MAX_SUMMARY_LENGTH);
  int summary_length = 0;

  char *line = strtok(text, "\n");
  while (line != NULL) {
    if (strlen(line) > MAX_LINE_LENGTH) {
      fprintf(stderr, "Error: Line too long (%d characters)\n", strlen(line));
      free(summary);
      return NULL;
    }

    // TODO: Actually summarize the line here

    if (summary_length + strlen(line) + 1 > MAX_SUMMARY_LENGTH) {
      fprintf(stderr, "Error: Summary too long\n");
      free(summary);
      return NULL;
    }

    strcat(summary, line);
    strcat(summary, " ");

    line = strtok(NULL, "\n");
  }

  return summary;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *text = malloc(file_size + 1);
  if (text == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for text\n");
    fclose(fp);
    return EXIT_FAILURE;
  }

  fread(text, 1, file_size, fp);
  fclose(fp);

  char *summary = summarize(text);
  if (summary == NULL) {
    fprintf(stderr, "Error: Could not summarize text\n");
    free(text);
    return EXIT_FAILURE;
  }

  printf("%s\n", summary);

  free(summary);
  free(text);

  return EXIT_SUCCESS;
}