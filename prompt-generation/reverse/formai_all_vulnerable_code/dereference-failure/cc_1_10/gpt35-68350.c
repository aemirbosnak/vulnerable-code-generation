//FormAI DATASET v1.0 Category: File Encyptor ; Style: imaginative
/*
  This is a C file encryptor program that uses the XOR encryption algorithm.
  The program takes a file path as input and encrypts the file by XOR-ing each byte with a secret key.
  The encrypted file is written to a new file with a ".encrypted" extension.
  The program also provides an option to decrypt an already encrypted file back to its original form.
  Author: Chatbot
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY 0x0F // Secret key used for encryption

void encryptFile(char *inputFilePath);
void decryptFile(char *inputFilePath);

int main(int argc, char **argv) {
  if(argc < 3) {
    printf("Usage: %s [encrypt|decrypt] [file_path]\n", argv[0]);
    exit(1);
  }

  if(strcmp(argv[1], "encrypt") == 0) {
    encryptFile(argv[2]);
    printf("File encrypted successfully!\n");
  } else if(strcmp(argv[1], "decrypt") == 0) {
    decryptFile(argv[2]);
    printf("File decrypted successfully!\n");
  } else {
    printf("Invalid operation! Please use 'encrypt' or 'decrypt'.\n");
    exit(1);
  }

  return 0;
}

void encryptFile(char *inputFilePath) {
  FILE *inputFile, *outputFile;
  char outputFilePath[100];
  int byte, i = 0;

  // Open the input file
  inputFile = fopen(inputFilePath, "rb");
  if(inputFile == NULL) {
    printf("Error: Unable to open input file %s\n", inputFilePath);
    exit(1);
  }

  // Create the output file with ".encrypted" extension
  strcpy(outputFilePath, inputFilePath);
  strcat(outputFilePath, ".encrypted");
  outputFile = fopen(outputFilePath, "wb");
  if(outputFile == NULL) {
    printf("Error: Unable to create output file %s\n", outputFilePath);
    exit(1);
  }

  // Encrypt each byte of the file and write to output file
  while((byte = fgetc(inputFile)) != EOF) {
    byte ^= ENCRYPTION_KEY; // XOR the byte with the secret key
    fputc(byte, outputFile);
    i++;
  }

  printf("Encrypted %d bytes of data from file %s\n", i, inputFilePath);

  // Close file pointers
  fclose(inputFile);
  fclose(outputFile);
}

void decryptFile(char *inputFilePath) {
  FILE *inputFile, *outputFile;
  char outputFilePath[100];
  int byte, i = 0;

  // Open the input file
  inputFile = fopen(inputFilePath, "rb");
  if(inputFile == NULL) {
    printf("Error: Unable to open input file %s\n", inputFilePath);
    exit(1);
  }

  // Create the output file by removing the ".encrypted" extension from input filename
  strcpy(outputFilePath, inputFilePath);
  int inputFilePathLen = strlen(inputFilePath);
  if(strcmp(outputFilePath + inputFilePathLen - 10, ".encrypted") == 0) {
    outputFilePath[inputFilePathLen - 10] = '\0';
  }
  outputFile = fopen(outputFilePath, "wb");
  if(outputFile == NULL) {
    printf("Error: Unable to create output file %s\n", outputFilePath);
    exit(1);
  }

  // Decrypt each byte of the file and write to output file
  while((byte = fgetc(inputFile)) != EOF) {
    byte ^= ENCRYPTION_KEY; // XOR the byte with the secret key
    fputc(byte, outputFile);
    i++;
  }

  printf("Decrypted %d bytes of data from file %s\n", i, inputFilePath);

  // Close file pointers
  fclose(inputFile);
  fclose(outputFile);
}