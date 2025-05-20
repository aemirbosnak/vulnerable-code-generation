//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_WORD_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024

// Function to read a text file and count the frequency of each word
void analyze_file(const char *file_name) {
  int word_counts[256];
  int i;
  int j;
  char word[MAX_WORD_LENGTH];
  FILE *file;

  file = fopen(file_name, "r");
  assert(file != NULL);

  // Initialize word counts to 0
  for (i = 0; i < 256; i++) {
    word_counts[i] = 0;
  }

  // Read each line from the file and count the frequency of each word
  while (fgets(word, MAX_WORD_LENGTH, file) != NULL) {
    for (j = 0; j < strlen(word); j++) {
      int index = word[j] - 'a';
      if (index >= 0 && index < 256) {
        word_counts[index]++;
      }
    }
  }

  // Print the word counts
  for (i = 0; i < 256; i++) {
    if (word_counts[i] > 0) {
      printf("%d: %s\n", i + 1, word_counts[i] > 1 ? word_counts[i] + " times" : "1 time");
    }
  }

  fclose(file);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    return 1;
  }

  analyze_file(argv[1]);
  return 0;
}