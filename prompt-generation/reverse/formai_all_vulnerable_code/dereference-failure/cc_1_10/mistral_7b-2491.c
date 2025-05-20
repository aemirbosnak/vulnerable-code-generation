//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOURCE_FILE "OriginOfLife"
#define DEST_FILE "NewBorn"

void die(const char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  FILE *source_file, *dest_file;
  char source_line[1024], dest_line[1024];
  size_t num_read;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  source_file = fopen(argv[1], "r");
  if (source_file == NULL) die("Could not open source file.");

  dest_file = fopen(argv[2], "r");
  if (dest_file == NULL) die("Could not open destination file.");

  while (fgets(source_line, sizeof(source_line), source_file) &&
         fgets(dest_line, sizeof(dest_line), dest_file)) {

    size_t source_len = strlen(source_line);
    size_t dest_len = strlen(dest_line);

    if (source_len != dest_len) {
      fprintf(stderr, "Line %ld in %s and %ld in %s have different lengths!\n",
              (long) (source_file ? ftell(source_file) / sizeof(char) : 0),
              SOURCE_FILE,
              (long) (dest_file ? ftell(dest_file) / sizeof(char) : 0),
              DEST_FILE);
      continue;
    }

    for (size_t i = 0; i < source_len; i++) {
      if (source_line[i] != dest_line[i]) {
        fprintf(stderr,
                "Line %ld in %s and %ld in %s differ at character %ld.\n",
                (long) (source_file ? ftell(source_file) / sizeof(char) : 0),
                SOURCE_FILE,
                (long) (dest_file ? ftell(dest_file) / sizeof(char) : 0),
                DEST_FILE,
                (size_t) i);
        break;
      }
    }
  }

  if (feof(source_file) && feof(dest_file)) {
    printf("Files are identical.\n");
  } else {
    fprintf(stderr, "Error: unexpected end of file(s).\n");
  }

  fclose(source_file);
  fclose(dest_file);
  return EXIT_SUCCESS;
}