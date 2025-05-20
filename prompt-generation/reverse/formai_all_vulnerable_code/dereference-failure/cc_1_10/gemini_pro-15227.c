//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A brush to dip in the colors of the plaintext
char* read_plaintext(char *pathname) {
  FILE *file;
  char *plaintext;
  long length;
  // Opening the canvas of words
  file = fopen(pathname, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  // Measuring the canvas
  fseek(file, 0, SEEK_END);
  length = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Allocating space for the masterpiece
  plaintext = malloc(length + 1);
  if (plaintext == NULL) {
    perror("Error allocating memory");
    exit(EXIT_FAILURE);
  }
  // Capturing the beauty of the plaintext
  fread(plaintext, 1, length, file);
  fclose(file);
  plaintext[length] = '\0';
  return plaintext;
}

// A palette to mix the colors of the key
char* read_key(char *pathname) {
  FILE *file;
  char *key;
  long length;
  // Opening the box of secrets
  file = fopen(pathname, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  // Measuring the secrets
  fseek(file, 0, SEEK_END);
  length = ftell(file);
  fseek(file, 0, SEEK_SET);
  // Allocating space for the magic
  key = malloc(length + 1);
  if (key == NULL) {
    perror("Error allocating memory");
    exit(EXIT_FAILURE);
  }
  // Unlocking the mysteries
  fread(key, 1, length, file);
  fclose(file);
  key[length] = '\0';
  return key;
}

// An easel to hold the canvas and the palette
struct cipher {
  char *plaintext;
  char *key;
  long length;
};

// A maestro to conduct the symphony of encryption
char* encrypt(struct cipher *c) {
  char *ciphertext;
  long i;
  // Allocating space for the encrypted masterpiece
  ciphertext = malloc(c->length + 1);
  if (ciphertext == NULL) {
    perror("Error allocating memory");
    exit(EXIT_FAILURE);
  }
  // Dipping the brush in the colors of the key
  for (i = 0; i < c->length; i++) {
    // Mixing the colors of the plaintext and the key
    ciphertext[i] = c->plaintext[i] ^ c->key[i % strlen(c->key)];
  }
  ciphertext[c->length] = '\0';
  return ciphertext;
}

// A frame to display the encrypted masterpiece
void print_ciphertext(char *ciphertext) {
  printf("%s\n", ciphertext);
}

// The main stage where the magic happens
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s plaintext_file key_file\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  // Reading the canvas and the palette
  struct cipher c = {
    .plaintext = read_plaintext(argv[1]),
    .key = read_key(argv[2]),
    .length = strlen(c.plaintext)
  };
  // Encrypting the masterpiece
  char *ciphertext = encrypt(&c);
  // Displaying the encrypted masterpiece
  print_ciphertext(ciphertext);
  // Releasing the memory
  free(c.plaintext);
  free(c.key);
  free(ciphertext);
  return EXIT_SUCCESS;
}