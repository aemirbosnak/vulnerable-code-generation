//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 256 // 256-bit key size for AES encryption
#define BLOCK_SIZE 16 // 128-bit block size for AES encryption

void hexPrint(unsigned char *array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%02x", array[i]);
  }
  printf("\n");
}

int main() {
  unsigned char *key = (unsigned char *)"mysecretkey12345"; // the secret key
  unsigned char iv[BLOCK_SIZE]; // initialization vector
  memset(iv, 0x00, BLOCK_SIZE);

  unsigned char message[256]; // the message to encrypt or decrypt
  memset(message, 0x00, sizeof(message));

  int choice;
  printf("Enter 1 to encrypt, 2 to decrypt: ");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Enter message to encrypt (max 256 bytes): ");
    fflush(stdin);
    fgets(message, sizeof(message), stdin);
    strtok(message, "\n");

    int len = strlen(message);

    // round up to nearest multiple of BLOCK_SIZE
    int padded_len = ((len + BLOCK_SIZE - 1) / BLOCK_SIZE) * BLOCK_SIZE;
    unsigned char *encrypted = malloc(padded_len);

    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE, &aes_key);

    AES_cbc_encrypt(message, encrypted, strlen(message), &aes_key, iv, AES_ENCRYPT);

    printf("Encrypted message: ");
    hexPrint(encrypted, padded_len);

  } else if (choice == 2) {
    printf("Enter message to decrypt (hex format): ");
    scanf("%s", message);

    int len = strlen(message) / 2;

    unsigned char *encrypted = malloc(len);
    for (int i = 0; i < len; i++) {
      sscanf(&message[i * 2], "%02x", &encrypted[i]);
    }

    unsigned char *decrypted = malloc(len);

    AES_KEY aes_key;
    AES_set_decrypt_key(key, KEY_SIZE, &aes_key);

    AES_cbc_encrypt(encrypted, decrypted, len, &aes_key, iv, AES_DECRYPT);

    decrypted[len] = '\0';
    printf("Decrypted message: %s\n", decrypted);

  } else {
    printf("Invalid choice.\n");
    return 1;
  }

  return 0;
}