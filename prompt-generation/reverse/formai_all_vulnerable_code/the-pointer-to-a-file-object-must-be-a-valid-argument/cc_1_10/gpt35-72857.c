//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold metadata information
struct Metadata {
   char title[100];
   char artist[100];
   char album[100];
   char year[5];
};

// Function to read in metadata from a file
struct Metadata extract_metadata(char* filename) {
   struct Metadata data;
   FILE* file = fopen(filename, "r");
   char line[100];

   while (fgets(line, 100, file)) {
      // Ensure line is not a comment
      if (line[0] != '#') {
         char* token = strtok(line, ":");
         while (token != NULL) {
            if (strcmp(token, "Title") == 0) {
               token = strtok(NULL, ":");
               strcpy(data.title, token);
            } else if (strcmp(token, "Artist") == 0) {
               token = strtok(NULL, ":");
               strcpy(data.artist, token);
            } else if (strcmp(token, "Album") == 0) {
               token = strtok(NULL, ":");
               strcpy(data.album, token);
            } else if (strcmp(token, "Year") == 0) {
               token = strtok(NULL, ":");
               strcpy(data.year, token);
            }

            // Get next token
            token = strtok(NULL, ":");
         }
      }
   }

   fclose(file);
   return data;
}

int main() {
   struct Metadata data = extract_metadata("song.txt");

   printf("Title: %s\n", data.title);
   printf("Artist: %s\n", data.artist);
   printf("Album: %s\n", data.album);
   printf("Year: %s\n", data.year);

   return 0;
}