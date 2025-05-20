//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char* filename) {
  FILE *input, *output;
  char ch;
  int key = 13; // Change this to your desired key

  // Open the input file
  input = fopen(filename, "r");
  if (input == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  // Open the output file
  output = fopen("encrypted.txt", "w");
  if (output == NULL) {
    printf("Error opening file encrypted.txt\n");
    exit(1);
  }

  // Read a character from the input file
  while ((ch = fgetc(input)) != EOF) {
    // Encrypt the character
    ch += key;

    // Write the encrypted character to the output file
    fputc(ch, output);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);

  // Show a cool message!
  printf("File %s encrypted successfully! Prepare to witness the ancient, mystical encryption!", filename);
}

// Function to decrypt a file
void decryptFile(char* filename) {
  FILE *input, *output;
  char ch;
  int key = 13; // Change this to your desired key

  // Open the input file
  input = fopen(filename, "r");
  if (input == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  // Open the output file
  output = fopen("decrypted.txt", "w");
  if (output == NULL) {
    printf("Error opening file decrypted.txt\n");
    exit(1);
  }

  // Read a character from the input file
  while ((ch = fgetc(input)) != EOF) {
    // Decrypt the character
    ch -= key;

    // Write the decrypted character to the output file
    fputc(ch, output);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);

  // Show a cool message!
  printf("File %s decrypted successfully! You have conquered the enigmatic code!", filename);
}

// Main function
int main() {
  // Get the filename from the user
  char filename[100];
  printf("Enter the name of the file to encrypt: ");
  scanf("%s", filename);

  // Encrypt the file
  encryptFile(filename);

  // Decrypt the file
  decryptFile("encrypted.txt");

  return 0;
}