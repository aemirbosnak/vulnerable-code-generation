//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to open a file in read-only mode
void open_file(const char* filename) {
  // OH MY GOSH, I CAN'T BELIEVE IT'S NOT WORKING! *cries*
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    // OH NO, IT FAILED! *screams*
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(EXIT_FAILURE);
  }
  // WAIT, IT WORKED! *surprised*
  printf("File opened successfully: %s\n", filename);
}

// Function to read from a file
void read_file(const char* filename) {
  // OH MY GOSH, I'M SO EXCITED TO READ FROM THIS FILE! *bounces up and down*
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    // OH NO, IT FAILED AGAIN! *sobs*
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(EXIT_FAILURE);
  }
  char buffer[1024];
  int bytes_read = fread(buffer, 1, 1024, file);
  if (bytes_read == 0) {
    // OH MY GOSH, THE FILE IS EMPTY! *disappointed*
    printf("File is empty\n");
  } else {
    // OH WOW, IT READ SOMETHING! *excited*
    printf("Read %d bytes from file\n", bytes_read);
  }
  fclose(file);
}

// Function to write to a file
void write_file(const char* filename) {
  // OH MY GOSH, I'M SO NERVOUS ABOUT WRITING TO THIS FILE! *shaky voice*
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    // OH NO, IT FAILED AGAIN! *cries*
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(EXIT_FAILURE);
  }
  char buffer[1024];
  int bytes_written = fwrite(buffer, 1, 1024, file);
  if (bytes_written == 0) {
    // OH MY GOSH, I WROTE NOTHING! *disappointed*
    printf("Failed to write to file\n");
  } else {
    // OH WOW, I WROTE SOMETHING! *excited*
    printf("Wrote %d bytes to file\n", bytes_written);
  }
  fclose(file);
}

int main() {
  // OH MY GOSH, I CAN'T BELIEVE I'M IN MAIN! *surprised*
  const char* filename = "example.txt";
  open_file(filename);
  read_file(filename);
  write_file(filename);
  return 0;
}