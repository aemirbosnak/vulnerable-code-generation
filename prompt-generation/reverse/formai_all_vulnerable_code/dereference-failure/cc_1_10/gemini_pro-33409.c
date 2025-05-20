//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a custom data type to represent the state of the encryption process.
typedef struct {
  int key;
  int round;
  char *input;
  int input_length;
  char *output;
  int output_length;
} EncryptionState;

// Initialize the encryption state with the given key and input.
void init_encryption_state(EncryptionState *state, int key, char *input) {
  state->key = key;
  state->round = 0;
  state->input = input;
  state->input_length = strlen(input);
  state->output = malloc(state->input_length + 1);
  state->output_length = 0;
}

// Encrypt a single character.
char encrypt_character(EncryptionState *state, char character) {
  // Perform key-based encryption.
  char encrypted_character = character ^ state->key;

  // Perform round-based encryption.
  for (int i = 0; i < state->round; i++) {
    encrypted_character = encrypted_character + i;
    encrypted_character = encrypted_character % 256;
  }

  return encrypted_character;
}

// Encrypt the input and store the result in the output.
void encrypt(EncryptionState *state) {
  for (int i = 0; i < state->input_length; i++) {
    char encrypted_character = encrypt_character(state, state->input[i]);
    state->output[state->output_length++] = encrypted_character;
  }

  // Null-terminate the output string.
  state->output[state->output_length] = '\0';
}

// Print the input and output strings.
void print_strings(EncryptionState *state) {
  printf("Input: %s\n", state->input);
  printf("Output: %s\n\n", state->output);
}

// Main function to test the encryption process.
int main() {
  // Create an encryption state.
  EncryptionState state;

  // Initialize the encryption state with a key and input.
  init_encryption_state(&state, 123, "Hello World!");

  // Encrypt the input.
  encrypt(&state);

  // Print the input and output strings.
  print_strings(&state);

  return 0;
}