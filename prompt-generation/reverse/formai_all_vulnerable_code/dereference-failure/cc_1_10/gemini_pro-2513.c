//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom cipher implementation, inspired by the enigmatic Enigma machine
void enigma_cipher(char *message, char *key) {
  int message_len = strlen(message);
  int key_len = strlen(key);

  // Create a substitution table based on the key
  char substitution_table[26];
  int i, j;
  for (i = 0; i < 26; i++) {
    substitution_table[i] = (key[(i + key_len) % key_len] - 'A' + i) % 26 + 'A';
  }

  // Encrypt the message using the substitution table
  for (i = 0; i < message_len; i++) {
    if (message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = substitution_table[message[i] - 'A'];
    }
  }
}

// Obfuscated function that extracts a secret from a message
char *extract_secret(char *message) {
  int i, j, count = 0;
  char *secret = malloc(sizeof(char) * 100);

  for (i = 0; i < strlen(message); i++) {
    if (message[i] % 2 == 0) {
      secret[count++] = message[i];
    }
  }

  secret[count] = '\0';
  return secret;
}

int main() {
  char message[] = "The enigmatic message is concealed within this text.";
  char key[] = "CIPHER";

  // Encrypt the message using the enigma cipher
  enigma_cipher(message, key);

  // Extract the secret from the encrypted message
  char *secret = extract_secret(message);

  // Reveal the secret
  printf("Behold, the secret decoded from the enigmatic message: %s\n", secret);

  free(secret);
  return 0;
}