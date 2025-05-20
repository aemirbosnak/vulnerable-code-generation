//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to reverse a string
void reverse_string(char *str) {
  int i, j, temp;

  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

// Function to extract the first n characters of a string
char *extract_first_n(char *str, int n) {
  int i, j;

  if (n > strlen(str)) {
    n = strlen(str);
  }

  char *result = malloc(n + 1);
  for (i = 0, j = 0; i < n; i++, j++) {
    result[j] = str[i];
  }
  result[j] = '\0';

  return result;
}

// Function to extract the last n characters of a string
char *extract_last_n(char *str, int n) {
  int i, j;

  if (n > strlen(str)) {
    n = strlen(str);
  }

  char *result = malloc(n + 1);
  for (i = strlen(str) - n, j = 0; i >= 0; i--, j++) {
    result[j] = str[i];
  }
  result[j] = '\0';

  return result;
}

// Function to concatenate two strings
char *concatenate_strings(char *str1, char *str2) {
  int len1 = strlen(str1), len2 = strlen(str2);
  char *result = malloc(len1 + len2 + 1);

  for (int i = 0; i < len1; i++) {
    result[i] = str1[i];
  }
  for (int i = 0; i < len2; i++) {
    result[len1 + i] = str2[i];
  }

  result[len1 + len2] = '\0';

  return result;
}

int main() {
  char str1[] = "The quick brown fox jumps over the lazy dog";
  char str2[] = "with great excitement";
  char *result;

  // Reverse the first string
  reverse_string(str1);

  // Extract the first 5 characters of the first string
  char *first_five = extract_first_n(str1, 5);

  // Extract the last 5 characters of the first string
  char *last_five = extract_last_n(str1, 5);

  // Concatenate the first and second strings
  result = concatenate_strings(str1, str2);

  printf("First 5 characters of the first string: %s\n", first_five);
  printf("Last 5 characters of the first string: %s\n", last_five);
  printf("Concatenated strings: %s\n", result);

  free(first_five);
  free(last_five);
  free(result);

  return 0;
}