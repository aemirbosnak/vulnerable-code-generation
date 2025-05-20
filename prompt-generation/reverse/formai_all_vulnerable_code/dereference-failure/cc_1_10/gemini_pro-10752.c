//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>

// Welcome message
void welcome() {
  printf("***********************************************************************\n");
  printf("*    Welcome to the Retro String Manipulation Extravaganza!           *\n");
  printf("*---------------------------------------------------------------------*\n");
  printf("*    Behold, a journey through the annals of string-slinging prowess!   *\n");
  printf("***********************************************************************\n\n");
}

// Get a string from the user
char *get_string() {
  char *str = (char *)malloc(100);
  printf("Enter your string, oh valiant adventurer: ");
  scanf("%s", str);
  return str;
}

// Reverse a string
char *reverse_string(char *str) {
  int len = strlen(str);
  char *reversed = (char *)malloc(len + 1);
  for (int i = 0; i < len; i++) {
    reversed[len - i - 1] = str[i];
  }
  reversed[len] = '\0';
  return reversed;
}

// Print a string in a box
void print_in_box(char *str) {
  int len = strlen(str);
  printf("----------------------------------------\n");
  printf("| %s |\n", str);
  printf("----------------------------------------\n");
}

// Find the longest word in a string
char *longest_word(char *str) {
  char *longest = (char *)malloc(100);
  int max_len = 0;
  char *start = str;
  while (*str != '\0') {
    if (*str == ' ' || *str == '\n' || *str == '\t') {
      if (str - start > max_len) {
        max_len = str - start;
        strncpy(longest, start, max_len);
      }
      start = str + 1;
    }
    str++;
  }
  if (str - start > max_len) {
    max_len = str - start;
    strncpy(longest, start, max_len);
  }
  return longest;
}

// Main function
int main() {
  welcome();
  char *str = get_string();
  printf("Original string: %s\n\n", str);

  char *reversed = reverse_string(str);
  printf("Reversed string: %s\n\n", reversed);

  print_in_box(str);

  char *longest = longest_word(str);
  printf("Longest word: %s\n\n", longest);

  free(str);
  free(reversed);
  free(longest);
  return 0;
}