//FormAI DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int is_palindrome(char *str) {
  int length = strlen(str);
  for (int i = 0; i < length / 2; i++) {
    if (str[i] != str[length - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char str[MAX_LENGTH];
  printf("Enter a string: ");
  scanf("%[^\n]", str);

  // Convert all letters to uppercase
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - ('a' - 'A');
    }
  }

  // Print the uppercase string
  printf("Uppercase string: %s\n", str);

  // Reverse the string
  char *reverse = (char*)malloc(MAX_LENGTH * sizeof(char));
  for (int i = strlen(str) - 1, j = 0; i >= 0; i--, j++) {
    reverse[j] = str[i];
  }
  reverse[strlen(str)] = '\0';

  // Print the reversed string
  printf("Reversed string: %s\n", reverse);

  // Check if the original string is a palindrome
  if (is_palindrome(str)) {
    printf("Original string is a palindrome.\n");
  }
  else {
    printf("Original string is not a palindrome.\n");
  }

  // Check if the reversed string is a palindrome
  if (is_palindrome(reverse)) {
    printf("Reversed string is a palindrome.\n");
  }
  else {
    printf("Reversed string is not a palindrome.\n");
  }

  free(reverse);

  return 0;
}