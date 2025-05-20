//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the Enigma machine's rotor and reflector settings
static const int rotor_settings[3] = {5, 21, 9};
static const int reflector_settings[3] = {1, 17, 5};

// Define the mapping of characters to their encoded values
static const char encoding_map[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Define the inverse mapping of encoded values to their characters
static const char decoding_map[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Define the function to encode a single character
char encode_character(char c) {
  // Convert the character to uppercase
  c = toupper(c);

  // Find the index of the character in the encoding map
  int index = c - 'A';

  // Apply the rotor settings
  for (int i = 0; i < 3; i++) {
    index = (index + rotor_settings[i]) % 26;
  }

  // Apply the reflector settings
  for (int i = 0; i < 3; i++) {
    index = (index + reflector_settings[i]) % 26;
  }

  // Inverse the rotor settings
  for (int i = 2; i >= 0; i--) {
    index = (index - rotor_settings[i] + 26) % 26;
  }

  // Return the encoded character
  return encoding_map[index];
}

// Define the function to decode a single character
char decode_character(char c) {
  // Convert the character to uppercase
  c = toupper(c);

  // Find the index of the character in the decoding map
  int index = c - 'A';

  // Inverse the rotor settings
  for (int i = 2; i >= 0; i--) {
    index = (index - rotor_settings[i] + 26) % 26;
  }

  // Inverse the reflector settings
  for (int i = 2; i >= 0; i--) {
    index = (index - reflector_settings[i] + 26) % 26;
  }

  // Apply the rotor settings
  for (int i = 2; i >= 0; i--) {
    index = (index - rotor_settings[i] + 26) % 26;
  }

  // Return the decoded character
  return decoding_map[index];
}

// Define the function to encode a string
char *encode_string(char *s) {
  // Allocate memory for the encoded string
  char *encoded_string = malloc(strlen(s) + 1);

  // Encode each character in the string
  for (int i = 0; i < strlen(s); i++) {
    encoded_string[i] = encode_character(s[i]);
  }

  // Add the null terminator to the end of the string
  encoded_string[strlen(s)] = '\0';

  // Return the encoded string
  return encoded_string;
}

// Define the function to decode a string
char *decode_string(char *s) {
  // Allocate memory for the decoded string
  char *decoded_string = malloc(strlen(s) + 1);

  // Decode each character in the string
  for (int i = 0; i < strlen(s); i++) {
    decoded_string[i] = decode_character(s[i]);
  }

  // Add the null terminator to the end of the string
  decoded_string[strlen(s)] = '\0';

  // Return the decoded string
  return decoded_string;
}

// Define the main function
int main() {
  // Get the plaintext from the user
  char *plaintext = malloc(1024);
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Encode the plaintext
  char *encoded_string = encode_string(plaintext);

  // Print the encoded string
  printf("Encoded string: %s\n", encoded_string);

  // Decode the encoded string
  char *decoded_string = decode_string(encoded_string);

  // Print the decoded string
  printf("Decoded string: %s\n", decoded_string);

  // Free the allocated memory
  free(plaintext);
  free(encoded_string);
  free(decoded_string);

  return 0;
}