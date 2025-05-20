//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
// In the ethereal realm of bits and bytes,
// Where secrets dance in shadows,
// And mindscapes twist in enigmatic tides,
// I weave an incantation to shroud your words.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The keeper of secrets, a sentinel of truth,
// A maze of algorithms, a labyrinth of proof,
typedef struct {
  int key;
  int salt;
} Cipher;

Cipher weaveEnigma(int key, int salt) {
  // The threads of fate intertwine,
  // A dance of numbers, a celestial design,
  Cipher cipher = {key, salt};
  return cipher;
}

char *encrypt(Cipher cipher, char *plaintext) {
  // Through the labyrinth's winding ways,
  // A symphony of bits, a code that sways,
  int key = cipher.key;
  int salt = cipher.salt;
  int len = strlen(plaintext);
  char *ciphertext = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    ciphertext[i] = plaintext[i] + key + salt;
  }
  ciphertext[len] = '\0';
  return ciphertext;
}

char *decrypt(Cipher cipher, char *ciphertext) {
  // Unraveling the tapestry, deciphering the arcane,
  // Weaving words anew from the fabric of pain,
  int key = cipher.key;
  int salt = cipher.salt;
  int len = strlen(ciphertext);
  char *plaintext = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    plaintext[i] = ciphertext[i] - key - salt;
  }
  plaintext[len] = '\0';
  return plaintext;
}

int main(int argc, char *argv[]) {
  // As the sands of time shift and the stars align,
  // A secret message awaits, a treasure to divine,
  if (argc != 4) {
    printf("Usage: %s <key> <salt> <plaintext>\n", argv[0]);
    return 1;
  }
  
  int key = atoi(argv[1]);
  int salt = atoi(argv[2]);
  char *plaintext = argv[3];
  
  Cipher cipher = weaveEnigma(key, salt);
  char *ciphertext = encrypt(cipher, plaintext);
  
  printf("Encrypted message: %s\n", ciphertext);
  
  char *decrypted = decrypt(cipher, ciphertext);
  printf("Decrypted message: %s\n", decrypted);
  
  free(ciphertext);
  free(decrypted);
  return 0;
}