//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* KEY = "secretkey12345";

void encrypt_file(char* filename) {
  // Open the input file
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error: failed to open input file.\n");
    return;
  }

  // Open the output file
  char outfilename[256];
  sprintf(outfilename, "%s.enc", filename);
  FILE* outfp = fopen(outfilename, "wb");
  if (outfp == NULL) {
    printf("Error: failed to open output file.\n");
    fclose(fp);
    return;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  long int filesize = ftell(fp);
  rewind(fp);

  // Encrypt and write the file
  char buffer[256];
  int keylen = strlen(KEY);
  int pos = 0;
  while (pos < filesize) {
    int readlen = fread(buffer, 1, 256, fp);
    for (int i = 0; i < readlen; i++) {
      buffer[i] ^= KEY[i % keylen];
    }
    fwrite(buffer, 1, readlen, outfp);
    pos += readlen;
  }

  fclose(fp);
  fclose(outfp);

  printf("Encryption complete: %s\n", outfilename);
}

void decrypt_file(char* filename) {
  // Open the input file
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error: failed to open input file.\n");
    return;
  }

  // Open the output file
  char outfilename[256];
  sprintf(outfilename, "%s.dec", filename);
  FILE* outfp = fopen(outfilename, "wb");
  if (outfp == NULL) {
    printf("Error: failed to open output file.\n");
    fclose(fp);
    return;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  long int filesize = ftell(fp);
  rewind(fp);

  // Decrypt and write the file
  char buffer[256];
  int keylen = strlen(KEY);
  int pos = 0;
  while (pos < filesize) {
    int readlen = fread(buffer, 1, 256, fp);
    for (int i = 0; i < readlen; i++) {
      buffer[i] ^= KEY[i % keylen];
    }
    fwrite(buffer, 1, readlen, outfp);
    pos += readlen;
  }

  fclose(fp);
  fclose(outfp);

  printf("Decryption complete: %s\n", outfilename);
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s <encrypt/decrypt> <filename>\n", argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "encrypt") == 0) {
    encrypt_file(argv[2]);
  }
  else if (strcmp(argv[1], "decrypt") == 0) {
    decrypt_file(argv[2]);
  }
  else {
    printf("Invalid command.\n");
    return 1;
  }

  return 0;
}