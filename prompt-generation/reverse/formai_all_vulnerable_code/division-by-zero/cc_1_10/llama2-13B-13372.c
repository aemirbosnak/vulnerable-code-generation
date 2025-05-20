//LLAMA2-13B DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGE_LENGTH 50
#define MAX_KEY_LENGTH 20

// Define the encryption functions
void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

// Define the main function
int main() {
  char message[MAX_MESSAGE_LENGTH];
  char key[MAX_KEY_LENGTH];
  int choice;

  // Ask the user for the message and key
  printf("What is the message you wish to send? ");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);
  printf("What is the key you wish to use for encryption? ");
  fgets(key, MAX_KEY_LENGTH, stdin);

  // Encrypt the message
  encrypt(message, key);

  // Ask the user if they want to decrypt the message
  printf("Do you wish to decrypt the message? (y/n) ");
  scanf(" %c", &choice);

  if (choice == 'y') {
    // Decrypt the message
    decrypt(message, key);
  }

  // Print the decrypted message (if any)
  if (message[0] != '\0') {
    printf("Decrypted message: %s\n", message);
  } else {
    printf("No message to decrypt.\n");
  }

  return 0;
}

// Define the encryption function
void encrypt(char *message, char *key) {
  int i, j;
  char c;

  // Loop through each character of the message
  for (i = 0; message[i] != '\0'; i++) {
    // Calculate the corresponding cipher letter
    c = message[i] + (key[i % strlen(key)] - 'a') * 3;

    // If the cipher letter is outside the ASCII range, wrap around to the beginning
    if (c > 'z') {
      c = c - 'z';
    } else if (c < 'a') {
      c = c - 'a' + 'z';
    }

    // Store the cipher letter in the message
    message[i] = c;
  }
}

// Define the decryption function
void decrypt(char *message, char *key) {
  int i, j;
  char c;

  // Loop through each character of the message
  for (i = 0; message[i] != '\0'; i++) {
    // Calculate the corresponding plain letter
    c = message[i] - (key[i % strlen(key)] - 'a') * 3;

    // If the plain letter is outside the ASCII range, wrap around to the beginning
    if (c < 'a') {
      c = c + 'a' - 'z';
    } else if (c > 'z') {
      c = c - 'z';
    }

    // Store the plain letter in the message
    message[i] = c;
  }
}