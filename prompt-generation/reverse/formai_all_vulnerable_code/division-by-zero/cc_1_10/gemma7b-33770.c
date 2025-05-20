//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char key[MAX_BUFFER_SIZE];
  char message[MAX_BUFFER_SIZE];
  int key_length;
  int message_length;

  printf("Enter the key (a string): ");
  fgets(key, MAX_BUFFER_SIZE, stdin);

  printf("Enter the message (a string): ");
  fgets(message, MAX_BUFFER_SIZE, stdin);

  key_length = strlen(key);
  message_length = strlen(message);

  // Calculate the encrypted message length
  int encrypted_length = (message_length + key_length - 1) / key_length + 1;

  // Allocate memory for the encrypted message
  char* encrypted_message = malloc(encrypted_length * sizeof(char));

  // Encrypt the message
  encrypt(key, message, encrypted_message, key_length, message_length);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encrypted_message);

  // Free the memory allocated for the encrypted message
  free(encrypted_message);

  return 0;
}

int encrypt(char* key, char* message, char* encrypted_message, int key_length, int message_length) {
  int i, j, k;
  int message_index = 0;
  int encrypted_index = 0;

  for (i = 0; i < key_length; i++) {
    for (j = 0; j < message_length; j++) {
      k = (key[i] - 'a' + message[j] - 'a') % 26;
      encrypted_message[encrypted_index++] = 'a' + k;
    }
  }

  return 0;
}