//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
// A study in encryption with Sherlock Holmes' flair

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

// Watson's helper to acquire the enigma
char* get_input() {
  char* input = malloc(MAX_INPUT_SIZE);
  printf("Holmes: Enter the secret message, my dear Watson: ");
  fgets(input, MAX_INPUT_SIZE, stdin);
  return input;
}

// Holmes' brilliant encryption technique
char* encrypt(char* input) {
  int i, length = strlen(input);
  char* encrypted = malloc(length + 1); // Length plus null terminator
  for (i = 0; i < length; i++) {
    encrypted[i] = input[i] + 3; // Shift each character right by 3 (a simple cipher)
  }
  encrypted[length] = '\0';
  return encrypted;
}

// Moriarty's nemesis, the decryptor
char* decrypt(char* encrypted) {
  int i, length = strlen(encrypted);
  char* decrypted = malloc(length + 1);
  for (i = 0; i < length; i++) {
    decrypted[i] = encrypted[i] - 3; // Shift each character back by 3
  }
  decrypted[length] = '\0';
  return decrypted;
}

int main() {
  char* input = get_input();
  char* encrypted = encrypt(input);
  printf("Holmes: The encrypted enigma is: %s\n", encrypted);

  char* decrypted = decrypt(encrypted);
  printf("Watson: The decrypted message is: %s\n", decrypted);

  free(input);
  free(encrypted);
  free(decrypted);
  return 0;
}