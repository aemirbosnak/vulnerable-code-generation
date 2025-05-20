//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
  char* word;
  int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void insert_word(char* word) {
  int i;
  for (i = 0; i < num_words; i++) {
    if (strcmp(dictionary[i].word, word) == 0) {
      dictionary[i].count++;
      return;
    }
  }

  if (num_words == MAX_WORDS) {
    printf("Error: dictionary is full.\n");
    return;
  }

  dictionary[num_words].word = malloc(strlen(word) + 1);
  strcpy(dictionary[num_words].word, word);
  dictionary[num_words].count = 1;
  num_words++;
}

int find_word(char* word) {
  int i;
  for (i = 0; i < num_words; i++) {
    if (strcmp(dictionary[i].word, word) == 0) {
      return i;
    }
  }

  return -1;
}

void load_dictionary(char* filename) {
  FILE* fp = fopen(filename, "r");
  char line[MAX_WORD_LENGTH];

  while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
    char* word = strtok(line, "\n");
    insert_word(word);
  }

  fclose(fp);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s dictionary.txt\n", argv[0]);
    return 1;
  }

  load_dictionary(argv[1]);

  char input[MAX_WORD_LENGTH];
  while (scanf("%s", input) != EOF) {
    int index = find_word(input);
    if (index == -1) {
      printf("%s is not in the dictionary.\n", input);
    } else {
      printf("%s occurs %d times in the dictionary.\n", input, dictionary[index].count);
    }
  }

  return 0;
}