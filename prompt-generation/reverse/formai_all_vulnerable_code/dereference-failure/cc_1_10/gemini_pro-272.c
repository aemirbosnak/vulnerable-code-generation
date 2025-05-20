//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// The Sandman's Dreamy Encryption Function
void encrypt(char* plaintext, char* encrypted) {
  // The key is the cosmic dance of the celestial spheres
  char key[] = "Yxubz~4r6t5!l7po9i8m";

  // Swirl the text with the ethereal dance
  for (int i = 0; i < strlen(plaintext); i++) {
    int k = i % strlen(key);
    encrypted[i] = plaintext[i] ^ key[k];
  }
}

// The Sugar Plum Fairy's Sugar-Coated Decryption Function
void decrypt(char* encrypted, char* plaintext) {
  // The key is the sweet symphony of the moonlight's lullaby
  char key[] = "V6t5r4y7u8i9m!0l9p";

  // Unswirl the text with the saccharine dance
  for (int i = 0; i < strlen(encrypted); i++) {
    int k = i % strlen(key);
    plaintext[i] = encrypted[i] ^ key[k];
  }
}

int main() {
  // The Cheshire Cat's Grinning Message
  char plaintext[] = "Life is a riddle, and the key is found in the Cheshire Cat's grin.";

  // The Mad Hatter's Encrypted Tea Party
  char encrypted[strlen(plaintext)];
  encrypt(plaintext, encrypted);

  // The White Rabbit's Time-Warping Decryption
  char decrypted[strlen(plaintext)];
  decrypt(encrypted, decrypted);

  // The Dormouse's Sleepy Revelation
  printf("The Mad Hatter's encrypted tea party:\n%s\n", encrypted);
  printf("And the White Rabbit's decrypted riddle:\n%s\n", decrypted);

  // The Queen of Hearts' Off-with-their-Heads Loop
  for (int i = 0; i < 5; i++) {
    printf("Off with their heads!\n");
  }

  return 0;
}