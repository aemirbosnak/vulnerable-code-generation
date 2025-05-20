//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 255

char **wordList;
char **sentence;

void analyze_sentence() {
  sentence = malloc(MAX_SENTENCE_LENGTH);
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  // Remove punctuation and convert to lowercase
  char *p = sentence;
  while (*p) {
    *p = tolower(*p);
    if (!isalnum(*p)) *p = '\0';
    p++;
  }

  // Tokenize the sentence
  wordList = malloc(MAX_WORDS * sizeof(char *));
  char *word = strtok(sentence, " ");
  int i = 0;
  while (word) {
    wordList[i++] = word;
    word = strtok(NULL, " ");
  }

  // Analyze the words
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(wordList[i], "spam") == 0) {
      printf("Spam detected!\n");
      free(sentence);
      free(wordList);
      exit(0);
    }
  }

  free(sentence);
  free(wordList);
}

int main() {
  analyze_sentence();
  return 0;
}