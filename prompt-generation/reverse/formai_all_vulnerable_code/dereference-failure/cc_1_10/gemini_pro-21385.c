//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTED_FILENAME "encrypted_file.txt"
#define DECRYPTED_FILENAME "decrypted_file.txt"
#define KEYSTRING "KEYSTRING"

void encrypt(char *plaintext, char *encryptedtext, char *keystring) {
  int len = strlen(plaintext);
  for (int i = 0; i < len; i++) {
    encryptedtext[i] = plaintext[i] ^ keystring[i % strlen(keystring)];
  }
}

void decrypt(char *encryptedtext, char *decryptedtext, char *keystring) {
  int len = strlen(encryptedtext);
  for (int i = 0; i < len; i++) {
    decryptedtext[i] = encryptedtext[i] ^ keystring[i % strlen(keystring)];
  }
}

int main() {
  // Read the plaintext from a file.
  FILE *plaintextfile = fopen("plaintext.txt", "r");
  if (plaintextfile == NULL) {
    perror("Error opening plaintext file");
    return EXIT_FAILURE;
  }
  fseek(plaintextfile, 0, SEEK_END);
  long plaintextfilesize = ftell(plaintextfile);
  rewind(plaintextfile);
  char *plaintext = malloc(plaintextfilesize + 1);
  if (plaintext == NULL) {
    perror("Error allocating memory for plaintext");
    return EXIT_FAILURE;
  }
  fread(plaintext, 1, plaintextfilesize, plaintextfile);
  fclose(plaintextfile);

  // Encrypt the plaintext.
  char *encryptedtext = malloc(plaintextfilesize + 1);
  if (encryptedtext == NULL) {
    perror("Error allocating memory for encryptedtext");
    return EXIT_FAILURE;
  }
  encrypt(plaintext, encryptedtext, KEYSTRING);

  // Write the encrypted text to a file.
  FILE *encryptedfile = fopen(ENCRYPTED_FILENAME, "w");
  if (encryptedfile == NULL) {
    perror("Error opening encrypted file");
    return EXIT_FAILURE;
  }
  fwrite(encryptedtext, 1, plaintextfilesize, encryptedfile);
  fclose(encryptedfile);

  // Decrypt the encrypted text.
  char *decryptedtext = malloc(plaintextfilesize + 1);
  if (decryptedtext == NULL) {
    perror("Error allocating memory for decryptedtext");
    return EXIT_FAILURE;
  }
  decrypt(encryptedtext, decryptedtext, KEYSTRING);

  // Write the decrypted text to a file.
  FILE *decryptedfile = fopen(DECRYPTED_FILENAME, "w");
  if (decryptedfile == NULL) {
    perror("Error opening decrypted file");
    return EXIT_FAILURE;
  }
  fwrite(decryptedtext, 1, plaintextfilesize, decryptedfile);
  fclose(decryptedfile);

  // Free the allocated memory.
  free(plaintext);
  free(encryptedtext);
  free(decryptedtext);

  return EXIT_SUCCESS;
}