//FormAI DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("Usage: %s <dictionary file> <text file>\n", argv[0]);
    return 1;
  }

  FILE* dict_file = fopen(argv[1], "r");

  if (!dict_file) {
    printf("Error: Could not open dictionary file %s\n", argv[1]);
    return 1;
  }

  FILE* text_file = fopen(argv[2], "r");

  if (!text_file) {
    printf("Error: Could not open text file %s\n", argv[2]);
    return 1;
  }

  char* word = malloc(100);
  char* line = malloc(1000);
  int line_num = 0;
  int word_num = 0;
  int errors = 0;

  while (fgets(line, 1000, text_file)) {
    line_num++;
    char* token = strtok(line, " ,.;()'\n\"");
    while (token) {
      word_num++;
      int dict_word_found = 0;
      fseek(dict_file, 0, SEEK_SET);
      while (fgets(word, 100, dict_file)) {
        if (word[strlen(word) - 1] == '\n') {
          word[strlen(word) - 1] = '\0';
        }
        if (strcmp(token, word) == 0) {
          dict_word_found = 1;
          break;
        }
      }
      if (!dict_word_found) {
        errors++;
        printf("Error in line %d, word %d: %s\n", line_num, word_num, token);
      }
      token = strtok(NULL, " ,.;()'\n\"");
    }
  }

  printf("\n");
  printf("Total errors found: %d\n", errors);

  fclose(dict_file);
  fclose(text_file);
  free(word);
  free(line);

  return 0;
}