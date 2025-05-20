//FormAI DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *file_name, char *key) {
  FILE *fp = fopen(file_name, "rb+");
  char ch;
  int i = 0;

  if(fp == NULL) {
    printf("Error: Cannot open file %s\n", file_name);
    exit(1);
  }

  while((ch = fgetc(fp)) != EOF) {
    fseek(fp, i, SEEK_SET);
    fputc(ch ^ key[i % strlen(key)], fp);
    i++;
  }

  fclose(fp);
  printf("Successfully encrypted file %s using key %s\n", file_name, key);
}

void decrypt(char *file_name, char *key) {
  FILE *fp = fopen(file_name, "rb+");
  char ch;
  int i = 0;

  if(fp == NULL) {
    printf("Error: Cannot open file %s\n", file_name);
    exit(1);
  }

  while((ch = fgetc(fp)) != EOF) {
    fseek(fp, i, SEEK_SET);
    fputc(ch ^ key[i % strlen(key)], fp);
    i++;
  }

  fclose(fp);
  printf("Successfully decrypted file %s using key %s\n", file_name, key);
}

int main(int argc, char *argv[]) {
  char *file_name, *key, *mode;

  if(argc != 4) {
    printf("Usage: encyptor <file> <key> <mode>\n");
    printf("Modes: 'e' for encryption, 'd' for decryption\n");
    exit(1);
  }

  file_name = argv[1];
  key = argv[2];
  mode = argv[3];

  if(strlen(key) < 8) {
    printf("Error: Key must be at least 8 characters long\n");
    exit(1);
  }

  if(strcmp(mode, "e") == 0) {
    encrypt(file_name, key);
  } else if(strcmp(mode, "d") == 0) {
    decrypt(file_name, key);
  } else {
    printf("Error: Invalid mode\n");
    exit(1);
  }

  return 0;
}