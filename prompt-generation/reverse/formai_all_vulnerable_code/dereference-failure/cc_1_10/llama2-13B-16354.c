//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1024

void automate_text(char *text) {
  int i, j, k;
  char word[10];
  char *p;
  char *q;

  // Tokenize the text into individual words
  p = strtok(text, " ");
  while (p != NULL) {
    strcpy(word, p);
    word[strcspn(word, "")] = '\0'; // Remove any non-alphanumeric characters
    j = strlen(word);
    for (i = 0; i < j; i++) {
      if (isalpha(word[i])) {
        word[i] = tolower(word[i]); // Convert word to lowercase
      }
    }
    printf("%s ", word);
    p = strtok(NULL, " ");
  }

  // Remove any trailing spaces
  p = text + strlen(text) - 1;
  while (p > text && isspace(*p)) {
    *p = '\0';
    p--;
  }

  // Print the processed text
  printf("\n%s\n", text);
}

int main() {
  char text[MAX_LENGTH];

  // Read the text from the user
  printf("Enter a sentence or paragraph: ");
  fgets(text, MAX_LENGTH, stdin);

  // Automate the text
  automate_text(text);

  return 0;
}