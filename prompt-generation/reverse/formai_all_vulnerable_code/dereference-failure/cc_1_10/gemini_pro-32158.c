//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BLOCK_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input_file> <output_file> <password>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *input_file = argv[1];
  const char *output_file = argv[2];
  const char *password = argv[3];

  // Read the input file
  struct stat statbuf;
  if (stat(input_file, &statbuf) != 0) {
    perror("stat");
    return EXIT_FAILURE;
  }

  char *input_buffer = malloc(statbuf.st_size);
  if (input_buffer == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  int input_fd = open(input_file, O_RDONLY);
  if (input_fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  if (read(input_fd, input_buffer, statbuf.st_size) != statbuf.st_size) {
    perror("read");
    return EXIT_FAILURE;
  }

  close(input_fd);

  // Encrypt the input buffer
  char *encrypted_buffer = malloc(statbuf.st_size);
  if (encrypted_buffer == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  int password_length = strlen(password);
  int encrypted_buffer_index = 0;
  for (int i = 0; i < statbuf.st_size; i++) {
    encrypted_buffer[encrypted_buffer_index] = input_buffer[i] ^ password[i % password_length];
    encrypted_buffer_index++;
  }

  free(input_buffer);

  // Write the encrypted buffer to the output file
  int output_fd = open(output_file, O_WRONLY | O_CREAT, 0644);
  if (output_fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  if (write(output_fd, encrypted_buffer, statbuf.st_size) != statbuf.st_size) {
    perror("write");
    return EXIT_FAILURE;
  }

  close(output_fd);

  free(encrypted_buffer);

  return EXIT_SUCCESS;
}