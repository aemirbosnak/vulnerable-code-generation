//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: scientific
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Function to concatenate two strings
char *concatenate(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
  strcpy(result, str1);
  strcpy(result + len1, str2);
  return result;
}

// Function to reverse a string
char *reverse(char *str) {
  int len = strlen(str);
  char *result = malloc(len + 1); // +1 for the null-terminator
  for (int i = 0; i < len; i++) {
    result[i] = str[len - i - 1];
  }
  result[len] = '\0'; // Null-terminate the string
  return result;
}

// Function to compare two strings
int compare(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  if (len1 != len2) {
    return len1 - len2;
  }
  for (int i = 0; i < len1; i++) {
    if (str1[i] != str2[i]) {
      return str1[i] - str2[i];
    }
  }
  return 0;
}

// Function to find the length of a string
int length(char *str) {
  int len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}

// Function to find the first occurrence of a character in a string
char *find(char *str, char c) {
  while (*str != '\0') {
    if (*str == c) {
      return str;
    }
    str++;
  }
  return NULL;
}

// Function to find the last occurrence of a character in a string
char *rfind(char *str, char c) {
  char *last_occurrence = NULL;
  while (*str != '\0') {
    if (*str == c) {
      last_occurrence = str;
    }
    str++;
  }
  return last_occurrence;
}

// Function to replace all occurrences of a character in a string with another character
char *replace(char *str, char old_char, char new_char) {
  char *result = malloc(strlen(str) + 1); // +1 for the null-terminator
  int i = 0;
  while (*str != '\0') {
    if (*str == old_char) {
      result[i] = new_char;
    } else {
      result[i] = *str;
    }
    i++;
    str++;
  }
  result[i] = '\0'; // Null-terminate the string
  return result;
}

// Function to convert a string to lowercase
char *tolower(char *str) {
  char *result = malloc(strlen(str) + 1); // +1 for the null-terminator
  int i = 0;
  while (*str != '\0') {
    if (*str >= 'A' && *str <= 'Z') {
      result[i] = *str + 32;
    } else {
      result[i] = *str;
    }
    i++;
    str++;
  }
  result[i] = '\0'; // Null-terminate the string
  return result;
}

// Function to convert a string to uppercase
char *toupper(char *str) {
  char *result = malloc(strlen(str) + 1); // +1 for the null-terminator
  int i = 0;
  while (*str != '\0') {
    if (*str >= 'a' && *str <= 'z') {
      result[i] = *str - 32;
    } else {
      result[i] = *str;
    }
    i++;
    str++;
  }
  result[i] = '\0'; // Null-terminate the string
  return result;
}

// Main function
int main() {
  char *str1 = "Hello ";
  char *str2 = "World!";

  // Concatenate the two strings
  char *result = concatenate(str1, str2);
  printf("Concatenated string: %s\n", result);

  // Reverse the concatenated string
  char *reversed_result = reverse(result);
  printf("Reversed string: %s\n", reversed_result);

  // Compare the original and reversed strings
  int comparison = compare(result, reversed_result);
  if (comparison == 0) {
    printf("The original and reversed strings are equal.\n");
  } else if (comparison > 0) {
    printf("The original string is greater than the reversed string.\n");
  } else {
    printf("The reversed string is greater than the original string.\n");
  }

  // Find the length of the reversed string
  int length_of_reversed_result = length(reversed_result);
  printf("Length of the reversed string: %d\n", length_of_reversed_result);

  // Find the first occurrence of the character 'l' in the reversed string
  char *first_occurrence = find(reversed_result, 'l');
  if (first_occurrence != NULL) {
    printf("First occurrence of the character 'l' in the reversed string: %s\n",
           first_occurrence);
  } else {
    printf("Character 'l' not found in the reversed string.\n");
  }

  // Find the last occurrence of the character 'd' in the reversed string
  char *last_occurrence = rfind(reversed_result, 'd');
  if (last_occurrence != NULL) {
    printf("Last occurrence of the character 'd' in the reversed string: %s\n",
           last_occurrence);
  } else {
    printf("Character 'd' not found in the reversed string.\n");
  }

  // Replace all occurrences of the character 'o' with the character 'a' in the reversed string
  char *replaced_result = replace(reversed_result, 'o', 'a');
  printf("Replaced string: %s\n", replaced_result);

  // Convert the replaced string to lowercase
  char *lowercase_result = tolower(replaced_result);
  printf("Lowercase string: %s\n", lowercase_result);

  // Convert the lowercase string to uppercase
  char *uppercase_result = toupper(lowercase_result);
  printf("Uppercase string: %s\n", uppercase_result);

  // Free the allocated memory
  free(result);
  free(reversed_result);
  free(replaced_result);
  free(lowercase_result);
  free(uppercase_result);

  return 0;
}