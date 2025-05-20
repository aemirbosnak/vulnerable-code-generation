//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void parse_resume(char *resume) {
  char **words = NULL;
  int num_words = 0;

  // Split the resume into words
  words = split_resume(resume);

  // Count the number of words
  num_words = count_words(words);

  // Print the number of words
  printf("Number of words in the resume: %d\n", num_words);

  // Free the memory allocated for words
  free(words);
}

int split_resume(char *resume) {
  char **words = NULL;
  int num_words = 0;
  char *token = strtok(resume, " ");

  // While there are tokens to be found, split the resume into words
  while (token) {
    words = realloc(words, (num_words + 1) * sizeof(char *));
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  return words;
}

int count_words(char **words) {
  int num_words = 0;

  // Count the number of words in the list
  for (int i = 0; words[i] != NULL; i++) {
    num_words++;
  }

  return num_words;
}

int main() {
  char *resume = "John Doe\n123 Main St\nNew York, NY 10001\n(123) 456-7890\n";

  parse_resume(resume);

  return 0;
}