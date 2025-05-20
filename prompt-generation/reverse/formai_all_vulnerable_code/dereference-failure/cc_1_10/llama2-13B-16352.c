//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 256

// Generate a random key
void generate_key(char *key) {
  int i;
  for (i = 0; i < KEY_SIZE; i++) {
    key[i] = (char)rand() % 26 + 'A';
  }
}

// Encrypt a message
void encrypt(char *message, char *key) {
  int i, j;
  char temp;
  for (i = 0; i < MESSAGE_SIZE; i++) {
    // Shift the message by the corresponding position in the key
    for (j = 0; j < KEY_SIZE; j++) {
      temp = message[i] + (key[j] - 'A');
      if (temp > 'Z') {
        temp -= 'z';
      }
      message[i] = temp;
    }
  }
}

// Decrypt an encrypted message
void decrypt(char *message, char *key) {
  int i, j;
  char temp;
  for (i = 0; i < MESSAGE_SIZE; i++) {
    // Shift the message by the corresponding position in the key in reverse
    for (j = KEY_SIZE - 1; j >= 0; j--) {
      temp = message[i] - (key[j] - 'A');
      if (temp < 'a') {
        temp += 'z';
      }
      message[i] = temp;
    }
  }
}

int main() {
  char message[] = "The quick brown fox jumps over the lazy dog";
  char key[] = "randomkey";
  generate_key(key);
  encrypt(message, key);
  printf("%s\n", message);
  decrypt(message, key);
  printf("%s\n", message);
  return 0;
}