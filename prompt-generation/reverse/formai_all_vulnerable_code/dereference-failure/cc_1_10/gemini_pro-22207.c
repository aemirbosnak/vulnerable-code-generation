//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key.
#define KEY "This is a secret key"

// Recursively encrypt a string.
char *encrypt(char *str) {
  // If the string is empty, return an empty string.
  if (*str == '\0') {
    return "";
  }

  // Get the first character of the string.
  char c = *str;

  // Get the encrypted character.
  char e = c ^ KEY[strlen(KEY) - 1];

  // Recursively encrypt the rest of the string.
  char *rest = encrypt(str + 1);

  // Allocate memory for the encrypted string.
  char *encrypted = malloc(strlen(str) + 1);

  // Copy the encrypted character to the encrypted string.
  *encrypted = e;

  // Copy the rest of the encrypted string to the encrypted string.
  strcpy(encrypted + 1, rest);

  // Free the memory for the rest of the encrypted string.
  free(rest);

  // Return the encrypted string.
  return encrypted;
}

// Recursively decrypt a string.
char *decrypt(char *str) {
  // If the string is empty, return an empty string.
  if (*str == '\0') {
    return "";
  }

  // Get the first character of the string.
  char c = *str;

  // Get the decrypted character.
  char d = c ^ KEY[strlen(KEY) - 1];

  // Recursively decrypt the rest of the string.
  char *rest = decrypt(str + 1);

  // Allocate memory for the decrypted string.
  char *decrypted = malloc(strlen(str) + 1);

  // Copy the decrypted character to the decrypted string.
  *decrypted = d;

  // Copy the rest of the decrypted string to the decrypted string.
  strcpy(decrypted + 1, rest);

  // Free the memory for the rest of the decrypted string.
  free(rest);

  // Return the decrypted string.
  return decrypted;
}

// Get a string from the user.
char *get_string(void) {
  // Allocate memory for the string.
  char *str = malloc(1024);

  // Get the string from the user.
  printf("Enter a string: ");
  scanf("%s", str);

  // Return the string.
  return str;
}

// Print a string to the console.
void print_string(char *str) {
  // Print the string to the console.
  printf("%s\n", str);
}

// Main function.
int main(void) {
  // Get a string from the user.
  char *str = get_string();

  // Encrypt the string.
  char *encrypted = encrypt(str);

  // Print the encrypted string.
  print_string(encrypted);

  // Decrypt the string.
  char *decrypted = decrypt(encrypted);

  // Print the decrypted string.
  print_string(decrypted);

  // Free the memory for the strings.
  free(str);
  free(encrypted);
  free(decrypted);

  // Return 0.
  return 0;
}