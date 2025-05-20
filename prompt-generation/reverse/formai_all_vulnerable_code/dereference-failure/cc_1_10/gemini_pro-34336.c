//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 256
#define MAX_DICTIONARY_SIZE 10000
#define MAX_SENTENCE_LEN 1024

char** dictionary[MAX_DICTIONARY_SIZE];
int dictionarySize = 0;

void loadDictionary() {
  FILE* dictionaryFile = fopen("dictionary.txt", "r");
  if (dictionaryFile == NULL) {
    fprintf(stderr, "Error opening dictionary file\n");
    exit(1);
  }

  char line[MAX_WORD_LEN];
  while (fgets(line, MAX_WORD_LEN, dictionaryFile) != NULL) {
    char* word = malloc(strlen(line) + 1);
    strcpy(word, line);
    dictionary[dictionarySize++] = word;
  }

  fclose(dictionaryFile);
}

void translateSentence(char* sentence) {
  char* word = strtok(sentence, " ");
  while (word != NULL) {
    int found = 0;
    for (int i = 0; i < dictionarySize; i++) {
      if (strcmp(word, dictionary[i]) == 0) {
        printf("%s ", dictionary[i]);
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("%s ", word);
    }
    word = strtok(NULL, " ");
  }
}

int main() {
  loadDictionary();

  char sentence[MAX_SENTENCE_LEN];
  printf("Enter a sentence to translate: ");
  gets(sentence);

  translateSentence(sentence);
  printf("\n");

  return 0;
}