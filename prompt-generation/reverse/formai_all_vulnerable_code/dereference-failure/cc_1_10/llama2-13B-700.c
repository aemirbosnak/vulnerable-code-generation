//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LINE_LEN 1024
#define MAX_BUF_SIZE 4096

int main(void) {
  char line[MAX_LINE_LEN];
  char *buf = NULL;
  size_t len = 0;
  off_t pos = 0;

  // Open the input file
  FILE *fin = fopen("input.txt", "r");
  if (fin == NULL) {
    perror("Error opening input file");
    return 1;
  }

  // Create a memory-mapped file
  int fd = open("output.txt", O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    perror("Error creating output file");
    return 1;
  }

  // Mmap the input file
  buf = mmap(NULL, MAX_BUF_SIZE, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
  if (buf == MAP_FAILED) {
    perror("Error mmapping input file");
    return 1;
  }

  // Loop through the input file
  while (fgets(line, MAX_LINE_LEN, fin) != NULL) {
    // Check if the line is too long
    if (strlen(line) > MAX_LINE_LEN) {
      printf("Line too long, truncating...\n");
      break;
    }

    // Calculate the position of the next line
    pos = ftell(fin);

    // Write the line to the memory-mapped file
    if (write(fd, line, strlen(line)) < 0) {
      perror("Error writing to output file");
      return 1;
    }

    // Advance the position to the next line
    pos += strlen(line) + 1;
  }

  // Unmap the input file
  munmap(buf, MAX_BUF_SIZE);

  // Close the input and output files
  fclose(fin);
  close(fd);

  // Print the success message
  printf("Done! Output written to output.txt\n");

  return 0;
}