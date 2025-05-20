//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An ASCII art representation of a happy face
char *happy_face = ":)";

// Function to print a string in a box
void print_in_box(char *str) {
  int len = strlen(str);
  printf("+");
  for (int i = 0; i < len + 2; i++) {
    printf("-");
  }
  printf("+\n");
  printf("| %s |\n", str);
  printf("+");
  for (int i = 0; i < len + 2; i++) {
    printf("-");
  }
  printf("+\n");
}

// Function to replace all occurrences of a substring with another substring
void replace_substring(char *str, char *to_replace, char *replacement) {
  int len_to_replace = strlen(to_replace);
  int len_replacement = strlen(replacement);
  int len_str = strlen(str);

  // Create a new string to hold the result
  char *new_str = malloc(len_str + (len_replacement - len_to_replace) * 10 + 1);

  // Iterate over the string and replace all occurrences of the substring
  int new_str_idx = 0;
  for (int i = 0; i < len_str; i++) {
    if (strncmp(str + i, to_replace, len_to_replace) == 0) {
      for (int j = 0; j < len_replacement; j++) {
        new_str[new_str_idx++] = replacement[j];
      }
      i += len_to_replace - 1;
    } else {
      new_str[new_str_idx++] = str[i];
    }
  }

  // Terminate the new string
  new_str[new_str_idx] = '\0';

  // Copy the new string back to the original string
  strcpy(str, new_str);

  // Free the allocated memory
  free(new_str);
}

// Function to demonstrate text processing using the above functions
int main() {
  // Create a string to process
  char *str = "I'm so happy to be learning C!";

  // Print the original string
  printf("Original string: %s\n", str);

  // Print the string in a box
  print_in_box(str);

  // Replace all occurrences of "C" with "C++"
  replace_substring(str, "C", "C++");

  // Print the modified string
  printf("Modified string: %s\n", str);

  // Print the string with a happy face at the end
  printf("%s %s\n", str, happy_face);

  return 0;
}