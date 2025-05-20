//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

int main() {
  char text[1000];
  char words[MAX_WORDS][20];
  int numWords = 0;
  char *p, *q;

  printf("Enter text: ");
  fgets(text, 1000, stdin);

  // Tokenize the text
  p = text;
  while (p) {
    q = strchr(p, ' ');
    if (q) {
      words[numWords][0] = strndup(p, q - p);
      numWords++;
      p = q + 1;
    } else {
      words[numWords][0] = strndup(p, strlen(p));
      numWords++;
      p = NULL;
    }
  }

  // Analyze the words
  for (int i = 0; i < numWords; i++) {
    // Check if the word is a spam word
    if (isSpamWord(words[i][0])) {
      printf("WARNING: Word '%s' is a spam word.\n", words[i][0]);
    }
  }

  return 0;
}

int isSpamWord(char *word) {
  // Define a list of spam words
  char *spamWords[] = {"buy", "free", "miracle", "lottery", "prize"};

  // Check if the word is in the list of spam words
  for (int i = 0; i < 5; i++) {
    if (strcmp(word, spamWords[i]) == 0) {
      return 1;
    }
  }

  return 0;
}