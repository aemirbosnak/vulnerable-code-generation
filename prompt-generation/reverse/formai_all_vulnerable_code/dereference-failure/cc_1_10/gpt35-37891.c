//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_metadata(char* file_content) {
  char* metadata = malloc(256 * sizeof(char));
  char* start = strstr(file_content, "metadata: ");
  char* end = strstr(file_content, "\n\n");

  if (start && end) {
    int len = end - (start + 10);
    strncpy(metadata, start + 10, len);
    metadata[len] = '\0';
  } else {
    printf("Error: No metadata found in file!\n");
    free(metadata);
    return NULL;
  }

  return metadata;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Error: Please provide a file path!\n");
    return 1;
  }
  
  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Error: Unable to open file!\n");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  
  char* file_content = malloc(file_size * sizeof(char));
  if (!file_content) {
    printf("Error: Memory allocation failed!\n");
    fclose(fp);
    return 1;
  }

  fread(file_content, sizeof(char), file_size, fp);
  fclose(fp);

  char* metadata = get_metadata(file_content);
  if (!metadata) {
    free(file_content);
    return 1;
  }

  printf("Metadata: %s\n", metadata);

  free(metadata);
  free(file_content);

  return 0;
}