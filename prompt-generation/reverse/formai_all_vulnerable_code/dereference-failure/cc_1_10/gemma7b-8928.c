//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alien_translator(char **alien_sentence) {
  int alien_sentence_length = 0;
  for (int i = 0; alien_sentence[i] != NULL; i++) {
    alien_sentence_length++;
  }

  char **translated_sentence = (char **)malloc(alien_sentence_length * sizeof(char *));

  for (int i = 0; alien_sentence[i] != NULL; i++) {
    translated_sentence[i] = (char *)malloc((alien_sentence_length + 1) * sizeof(char));
  }

  for (int i = 0; alien_sentence[i] != NULL; i++) {
    int alien_word_length = 0;
    char *alien_word = alien_sentence[i];
    for (int j = 0; alien_word[j] != '\0'; j++) {
      alien_word_length++;
    }

    int translated_word_length = alien_word_length * 2;
    char *translated_word = (char *)malloc(translated_word_length * sizeof(char));

    for (int j = 0; alien_word[j] != '\0'; j++) {
      translated_word[j] = alien_word[j] * 2;
    }

    translated_sentence[i] = translated_word;
  }

  for (int i = 0; alien_sentence[i] != NULL; i++) {
    free(translated_sentence[i]);
  }

  free(translated_sentence);
}

int main() {
  char **alien_sentence = (char **)malloc(10 * sizeof(char *));

  alien_sentence[0] = "Q'krpl zybn tb'f vhr't";
  alien_sentence[1] = "R'nml wr'l cz'k";
  alien_sentence[2] = "P'nhl nd'r";

  alien_translator(alien_sentence);

  for (int i = 0; alien_sentence[i] != NULL; i++) {
    printf("%s\n", alien_sentence[i]);
  }

  free(alien_sentence);

  return 0;
}