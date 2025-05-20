//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse_string(char *str) {
  int len = strlen(str);
  char *new_str = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    new_str[i] = str[len - i - 1];
  }
  new_str[len] = '\0';
  return new_str;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
  int len = strlen(str);
  int max_len = 0;
  char *max_str = NULL;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j <= len; j++) {
      char *sub_str = strndup(str + i, j - i);
      if (is_palindrome(sub_str) && strlen(sub_str) > max_len) {
        max_len = strlen(sub_str);
        max_str = sub_str;
      }
      free(sub_str);
    }
  }
  return max_str;
}

// Function to find all the permutations of a string
char **permutations(char *str) {
  int len = strlen(str);
  int num_perms = 1;
  for (int i = 1; i <= len; i++) {
    num_perms *= i;
  }
  char **perms = malloc(num_perms * sizeof(char *));
  int index = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      char *new_str = malloc(len + 1);
      for (int k = 0; k < len; k++) {
        if (k == i) {
          new_str[k] = str[j];
        } else if (k == j) {
          new_str[k] = str[i];
        } else {
          new_str[k] = str[k];
        }
      }
      new_str[len] = '\0';
      perms[index++] = new_str;
    }
  }
  return perms;
}

// Function to test the string manipulation functions
int main() {
  // Reverse a string
  char *str = "Hello world";
  printf("Original string: %s\n", str);
  char *reversed_str = reverse_string(str);
  printf("Reversed string: %s\n", reversed_str);
  free(reversed_str);

  // Check if a string is a palindrome
  str = "racecar";
  printf("Original string: %s\n", str);
  int is_pal = is_palindrome(str);
  if (is_pal) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  // Find the longest palindrome in a string
  str = "abcdefggfedcba";
  printf("Original string: %s\n", str);
  char *longest_pal = longest_palindrome(str);
  printf("Longest palindrome: %s\n", longest_pal);
  free(longest_pal);

  // Find all the permutations of a string
  str = "abc";
  printf("Original string: %s\n", str);
  char **perms = permutations(str);
  for (int i = 0; i < 6; i++) {
    printf("Permutation %d: %s\n", i + 1, perms[i]);
    free(perms[i]);
  }
  free(perms);

  return 0;
}