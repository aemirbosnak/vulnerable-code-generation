//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: artistic
// The Artistic Text Processor

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Function to print a line of artistic text
void artistic_print(char *line) {
  printf("%s\n", line);
}

// Function to process a block of text
void process_block(char *text) {
  // Split the text into individual lines
  char *lines[10];
  int i;
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] == '\n') {
      lines[i/2] = text + i + 1;
      i++;
    }
  }

  // Apply artistic effects to each line
  for (i = 0; i < 10; i++) {
    char *line = lines[i];
    if (strlen(line) > 0) {
      // Randomly change some characters to uppercase
      for (int j = 0; j < strlen(line); j++) {
        if (rand() % 2 == 0) {
          line[j] = toupper(line[j]);
        }
      }

      // Add some random punctuation
      for (int j = 0; j < 5; j++) {
        if (rand() % 2 == 0) {
          line[strlen(line) - 1] = ',';
        }
      }

      // Print the line of artistic text
      artistic_print(line);
    }
  }
}

int main() {
  char text[MAX_LENGTH];
  gets(text);

  // Process the block of text
  process_block(text);

  return 0;
}