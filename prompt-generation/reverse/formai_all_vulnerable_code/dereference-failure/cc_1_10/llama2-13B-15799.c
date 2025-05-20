//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16
#define IV_SIZE 16

// Define the key and IV
const char *key = "0123456789abcdef";
const char *iv = "0123456789abcdef";

// Define the message to be encrypted
const char *message = "My dearest, my heart beats for thee";

// Define the file to be written
const char *file_name = "love_letter.enc";

int main() {
  // Create the file
  int fd = open(file_name, O_RDWR | O_CREAT, 0600);
  if (fd == -1) {
    perror("Error creating file");
    return 1;
  }

  // Set the file's size
  struct stat stat_info;
  fstat(fd, &stat_info);
  size_t file_size = stat_info.st_size;

  // Set up the memory mapping
  char *mapping = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
  if (mapping == MAP_FAILED) {
    perror("Error mapping file");
    close(fd);
    return 1;
  }

  // Encrypt the message
  for (size_t i = 0; i < strlen(message); i++) {
    char c = message[i];
    // XOR the plaintext with the key
    c = (c ^ key[i % KEY_SIZE]);
    // XOR the plaintext with the IV
    c = (c ^ iv[i % IV_SIZE]);
    // Write the ciphertext to the file
    mapping[i] = c;
  }

  // Unmap the file
  munmap(mapping, file_size);

  // Close the file
  close(fd);

  // Print the encrypted message
  printf("Encrypted message: %s\n", mapping);

  return 0;
}