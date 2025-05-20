//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *alien;
  char *english;
} translation;

translation dictionary[] = {
  { "grok", "understand" },
  { "plen", "rule" },
  { "glu", "body" },
  { "flit", "wings" },
  { "bung", "hole" },
  { "jit", "jump" },
  { "yipyip", "happy" },
  { "yip", "yes" },
  { "nop", "no" },
  { "teehee", "laugh" },
  { "giggle", "laugh" },
  { "chortle", "laugh" }
};

int main(int argc, char *argv[]) {
  char *alien;
  char *english;
  int i;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <alien word>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  alien = argv[1];

  for (i = 0; i < sizeof(dictionary) / sizeof(translation); i++) {
    if (strcmp(alien, dictionary[i].alien) == 0) {
      english = dictionary[i].english;
      break;
    }
  }

  if (english == NULL) {
    fprintf(stderr, "Unknown alien word: %s\n", alien);
    exit(EXIT_FAILURE);
  }

  printf("%s = %s\n", alien, english);

  return EXIT_SUCCESS;
}