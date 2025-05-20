//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000
#define MAX_WORDS_IN_SENTENCE 50

char* dictionary[] = {"HELLO", "WORLD", "I", "AM", "AN", "ALIEN", "FROM", "ANOTHER", "PLANET", "I", "SPEAK", "YOUR", "LANGUAGE", "NOW", "I", "HAVE", "A", "MESSAGE", "FOR", "YOU", "I", "COME", "IN", "PEACE", "I", "DO", "NOT", "WANT", "TO", "HURT", "YOU", "I", "JUST", "WANT", "TO", "LEARN", "ABOUT", "YOUR", "CULTURE", "AND", "YOUR", "PEOPLE", "I", "HOPE", "THAT", "YOU", "WILL", "ACCEPT", "ME", "AND", "MY", "FELLOW", "ALIENS", "INTO", "YOUR", "SOCIETY", "I", "BELIEVE", "THAT", "WE", "CAN", "LIVE", "TOGETHER", "IN", "PEACE", "AND", "HARMONY", "THANK", "YOU", "FOR", "LISTENING"};
char* alien_language[] = {"XROO", "XLOO", "I", "ME", "MI", "KLOK", "LO", "NA", "KIL", "I", "UKO", "PA", "NIF", "NOW", "I", "FI", "A", "MAK", "LI", "PA", "I", "KOM", "IN", "PES", "I", "DO", "NI", "WANT", "LI", "UL", "PA", "I", "JUS", "WANT", "LI", "LAN", "LO", "PA", "NIF", "AND", "PA", "PIL", "I", "HAP", "TA", "PA", "WIL", "AKP", "ME", "AND", "MI", "FEL", "KLOK", "LO", "PA", "SI", "I", "BEL", "TA", "PA", "WE", "KAN", "LI", "TEG", "IN", "PES", "AND", "HAM", "TANK", "PA", "LI", "NIF"};
int dictionary_size = sizeof(dictionary) / sizeof(char*);
int alien_language_size = sizeof(alien_language) / sizeof(char*);

char* translate_word(char* word) {
  int i;
  for (i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return alien_language[i];
    }
  }
  return NULL;
}

char* translate_sentence(char* sentence) {
  int i, j;
  char* translated_sentence = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
  char* word;
  char* translated_word;
  i = 0;
  j = 0;
  while (i < strlen(sentence)) {
    while (sentence[i] == ' ') {
      i++;
    }
    if (sentence[i] == '\0') {
      break;
    }
    j = i;
    while (sentence[j] != ' ' && sentence[j] != '\0') {
      j++;
    }
    word = malloc((j - i + 1) * sizeof(char));
    strncpy(word, sentence + i, j - i);
    word[j - i] = '\0';
    translated_word = translate_word(word);
    if (translated_word != NULL) {
      strcat(translated_sentence, translated_word);
      strcat(translated_sentence, " ");
    }
    i = j;
  }
  return translated_sentence;
}

int main() {
  char* sentence;
  char* translated_sentence;
  srand(time(NULL));
  sentence = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
  translated_sentence = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
  printf("Enter a sentence in English: ");
  gets(sentence);
  translated_sentence = translate_sentence(sentence);
  printf("The sentence in Alien language is: %s\n", translated_sentence);
  return 0;
}