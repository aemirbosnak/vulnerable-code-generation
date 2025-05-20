//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover data from a file
int recover_data(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);

  // Allocate a buffer to store the file data
  char *buffer = malloc(file_size);
  if (buffer == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return -1;
  }

  // Read the file data into the buffer
  if (fread(buffer, file_size, 1, fp) != 1) {
    perror("Error reading file");
    free(buffer);
    fclose(fp);
    return -1;
  }

  // Close the file
  fclose(fp);

  // Search for the end of the file signature
  char *eof_signature = strstr(buffer, "EOF");
  if (eof_signature == NULL) {
    printf("Error finding end of file signature\n");
    free(buffer);
    return -1;
  }

  // Get the length of the data to recover
  int data_length = eof_signature - buffer;

  // Allocate a buffer to store the recovered data
  char *recovered_data = malloc(data_length);
  if (recovered_data == NULL) {
    perror("Error allocating memory");
    free(buffer);
    return -1;
  }

  // Copy the recovered data into the buffer
  memcpy(recovered_data, buffer, data_length);

  // Write the recovered data to a new file
  fp = fopen("recovered_data.txt", "wb");
  if (fp == NULL) {
    perror("Error opening file");
    free(buffer);
    free(recovered_data);
    return -1;
  }

  if (fwrite(recovered_data, data_length, 1, fp) != 1) {
    perror("Error writing file");
    free(buffer);
    free(recovered_data);
    fclose(fp);
    return -1;
  }

  // Close the file
  fclose(fp);

  // Free the buffers
  free(buffer);
  free(recovered_data);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  if (recover_data(argv[1]) != 0) {
    return -1;
  }

  return 0;
}