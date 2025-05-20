//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define DICTIONARY_SIZE 370099

char *dictionary[DICTIONARY_SIZE];

void load_dictionary() {
  FILE *fp;
  char dict_word[MAX_WORD_SIZE];

  if ((fp = fopen("dictionary.txt", "r")) == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  int i = 0;
  while (fgets(dict_word, MAX_WORD_SIZE, fp)) {
    dictionary[i] = strdup(dict_word);
    if (dictionary[i][strlen(dictionary[i]) - 1] == '\n') {
      dictionary[i][strlen(dictionary[i]) - 1] = '\0';
    }
    i++;
  }

  fclose(fp);
}

void spell_check(const char *filename) {
  FILE *fp;
  char line[MAX_WORD_SIZE];

  if ((fp = fopen(filename, "r")) == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  int line_num = 1;
  while (fgets(line, MAX_WORD_SIZE, fp)) {
    char *word = strtok(line, " \n");
    while (word) {
      if (strlen(word) > MAX_WORD_SIZE) {
        printf("Error: %s at line %d is too long.\n", word, line_num);
      }
      // Strip punctuations
      for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
          memmove(&word[i], &word[i + 1], strlen(word) - i);
          i--;
        }
      }

      int first = 0;
      int last = DICTIONARY_SIZE - 1;
      int middle = (first + last) / 2;

      int found = 0;
      while (first <= last) {
        int cmp = strcmp(word, dictionary[middle]);
        if (cmp == 0) {
          found = 1;
          break;
        } else if (cmp < 0) {
          last = middle - 1;
        } else {
          first = middle + 1;
        }
        middle = (first + last) / 2;
      }

      if (!found) {
        printf("Error: %s at line %d is misspelled.\n", word, line_num);
      }

      word = strtok(NULL, " \n");
    }
    line_num++;
  }

  fclose(fp);
}

int main() {
  load_dictionary();
  spell_check("document.txt");
  return 0;
}