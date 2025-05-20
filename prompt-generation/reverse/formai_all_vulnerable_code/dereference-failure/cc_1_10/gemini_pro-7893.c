//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

/*
 * Calculate the checksum of a file.
 *
 * @param file The file to calculate the checksum of.
 * @return The checksum of the file, or -1 if an error occurred.
 */
long calculate_checksum(FILE *file) {
  long checksum = 0;
  int c;

  while ((c = fgetc(file)) != EOF) {
    checksum += c;
  }

  if (ferror(file)) {
    return -1;
  } else {
    return checksum;
  }
}

/*
 * Print the usage information for the program.
 */
void print_usage(char *program_name) {
  printf("Usage: %s <file>\n", program_name);
  printf("Calculates the checksum of a file.\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    print_usage(argv[0]);
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  long checksum = calculate_checksum(file);
  if (checksum == -1) {
    perror("Error calculating checksum");
    return EXIT_FAILURE;
  }

  printf("Checksum: %ld\n", checksum);

  fclose(file);

  return EXIT_SUCCESS;
}