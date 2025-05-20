//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a human word to a cat word
char *cat_speak(char *word) {
  int i;
  char *cat_word = malloc(strlen(word) + 1);
  for (i = 0; i < strlen(word); i++) {
    if (word[i] == 'a' || word[i] == 'A') {
      cat_word[i] = 'm';
    } else if (word[i] == 'e' || word[i] == 'E') {
      cat_word[i] = 'o';
    } else if (word[i] == 'i' || word[i] == 'I') {
      cat_word[i] = 'a';
    } else if (word[i] == 'o' || word[i] == 'O') {
      cat_word[i] = 'e';
    } else if (word[i] == 'u' || word[i] == 'U') {
      cat_word[i] = 'i';
    } else {
      cat_word[i] = word[i];
    }
  }
  return cat_word;
}

// Function to translate a sentence into cat language
char *translate_sentence(char *sentence) {
  int i, word_count = 0;
  char *cat_sentence, **words;
  words = malloc(sizeof(char *) * 100);
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[word_count++] = strdup(word);
    word = strtok(NULL, " ");
  }
  cat_sentence = malloc(strlen(sentence) + 1);
  for (i = 0; i < word_count; i++) {
    strcat(cat_sentence, cat_speak(words[i]));
    strcat(cat_sentence, " ");
    free(words[i]);
  }
  free(words);
  return cat_sentence;
}

int main() {
  char *sentence = "Hello world!";
  char *cat_sentence = translate_sentence(sentence);
  printf("Original sentence: %s\n", sentence);
  printf("Cat-speak sentence: %s\n", cat_sentence);
  free(cat_sentence);
  return 0;
}