//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare a string and initialize it with the phrase "The quick brown fox jumps over the lazy dog."
  char *string = "The quick brown fox jumps over the lazy dog.";

  // Calculate the length of the string.
  int length = strlen(string);

  // Create an array of characters to store the reversed string.
  char *reversedString = malloc(length + 1);

  // Reverse the string.
  for (int i = 0; i < length; i++) {
    reversedString[length - i - 1] = string[i];
  }

  // Terminate the reversed string with a null character.
  reversedString[length] = '\0';

  // Print the original string and the reversed string.
  printf("Original string: %s\n", string);
  printf("Reversed string: %s\n", reversedString);

  // Calculate the midpoint of the string.
  int midpoint = length / 2;

  // Create an array of characters to store the first half of the string.
  char *firstHalf = malloc(midpoint + 1);

  // Copy the first half of the string into the firstHalf array.
  memcpy(firstHalf, string, midpoint);

  // Terminate the first half of the string with a null character.
  firstHalf[midpoint] = '\0';

  // Create an array of characters to store the second half of the string.
  char *secondHalf = malloc(length - midpoint + 1);

  // Copy the second half of the string into the secondHalf array.
  memcpy(secondHalf, string + midpoint, length - midpoint);

  // Terminate the second half of the string with a null character.
  secondHalf[length - midpoint] = '\0';

  // Print the first half of the string and the second half of the string.
  printf("First half of the string: %s\n", firstHalf);
  printf("Second half of the string: %s\n", secondHalf);

  // Concatenate the reversed string and the first half of the string.
  char *newString = malloc(length + midpoint + 1);

  // Copy the reversed string into the newString array.
  memcpy(newString, reversedString, length);

  // Copy the first half of the string into the newString array after the reversed string.
  memcpy(newString + length, firstHalf, midpoint);

  // Terminate the new string with a null character.
  newString[length + midpoint] = '\0';

  // Print the new string.
  printf("New string: %s\n", newString);

  // Free the memory allocated for the reversed string, the first half of the string, and the second half of the string.
  free(reversedString);
  free(firstHalf);
  free(secondHalf);

  return 0;
}