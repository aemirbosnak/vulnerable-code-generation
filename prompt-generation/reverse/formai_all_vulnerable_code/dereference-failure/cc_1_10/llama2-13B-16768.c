//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define SEARCH_LENGTH 20

// Declare a function to search for a word in a string
int search(char *str, char *word) {
  int i, j, k;
  char c;

  // Start by initializing the search index
  i = 0;
  j = 0;
  k = 0;

  // Loop through the string and word
  while ((c = *str++) != '\0') {
    // If the current character is the first character of the word
    if (k == 0 && c == *word++) {
      // Increment the search index
      i++;

      // If the current character is not the last character of the word
      if (c != *(word + j)) {
        // Keep searching
        j++;
      } else {
        // Found the word!
        return i - j;
      }
    }

    // If the current character is not the first character of the word
    else {
      // Keep searching
      j++;
    }
  }

  // If we reached the end of the string without finding the word
  return -1;
}

int main() {
  char str[] = "Hello, how are you?";
  char word[] = "how";
  int result;

  // Search for the word
  result = search(str, word);

  // Print the result
  if (result == -1) {
    printf("The word %s was not found in the string %s.\n", word, str);
  } else {
    printf("The word %s was found at position %d in the string %s.\n", word, result, str);
  }

  return 0;
}