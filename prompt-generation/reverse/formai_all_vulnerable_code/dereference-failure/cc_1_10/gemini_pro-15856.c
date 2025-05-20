//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: unmistakable
// Encryption Enigma Machine

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Rotor wiring
int rotor1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
int rotor2[] = {7, 4, 2, 13, 15, 22, 20, 9, 6, 18, 5, 25, 17, 16, 19, 11, 2, 8, 10, 23, 1, 21, 14, 24, 3, 12};
int rotor3[] = {1, 14, 25, 3, 6, 19, 12, 11, 8, 21, 2, 22, 9, 10, 23, 24, 16, 5, 20, 7, 18, 4, 15, 17, 13};
int reflector[] = {26, 11, 19, 15, 20, 7, 23, 9, 1, 18, 16, 17, 21, 25, 12, 22, 10, 4, 24, 3, 8, 13, 6, 2, 14};

// Rotor position
int rotor1Pos = 0;
int rotor2Pos = 0;
int rotor3Pos = 0;

// Function to encode a character
char encodeChar(char c) {
  // Convert character to number
  int num = c - 'A' + 1;

  // Pass through rotors
  num = rotor1[(num + rotor1Pos) % 26];
  num = rotor2[(num + rotor2Pos) % 26];
  num = rotor3[(num + rotor3Pos) % 26];

  // Reflect
  num = reflector[num - 1];

  // Pass back through rotors
  num = rotor3[(num - rotor3Pos + 26) % 26] + 1;
  num = rotor2[(num - rotor2Pos + 26) % 26] + 1;
  num = rotor1[(num - rotor1Pos + 26) % 26] + 1;

  // Convert number to character
  return 'A' + (num - 1);
}

// Function to encode a string
char *encodeString(char *s) {
  int len = strlen(s);
  char *encoded = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    encoded[i] = encodeChar(s[i]);
  }
  encoded[len] = '\0';
  return encoded;
}

// Main function
int main() {
  printf("Enter a message to encode: ");
  char s[1024];
  gets(s);

  // Encode the message
  char *encoded = encodeString(s);

  // Print the encoded message
  printf("Encoded message: %s\n", encoded);

  // Free the allocated memory
  free(encoded);

  return 0;
}