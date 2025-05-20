//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int key;
  char *alphabet;
} cipher_t;

char *generate_alphabet(int key) {
  char *alphabet = (char *)malloc(26);
  for (int i = 0; i < 26; i++) {
    alphabet[i] = 'A' + (i + key) % 26;
  }
  return alphabet;
}

char *encrypt(cipher_t *cipher, char *plaintext) {
  char *ciphertext = (char *)malloc(strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    int index = plaintext[i] - 'A';
    if (index >= 0 && index < 26) {
      ciphertext[i] = cipher->alphabet[index];
    } else {
      ciphertext[i] = plaintext[i];
    }
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

char *decrypt(cipher_t *cipher, char *ciphertext) {
  char *plaintext = (char *)malloc(strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    int index = strchr(cipher->alphabet, ciphertext[i]) - cipher->alphabet;
    if (index >= 0 && index < 26) {
      plaintext[i] = 'A' + index;
    } else {
      plaintext[i] = ciphertext[i];
    }
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

int main() {
  cipher_t cipher;
  cipher.key = 5;
  cipher.alphabet = generate_alphabet(cipher.key);

  char *plaintext = "SECRET MESSAGE";
  char *ciphertext = encrypt(&cipher, plaintext);
  printf("Ciphertext: %s\n", ciphertext);

  char *decrypted_plaintext = decrypt(&cipher, ciphertext);
  printf("Decrypted Plaintext: %s\n", decrypted_plaintext);

  free(cipher.alphabet);
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}