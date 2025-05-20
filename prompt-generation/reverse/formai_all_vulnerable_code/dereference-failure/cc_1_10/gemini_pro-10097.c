//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024

unsigned char *file_buffer;
unsigned int file_size;

unsigned char virus_signature[] = {
  0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
  0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
  0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
  0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41
};
unsigned int virus_signature_length = sizeof(virus_signature);

int scan_file(char *filename) {
  FILE *file;
  int result;

  file = fopen(filename, "rb");
  if (file == NULL) {
    return -1;
  }

  fseek(file, 0, SEEK_END);
  file_size = ftell(file);
  if (file_size > MAX_FILE_SIZE) {
    fclose(file);
    return -1;
  }

  file_buffer = malloc(file_size);
  if (file_buffer == NULL) {
    fclose(file);
    return -1;
  }

  fseek(file, 0, SEEK_SET);
  result = fread(file_buffer, 1, file_size, file);
  fclose(file);

  if (result != file_size) {
    free(file_buffer);
    return -1;
  }

  for (unsigned int i = 0; i < file_size - virus_signature_length; i++) {
    if (memcmp(&file_buffer[i], virus_signature, virus_signature_length) == 0) {
      printf("Virus found at offset %u in file %s\n", i, filename);
      return 1;
    }
  }

  free(file_buffer);
  return 0;
}

int main(int argc, char **argv) {
  int result;

  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  result = scan_file(argv[1]);
  if (result == 1) {
    printf("File %s is infected\n", argv[1]);
  } else if (result == 0) {
    printf("File %s is clean\n", argv[1]);
  } else {
    printf("Error scanning file %s\n", argv[1]);
  }

  return 0;
}