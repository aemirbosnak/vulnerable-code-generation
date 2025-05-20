//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

struct ImageMetadata {
  char id[64];
  int width;
  int height;
};

int extractMetadata(char* filename, struct ImageMetadata* metadata) {
  FILE* fp;
  char* buffer;
  size_t fileSize;
  
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s", filename);
    return -1;
  }
  
  buffer = (char*) malloc(MAX_FILE_SIZE);
  fileSize = fread(buffer, sizeof(char), MAX_FILE_SIZE, fp);
  
  // Extract metadata from buffer
  if (fileSize >= 64) {
    strncpy(metadata->id, buffer, 64);
  }
  metadata->width = *(int*) (buffer + 64);
  metadata->height = *(int*) (buffer + 68);
  
  free(buffer);
  fclose(fp);
  
  return 0;
}

int main() {
  struct ImageMetadata metadata;
  char* filename = "image.jpg";
  int result;
  
  result = extractMetadata(filename, &metadata);
  
  if (result == 0) {
    printf("Metadata for %s:\n", filename);
    printf("ID: %s\n", metadata.id);
    printf("Width: %d\n", metadata.width);
    printf("Height: %d\n", metadata.height);
  }
  
  return 0;
}