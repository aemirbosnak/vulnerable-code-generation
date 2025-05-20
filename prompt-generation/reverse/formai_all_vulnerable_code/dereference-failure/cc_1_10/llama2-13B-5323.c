//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definition of the recursive function
void rec_string_manipulate(char *str, int len, int depth) {
  if (depth == 0) {
    // Base case: no more recursion, just print the string
    printf("%s\n", str);
    return;
  }

  // Recursive case: manipulate the string and recurse
  char *new_str = malloc(len + 1);
  int i, j;

  // Loop through each character in the string
  for (i = 0; i < len; i++) {
    // If the character is a space, replace it with a *
    if (str[i] == ' ') {
      new_str[i] = '*';
    }

    // If the character is a *, replace it with a space
    else if (str[i] == '*') {
      new_str[i] = ' ';
    }

    // If the character is not a space or *, leave it as is
    else {
      new_str[i] = str[i];
    }
  }

  // Recursively manipulate the remaining part of the string
  rec_string_manipulate(new_str, len, depth - 1);

  // Free the new string
  free(new_str);
}

int main() {
  char str[] = "Hello world! How are you?";
  int len = strlen(str);

  // Call the recursive function with the string, length, and depth
  rec_string_manipulate(str, len, 3);

  return 0;
}