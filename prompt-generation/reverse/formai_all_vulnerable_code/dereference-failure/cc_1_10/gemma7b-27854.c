//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word *words;

void analyze_sentence(char *sentence) {
  // Tokenize the sentence into words
  char *word_ptr = sentence;
  Word *new_word = malloc(sizeof(Word));
  new_word->word = strdup(word_ptr);
  new_word->frequency = 1;
  words->word = new_word;
  words++;

  while ((word_ptr = strchr(word_ptr, ' ')) != NULL) {
    word_ptr++;
    new_word = malloc(sizeof(Word));
    new_word->word = strdup(word_ptr);
    new_word->frequency = 1;
    words->word = new_word;
    words++;
  }

  // Calculate word frequency
  for (Word *w = words; w->word; w++) {
    for (Word *v = words; v->word; v++) {
      if (strcmp(w->word, v->word) == 0) {
        w->frequency++;
      }
    }
  }
}

int main() {
  words = malloc(sizeof(Word));
  words->word = NULL;

  // Analyze a sentence
  analyze_sentence("This is a sample sentence with many words.");

  // Print the words and their frequency
  for (Word *w = words; w->word; w++) {
    printf("%s: %d\n", w->word, w->frequency);
  }

  return 0;
}