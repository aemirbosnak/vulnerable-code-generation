//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines a custom XOR encryption function
unsigned char encrypt(unsigned char plaintext, unsigned char key) {
  return plaintext ^ key;
}

// Performs file encryption
void encryptFile(char *inputFile, char *outputFile, unsigned char key) {
  // Open the input file
  FILE *input = fopen(inputFile, "rb");
  if (input == NULL) {
    printf("Error opening input file %s\n", inputFile);
    exit(1);
  }

  // Create the output file
  FILE *output = fopen(outputFile, "wb");
  if (output == NULL) {
    printf("Error opening output file %s\n", outputFile);
    exit(1);
  }

  // Read and encrypt the file contents
  char buffer[256];
  while (fread(buffer, sizeof(char), 256, input) > 0) {
    for (int i = 0; i < 256; i++) {
      buffer[i] = encrypt(buffer[i], key);
    }
    fwrite(buffer, sizeof(char), 256, output);
  }

  // Close the files
  fclose(input);
  fclose(output);

  printf("File %s encrypted successfully using key %d\n", inputFile, key);
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s input-file output-file encryption-key\n", argv[0]);
    return 1;
  }

  char *inputFile = argv[1];
  char *outputFile = argv[2];
  unsigned char key = atoi(argv[3]);

  encryptFile(inputFile, outputFile, key);

  return 0;
}