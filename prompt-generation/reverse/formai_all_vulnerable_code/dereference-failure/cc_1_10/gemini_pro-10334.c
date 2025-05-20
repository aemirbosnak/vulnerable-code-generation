//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 64  // Max size of key in bytes

typedef struct {
  char *key;
  int key_size;
} Key;

typedef struct {
  char *data;
  int data_size;
} EncryptedData;

Key generate_key(int key_size) {
  Key key;
  key.key = malloc(key_size);
  for (int i = 0; i < key_size; i++) {
    key.key[i] = rand() % 256;
  }
  key.key_size = key_size;
  return key;
}

EncryptedData encrypt_data(char *data, int data_size, Key key) {
  EncryptedData encrypted_data;
  encrypted_data.data = malloc(data_size);
  for (int i = 0; i < data_size; i++) {
    encrypted_data.data[i] = data[i] ^ key.key[i % key.key_size];
  }
  encrypted_data.data_size = data_size;
  return encrypted_data;
}

char *decrypt_data(EncryptedData encrypted_data, Key key) {
  char *data = malloc(encrypted_data.data_size);
  for (int i = 0; i < encrypted_data.data_size; i++) {
    data[i] = encrypted_data.data[i] ^ key.key[i % key.key_size];
  }
  return data;
}

int main() {
  // Generate a random key
  srand(time(NULL));
  Key key = generate_key(MAX_KEY_SIZE);

  // Encrypt the data
  char *data = "The quick brown fox jumps over the lazy dog";
  int data_size = strlen(data);
  EncryptedData encrypted_data = encrypt_data(data, data_size, key);

  // Decrypt the data
  char *decrypted_data = decrypt_data(encrypted_data, key);

  // Print the decrypted data
  printf("Decrypted data: %s\n", decrypted_data);

  return 0;
}