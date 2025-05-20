//LLAMA2-13B DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 100
#define MAX_WORD_LENGTH 20

// Function to generate a random word
void generate_word(char *word) {
  int i, j;
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    word[i] = 'a' + (rand() % 26);
  }
  word[MAX_WORD_LENGTH] = '\0';
}

// Function to check if a word is a palindrome
int is_palindrome(char *word) {
  int i, j;
  for (i = 0; i < MAX_WORD_LENGTH / 2; i++) {
    if (word[i] != word[MAX_WORD_LENGTH - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to find the longest common prefix of two words
int find_longest_common_prefix(char *word1, char *word2) {
  int i, j;
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    if (word1[i] == word2[i]) {
      continue;
    }
    break;
  }
  return i;
}

int main() {
  char word1[MAX_WORD_LENGTH], word2[MAX_WORD_LENGTH], longest_common_prefix[MAX_WORD_LENGTH];
  int i, j, k;

  // Generate two random words
  generate_word(word1);
  generate_word(word2);

  // Find the longest common prefix of the two words
  k = find_longest_common_prefix(word1, word2);

  // Print the longest common prefix
  for (i = 0; i < k; i++) {
    longest_common_prefix[i] = word1[i];
  }
  printf("Longest common prefix: %s\n", longest_common_prefix);

  // Check if the two words are palindromes
  if (is_palindrome(word1) && is_palindrome(word2)) {
    printf("Both words are palindromes!\n");
  } else {
    printf("At least one word is not a palindrome.\n");
  }

  return 0;
}