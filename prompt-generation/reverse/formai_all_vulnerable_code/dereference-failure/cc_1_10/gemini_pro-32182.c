//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Declarations
typedef unsigned char Byte;
const char *PASSPHRASE = "OpenSesame"; // Change me!

// Encrypt a single byte
Byte encryptByte(Byte b, Byte key) {
  return b ^ key;
}

// Encrypt an entire file
int encryptFile(char *filename) {
  FILE *fIn = fopen(filename, "rb");
  FILE *fOut = fopen("encrypted.bin", "wb");
  if (!fIn || !fOut) return -1;

  // Get file size
  fseek(fIn, 0, SEEK_END);
  long fileSize = ftell(fIn);
  rewind(fIn);

  // Read the file into memory
  Byte *buffer = malloc(fileSize);
  fread(buffer, 1, fileSize, fIn);
  fclose(fIn);

  // Encrypt the file
  int i;
  for (i = 0; i < fileSize; i++) {
    buffer[i] = encryptByte(buffer[i], PASSPHRASE[i % strlen(PASSPHRASE)]);
  }

  // Write the encrypted file to disk
  fwrite(buffer, 1, fileSize, fOut);
  fclose(fOut);

  free(buffer);
  return 0;
}

// Main function
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  // Encrypt the file
  if (encryptFile(argv[1]) == 0) {
    printf("File encrypted successfully.\n");
  } else {
    printf("Error encrypting file.\n");
  }

  return 0;
}