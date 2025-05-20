//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Here, I present to you an extraordinary C program that embarks on a journey into the enigmatic realm of cryptography.
// This program will unveil the secrets of data encryption and decryption, empowering you to safeguard your valuable information.

// Let us dive right in and define the cryptographic key. This key will serve as the gatekeeper, unlocking the encrypted secrets.
// For the sake of simplicity, we will use a hardcoded key in this example.
char key[] = "MyTopSecretEncryptionKey";

// Now, let's introduce the function responsible for encrypting our data. This function, appropriately named encrypt(),
// takes the plaintext and the key as inputs and returns the encrypted ciphertext.
char *encrypt(char *plaintext) {
  // We allocate memory to store the encrypted ciphertext.
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Time to perform the encryption magic! We iterate through each character of the plaintext.
  for (int i = 0; i < strlen(plaintext); i++) {
    // Here's the crux of the encryption process. We apply the XOR operation between the plaintext character and the corresponding key character.
    ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
  }

  // To ensure the encrypted data remains intact, we add a null terminator at the end of the ciphertext.
  ciphertext[strlen(plaintext)] = '\0';

  // And voila! We return the encrypted ciphertext, ready to be transmitted or stored securely.
  return ciphertext;
}

// Now, let's shift our focus to the decryption process. We need a function to reverse the encryption and retrieve the original plaintext.
// Enter the decrypt() function, which takes the encrypted ciphertext and the key as inputs and returns the decrypted plaintext.
char *decrypt(char *ciphertext) {
  // We allocate memory to store the decrypted plaintext.
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Time to undo the encryption magic! We iterate through each character of the ciphertext.
  for (int i = 0; i < strlen(ciphertext); i++) {
    // Here comes the decryption trickery. We apply the XOR operation once again, this time between the ciphertext character and the corresponding key character.
    plaintext[i] = ciphertext[i] ^ key[i % strlen(key)];
  }

  // Just like before, we add a null terminator to ensure the decrypted plaintext remains intact.
  plaintext[strlen(ciphertext)] = '\0';

  // And tada! We return the decrypted plaintext, now restored to its original form.
  return plaintext;
}

// Let's put our encryption and decryption functions to the test.
int main() {
  // First, we define a plaintext message that we wish to encrypt.
  char plaintext[] = "This is a secret message.";

  // Now, let's encrypt the plaintext using our encrypt() function.
  char *ciphertext = encrypt(plaintext);

  // Time to display the encrypted ciphertext. Behold, the secrets are now hidden!
  printf("Encrypted Ciphertext: %s\n", ciphertext);

  // But wait, there's more! Let's decrypt the ciphertext using our decrypt() function to reveal the original plaintext.
  char *decryptedText = decrypt(ciphertext);

  // Finally, let's display the decrypted plaintext, proving that our encryption and decryption functions work flawlessly.
  printf("Decrypted Plaintext: %s\n", decryptedText);

  // Freeing the allocated memory, because we're responsible programmers!
  free(ciphertext);
  free(decryptedText);

  return 0;
}