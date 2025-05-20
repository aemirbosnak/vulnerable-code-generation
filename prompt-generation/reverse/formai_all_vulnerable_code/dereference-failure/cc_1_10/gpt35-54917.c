//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[100];
  char key[100];
  int i, j, k, len1, len2;
  
  printf("Enter message to encrypt: ");
  fgets(message, 100, stdin);
  printf("Enter key: ");
  fgets(key, 100, stdin);

  len1 = strlen(message);
  len2 = strlen(key);

  /* Removing newline character from message and key */
  message[strcspn(message, "\n")] = 0;
  key[strcspn(key, "\n")] = 0;

  /* Padding the key with itself */
  char *padded_key = (char*) malloc(len1 * sizeof(char));
  j = 0;
  for(i = 0; i < len1; i++) {
    padded_key[i] = key[j];
    j++;
    if(j == len2) {
      j = 0;
    }
  }

  /* XORing message and padded key */
  char encrypted_message[100];
  for(i = 0; i < len1; i++) {
    encrypted_message[i] = (char)((int)message[i] ^ (int)padded_key[i]);
  }
  encrypted_message[i] = '\0';
  
  printf("Encrypted message: %s", encrypted_message);

  /* Decrypting the message */
  char decrypted_message[100];
  for(i = 0; i < len1; i++) {
    decrypted_message[i] = (char)((int)encrypted_message[i] ^ (int)padded_key[i]);
  }
  decrypted_message[i] = '\0';
  
  printf("\nDecrypted message: %s", decrypted_message);
  
  free(padded_key);
  return 0;
}