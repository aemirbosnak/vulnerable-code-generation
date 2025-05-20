//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word words[MAX_WORDS];

void analyze_text(char *text) {
  char *ptr = text;
  Word *word = words;

  // Tokenize the text
  char *token = strtok(ptr, " ");

  // Iterate over the tokens
  while (token) {
    int i = 0;
    for (Word *w = words; w->word; i++) {
      if (strcmp(token, w->word) == 0) {
        w->frequency++;
        break;
      }
    }

    // If the word is not found, add it to the list
    if (i == MAX_WORDS) {
      word->word = strdup(token);
      word->frequency = 1;
      word++;
    }

    token = strtok(NULL, " ");
  }
}

int main() {
  char *text = "This is a sample text with many spam words, such as free, offer, and miracle. It also contains some legitimate words, such as apple, banana, and orange.";

  analyze_text(text);

  // Print the words and their frequencies
  for (Word *w = words; w->word; w++) {
    printf("%s: %d\n", w->word, w->frequency);
  }

  return 0;
}