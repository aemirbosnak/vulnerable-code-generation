//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Cyberpunk
// Initiating data encryption sequence...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining our customized cipher algorithm:
char* cyberpunkCipher(char* inputText, int key) {

  // Initializing variables for our encryption process:
  int inputLength = strlen(inputText);
  char* encryptedText = (char*)malloc(inputLength + 1);
  srand(time(NULL)); // Setting a random seed for enhanced security!

  // Looping through each character of the input text:
  for (int i = 0; i < inputLength; i++) {

    // Encrypting each character using our advanced algorithm:
    encryptedText[i] = (inputText[i] + key) ^ (rand() % 256);
  }

  // Terminating the encrypted text with a null character:
  encryptedText[inputLength] = '\0';

  // Returning the encrypted result:
  return encryptedText;
}

int main() {

  // Greetings, User! Prepare your data for encryption.
  printf("Greetings, User!\n");

  // Prompting for input text to encrypt:
  char inputText[1024];
  printf("Enter the text you wish to encrypt: ");
  scanf("%[^\n]", inputText);

  // Prompting for encryption key:
  int key;
  printf("Enter the encryption key (an integer): ");
  scanf("%d", &key);

  // Initiating the encryption process:
  char* encryptedText = cyberpunkCipher(inputText, key);

  // Displaying the encrypted text:
  printf("Encrypted Text: %s\n", encryptedText);

  // Prompting user to decrypt the encrypted text:
  printf("Type 'decrypt' to decrypt the encrypted text: ");
  char decryptOption[8];
  scanf("%s", decryptOption);

  // Decryption process:
  if (strcmp(decryptOption, "decrypt") == 0) {

    // Decrypting the encrypted text using the same key:
    char* decryptedText = cyberpunkCipher(encryptedText, -key);

    // Displaying the decrypted text:
    printf("Decrypted Text: %s\n", decryptedText);
  }

  // Farewell message:
  printf("Encryption and Decryption complete. Stay vigilant in the digital realm.\n");

  return 0;
}