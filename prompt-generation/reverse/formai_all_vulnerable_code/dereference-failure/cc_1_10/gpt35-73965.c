//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *input_file = argv[1];
  FILE *fp;
  long file_size;

  fp = fopen(input_file, "rb");

  fseek(fp, 0L, SEEK_END);
  file_size = ftell(fp);
  rewind(fp);

  char *file_data = (char *)malloc(sizeof(char) * file_size);
  
  fread(file_data, sizeof(char), file_size, fp);

  /* Extracting metadata magic bytes */
  char *metadata_magic = (char *)malloc(sizeof(char) * 4);
  memcpy(metadata_magic, file_data, 4);

  printf("Metadata magic:\n");
  for (int i = 0; i < 4; i++) {
    if (i % 2 == 0) {
      printf("%c ", metadata_magic[i]);
    } else {
      printf("%c\n", metadata_magic[i]);
    }
  }

  /* Extracting metadata version */
  char *metadata_version = (char *)malloc(sizeof(char) * 2);
  memcpy(metadata_version, file_data + 4, 2);

  printf("Metadata version:\n");
  printf("%c%c\n", metadata_version[0], metadata_version[1]);

  /* Extracting metadata length */
  int metadata_length = *((int *)(file_data + 6));

  printf("Metadata length: %d\n", metadata_length);

  /* Extracting metadata */
  char *metadata = (char *)malloc(sizeof(char) * metadata_length);
  memcpy(metadata, file_data + 10, metadata_length);

  printf("Metadata:\n%s\n", metadata);

  /* Cleanup */
  free(metadata);
  free(metadata_version);
  free(metadata_magic);
  free(file_data);

  fclose(fp);

  return 0;
}