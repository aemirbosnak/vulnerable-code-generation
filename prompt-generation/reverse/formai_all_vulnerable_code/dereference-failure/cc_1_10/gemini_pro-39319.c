//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the alphabet
char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// define the key
char key[] = "mysecretkey";

// define the function to encrypt the message
char *encrypt(char *message) {
  char *encrypted_message = malloc(strlen(message) + 1);
  for (int i = 0; i < strlen(message); i++) {
    int index = strchr(alphabet, message[i]) - alphabet;
    int shifted_index = (index + strlen(key)) % strlen(alphabet);
    encrypted_message[i] = alphabet[shifted_index];
  }
  return encrypted_message;
}

// define the function to decrypt the message
char *decrypt(char *encrypted_message) {
  char *decrypted_message = malloc(strlen(encrypted_message) + 1);
  for (int i = 0; i < strlen(encrypted_message); i++) {
    int index = strchr(alphabet, encrypted_message[i]) - alphabet;
    int shifted_index = (index - strlen(key)) % strlen(alphabet);
    decrypted_message[i] = alphabet[shifted_index];
  }
  return decrypted_message;
}

// get the message from the user
char *get_message() {
  char *message = malloc(1024);
  printf("Enter the message to be encrypted: ");
  scanf("%s", message);
  return message;
}

// print the encrypted message
void print_encrypted_message(char *encrypted_message) {
  printf("Encrypted message: %s\n", encrypted_message);
}

// print the decrypted message
void print_decrypted_message(char *decrypted_message) {
  printf("Decrypted message: %s\n", decrypted_message);
}

// main function
int main() {
  // get the message from the user
  char *message = get_message();

  // encrypt the message
  char *encrypted_message = encrypt(message);

  // print the encrypted message
  print_encrypted_message(encrypted_message);

  // decrypt the message
  char *decrypted_message = decrypt(encrypted_message);

  // print the decrypted message
  print_decrypted_message(decrypted_message);

  // free the allocated memory
  free(message);
  free(encrypted_message);
  free(decrypted_message);

  return 0;
}