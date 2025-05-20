//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold metadata information
typedef struct metadata {
   char artist[50];
   char album[50];
   char title[50];
   char genre[50];
   int year;
   int trackNumber;
} Metadata;

// Define a function to extract metadata from a file
Metadata* extractMetadata(char* filePath) {

   // Open the file in binary mode
   FILE* file = fopen(filePath, "rb");

   // Check if the file was opened successfully
   if (file == NULL) {
      printf("\nFailed to open file!");
      return NULL;
   }

   // Allocate memory for the metadata struct
   Metadata* metadata = (Metadata*) malloc(sizeof(Metadata));

   // Read metadata from the file
   fseek(file, -128, SEEK_END);
   fread(metadata->title, 30, 1, file);
   fread(metadata->artist, 30, 1, file);
   fread(metadata->album, 30, 1, file);
   fread(&metadata->year, 4, 1, file);
   fread(metadata->genre, 1, 1, file);

   // Close the file
   fclose(file);

   // Return the metadata struct
   return metadata;
}

int main() {

   // Test the extractMetadata function
   Metadata* metadata = extractMetadata("example.mp3");

   // Check if metadata was extracted
   if (metadata != NULL) {

      // Print the extracted metadata
      printf("\nTitle: %s", metadata->title);
      printf("\nArtist: %s", metadata->artist);
      printf("\nAlbum: %s", metadata->album);
      printf("\nYear: %d", metadata->year);
      printf("\nGenre: %d", metadata->genre);

      // Free memory allocated for metadata
      free(metadata);
   }

   return 0;
}