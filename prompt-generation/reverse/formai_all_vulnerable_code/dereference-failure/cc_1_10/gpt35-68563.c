//FormAI DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  FILE *fp;
  long length;
  char *buffer;
  int count = 0;

  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    printf("Unable to open file %s\n", argv[1]);
    exit(1);
  }

  // get file length
  fseek(fp, 0, SEEK_END);
  length = ftell(fp);
  rewind(fp);

  // allocate memory for file content
  buffer = (char*) malloc(length + 1);
  if (buffer == NULL)
  {
    printf("Memory allocation error\n");
    exit(1);
  }

  // read file content into buffer
  fread(buffer, 1, length, fp);

  // count words
  char *word = strtok(buffer, " \t\n\r");
  while (word) {
    count++;
    word = strtok(NULL, " \t\n\r");
  }

  printf("Total words in file %s: %d\n", argv[1], count);

  // cleanup
  free(buffer);
  fclose(fp);

  return 0;
}