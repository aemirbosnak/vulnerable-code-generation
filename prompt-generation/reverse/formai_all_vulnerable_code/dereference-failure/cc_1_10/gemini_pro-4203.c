//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: decentralized
// Decentralized C File Encryptor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

// XOR encryption key
unsigned char key[] = {0x5a, 0xc3, 0x7b, 0x65, 0xa4, 0x5e, 0x01, 0x8a};

// Maximum key size
#define MAX_KEY_SIZE 8

// Encrypt a file
int encrypt_file(char *input_file, char *output_file) {
  // Open input and output files
  int input_fd = open(input_file, O_RDONLY);
  if (input_fd < 0) {
    perror("Failed to open input file");
    return -1;
  }

  int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (output_fd < 0) {
    perror("Failed to open output file");
    return -1;
  }

  // Get file size
  struct stat statbuf;
  if (fstat(input_fd, &statbuf) < 0) {
    perror("Failed to get file size");
    return -1;
  }

  // Allocate buffer
  char *buffer = malloc(statbuf.st_size);
  if (buffer == NULL) {
    perror("Failed to allocate buffer");
    return -1;
  }

  // Read file into buffer
  ssize_t bytes_read = read(input_fd, buffer, statbuf.st_size);
  if (bytes_read < 0) {
    perror("Failed to read file");
    return -1;
  }

  // Encrypt buffer
  for (size_t i = 0; i < statbuf.st_size; i++) {
    buffer[i] ^= key[i % MAX_KEY_SIZE];
  }

  // Write encrypted buffer to output file
  ssize_t bytes_written = write(output_fd, buffer, statbuf.st_size);
  if (bytes_written < 0) {
    perror("Failed to write encrypted file");
    return -1;
  }

  // Free buffer
  free(buffer);

  // Close files
  close(input_fd);
  close(output_fd);

  return 0;
}

// Decrypt a file
int decrypt_file(char *input_file, char *output_file) {
  // Open input and output files
  int input_fd = open(input_file, O_RDONLY);
  if (input_fd < 0) {
    perror("Failed to open input file");
    return -1;
  }

  int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (output_fd < 0) {
    perror("Failed to open output file");
    return -1;
  }

  // Get file size
  struct stat statbuf;
  if (fstat(input_fd, &statbuf) < 0) {
    perror("Failed to get file size");
    return -1;
  }

  // Allocate buffer
  char *buffer = malloc(statbuf.st_size);
  if (buffer == NULL) {
    perror("Failed to allocate buffer");
    return -1;
  }

  // Read file into buffer
  ssize_t bytes_read = read(input_fd, buffer, statbuf.st_size);
  if (bytes_read < 0) {
    perror("Failed to read file");
    return -1;
  }

  // Decrypt buffer
  for (size_t i = 0; i < statbuf.st_size; i++) {
    buffer[i] ^= key[i % MAX_KEY_SIZE];
  }

  // Write decrypted buffer to output file
  ssize_t bytes_written = write(output_fd, buffer, statbuf.st_size);
  if (bytes_written < 0) {
    perror("Failed to write decrypted file");
    return -1;
  }

  // Free buffer
  free(buffer);

  // Close files
  close(input_fd);
  close(output_fd);

  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if correct number of arguments
  if (argc != 4) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", argv[0]);
    return 1;
  }

  // Get operation
  char *operation = argv[1];

  // Get input file
  char *input_file = argv[2];

  // Get output file
  char *output_file = argv[3];

  // Perform operation
  int status;
  if (strcmp(operation, "encrypt") == 0) {
    status = encrypt_file(input_file, output_file);
  } else if (strcmp(operation, "decrypt") == 0) {
    status = decrypt_file(input_file, output_file);
  } else {
    printf("Invalid operation: %s\n", operation);
    return 1;
  }

  // Check if operation was successful
  if (status < 0) {
    return 1;
  }

  return 0;
}