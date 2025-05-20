//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Read the file into a buffer.
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  fseek(fp, 0, SEEK_END);
  long len = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *buf = malloc(len + 1);
  if (buf == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  fread(buf, 1, len, fp);
  fclose(fp);
  buf[len] = '\0';

  // Tokenize the buffer.
  char *tokens[1024];
  int num_tokens = 0;
  char *token = strtok(buf, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Count the number of occurrences of each token.
  int counts[1024];
  memset(counts, 0, sizeof(counts));
  for (int i = 0; i < num_tokens; i++) {
    for (int j = 0; j < num_tokens; j++) {
      if (strcmp(tokens[i], tokens[j]) == 0) {
        counts[i]++;
      }
    }
  }

  // Print the tokens and their counts.
  for (int i = 0; i < num_tokens; i++) {
    printf("%s: %d\n", tokens[i], counts[i]);
  }

  // Free the buffer.
  free(buf);

  return EXIT_SUCCESS;
}