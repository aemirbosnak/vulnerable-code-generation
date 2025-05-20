//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our super cool text processing functions!
char* textToUpper(char* text);
char* textToLower(char* text);
char* textReverse(char* text);
char* textReplace(char* text, char* find, char* replace);
char* textTrim(char* text);

// Get ready for some text processing magic!
int main() {
  // Let's create some exciting text!
  char* text = "This is some AMAZING text that needs processing!";

  // Time to show off our text processing skills!
  printf("Original Text: %s\n", text);
  printf("Uppercase Text: %s\n", textToUpper(text));
  printf("Lowercase Text: %s\n", textToLower(text));
  printf("Reversed Text: %s\n", textReverse(text));
  printf("Replaced Text: %s\n", textReplace(text, "AMAZING", "FANTASTIC"));
  printf("Trimmed Text: %s\n", textTrim(text));

  // Don't forget to clean up after ourselves!
  free(text);
  return 0;
}

// Convert text to uppercase!
char* textToUpper(char* text) {
  int length = strlen(text);
  for (int i = 0; i < length; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] -= 32;
    }
  }
  return text;
}

// Convert text to lowercase!
char* textToLower(char* text) {
  int length = strlen(text);
  for (int i = 0; i < length; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] += 32;
    }
  }
  return text;
}

// Flip the text upside down!
char* textReverse(char* text) {
  int length = strlen(text);
  char temp;
  for (int i = 0; i < length / 2; i++) {
    temp = text[i];
    text[i] = text[length - i - 1];
    text[length - i - 1] = temp;
  }
  return text;
}

// Find and replace words like a pro!
char* textReplace(char* text, char* find, char* replace) {
  int findLength = strlen(find);
  int replaceLength = strlen(replace);
  int textLength = strlen(text);

  // Prepare to replace all occurrences of 'find' with 'replace'
  for (int i = 0; i < textLength - findLength + 1; i++) {
    if (strncmp(text + i, find, findLength) == 0) {
      // Found a match! Let's replace it!
      for (int j = 0; j < replaceLength - findLength; j++) {
        text[i + j] = replace[j];
      }
      // Adjust the text length accordingly
      textLength = textLength - findLength + replaceLength;
    }
  }
  return text;
}

// Trim those pesky spaces!
char* textTrim(char* text) {
  int length = strlen(text);
  int startIndex = 0;
  int endIndex = length - 1;

  // Find the first non-whitespace character
  while (text[startIndex] == ' ') {
    startIndex++;
  }

  // Find the last non-whitespace character
  while (text[endIndex] == ' ') {
    endIndex--;
  }

  // Create a new string with the trimmed text
  char* trimmedText = malloc(endIndex - startIndex + 1);
  strncpy(trimmedText, text + startIndex, endIndex - startIndex + 1);
  trimmedText[endIndex - startIndex + 1] = '\0';

  return trimmedText;
}