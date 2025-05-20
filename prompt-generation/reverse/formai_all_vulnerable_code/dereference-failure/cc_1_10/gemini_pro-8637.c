//GEMINI-pro DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new file
FILE *create_file(char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error creating file");
    return NULL;
  }
  return fp;
}

// Function to write data to a file
void write_data_to_file(FILE *fp, char *data) {
  if (fputs(data, fp) == EOF) {
    perror("Error writing to file");
  }
}

// Function to read data from a file
char *read_data_from_file(FILE *fp) {
  char *data;
  long file_size;
  fseek(fp, 0, SEEK_END);
  file_size = ftell(fp);
  rewind(fp);
  data = malloc(file_size + 1);
  if (data == NULL) {
    perror("Error allocating memory");
    return NULL;
  }
  fread(data, 1, file_size, fp);
  data[file_size] = '\0';
  return data;
}

// Function to close a file
void close_file(FILE *fp) {
  fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
  FILE *fp;
  char *data;

  // Check if the user specified a filename
  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 1;
  }

  // Create the file
  fp = create_file(argv[1]);
  if (fp == NULL) {
    return 1;
  }

  // Write data to the file
  write_data_to_file(fp, "Hello, world!\n");

  // Read data from the file
  data = read_data_from_file(fp);
  if (data == NULL) {
    return 1;
  }

  // Print the data to the console
  printf("%s", data);

  // Close the file
  close_file(fp);

  return 0;
}