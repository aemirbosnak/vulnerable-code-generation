//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100

/*
 * The is_palindrome() function checks if a given word is a palindrome.
 * A palindrome is a word that is the same when read forwards or backwards.
 *
 * @param word the word to check
 * @param length the length of the word
 *
 * @return 1 if the word is a palindrome, 0 otherwise
 */
int is_palindrome(char* word, int length)
{
  // Check if the word is empty.
  if (length == 0)
  {
    return 0;
  }

  // Check if the first and last letters of the word are the same.
  if (word[0] != word[length - 1])
  {
    return 0;
  }

  // Check if the middle letters of the word are the same.
  if (length > 2)
  {
    if (word[1] != word[length - 2])
    {
      return 0;
    }
  }

  // Check if the remaining letters of the word are the same.
  if (length > 4)
  {
    for (int i = 2; i < length - 2; i++)
    {
      if (word[i] != word[length - i - 1])
      {
        return 0;
      }
    }
  }

  // The word is a palindrome.
  return 1;
}

int main(int argc, char** argv) {
  // Check if the user has provided a word to check.
  if (argc != 2) {
    printf("Usage: %s <word>\n", argv[0]);
    return 1;
  }

  // Get the word from the user.
  char* word = argv[1];

  // Get the length of the word.
  int length = strlen(word);

  // Check if the word is a palindrome.
  int is_palindrome_result = is_palindrome(word, length);

  // Print the result to the user.
  if (is_palindrome_result) {
    printf("%s is a palindrome.\n", word);
  } else {
    printf("%s is not a palindrome.\n", word);
  }

  return 0;
}