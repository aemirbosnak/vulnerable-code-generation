//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
/* A C Metadata Extractor Program */
/* Authored by D.Knuth */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char* argv[]) {
  FILE *file;
  char *buffer;
  long file_size;
  
  if (argc != 2) {
    printf("Error: Incorrect number of arguments\n");
    printf("Usage: metadata_extractor <filename>\n");
    exit(1);
  }
  
  file = fopen(argv[1], "rb");
  
  if (!file) {
    printf("Error: Failed to open file %s\n", argv[1]);
    exit(1);
  }
  
  fseek(file, 0L, SEEK_END);
  file_size = ftell(file);
  rewind(file);
  
  buffer = (char*) malloc(sizeof(char) * file_size);
  
  if (!buffer) {
    printf("Error: Failed to allocate memory\n");
    exit(1);
  }
  
  fread(buffer, sizeof(char), file_size, file);
  
  fclose(file);
  
  printf("File Name: %s\n", argv[1]);
  
  char *token, *rest = buffer;
  while ((token = strtok_r(rest, "\n", &rest))) {
    if (strstr(token, "Title: ")) {
      printf("Title: %s\n", token+7);
    } else if (strstr(token, "Artist: ")) {
      printf("Artist: %s\n", token+8);
    } else if (strstr(token, "Album: ")) {
      printf("Album: %s\n", token+7);
    } else if (strstr(token, "Year: ")) {
      printf("Year: %s\n", token+6);
    }
  }
  
  free(buffer);
  
  return 0;
}