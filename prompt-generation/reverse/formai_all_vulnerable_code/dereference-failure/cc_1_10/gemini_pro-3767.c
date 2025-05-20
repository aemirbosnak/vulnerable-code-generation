//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// The secret key (should be a large random number)
#define SECRET_KEY 0x123456789ABCDEF0

// Encrypts the given file using the secret key
void encrypt_file(char *filename) {
  // Open the file for reading and writing
  FILE *file = fopen(filename, "rb+");
  if (file == NULL) {
    perror("fopen");
    exit(1);
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  // Allocate a buffer to hold the encrypted data
  char *encrypted_data = malloc(file_size);
  if (encrypted_data == NULL) {
    perror("malloc");
    exit(1);
  }

  // Encrypt the data
  for (long i = 0; i < file_size; i++) {
    // Read the next byte from the file
    unsigned char byte;
    fread(&byte, 1, 1, file);

    // Encrypt the byte using the secret key
    byte ^= SECRET_KEY;

    // Store the encrypted byte in the buffer
    encrypted_data[i] = byte;
  }

  // Seek to the beginning of the file
  rewind(file);

  // Write the encrypted data to the file
  fwrite(encrypted_data, 1, file_size, file);

  // Close the file
  fclose(file);

  // Free the buffer
  free(encrypted_data);

  // Print a success message
  printf("File encrypted successfully!\n");
}

// Decrypts the given file using the secret key
void decrypt_file(char *filename) {
  // Open the file for reading and writing
  FILE *file = fopen(filename, "rb+");
  if (file == NULL) {
    perror("fopen");
    exit(1);
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  // Allocate a buffer to hold the decrypted data
  char *decrypted_data = malloc(file_size);
  if (decrypted_data == NULL) {
    perror("malloc");
    exit(1);
  }

  // Decrypt the data
  for (long i = 0; i < file_size; i++) {
    // Read the next byte from the file
    unsigned char byte;
    fread(&byte, 1, 1, file);

    // Decrypt the byte using the secret key
    byte ^= SECRET_KEY;

    // Store the decrypted byte in the buffer
    decrypted_data[i] = byte;
  }

  // Seek to the beginning of the file
  rewind(file);

  // Write the decrypted data to the file
  fwrite(decrypted_data, 1, file_size, file);

  // Close the file
  fclose(file);

  // Free the buffer
  free(decrypted_data);

  // Print a success message
  printf("File decrypted successfully!\n");
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s encrypt|decrypt filename\n", argv[0]);
    return 1;
  }

  char *command = argv[1];
  char *filename = argv[2];

  if (strcmp(command, "encrypt") == 0) {
    encrypt_file(filename);
  } else if (strcmp(command, "decrypt") == 0) {
    decrypt_file(filename);
  } else {
    printf("Invalid command: %s\n", command);
    return 1;
  }

  return 0;
}