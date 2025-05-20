//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(const char *filename, const char *key);
void decrypt(const char *filename, const char *key);

/* program entry point */
int main(int argc, char **argv) {
  if (argc < 4) {
    printf("Usage: %s <encrypt/decrypt> <filename> <key>\n", argv[0]);
    exit(1);
  }
  if (strcmp(argv[1], "encrypt") == 0) {
    encrypt(argv[2], argv[3]);
  } else if (strcmp(argv[1], "decrypt") == 0) {
    decrypt(argv[2], argv[3]);
  } else {
    printf("Unknown command: %s\n", argv[1]);
    exit(1);
  }
  return 0;
}

/* encrypts the file with the given key and saves it as "filename.enc" */
void encrypt(const char *filename, const char *key) {
  FILE *file_in = fopen(filename, "rb");
  if (file_in == NULL) {
    printf("Failed to open file %s\n", filename);
    exit(1);
  }
  char *output_filename = malloc(strlen(filename) + 5);
  sprintf(output_filename, "%s.enc", filename);
  FILE *file_out = fopen(output_filename, "wb");
  if (file_out == NULL) {
    printf("Failed to create encrypted file %s\n", output_filename);
    exit(1);
  }
  int c;
  int i = 0;
  while ((c = fgetc(file_in)) != EOF) {
    c = c ^ key[i]; // exclusive or the character with the key character
    i++;
    i = i % strlen(key); // loop over the key if necessary
    fputc(c, file_out);
  }
  fclose(file_in);
  fclose(file_out);
}

/* decrypts the file with the given key and saves it as "filename.dec" */
void decrypt(const char *filename, const char *key) {
  FILE *file_in = fopen(filename, "rb");
  if (file_in == NULL) {
    printf("Failed to open file %s\n", filename);
    exit(1);
  }
  char *output_filename = malloc(strlen(filename) + 5);
  sprintf(output_filename, "%s.dec", filename);
  FILE *file_out = fopen(output_filename, "wb");
  if (file_out == NULL) {
    printf("Failed to create decrypted file %s\n", output_filename);
    exit(1);
  }
  int c;
  int i = 0;
  while ((c = fgetc(file_in)) != EOF) {
    c = c ^ key[i]; // exclusive or the character with the key character
    i++;
    i = i % strlen(key); // loop over the key if necessary
    fputc(c, file_out);
  }
  fclose(file_in);
  fclose(file_out);
}