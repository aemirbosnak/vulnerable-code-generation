//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Meow!
void meow(char *s) { printf("%s\n", s); }

// Hiss!
void hiss(char *s) { printf("(%s)\n", s); }

// Purr!
void purr(char *s) { printf("[%s]\n", s); }

// Scratch!
void scratch(char *s) { printf("<%s>\n", s); }

// Lick!
void lick(char *s) { printf("{ %s }\n", s); }

// Blink!
void blink(char *s) { printf("|%s|\n", s); }

// Wag tail!
void wag(char *s) { printf("\"%s\"", s); }

// Rub against you!
void rub(char *s) { printf("^%s^\n", s); }

// Knead you!
void knead(char *s) { printf("*%s*\n", s); }

// Headbutt you!
void headbutt(char *s) { printf("!%s!\n", s); }

// Bite you!
void bite(char *s) { printf("?%s?\n", s); }

int main() {
  // Initialize the cat translator
  char *dict[] = {"meow", "hiss", "purr", "scratch", "lick", "blink", "wag", "rub",
                  "knead", "headbutt", "bite"};
  void (*func[])() = {meow, hiss, purr, scratch, lick, blink, wag, rub, knead, headbutt,
                       bite};
  int n = sizeof(dict) / sizeof(dict[0]);

  // Get the user's input
  char *input = malloc(100);
  printf("Enter a phrase: ");
  scanf("%s", input);

  // Translate the input
  for (int i = 0; i < strlen(input); i++) {
    char c = input[i];
    for (int j = 0; j < n; j++) {
      if (c == dict[j][0]) { func[j](dict[j]); }
    }
  }

  // Free the allocated memory
  free(input);

  return 0;
}