//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our super secret, totally unbreakable hash function
unsigned long long hash(const char *str) {
  unsigned long long h = 0;
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    h = (h << 5) + h + (unsigned char)str[i];
  }
  return h;
}

int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter your super secret message: ");
  scanf("%s", str);

  // Hash the input string
  unsigned long long h = hash(str);

  // Print the hash value
  printf("Your super secret hash is: %llu\n", h);

  // Now, let's try to break the hash function!
  char *evil_twin = malloc(strlen(str) + 1);
  strcpy(evil_twin, str);

  // Flip a single bit in the input string
  int bit_to_flip = rand() % (strlen(str) * 8);
  evil_twin[bit_to_flip / 8] ^= (1 << (bit_to_flip % 8));

  // Hash the modified input string
  unsigned long long h_evil = hash(evil_twin);

  // Print the modified hash value
  printf("Your evil twin's hash is: %llu\n", h_evil);

  // Check if the hash values are different
  if (h != h_evil) {
    printf("Oops, looks like our hash function isn't so unbreakable after all!\n");
  } else {
    printf("Phew, our hash function is still safe from the evil twins!\n");
  }

  // Free the allocated memory
  free(evil_twin);

  return 0;
}