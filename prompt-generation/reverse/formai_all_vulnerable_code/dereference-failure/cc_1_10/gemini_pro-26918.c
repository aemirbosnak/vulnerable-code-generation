//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "SECRET"

// Define the number of rounds for encryption
#define ROUNDS 10

// Function to encrypt data
char *encrypt(char *data) {
  char *encryptedData = malloc(strlen(data) + 1);
  int i, j, k;
  
  // Perform the encryption rounds
  for (i = 0; i < ROUNDS; i++) {
    // Apply the encryption key XOR operation
    for (j = 0; j < strlen(data); j++) {
      encryptedData[j] = data[j] ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }
    
    // Shift the data bits
    for (j = 0; j < strlen(data); j++) {
      // Shift left by 1 bit
      encryptedData[j] = (encryptedData[j] << 1) | (encryptedData[j] >> 7);
    }
    
    // Apply a random permutation
    for (j = 0; j < strlen(data); j++) {
      k = rand() % strlen(data);
      char temp = encryptedData[j];
      encryptedData[j] = encryptedData[k];
      encryptedData[k] = temp;
    }
  }
  
  // Return the encrypted data
  return encryptedData;
}

// Function to decrypt data
char *decrypt(char *data) {
  char *decryptedData = malloc(strlen(data) + 1);
  int i, j, k;
  
  // Reverse the encryption rounds
  for (i = ROUNDS - 1; i >= 0; i--) {
    // Reverse the random permutation
    for (j = 0; j < strlen(data); j++) {
      k = rand() % strlen(data);
      char temp = decryptedData[j];
      decryptedData[j] = decryptedData[k];
      decryptedData[k] = temp;
    }
    
    // Shift the data bits right
    for (j = 0; j < strlen(data); j++) {
      // Shift right by 1 bit
      decryptedData[j] = (decryptedData[j] >> 1) | (decryptedData[j] << 7);
    }
    
    // Apply the encryption key XOR operation
    for (j = 0; j < strlen(data); j++) {
      decryptedData[j] = data[j] ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }
  }
  
  // Return the decrypted data
  return decryptedData;
}

// Retro-style banner
void printBanner() {
  printf("********************************************************************************\n");
  printf("***             _                            _                          ***\n");
  printf("***            | |                          | |                         ***\n");
  printf("***   ___ __ _  | | ___  _ __ ___   ___  ___| | ___  _ __   ___  _ __   ***\n");
  printf("***  / __/ _` | | |/ _ \\| '_ ` _ \\ / _ \\/ __| |/ _ \\| '__| / _ \\| '_ \\  ***\n");
  printf("*** | (_| (_| | | | (_) | | | | | |  __/ (__| | (_) | |    | (_) | | | | ***\n");
  printf("***  \\___\\__,_| |_|\\___/|_| |_| |_|\\___|\\___|_|\\___/|_|     \\___/|_| |_| ***\n");
  printf("********************************************************************************\n");
  printf("***                                                                      ***\n");
  printf("***  Welcome to the Retro Encryption Machine!  ***\n");
  printf("***                                                                      ***\n");
  printf("********************************************************************************\n");
}

// Main function
int main() {
  // Print the retro banner
  printBanner();
  
  // Get the input from the user
  char *input = malloc(1024);
  printf("Enter your secret message: ");
  fgets(input, 1024, stdin);
  
  // Encrypt the input
  char *encrypted = encrypt(input);

  // Print the encrypted message
  printf("\nYour encrypted message is: %s\n", encrypted);

  // Decrypt the encrypted message
  char *decrypted = decrypt(encrypted);

  // Print the decrypted message
  printf("\nYour decrypted message is: %s\n", decrypted);

  // Free the allocated memory
  free(input);
  free(encrypted);
  free(decrypted);
  
  return 0;
}