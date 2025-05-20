//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1000

char **words(char **w, int n) {
  w = malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    w[i] = malloc(20 * sizeof(char));
  }
  return w;
}

int main() {
  char **w = NULL;
  int n = 0;

  char *text = "This is a sample text with some spam words, such as buy, sell, and make money.";

  w = words(w, n);

  n = split_text(text, w);

  for (int i = 0; i < n; i++) {
    printf("%s\n", w[i]);
  }

  return 0;
}

int split_text(char *text, char **w) {
  int n = 0;
  char *p = text;
  char *q;

  while (p) {
    q = strchr(p, ' ');
    if (q) {
      *w[n++] = malloc(q - p + 1);
      memcpy(*w[n - 1], p, q - p);
      *w[n - 1] = '\0';
      p = q + 1;
    } else {
      *w[n++] = malloc(strlen(p) + 1);
      strcpy(*w[n - 1], p);
      *w[n - 1] = '\0';
      p = NULL;
    }
  }

  return n;
}