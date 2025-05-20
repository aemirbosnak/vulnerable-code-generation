//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20

typedef struct alien_word {
  char *word;
  int translation;
} alien_word;

alien_word alien_words[MAX_WORDS];

void translate_alien(char *alien_phrase) {
  int i = 0;
  char *word = NULL;
  alien_word *current_word = NULL;

  while (alien_phrase[i] != '\0') {
    word = malloc(20);
    current_word = &alien_words[i];

    for (int j = 0; alien_phrase[j] != '\0' && alien_phrase[j] != ' '; j++) {
      word[j] = alien_phrase[j];
    }

    current_word->word = word;
    current_word->translation = translate_word(word);

    i++;
  }

  free(alien_phrase);
}

int translate_word(char *word) {
  int i = 0;
  int translation = 0;

  for (i = 0; word[i] != '\0'; i++) {
    switch (word[i]) {
      case 'a':
        translation += 1;
        break;
      case 'b':
        translation += 2;
        break;
      case 'c':
        translation += 3;
        break;
      case 'd':
        translation += 4;
        break;
      case 'e':
        translation += 5;
        break;
      case 'f':
        translation += 6;
        break;
      case 'g':
        translation += 7;
        break;
      case 'h':
        translation += 8;
        break;
      case 'i':
        translation += 9;
        break;
      case 'j':
        translation += 10;
        break;
    }
  }

  return translation;
}

int main() {
  alien_words[0].word = "blorg";
  alien_words[0].translation = 10;

  alien_words[1].word = "spork";
  alien_words[1].translation = 20;

  translate_alien("blorg spork");

  for (int i = 0; i < MAX_WORDS; i++) {
    printf("%s translates to %d\n", alien_words[i].word, alien_words[i].translation);
  }

  return 0;
}