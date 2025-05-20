//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom function to perform Caesar cipher encryption
char* encryptCaesar(char* plaintext, int key) {
  int len = strlen(plaintext);
  char* ciphertext = malloc(len + 1);  // +1 for null-terminator
  for (int i = 0; i < len; i++) {
    char c = plaintext[i];
    if (isalpha(c)) {
      c += key;
      if (c > 'z') {  // Wrap around if exceeding 'z'
        c -= 26;
      }
      else if (c < 'a') {  // Wrap around if falling below 'a'
        c += 26;
      }
    }
    ciphertext[i] = c;
  }
  ciphertext[len] = '\0';  // Null-terminate the ciphertext
  return ciphertext;
}

// Custom function to perform Caesar cipher decryption
char* decryptCaesar(char* ciphertext, int key) {
  int len = strlen(ciphertext);
  char* plaintext = malloc(len + 1);  // +1 for null-terminator
  for (int i = 0; i < len; i++) {
    char c = ciphertext[i];
    if (isalpha(c)) {
      c -= key;
      if (c > 'z') {  // Wrap around if exceeding 'z'
        c -= 26;
      }
      else if (c < 'a') {  // Wrap around if falling below 'a'
        c += 26;
      }
    }
    plaintext[i] = c;
  }
  plaintext[len] = '\0';  // Null-terminate the plaintext
  return plaintext;
}

// Main function to drive the program
int main() {
  char* original_message = "Hello, world!";

  // Encrypt the message using Caesar cipher with a key of 3
  int encryption_key = 3;
  char* encrypted_message = encryptCaesar(original_message, encryption_key);
  printf("Encrypted Message: %s\n", encrypted_message);

  // Decrypt the encrypted message using Caesar cipher with the same key
  char* decrypted_message = decryptCaesar(encrypted_message, encryption_key);
  printf("Decrypted Message: %s\n", decrypted_message);

  // Verify if the original message was successfully recovered
  int are_equal = strcmp(original_message, decrypted_message);
  if (are_equal == 0) {
    printf("Wow! The original message was recovered perfectly.\n");
  } else {
    printf("Oops, something went wrong during decryption.\n");
  }

  // Free up the dynamically allocated memory
  free(encrypted_message);
  free(decrypted_message);

  return 0;
}