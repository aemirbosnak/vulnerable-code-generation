//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char filename[100];
  char password[100];
  int i, key;

  printf("Enter the name of the file to encrypt: ");
  scanf("%s", filename);
  printf("Enter the password: ");
  scanf("%s", password);

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  key = strlen(password);

  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *buffer = malloc(fsize + 1);
  if (buffer == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  fread(buffer, 1, fsize, fp);
  fclose(fp);

  for (i = 0; i < fsize; i++) {
    buffer[i] ^= password[i % key];
  }

  fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  fwrite(buffer, 1, fsize, fp);
  fclose(fp);

  free(buffer);

  printf("File encrypted successfully\n");

  return 0;
}