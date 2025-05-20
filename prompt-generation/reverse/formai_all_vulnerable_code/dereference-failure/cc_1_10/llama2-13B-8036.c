//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: excited
// 🔥 Secret Message Encryption 🔥
  // You know you want to 😏

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_LENGTH 10
#define MESSAGE_LENGTH 25

// 🔒 Generate Random Key 🔒
unsigned char generateRandomKey(int length) {
  unsigned char key[length];
  for (int i = 0; i < length; i++) {
    key[i] = (unsigned char)rand() % 256;
  }
  return key;
}

// 🔓 Encrypt Message 🔓
void encryptMessage(const char* message, const unsigned char* key) {
  int messageLength = strlen(message);
  int keyLength = sizeof(key);
  unsigned char* encryptedMessage = (unsigned char*)malloc(messageLength + 1);
  for (int i = 0; i < messageLength; i++) {
    encryptedMessage[i] = (message[i] + key[i % keyLength]) % 256;
  }
  encryptedMessage[messageLength] = '\0';
  printf("Encrypted message: %s\n", encryptedMessage);
}

// 🔑 Decrypt Message 🔑
void decryptMessage(const char* encryptedMessage, const unsigned char* key) {
  int messageLength = strlen(encryptedMessage);
  int keyLength = sizeof(key);
  unsigned char* decryptedMessage = (unsigned char*)malloc(messageLength + 1);
  for (int i = 0; i < messageLength; i++) {
    decryptedMessage[i] = (encryptedMessage[i] - key[i % keyLength]) % 256;
  }
  decryptedMessage[messageLength] = '\0';
  printf("Decrypted message: %s\n", decryptedMessage);
}

int main() {
  // 🔒 Generate Random Key 🔒
  unsigned char key[KEY_LENGTH];
  generateRandomKey(KEY_LENGTH);

  // 📝 Define Message 📝
  const char* message = "Hello, world!";

  // 🔓 Encrypt Message 🔓
  encryptMessage(message, key);

  // 🔑 Decrypt Message 🔑
  decryptMessage(message, key);

  return 0;
}