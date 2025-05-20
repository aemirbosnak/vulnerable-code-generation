//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The cosmic sentinel, guarding against celestial folly.
char *cast(char *input) {
  char *purified = malloc(strlen(input) + 1);
  int i, j = 0;

  for (i = 0; input[i]; i++) {
    // Alpha-numeric characters are like stars, guiding us through the void.
    if (isalnum(input[i])) {
      purified[j++] = input[i];
    }
      // Asterisks are celestial gateways, but they have no place here.
    else if (input[i] == '*') {
      purified[j++] = ' ';
    }
      // Control characters are cosmic anomalies, to be purged from the input stream.
    else if (iscntrl(input[i])) {
      continue;
    }
      // Unforeseen characters are like rogue planets, threatening the celestial order.
    else {
      free(purified);
      return NULL;
    }
  }
  purified[j] = '\0';
  return purified;
}

// The celestial navigator, charting a course through the astral sea of user input.
int main() {
  char *input, *purified;
  size_t len = 0;
  ssize_t nread;

  printf("Input your celestial message, voyager:\n");
  while ((nread = getline(&input, &len, stdin)) != -1) {
    // Invoke the cosmic sentinel to purify the input stream.
    purified = cast(input);
    if (purified == NULL) {
      printf("Your message contains forbidden cosmic anomalies. Please revise and try again.\n");
      continue;
    }
    printf("Your purified message, as the cosmic sentinel has ordained:\n%s", purified);
    free(purified);
  }
  free(input);
  return 0;
}