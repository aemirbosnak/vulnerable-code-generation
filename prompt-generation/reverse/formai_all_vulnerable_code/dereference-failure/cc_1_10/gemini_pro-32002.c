//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATTERNS 100
#define MAX_PATTERN_SIZE 100

static const char * patterns[] = {
  "free money",
  "win a prize",
  "too good to be true",
  "click here",
  "act now",
  "limited time offer",
  "no strings attached",
  "this is not a scam",
  "you're a winner",
  "you've been selected"
};

static int num_patterns = sizeof(patterns) / sizeof(*patterns);

int main() {
  char * input;
  int i, j;
  int is_spam;

  printf("Enter the text to check for spam: ");
  input = malloc(1024);
  fgets(input, 1024, stdin);

  is_spam = 0;
  for (i = 0; i < num_patterns; i++) {
    for (j = 0; j < strlen(input); j++) {
      if (strstr(&input[j], patterns[i])) {
        is_spam = 1;
        break;
      }
    }
  }

  if (is_spam) {
    printf("The text you entered is likely to be spam.\n");
  } else {
    printf("The text you entered is not likely to be spam.\n");
  }

  free(input);
  return 0;
}