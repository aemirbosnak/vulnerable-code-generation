//FormAI DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 100000 // Maximum file size to encrypt

void encrypt_file(char *file_name);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: %s <file name>\n", argv[0]);
    exit(1);
  }

  encrypt_file(argv[1]);

  return 0;
}

void encrypt_file(char *file_name) {
  FILE *file, *encrypted_file;
  char ch, encrypted_ch;
  int i = 0;

  file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error: Unable to open file %s\n", file_name);
    exit(1);
  }

  // Create encrypted file
  encrypted_file = fopen("encrypted_file.txt", "w");
  if (encrypted_file == NULL) {
    printf("Error: Unable to open file encrypted_file.txt\n");
    exit(1);
  }

  while ((ch = fgetc(file)) != EOF && i < MAX_FILE_SIZE) {
    // Encrypt character
    encrypted_ch = ch + 5;

    // Write encrypted character to file
    fputc(encrypted_ch, encrypted_file);

    i++;
  }

  fclose(file);
  fclose(encrypted_file);

  printf("File %s encrypted successfully!\n", file_name);
}