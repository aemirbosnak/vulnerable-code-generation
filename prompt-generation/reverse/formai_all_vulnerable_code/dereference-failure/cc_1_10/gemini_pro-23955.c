//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if the user wants to encrypt or decrypt
int get_mode() {
  char choice;
  printf("Do you want to encrypt (e) or decrypt (d)? ");
  scanf(" %c", &choice);
  return choice == 'e' ? 1 : 0;
}

// Get the input string from the user
char* get_input() {
  char* input = NULL;
  size_t len = 0;
  printf("Enter the string to encrypt/decrypt: ");
  getline(&input, &len, stdin);
  return input;
}

// Encrypt the input string using a simple XOR cipher
char* encrypt(char* input) {
  int key = 13;  // You can change this to any number
  char* encrypted = malloc(strlen(input) + 1);
  for (int i = 0; i < strlen(input); i++) {
    encrypted[i] = input[i] ^ key;
  }
  encrypted[strlen(input)] = '\0';
  return encrypted;
}

// Decrypt the input string using the same XOR cipher
char* decrypt(char* input) {
  int key = 13;
  char* decrypted = malloc(strlen(input) + 1);
  for (int i = 0; i < strlen(input); i++) {
    decrypted[i] = input[i] ^ key;
  }
  decrypted[strlen(input)] = '\0';
  return decrypted;
}

// Print the encrypted/decrypted string
void print_output(char* output, int mode) {
  if (mode == 1) {
    printf("Encrypted string: %s", output);
  } else {
    printf("Decrypted string: %s", output);
  }
}

// Free the allocated memory
void cleanup(char* input, char* output) {
  free(input);
  free(output);
}

int main() {
  int mode = get_mode();
  char* input = get_input();
  char* output = mode == 1 ? encrypt(input) : decrypt(input);
  print_output(output, mode);
  cleanup(input, output);
  return 0;
}