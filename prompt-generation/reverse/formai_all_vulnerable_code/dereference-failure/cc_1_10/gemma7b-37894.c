//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word words[MAX_WORDS];

void analyze_text(char *text) {
  char *ptr = text;
  Word *currentWord = &words[0];

  while (*ptr) {
    char word[256];
    int i = 0;

    while (*ptr && !isspace(*ptr) && i < 256) {
      word[i++] = *ptr;
      ptr++;
    }

    word[i] = '\0';

    int found = 0;
    for (int j = 0; j < MAX_WORDS; j++) {
      if (strcmp(word, words[j].word) == 0) {
        words[j].frequency++;
        found = 1;
      }
    }

    if (!found) {
      currentWord->word = strdup(word);
      currentWord->frequency = 1;
      currentWord++;
    }
  }
}

int main() {
  char text[] = "This is a sample text with some spam words, such as buy, sell, and make. The text also contains some non-spam words, such as the, and of. You can see that the spam words are repeated more often than the non-spam words.";

  analyze_text(text);

  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].frequency > 1) {
      printf("%s: %d\n", words[i].word, words[i].frequency);
    }
  }

  return 0;
}