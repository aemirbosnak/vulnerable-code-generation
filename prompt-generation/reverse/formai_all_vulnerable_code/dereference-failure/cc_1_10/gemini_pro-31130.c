//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store metadata about a file
typedef struct metadata {
  char *filename;        // The name of the file
  char *filetype;        // The type of the file (e.g., "text", "image", "video")
  unsigned long int size;  // The size of the file in bytes
  unsigned long int lines; // The number of lines in the file (if it is a text file)
  unsigned long int words; // The number of words in the file (if it is a text file)
} metadata;

// A function to extract metadata from a file
metadata *extract_metadata(char *filename) {
  // Allocate memory for the metadata structure
  metadata *md = malloc(sizeof(metadata));

  // Set the filename field
  md->filename = filename;

  // Determine the file type
  char *ext = strrchr(filename, '.');
  if (ext != NULL) {
    if (strcmp(ext, ".txt") == 0) {
      md->filetype = "text";
    } else if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) {
      md->filetype = "image";
    } else if (strcmp(ext, ".mp4") == 0) {
      md->filetype = "video";
    } else {
      md->filetype = "unknown";
    }
  } else {
    md->filetype = "unknown";
  }

  // Get the file size
  FILE *fp = fopen(filename, "r");
  if (fp != NULL) {
    fseek(fp, 0L, SEEK_END);
    md->size = ftell(fp);
    fclose(fp);
  } else {
    md->size = 0;
  }

  // If the file is a text file, count the number of lines and words
  if (strcmp(md->filetype, "text") == 0) {
    fp = fopen(filename, "r");
    if (fp != NULL) {
      char line[1024];
      md->lines = 0;
      md->words = 0;
      while (fgets(line, sizeof(line), fp) != NULL) {
        md->lines++;
        char *word = strtok(line, " ");
        while (word != NULL) {
          md->words++;
          word = strtok(NULL, " ");
        }
      }
      fclose(fp);
    }
  }

  // Return the metadata structure
  return md;
}

// A function to print the metadata for a file
void print_metadata(metadata *md) {
  printf("Filename: %s\n", md->filename);
  printf("Filetype: %s\n", md->filetype);
  printf("Size: %lu bytes\n", md->size);
  if (strcmp(md->filetype, "text") == 0) {
    printf("Lines: %lu\n", md->lines);
    printf("Words: %lu\n", md->words);
  }
}

// The main function
int main(int argc, char *argv[]) {
  // Check if a filename was provided
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Extract metadata from the file
  metadata *md = extract_metadata(argv[1]);

  // Print the metadata for the file
  print_metadata(md);

  // Free the memory allocated for the metadata structure
  free(md);

  return 0;
}