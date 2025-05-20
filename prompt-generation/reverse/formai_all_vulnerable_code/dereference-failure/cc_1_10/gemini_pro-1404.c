//GEMINI-pro DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the input file in read-only mode
  int fd_in = open(argv[1], O_RDONLY);
  if (fd_in == -1) {
    fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Check if the output file exists
  struct stat st;
  if (stat(argv[2], &st) == 0) {
    // Output file exists, prompt for confirmation before overwriting
    printf("Output file already exists. Overwrite? (y/n) ");
    char input[2];
    fgets(input, sizeof(input), stdin);
    if (strcmp(input, "y\n") != 0) {
      printf("Aborting...\n");
      close(fd_in);
      return EXIT_SUCCESS;
    }
  }

  // Open the output file in write-only mode, truncating any existing content
  int fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd_out == -1) {
    fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
    close(fd_in);
    return EXIT_FAILURE;
  }

  // Allocate a buffer for the data
  char buffer[BUFSIZ];
  ssize_t bytes_read;

  // Read from the input file and write to the output file until EOF
  while ((bytes_read = read(fd_in, buffer, BUFSIZ)) > 0) {
    // Write to the output file
    if (write(fd_out, buffer, bytes_read) == -1) {
      fprintf(stderr, "Error writing to output file: %s\n", strerror(errno));
      close(fd_in);
      close(fd_out);
      return EXIT_FAILURE;
    }
  }

  // Check for errors during read
  if (bytes_read == -1) {
    fprintf(stderr, "Error reading from input file: %s\n", strerror(errno));
    close(fd_in);
    close(fd_out);
    return EXIT_FAILURE;
  }

  // Close the files
  close(fd_in);
  close(fd_out);

  return EXIT_SUCCESS;
}