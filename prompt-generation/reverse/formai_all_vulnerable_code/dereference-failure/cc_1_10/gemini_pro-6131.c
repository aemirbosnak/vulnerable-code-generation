//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Calculate the checksum of a given string
int calculate_checksum(char *string) {
  // Initialize the checksum to 0
  int checksum = 0;

  // Iterate over each character in the string
  for (int i = 0; string[i] != '\0'; i++) {
    // Add the ASCII value of the character to the checksum
    checksum += string[i];
  }

  // Return the checksum
  return checksum;
}

// Print the checksum of a given string
void print_checksum(char *string) {
  // Calculate the checksum of the string
  int checksum = calculate_checksum(string);

  // Print the checksum to the console
  printf("The checksum of '%s' is %d\n", string, checksum);
}

// Get a string from the user
char *get_string_from_user() {
  // Create a buffer to store the string
  char *buffer = malloc(1024);

  // Get the string from the user
  printf("Enter a string: ");
  scanf("%s", buffer);

  // Return the string
  return buffer;
}

// Main function
int main() {
  // Get a string from the user
  char *string = get_string_from_user();

  // Print the checksum of the string
  print_checksum(string);

  // Free the memory allocated for the string
  free(string);

  // Return 0 to indicate success
  return 0;
}