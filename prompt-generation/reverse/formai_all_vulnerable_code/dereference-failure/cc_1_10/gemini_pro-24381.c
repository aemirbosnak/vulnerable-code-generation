//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: medieval
// In a realm where knowledge begets power, behold, a Metadata Extractor of no ordinary caliber

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// An array of characters to hold the file's contents, a tome filled with wisdom
char* tome;

// A function to read yonder file, a scroll containing a wealth of lore
int ReadFile(char* filename) {
  FILE* scroll = fopen(filename, "r");
  if (scroll == NULL) {
    printf("The scroll is lost, unable to open %s\n", filename);
    return 0;
  }
  // Determine the size of the scroll, its parchment length
  fseek(scroll, 0L, SEEK_END);
  long scrollLength = ftell(scroll);
  rewind(scroll);
  // Allocate space for the scroll's contents
  tome = malloc(scrollLength + 1);
  fread(tome, 1, scrollLength, scroll);
  fclose(scroll);
  tome[scrollLength] = '\0';
  return 1;
}

// A function to extract the metadata from the tome, a task fit for a wizard
char* ExtractMetadata(char* tome) {
  char* metadata = strstr(tome, "Metadata:");
  if (metadata == NULL) {
    printf("No metadata found");
    return NULL;
  }
  // Locate the end of the metadata, where its wisdom ends
  char* metadataEnd = strstr(metadata, "\n");
  int metadataLength = metadataEnd - metadata;
  // Copy the metadata into a separate parchment
  char* extractedMetadata = malloc(metadataLength + 1);
  strncpy(extractedMetadata, metadata, metadataLength);
  extractedMetadata[metadataLength] = '\0';
  return extractedMetadata;
}

// A function to display the metadata, a revelation to behold
void DisplayMetadata(char* metadata) {
  if (metadata == NULL) {
    printf("No metadata to display");
    return;
  }
  printf("\nMetadata:\n%s", metadata);
}

// The main function, where the adventure commences
int main(int argc, char* argv[]) {
  // If the user fails to provide a file, alas, the quest must be abandoned
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  // Attempt to read the file, its secrets begging to be unveiled
  if (!ReadFile(argv[1])) {
    printf("Failed to read the file");
    return 1;
  }
  // Seek the metadata, a hidden treasure within the tome
  char* metadata = ExtractMetadata(tome);
  // Display the metadata, a beacon of knowledge in the dark
  DisplayMetadata(metadata);
  return 0;
}