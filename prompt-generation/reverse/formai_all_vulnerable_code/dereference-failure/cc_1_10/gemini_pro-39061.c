//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the metadata object.
static struct Metadata {
  char *title;
  char *description;
  char *keywords;
} metadata = {
  .title = "Untitled",
  .description = "",
  .keywords = "",
};

// Read the input file.
static char *read_input(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);
  char *buffer = malloc(size + 1);
  if (buffer == NULL) {
    fclose(fp);
    return NULL;
  }
  fread(buffer, size, 1, fp);
  fclose(fp);
  buffer[size] = '\0';
  return buffer;
}

// Extract the metadata from the input file.
static int extract_metadata(const char *input) {
  // Find the <meta> tags.
  char *meta_start = strstr(input, "<meta");
  if (meta_start == NULL) {
    return 1;
  }
  // Loop through the <meta> tags.
  while (meta_start != NULL) {
    // Find the name of the metadata.
    char *name_start = strstr(meta_start, "name=");
    if (name_start == NULL) {
      meta_start = strstr(meta_start, "<meta");
      continue;
    }
    name_start += 6;
    char *name_end = strchr(name_start, '"');
    if (name_end == NULL) {
      meta_start = strstr(meta_start, "<meta");
      continue;
    }
    char *name = malloc(name_end - name_start + 1);
    if (name == NULL) {
      return 1;
    }
    strncpy(name, name_start, name_end - name_start);
    name[name_end - name_start] = '\0';
    // Find the content of the metadata.
    char *content_start = strstr(meta_start, "content=");
    if (content_start == NULL) {
      meta_start = strstr(meta_start, "<meta");
      continue;
    }
    content_start += 9;
    char *content_end = strchr(content_start, '"');
    if (content_end == NULL) {
      meta_start = strstr(meta_start, "<meta");
      continue;
    }
    char *content = malloc(content_end - content_start + 1);
    if (content == NULL) {
      free(name);
      return 1;
    }
    strncpy(content, content_start, content_end - content_start);
    content[content_end - content_start] = '\0';
    // Update the metadata object.
    if (strcmp(name, "title") == 0) {
      metadata.title = content;
    } else if (strcmp(name, "description") == 0) {
      metadata.description = content;
    } else if (strcmp(name, "keywords") == 0) {
      metadata.keywords = content;
    }
    // Find the next <meta> tag.
    meta_start = strstr(meta_start, "<meta");
  }
  return 0;
}

// Print the metadata object.
static void print_metadata() {
  printf("Title: %s\n", metadata.title);
  printf("Description: %s\n", metadata.description);
  printf("Keywords: %s\n", metadata.keywords);
}

// Free the memory allocated by the metadata object.
static void free_metadata() {
  free(metadata.title);
  free(metadata.description);
  free(metadata.keywords);
}

// Main function.
int main(int argc, char *argv[]) {
  // Check the command line arguments.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  // Read the input file.
  char *input = read_input(argv[1]);
  if (input == NULL) {
    fprintf(stderr, "Error: Could not read input file.\n");
    return 1;
  }
  // Extract the metadata from the input file.
  int status = extract_metadata(input);
  if (status != 0) {
    fprintf(stderr, "Error: Could not extract metadata.\n");
    return 1;
  }
  // Print the metadata object.
  print_metadata();
  // Free the memory allocated by the metadata object.
  free_metadata();
  // Free the memory allocated by the input file.
  free(input);
  return 0;
}