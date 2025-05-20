//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 200

typedef struct Spam {
  char **words;
  char **sentences;
  int numWords;
  int numSentences;
} Spam;

Spam *spam_create() {
  Spam *s = (Spam *)malloc(sizeof(Spam));
  s->words = (char **)malloc(sizeof(char *) * MAX_WORDS);
  s->sentences = (char **)malloc(sizeof(char *) * MAX_SENTENCE_LENGTH);
  s->numWords = 0;
  s->numSentences = 0;
  return s;
}

void spam_add_word(Spam *s, char *word) {
  s->words[s->numWords++] = word;
}

void spam_add_sentence(Spam *s, char *sentence) {
  s->sentences[s->numSentences++] = sentence;
}

int spam_detect(Spam *s) {
  int i, j, score = 0;
  for (i = 0; i < s->numWords; i++) {
    for (j = 0; j < s->numSentences; j++) {
      if (strstr(s->sentences[j], s->words[i]) != NULL) {
        score++;
      }
    }
  }
  return score;
}

int main() {
  Spam *s = spam_create();
  spam_add_word(s, "free");
  spam_add_word(s, "lottery");
  spam_add_sentence(s, "You have won $1 million!");
  spam_add_sentence(s, "Get rich quick!");

  int score = spam_detect(s);
  printf("Score: %d", score);

  return 0;
}