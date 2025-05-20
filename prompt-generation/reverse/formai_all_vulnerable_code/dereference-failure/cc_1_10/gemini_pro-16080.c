//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all occurrences of a character from a string
char *remove_character(char *str, char c) {
  int n = strlen(str);
  char *new_str = malloc(n + 1);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] != c) {
      new_str[j] = str[i];
      j++;
    }
  }
  new_str[j] = '\0';
  return new_str;
}

// Function to count the number of occurrences of a character in a string
int count_character(char *str, char c) {
  int n = strlen(str);
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == c) {
      count++;
    }
  }
  return count;
}

// Function to replace all occurrences of a character with another character
char *replace_character(char *str, char c, char d) {
  int n = strlen(str);
  char *new_str = malloc(n + 1);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == c) {
      new_str[j] = d;
      j++;
    } else {
      new_str[j] = str[i];
      j++;
    }
  }
  new_str[j] = '\0';
  return new_str;
}

// Function to convert a string to uppercase
char *to_uppercase(char *str) {
  int n = strlen(str);
  char *new_str = malloc(n + 1);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      new_str[j] = str[i] - 32;
      j++;
    } else {
      new_str[j] = str[i];
      j++;
    }
  }
  new_str[j] = '\0';
  return new_str;
}

// Function to convert a string to lowercase
char *to_lowercase(char *str) {
  int n = strlen(str);
  char *new_str = malloc(n + 1);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      new_str[j] = str[i] + 32;
      j++;
    } else {
      new_str[j] = str[i];
      j++;
    }
  }
  new_str[j] = '\0';
  return new_str;
}

// Function to reverse a string
char *reverse_string(char *str) {
  int n = strlen(str);
  char *new_str = malloc(n + 1);
  int j = n - 1;
  for (int i = 0; i < n; i++) {
    new_str[j] = str[i];
    j--;
  }
  new_str[n] = '\0';
  return new_str;
}

// Driver code
int main() {
  char str[] = "Hello, world!";

  // Remove all occurrences of the character 'o'
  char *new_str = remove_character(str, 'o');
  printf("New string after removing all occurrences of 'o': %s\n", new_str);

  // Count the number of occurrences of the character 'l'
  int count = count_character(str, 'l');
  printf("Number of occurrences of the character 'l': %d\n", count);

  // Replace all occurrences of the character 'l' with the character 'x'
  char *new_str2 = replace_character(str, 'l', 'x');
  printf("New string after replacing all occurrences of 'l' with 'x': %s\n", new_str2);

  // Convert the string to uppercase
  char *new_str3 = to_uppercase(str);
  printf("String converted to uppercase: %s\n", new_str3);

  // Convert the string to lowercase
  char *new_str4 = to_lowercase(str);
  printf("String converted to lowercase: %s\n", new_str4);

  // Reverse the string
  char *new_str5 = reverse_string(str);
  printf("Reversed string: %s\n", new_str5);

  return 0;
}