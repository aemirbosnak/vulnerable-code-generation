//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption function
char encrypt(char c, int key) {
  return c + key;
}

// Custom decryption function
char decrypt(char c, int key) {
  return c - key;
}

// Encrypts the given file and saves it to the output file
void encrypt_file(char* input_file, char* output_file, int key) {
  // Open the input and output files
  FILE* in = fopen(input_file, "r");
  FILE* out = fopen(output_file, "w");
  
  // Check if the files were opened successfully
  if (in == NULL || out == NULL) {
    printf("Error opening files!\n");
    exit(1);
  }
  
  // Read the input file character by character
  char c;
  while ((c = fgetc(in)) != EOF) {
    // Encrypt the character and write it to the output file
    putc(encrypt(c, key), out);
  }
  
  // Close the input and output files
  fclose(in);
  fclose(out);
  
  // Notify the user that the file has been encrypted
  printf("File encrypted successfully!\n");
}

// Decrypts the given file and saves it to the output file
void decrypt_file(char* input_file, char* output_file, int key) {
  // Open the input and output files
  FILE* in = fopen(input_file, "r");
  FILE* out = fopen(output_file, "w");
  
  // Check if the files were opened successfully
  if (in == NULL || out == NULL) {
    printf("Error opening files!\n");
    exit(1);
  }
  
  // Read the input file character by character
  char c;
  while ((c = fgetc(in)) != EOF) {
    // Decrypt the character and write it to the output file
    putc(decrypt(c, key), out);
  }
  
  // Close the input and output files
  fclose(in);
  fclose(out);
  
  // Notify the user that the file has been decrypted
  printf("File decrypted successfully!\n");
}

int main() {
  // Get the input file name, output file name, and encryption key from the user
  char input_file[50], output_file[50];
  int key;
  printf("Enter input file name: ");
  scanf("%s", input_file);
  printf("Enter output file name: ");
  scanf("%s", output_file);
  printf("Enter encryption key (0-255): ");
  scanf("%d", &key);
  
  // Encrypt the file using the given encryption key
  encrypt_file(input_file, output_file, key);
  
  // Decrypt the encrypted file using the same encryption key
  decrypt_file(output_file, strcat(output_file, ".dec"), key);
  
  return 0;
}