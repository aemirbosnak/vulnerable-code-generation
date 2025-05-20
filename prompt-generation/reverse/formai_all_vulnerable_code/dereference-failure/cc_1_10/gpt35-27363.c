//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEYLEN 10

char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

int main(void) {
   char plaintext[100], ciphertext[100], *decryptedtext, key[KEYLEN];
   
   printf("Enter plaintext: ");
   scanf("%s", plaintext);
   printf("Enter key (10 characters): ");
   scanf("%s", key);
   
   // Encrypt plaintext using key
   strcpy(ciphertext, encrypt(plaintext, key));
   
   // Decrypt ciphertext using key
   decryptedtext = decrypt(ciphertext, key);
   
   printf("\n\nPlaintext: %s\n", plaintext);
   printf("Ciphertext: %s\n", ciphertext);
   printf("Decrypted text: %s\n", decryptedtext);
   
   return 0;
}

char *encrypt(char *plaintext, char *key) {
   char *ciphertext = (char *)malloc(sizeof(char) * (strlen(plaintext) + 1));
   int i;
   
   for(i = 0; i < strlen(plaintext); i++) {
      *(ciphertext + i) = *(plaintext + i) ^ *(key + (i % KEYLEN));
   }
   *(ciphertext + i) = '\0';
   
   return ciphertext;
}

char *decrypt(char *ciphertext, char *key) {
   char *decryptedtext = (char *)malloc(sizeof(char) * (strlen(ciphertext) + 1));
   int i;
   
   for(i = 0; i < strlen(ciphertext); i++) {
      *(decryptedtext + i) = *(ciphertext + i) ^ *(key + (i % KEYLEN));
   }
   *(decryptedtext + i) = '\0';
   
   return decryptedtext;
}