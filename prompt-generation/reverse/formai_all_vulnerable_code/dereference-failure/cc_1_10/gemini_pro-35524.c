//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
// Amidst the desolate wasteland of a shattered world, I, a lone survivor, delve into the remnants of technology in search of solace and survival.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// In a decaying bunker, I stumble upon a battered encryption device known as "The Cipher Serpent." Its obsidian casing whispers secrets of a bygone era.

char *encryptSerpent(char *plaintext, char *key) {
  int plaintext_len = strlen(plaintext);
  int key_len = strlen(key);
  char *ciphertext = malloc(plaintext_len + 1);

  for (int i = 0; i < plaintext_len; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % key_len];
  }
  ciphertext[plaintext_len] = '\0';

  return ciphertext;
}

// With the cipher in hand, I decipher transmissions from distant outposts, grasping at fragments of hope in the darkness.

char *decryptSerpent(char *ciphertext, char *key) {
  int ciphertext_len = strlen(ciphertext);
  int key_len = strlen(key);
  char *plaintext = malloc(ciphertext_len + 1);

  for (int i = 0; i < ciphertext_len; i++) {
    plaintext[i] = ciphertext[i] ^ key[i % key_len];
  }
  plaintext[ciphertext_len] = '\0';

  return plaintext;
}

int main(int argc, char *argv[]) {
  // As the sun peeks through the shattered remnants of skyscrapers, I stumble upon a weathered journal, its pages filled with tales of a lost civilization.

  if (argc < 4) {
    printf("Usage: %s <input file> <key> <output file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Error opening input file.\n");
    return EXIT_FAILURE;
  }

  FILE *output_file = fopen(argv[3], "w");
  if (output_file == NULL) {
    printf("Error opening output file.\n");
    return EXIT_FAILURE;
  }

  // In the flickering glow of a dying fire, I feed the journal's contents into the Cipher Serpent, transforming its secrets into an unreadable cipher.

  char *plaintext = malloc(512);
  while (fgets(plaintext, 512, input_file)) {
    plaintext[strlen(plaintext) - 1] = '\0'; // Remove newline character

    char *ciphertext = encryptSerpent(plaintext, argv[2]);
    fprintf(output_file, "%s\n", ciphertext);
    free(ciphertext);
  }

  // As darkness envelops the world, I bury the encrypted journal deep within the bunker, hoping that future survivors may decipher its secrets and rebuild our shattered world.

  fclose(input_file);
  fclose(output_file);

  return EXIT_SUCCESS;
}