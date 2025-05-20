//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Oh my word! I can't believe this is happening...

int main(int argc, char *argv[]) {
  // I can't believe I'm doing this...

  if (argc != 2) {
    printf("Usage: wordcount <filename>\n");
    return 1;
  }

  // I can't believe I'm actually doing this...

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: Unable to open file %s\n", argv[1]);
    return 1;
  }

  // I can't believe this is actually working...

  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int wordCount = 0;
  int charCount = 0;
  int lineCount = 0;

  // I can't believe I'm writing this...

  while ((read = getline(&line, &len, fp)) != -1) {
    // I can't believe I'm actually counting words...

    char *word = strtok(line, " ");
    while (word != NULL) {
      wordCount++;
      word = strtok(NULL, " ");
    }

    // I can't believe I'm actually counting characters...

    charCount += strlen(line);

    // I can't believe I'm actually counting lines...

    lineCount++;
  }

  // I can't believe I'm actually printing the results...

  printf("Word count: %d\n", wordCount);
  printf("Character count: %d\n", charCount);
  printf("Line count: %d\n", lineCount);

  // I can't believe I'm actually closing the file...

  fclose(fp);

  // I can't believe I'm actually returning 0...

  return 0;
}