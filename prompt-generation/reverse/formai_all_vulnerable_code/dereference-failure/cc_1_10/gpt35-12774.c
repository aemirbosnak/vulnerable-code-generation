//FormAI DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char file[100];
  printf("Welcome to the C File Encryptor Program!\n");
  printf("Please enter the name of the file you wish to encrypt: ");
  scanf("%s", file);

  // Open the file and check if it exists
  FILE* fp;
  fp = fopen(file, "r");
  if(fp == NULL) {
    printf("Error: %s file does not exist.", file);
    return 1;
  }

  // Get the file size
  fseek(fp, 0L, SEEK_END);
  int size = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  // Allocate memory to store the file data
  char* data = (char*) malloc(size + 1);

  // Read file data into memory
  fread(data, size, 1, fp);
  fclose(fp);

  // Get user password for encryption
  char password[100];
  printf("Please enter a password to encrypt the file: ");
  scanf("%s", password);

  // Encrpyt file data with XOR
  int passwordLength = strlen(password);
  for(int i = 0; i < size; i++) {
    data[i] = data[i] ^ password[i % passwordLength];
  }

  // Write encrypted data back to the file
  fp = fopen(file, "w");
  fwrite(data, size, 1, fp);
  fclose(fp);
  free(data);

  printf("Congratulations! The file \"%s\" has been successfully encrypted with the password \"%s\".\n", file, password);
  return 0;
}