//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

int main() {
  char text[1000];
  printf("Enter text: ");
  fgets(text, 1000, stdin);

  // Remove punctuation and convert to lowercase
  char *p = text;
  while (*p) {
    if (ispunct(*p)) {
      *p = '\0';
    } else if (isupper(*p)) {
      *p = tolower(*p);
    }
    p++;
  }

  // Tokenize the text
  char words[MAX_WORDS][20];
  int num_words = 0;
  char *w = strtok(text, " ");
  while (w) {
    strcpy(words[num_words++], w);
    w = strtok(NULL, " ");
  }

  // Analyze the words
  int spam_score = 0;
  for (int i = 0; i < num_words; i++) {
    if (strcmp(words[i], "free") == 0) {
      spam_score++;
    } else if (strcmp(words[i], "lottery") == 0) {
      spam_score++;
    } else if (strcmp(words[i], "prize") == 0) {
      spam_score++;
    } else if (strlen(words[i]) < 3) {
      spam_score++;
    }
  }

  // Determine the spam probability
  int probability = spam_score * 100 / num_words;

  // Display the results
  printf("Spam probability: %d%%", probability);

  return 0;
}