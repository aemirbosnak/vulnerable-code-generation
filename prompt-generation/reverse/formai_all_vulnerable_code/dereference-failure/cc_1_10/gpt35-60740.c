//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>

/**
 * The Caesar Cipher is a simple substitution cipher that replaces
 * each letter with a letter 'k' positions down the alphabet.
 */
char *caesar_cipher(const char *plaintext, int key) {
  char *ciphertext = (char *) malloc((sizeof(char) * strlen(plaintext)) + 1);
  int i;
  for (i = 0; i < strlen(plaintext); i++) {
    // Only encrypt alphabetical characters
    if (isalpha(plaintext[i])) {
      // Determine if the character is uppercase or lowercase
      char shift_base;
      if (isupper(plaintext[i])) {
        shift_base = 'A';
      } else {
        shift_base = 'a';
      }

      // Apply the Caesar shift
      char shifted_char = (plaintext[i] - shift_base + key) % 26 + shift_base;

      ciphertext[i] = shifted_char;
    } else {
      // Non-alphabetical characters are copied as is
      ciphertext[i] = plaintext[i];
    }
  }
  ciphertext[i] = '\0';
  return ciphertext;
}

int main(int argc, const char *argv[]) {
  if (argc < 3) {
    printf("usage: %s <plaintext> <key>\n", argv[0]);
    return 1;
  }

  const char *plaintext = argv[1];
  int key = atoi(argv[2]);

  printf("plaintext: %s\n", plaintext);
  printf("key: %d\n", key);

  char *ciphertext = caesar_cipher(plaintext, key);

  printf("ciphertext: %s\n", ciphertext);

  free(ciphertext);
  return 0;
}