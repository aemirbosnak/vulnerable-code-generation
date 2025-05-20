//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
// Ada Lovelace inspired C Data Recovery Tool

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_file(const char *filename, char **buffer, size_t *size);
void write_file(const char *filename, char *buffer, size_t size);

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Usage: %s <source-file> <target-file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *source = argv[1];
  const char *target = argv[2];
  
  char *buffer;
  size_t size;

  read_file(source, &buffer, &size);

  // parse the data in the buffer and recover any lost data
  // ...

  write_file(target, buffer, size);

  printf("%s recovered and saved to %s successfully!\n", source, target);

  return 0;
}

void read_file(const char *filename, char **buffer, size_t *size) {
  FILE *fp = fopen(filename, "rb");

  if(!fp) {
    printf("Error: Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  // Allocate memory for buffer
  *buffer = (char*) malloc(BUFFER_SIZE);

  // Read file contents into buffer
  char tmp[BUFFER_SIZE];
  size_t n = 0;
  while ((n = fread(tmp, 1, BUFFER_SIZE, fp))) {
    if (n < BUFFER_SIZE)
      tmp[n] = '\0';
    *buffer = strcat(*buffer, tmp);
  }

  // Determine file size
  *size = ftell(fp);

  fclose(fp);
}

void write_file(const char *filename, char *buffer, size_t size) {
  FILE *fp = fopen(filename, "wb");

  if(!fp) {
    printf("Error: Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  // Write buffer to file
  fwrite(buffer, 1, size, fp);

  fclose(fp);
}