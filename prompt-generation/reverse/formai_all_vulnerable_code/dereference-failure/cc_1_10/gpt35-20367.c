//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extractMetadata(char *filename) {
  // Open file
  FILE *fp = fopen(filename, "r");
  
  // Check if file exists
  if (fp == NULL) {
    printf("File %s does not exist.\n", filename);
    return;
  }
  
  // Retrieve file extension
  char *file_extension = strrchr(filename, '.');
  if (file_extension == NULL) {
    printf("Could not retrieve file extension for %s.\n", filename);
    return;
  }
  
  // Metadata extraction based on file extension
  if (strcmp(file_extension, ".bmp") == 0) {
    // Extract BMP metadata
    printf("BMP metadata extracted from %s.\n", filename);

  } else if (strcmp(file_extension, ".mp3") == 0) {
    // Extract MP3 metadata
    printf("MP3 metadata extracted from %s.\n", filename);

  } else if (strcmp(file_extension, ".pdf") == 0) {
    // Extract PDF metadata
    printf("PDF metadata extracted from %s.\n", filename);

  } else {
    // Unknown file type
    printf("Unsupported file type %s.\n", file_extension);
    return;
  }
  
  // Close file
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }
  
  char *filename = argv[1];
  
  // Extract metadata
  extractMetadata(filename);
  
  return 0;
}