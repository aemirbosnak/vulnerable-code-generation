//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int main() {
  char *str = malloc(MAX_SIZE);
  if (str == NULL) {
    perror("malloc");
    return 1;
  }

  // Read input into str
  if (fgets(str, MAX_SIZE, stdin) == NULL) {
    perror("fgets");
    return 1;
  }

  // Remove trailing newline from str
  int len = strlen(str);
  if (str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }

  // Convert str to lowercase
  for (int i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }

  // Count the number of occurrences of each letter in str
  int counts[26] = {0};
  for (int i = 0; i < len; i++) {
    int index = str[i] - 'a';
    counts[index]++;
  }

  // Find the most frequently occurring letter in str
  int max_count = 0;
  char most_frequent_letter;
  for (int i = 0; i < 26; i++) {
    if (counts[i] > max_count) {
      max_count = counts[i];
      most_frequent_letter = 'a' + i;
    }
  }

  // Print the most frequently occurring letter
  printf("The most frequently occurring letter in '%s' is '%c'.\n", str, most_frequent_letter);

  // Free the memory allocated for str
  free(str);

  return 0;
}