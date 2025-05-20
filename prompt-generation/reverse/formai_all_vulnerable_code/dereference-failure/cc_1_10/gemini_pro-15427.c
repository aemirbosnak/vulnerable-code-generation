//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
unsigned char generate_key() {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate a random key between 0 and 255
  return rand() % 256;
}

// Function to encrypt a file
void encrypt_file(FILE *input_file, FILE *output_file, unsigned char key) {
  // Read the input file byte by byte
  int ch;
  while ((ch = fgetc(input_file)) != EOF) {
    // XOR the byte with the key
    ch ^= key;

    // Write the encrypted byte to the output file
    fputc(ch, output_file);
  }
}

// Function to decrypt a file
void decrypt_file(FILE *input_file, FILE *output_file, unsigned char key) {
  // Read the input file byte by byte
  int ch;
  while ((ch = fgetc(input_file)) != EOF) {
    // XOR the byte with the key
    ch ^= key;

    // Write the decrypted byte to the output file
    fputc(ch, output_file);
  }
}

int main() {
  // Get the input and output file names from the user
  char input_file_name[256];
  char output_file_name[256];
  printf("Enter the name of the input file: ");
  scanf("%s", input_file_name);
  printf("Enter the name of the output file: ");
  scanf("%s", output_file_name);

  // Open the input and output files
  FILE *input_file = fopen(input_file_name, "rb");
  if (input_file == NULL) {
    printf("Error: Could not open input file %s\n", input_file_name);
    return 1;
  }
  FILE *output_file = fopen(output_file_name, "wb");
  if (output_file == NULL) {
    printf("Error: Could not open output file %s\n", output_file_name);
    return 1;
  }

  // Generate a random key
  unsigned char key = generate_key();

  // Encrypt the input file
  encrypt_file(input_file, output_file, key);

  // Close the input and output files
  fclose(input_file);
  fclose(output_file);

  printf("File encrypted successfully!\n");

  return 0;
}