//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 256

typedef struct Word {
  char *word;
  int frequency;
} Word;

typedef struct Sentence {
  char *sentence;
  Word **words;
  int num_words;
} Sentence;

Sentence *create_sentence(char *sentence) {
  Sentence *s = malloc(sizeof(Sentence));
  s->sentence = strdup(sentence);
  s->words = malloc(MAX_WORDS * sizeof(Word));
  s->num_words = 0;

  return s;
}

void add_word(Sentence *s, char *word) {
  Word *w = malloc(sizeof(Word));
  w->word = strdup(word);
  w->frequency = 0;

  s->words[s->num_words++] = w;
}

int sentiment_analysis(Sentence *s) {
  int sentiment = 0;
  for (int i = 0; i < s->num_words; i++) {
    char *word = s->words[i]->word;
    if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0) {
      sentiment++;
    } else if (strcmp(word, "sad") == 0 || strcmp(word, "sadness") == 0) {
      sentiment--;
    }
  }

  return sentiment;
}

int main() {
  char *sentence = "I am happy today, but I am sad that I lost my phone.";
  Sentence *s = create_sentence(sentence);

  add_word(s, "happy");
  add_word(s, "sad");
  add_word(s, "joy");
  add_word(s, "sadness");

  int sentiment = sentiment_analysis(s);

  printf("Sentiment: %d\n", sentiment);

  return 0;
}