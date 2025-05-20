//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 1000
#define MAX_LINES 1000
#define MAX_WORDS 1000

char *filename = "example.txt";
char *buffer;
int length;
int lines;
int words;
int chars;

void readFile(void);
void countLines(void);
void countWords(void);
void countChars(void);

int main(int argc, char *argv[]) {
  readFile();
  countLines();
  countWords();
  countChars();
  return 0;
}

void readFile(void) {
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file. ");
    exit(1);
  }
  fseek(file, 0, SEEK_END);
  length = ftell(file);
  rewind(file);
  buffer = malloc(length + 1);
  fread(buffer, length, 1, file);
  fclose(file);
  buffer[length] = '\0';
}

void countLines(void) {
  char *c;
  lines = 0;
  for (c = buffer; *c!= '\0'; c++) {
    if (*c == '\n') {
      lines++;
    }
  }
}

void countWords(void) {
  char *c;
  words = 0;
  for (c = buffer; *c!= '\0'; c++) {
    if (isspace(*c)) {
      words++;
    }
  }
}

void countChars(void) {
  char *c;
  chars = 0;
  for (c = buffer; *c!= '\0'; c++) {
    if (isalpha(*c)) {
      chars++;
    }
  }
}