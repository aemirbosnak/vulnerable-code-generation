//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random key
int generateKey() {
  srand(time(NULL));
  return rand() % 256;
}

// Encrypt a file using the given key
void encryptFile(const char *fileName, int key) {
  FILE *inputFile = fopen(fileName, "rb");
  if (inputFile == NULL) {
    printf("Error: Could not open input file %s\n", fileName);
    return;
  }

  FILE *outputFile = fopen("encrypted.bin", "wb");
  if (outputFile == NULL) {
    printf("Error: Could not open output file encrypted.bin\n");
    return;
  }

  int ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    fputc(ch ^ key, outputFile);
  }

  fclose(inputFile);
  fclose(outputFile);

  printf("File %s encrypted successfully!\n", fileName);
}

// Decrypt a file using the given key
void decryptFile(const char *fileName, int key) {
  FILE *inputFile = fopen(fileName, "rb");
  if (inputFile == NULL) {
    printf("Error: Could not open input file %s\n", fileName);
    return;
  }

  FILE *outputFile = fopen("decrypted.bin", "wb");
  if (outputFile == NULL) {
    printf("Error: Could not open output file decrypted.bin\n");
    return;
  }

  int ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    fputc(ch ^ key, outputFile);
  }

  fclose(inputFile);
  fclose(outputFile);

  printf("File %s decrypted successfully!\n", fileName);
}

int main() {
  int key = generateKey();

  printf("Yay! I'm so happy to help you encrypt and decrypt your files! Let's get started!\n");

  char fileName[256];
  printf("What's the name of the file you want to encrypt or decrypt? ");
  scanf("%s", fileName);

  int choice;
  printf("Do you want to encrypt (1) or decrypt (2) the file? ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      encryptFile(fileName, key);
      break;
    case 2:
      decryptFile(fileName, key);
      break;
    default:
      printf("Invalid choice. Please enter 1 to encrypt or 2 to decrypt.\n");
  }

  printf("Hooray! Your file has been encrypted or decrypted successfully! I'm proud of you!\n");

  return 0;
}