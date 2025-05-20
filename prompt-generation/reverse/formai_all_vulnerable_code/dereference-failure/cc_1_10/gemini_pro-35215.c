//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = malloc(file_size);
  if (buffer == NULL) {
    perror("malloc");
    fclose(file);
    return EXIT_FAILURE;
  }

  fread(buffer, 1, file_size, file);
  fclose(file);

  // Search for the file header
  char *header = "FLV";
  char *found = strstr(buffer, header);
  if (found == NULL) {
    printf("File is not a valid FLV file.\n");
    free(buffer);
    return EXIT_FAILURE;
  }

  // Get the file size from the header
  long found_file_size = *(long *)(found + 4);

  // Read the rest of the file into another buffer
  char *rest_of_file = malloc(found_file_size - (found - buffer));
  if (rest_of_file == NULL) {
    perror("malloc");
    free(buffer);
    return EXIT_FAILURE;
  }

  memcpy(rest_of_file, found, found_file_size - (found - buffer));

  // Write the rest of the file to a new file
  file = fopen("recovered.flv", "wb");
  if (file == NULL) {
    perror("fopen");
    free(buffer);
    free(rest_of_file);
    return EXIT_FAILURE;
  }

  fwrite(rest_of_file, 1, found_file_size - (found - buffer), file);
  fclose(file);

  printf("File recovered successfully.\n");

  free(buffer);
  free(rest_of_file);

  return EXIT_SUCCESS;
}