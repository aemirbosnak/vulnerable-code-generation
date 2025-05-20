//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_ATTEMPTS 5

int main() {
  int attempts = 0;
  char* sentence = NULL;
  char* word = NULL;
  size_t len = 0;

  srand(time(NULL));

  while (1) {
    // Generate a random sentence
    sentence = malloc(rand() % MAX_LENGTH + 1);
    len = strlen(sentence);
    word = malloc(len + 1);
    strcpy(word, sentence);

    // Check if the word is a palindrome
    if (is_palindrome(word) == 0) {
      // If the word is not a palindrome, print an error message
      printf("Error: Word %s is not a palindrome\n", word);
      free(word);
      free(sentence);
      continue;
    }

    // Print the word
    printf("Palindrome: %s\n", word);

    // Increment the attempts counter
    attempts++;

    // Check if the maximum number of attempts has been reached
    if (attempts >= MAX_ATTEMPTS) {
      break;
    }
  }

  return 0;
}

// Function to check if a word is a palindrome
int is_palindrome(char* word) {
  size_t i = 0;
  size_t j = strlen(word) - 1;

  while (i < j) {
    if (word[i] != word[j]) {
      return 0; // Not a palindrome
    }
    i++;
    j--;
  }

  return 1; // Palindrome
}