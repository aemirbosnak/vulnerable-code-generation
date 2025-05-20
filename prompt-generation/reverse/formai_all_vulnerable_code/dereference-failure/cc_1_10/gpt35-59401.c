//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <string.h>

/* Function to extract metadata from files */
void extract_metadata(char *filename) {
  /* Open file in binary mode */
  FILE *fp = fopen(filename, "rb");
  
  if(fp == NULL) {
    printf("Error opening file!\n");
    return;
  }

  /* Read first 10 bytes of file */
  char header[11];
  fread(header, sizeof(char), 10, fp);
  header[10] = '\0';

  /* Check if file type is supported */
  if(strcmp(header, "META-CODE") != 0) {
    printf("Unsupported file type!\n");
    return;
  }

  /* Extract metadata */
  int version_num;
  char author[101];
  int num_functions;

  fread(&version_num, sizeof(int), 1, fp);
  fread(author, sizeof(char), 100, fp);
  author[100] = '\0';
  fread(&num_functions, sizeof(int), 1, fp);

  /* Print metadata */
  printf("Metadata for file \"%s\":\n", filename);
  printf("Version Number: %d\n", version_num);
  printf("Author: %s\n", author);
  printf("Number of Functions: %d\n", num_functions);

  fclose(fp);
}

int main() {
  /* Call extract_metadata function for each file */
  extract_metadata("example-metadata1.meta");
  extract_metadata("example-metadata2.meta");
  extract_metadata("example-metadata3.meta");

  return 0;
}