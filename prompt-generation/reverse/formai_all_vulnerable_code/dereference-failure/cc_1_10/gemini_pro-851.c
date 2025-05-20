//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
// In the desolate ruins of a forgotten world, amidst the echoes of a shattered civilization, a lone wanderer emerges from the shadows.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A cryptic cipher, born from the ashes of lost knowledge.
char *cipher = "XeXzXArX5jX$irXxwX$#wX%tX&!cX(X)sX$%r";

// A ritual to encode a relic of the past, a file.
int encryptFile(char *filePath) {
  FILE *file = fopen(filePath, "rb");
  if (!file) {
    printf("File not found or inaccessible. Check your path, wanderer.\n");
    return -1;
  }

  long fileSize;
  fseek(file, 0L, SEEK_END);
  fileSize = ftell(file);
  rewind(file);

  unsigned char *buffer = (unsigned char *)malloc(fileSize);
  if (!buffer) {
    printf("Memory allocation failed. The echoes of greatness are too heavy.\n");
    return -1;
  }

  size_t bytesRead = fread(buffer, 1, fileSize, file);
  if (bytesRead != fileSize) {
    printf("Could not read the file's contents. Seek shelter in a different location.\n");
    return -1;
  }
  fclose(file);

  srand(time(NULL));

  for (long i = 0; i < fileSize; i++) {
    int randomNumber = rand() % 48;
    int cipherChar = cipher[randomNumber];
    buffer[i] ^= cipherChar;
  }

  char *encryptedFileName = (char *)malloc(strlen(filePath) + 5);
  if (!encryptedFileName) {
    printf("Memory allocation failed. The whispers of lost knowledge are too deafening.\n");
    return -1;
  }

  sprintf(encryptedFileName, "%s.enc", filePath);

  FILE *encryptedFile = fopen(encryptedFileName, "wb");
  if (!encryptedFile) {
    printf("Could not create the encrypted file. The path is blocked by an unknown force.\n");
    return -1;
  }

  size_t bytesWritten = fwrite(buffer, 1, fileSize, encryptedFile);
  if (bytesWritten != fileSize) {
    printf("Could not write to the encrypted file. The portal is sealed.\n");
    return -1;
  }
  fclose(encryptedFile);

  printf("File encrypted and hidden among the ruins. May it guide you through the darkness.\n");

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filepath>\n", argv[0]);
    return 1;
  }

  char *filePath = argv[1];

  int result = encryptFile(filePath);
  if (result != 0) {
    printf("Encryption failed. The spirits of the old world are against us.\n");
    return 1;
  }

  return 0;
}