//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT_KEY 0x7f

void encrypt_file(char *filename) {
  FILE *fp = fopen(filename, "rb+");
  if (!fp) {
    perror("Error opening file");
    return;
  }

  fseek(fp, 0, SEEK_END);
  long filesize = ftell(fp);
  rewind(fp);

  unsigned char *buffer = malloc(filesize);
  fread(buffer, filesize, 1, fp);

  for (long i = 0; i < filesize; i++) {
    buffer[i] ^= ENCRYPT_KEY;
  }

  fseek(fp, 0, SEEK_SET);
  fwrite(buffer, filesize, 1, fp);

  free(buffer);
  fclose(fp);
}

void decrypt_file(char *filename) {
  FILE *fp = fopen(filename, "rb+");
  if (!fp) {
    perror("Error opening file");
    return;
  }

  fseek(fp, 0, SEEK_END);
  long filesize = ftell(fp);
  rewind(fp);

  unsigned char *buffer = malloc(filesize);
  fread(buffer, filesize, 1, fp);

  for (long i = 0; i < filesize; i++) {
    buffer[i] ^= ENCRYPT_KEY;
  }

  fseek(fp, 0, SEEK_SET);
  fwrite(buffer, filesize, 1, fp);

  free(buffer);
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s [encrypt|decrypt] [filename] [key]\n", argv[0]);
    return 1;
  }

  char *action = argv[1];
  char *filename = argv[2];
  char *key = argv[3];

  if (strcmp(action, "encrypt") == 0) {
    encrypt_file(filename);
  } else if (strcmp(action, "decrypt") == 0) {
    decrypt_file(filename);
  } else {
    printf("Invalid action: %s\n", action);
    return 1;
  }

  printf("%s file successfully.\n", action);
  return 0;
}