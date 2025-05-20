//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *text = "Knock, knock. Who's there? Boo. Boo who? Don't cry, it's just a joke!";

  printf("Original text: %s\n", text);

  // Replace all occurrences of "Boo" with "Booh"
  char *boo = "Boo";
  char *booh = "Booh";
  char *ptr = text;
  while ((ptr = strstr(ptr, boo)) != NULL) {
    memcpy(ptr, booh, strlen(booh));
    ptr += strlen(booh);
  }

  printf("Replaced \"Boo\" with \"Booh\": %s\n", text);

  // Remove all vowels from the text
  char vowels[] = "aeiouAEIOU";
  for (char *c = text; *c != '\0'; c++) {
    if (strchr(vowels, *c) != NULL) {
      *c = ' ';
    }
  }

  printf("Vowels removed: %s\n", text);

  // Convert the text to uppercase
  for (char *c = text; *c != '\0'; c++) {
    *c = toupper(*c);
  }

  printf("Uppercase: %s\n", text);

  // Reverse the order of the words in the text
  char *words[100];
  int numWords = 0;
  char *p = strtok(text, " ");
  while (p != NULL) {
    words[numWords++] = p;
    p = strtok(NULL, " ");
  }

  for (int i = numWords - 1; i >= 0; i--) {
    printf("%s ", words[i]);
  }

  printf("\n");

  return 0;
}